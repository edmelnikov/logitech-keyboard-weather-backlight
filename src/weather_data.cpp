/* the following pragma's allow libcurl to link properly */
#pragma comment(lib, "wldap32.lib")
#pragma comment(lib, "crypt32.lib")
#pragma comment(lib, "Ws2_32.lib")
#pragma comment(lib, "Normaliz.lib")

#include <cstdint>
#include <iostream>
#include <memory>
#include <string>

#include "curl/curl.h"
#include "logitech_keyboard_weather_backlight/weather_data.h"
#include "json/nlohmann/json.hpp"

using json = nlohmann::json;

/* 
    Handles the received data
    (static makes the function visible only in this translation unit)
*/
static size_t write_func(char *data, size_t size, size_t nmemb, std::string *userdata) {
    userdata->append(data);
    return size*nmemb; // number of bytes
}

/*
    JSON parser
*/
static int parse_json(std::string data_string) {
    json data_json = json::parse(data_string);
    // std::cout << data_json["main"]["temp"] << std::endl;
    return data_json["main"]["temp"];
}

/*
    gets weather data using openweather api
*/
int get_weather_data(const char* api_token, const char* city_name) {
    CURL *curl;
    CURLcode curlResult;    
    std::string curlBuffer; // this is where html data is stored
    char url[256]; // using char since libcurl accepts char url's
    strcpy_s(url, "https://api.openweathermap.org/data/2.5/weather?");

    /* url parameters: */
    /* city name */   
    strcat_s(url, "q=");
    strcat_s(url, city_name);
    strcat_s(url, "&");
    /* api key */ 
    strcat_s(url, "appid=");
    strcat_s(url, api_token);
    strcat_s(url, "&");
    /* units */
    strcat_s(url, "units=metric");

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);

        /* Don't bother trying IPv6, which would increase DNS resolution time */
        curl_easy_setopt(curl, CURLOPT_IPRESOLVE, CURL_IPRESOLVE_V4);

        /* time out after 10 seconds */
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);

        /* allow redirects */
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        /* where and how to write data */ 
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &curlBuffer);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_func);

        /* perform a blocking request to the server with options set above */        
        curlResult = curl_easy_perform(curl);
        
        /* extract information from a curl handle */
        long httpCode(0);
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);

        /* end a libcurl easy handle */
        curl_easy_cleanup(curl);

        if (httpCode == 200 && curlResult == CURLE_OK) {
            int temperature;
            temperature = parse_json(curlBuffer);
            return temperature;
        } 
        else {
            std::cout << "HTTP code " << httpCode << std::endl;            
            exit(EXIT_FAILURE);
        }      
    }
    return -100;
}
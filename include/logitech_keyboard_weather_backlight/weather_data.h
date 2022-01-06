#pragma once 
#include <string>

static size_t write_func(char *data, size_t size, size_t nmemb, std::string *userdata); // cannot determine which instance of overloaded function ?
int get_weather_data(const char* api_token, const char* city_name);

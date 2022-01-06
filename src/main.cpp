#include <iostream>
#include <chrono>
#include <thread>
#include <stdlib.h>

#include "LogitechLEDLib/LogitechLEDLib.h"
#include "logitech_keyboard_weather_backlight/plot_numbers.h"
#include "logitech_keyboard_weather_backlight/weather_data.h"


int main(int argc, char **argv){

    // command line arguments checks 
    if (argc < 2) {
        std::cout << "No API token!" << std::endl;
        exit(EXIT_FAILURE);
    }
    else if (argc < 3) {
        std::cout << "No city name!" << std::endl;
        exit(EXIT_FAILURE);
    }

    const char* api_token = argv[1];
    const char* city_name = argv[2];

    std::cout << get_weather_data(api_token, city_name) << std::endl;

    // if (LogiLedInitWithName("Weather") == 1){
    //     std::cout << "Keyboard control started " << std::endl;
    //     std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    //     LogiLedSetLightingForKeyWithKeyName(LogiLed::F6, 0, 125, 255);
    //     //plot_digit(1, DecimalPlace::TENS, 255, 255, 255);
    //     //plot_digit(2, DecimalPlace::ONES, 255, 255, 255);
    //     // int temperature = get_weather_data(api_token, city_name);
    //     // plot_number(temperature);
    //     // display_weather_data(0, 0, 0);

        
    // }
    // else {
    //     printf("The connection with Logitech Gaming Software is broken!\n");
    //     exit(EXIT_FAILURE);
    // }
    return 0; 
    // exit(EXIT_SUCCESS);
}

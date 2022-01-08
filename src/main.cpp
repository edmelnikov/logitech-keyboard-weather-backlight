#include <iostream>
#include <chrono>
#include <thread>
#include <stdlib.h>

#include "LogitechLEDLib/LogitechLEDLib.h"
#include "logitech_keyboard_weather_backlight/plot_numbers.h"
#include "logitech_keyboard_weather_backlight/weather_data.h"

int main(int argc, char **argv){
    /* command line arguments checks */ 
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

    if (LogiLedInitWithName("Weather") == 1){ // initialize the session
        std::cout << "Keyboard control started " << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // wait some time after the initialization
        LogiLedSetTargetDevice(LOGI_DEVICETYPE_ALL);
        LogiLedSetLighting(64, 64, 64); // background color
        LogiLedSetTargetDevice(LOGI_DEVICETYPE_PERKEY_RGB); // set the target device (rgb keyboard)
        LogiLedSaveCurrentLighting(); // save current keyboard lighting
        
        int temperature; 

        /* main loop */
        /* wip */
        // while(1) {

        // }

        for (int i = 0; i < 1; i++) { 
            temperature = get_weather_data(api_token, city_name);
            std::cout << temperature << std::endl;
            plot_temperature(temperature, 256, 256, 0, 256, 0, 256);
            std::this_thread::sleep_for(std::chrono::milliseconds(10000));
        }

        // display_weather_data(0, 0, 0);

        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        // LogiLedRestoreLighting(); 
        LogiLedShutdown(); // restore the last saved lighting and free memory used by sdk
        exit(EXIT_SUCCESS);
        
    }
    else {
        printf("The connection with Logitech Gaming Software is broken!\n");
        exit(EXIT_FAILURE);
    }
    return 0; 
    // exit(EXIT_SUCCESS);
}

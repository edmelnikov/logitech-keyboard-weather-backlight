#include <stdio.h>
#include <chrono>
#include <thread>
//#include <curl/curl.h>
#include "LogitechLEDLib.h"
#include "plot_numbers.h"

int main(){
    if (LogiLedInitWithName("Some name") == 1){
        printf("Keyboard control started \n");
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        display_weather_data(0, 0, 0);
    }
    else {
        printf("The connection with Logitech Gaming Software is broken!\n");
        return -1;
    }
    // TODO: add curl support    
    return 0;
}

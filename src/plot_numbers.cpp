#include <stdio.h>
#include <chrono>
#include <thread>
//#include <curl/curl.h>

#include "LogitechLEDLib.h"
#include "plot_numbers.h"

/* 
    The following function plots lines for a digit 
*/
void plot_line(const DecimalPlace decimal_place, const LinePosition line_position, const int redPercentage, const int greenPercentage, const int bluePercentage) { 
    if (decimal_place == DecimalPlace::TENS) {
        if (line_position == LinePosition::VERTICAL_LEFT) {
            LogiLedSetLightingForKeyWithKeyName(LogiLed::F2, redPercentage, greenPercentage, bluePercentage);
            LogiLedSetLightingForKeyWithKeyName(LogiLed::THREE, redPercentage, greenPercentage, bluePercentage);
            LogiLedSetLightingForKeyWithKeyName(LogiLed::E, redPercentage, greenPercentage, bluePercentage);
            LogiLedSetLightingForKeyWithKeyName(LogiLed::D, redPercentage, greenPercentage, bluePercentage);
            LogiLedSetLightingForKeyWithKeyName(LogiLed::C, redPercentage, greenPercentage, bluePercentage);
        }
        else if (line_position == LinePosition::VERTICAL_RIGHT){
            LogiLedSetLightingForKeyWithKeyName(LogiLed::F4, redPercentage, greenPercentage, bluePercentage);
            LogiLedSetLightingForKeyWithKeyName(LogiLed::FIVE, redPercentage, greenPercentage, bluePercentage);
            LogiLedSetLightingForKeyWithKeyName(LogiLed::T, redPercentage, greenPercentage, bluePercentage);
            LogiLedSetLightingForKeyWithKeyName(LogiLed::G, redPercentage, greenPercentage, bluePercentage);
            LogiLedSetLightingForKeyWithKeyName(LogiLed::B, redPercentage, greenPercentage, bluePercentage);
        }
        else if (line_position == LinePosition::HORIZONTAL_TOP){
            LogiLedSetLightingForKeyWithKeyName(LogiLed::F2, redPercentage, greenPercentage, bluePercentage);
            LogiLedSetLightingForKeyWithKeyName(LogiLed::F3, redPercentage, greenPercentage, bluePercentage);
            LogiLedSetLightingForKeyWithKeyName(LogiLed::F4, redPercentage, greenPercentage, bluePercentage);
        }
        else if (line_position == LinePosition::HORIZONTAL_MID){
            LogiLedSetLightingForKeyWithKeyName(LogiLed::E, redPercentage, greenPercentage, bluePercentage);
            LogiLedSetLightingForKeyWithKeyName(LogiLed::R, redPercentage, greenPercentage, bluePercentage);
            LogiLedSetLightingForKeyWithKeyName(LogiLed::T, redPercentage, greenPercentage, bluePercentage);
        }
        else if (line_position == LinePosition::HORIZONTAL_BOT){
            LogiLedSetLightingForKeyWithKeyName(LogiLed::C, redPercentage, greenPercentage, bluePercentage);
            LogiLedSetLightingForKeyWithKeyName(LogiLed::V, redPercentage, greenPercentage, bluePercentage);
            LogiLedSetLightingForKeyWithKeyName(LogiLed::B, redPercentage, greenPercentage, bluePercentage);
        }
    }
    else if (decimal_place == DecimalPlace::ONES) {        
        if (line_position == LinePosition::VERTICAL_LEFT) {
            LogiLedSetLightingForKeyWithKeyName(LogiLed::F6, redPercentage, greenPercentage, bluePercentage);
            LogiLedSetLightingForKeyWithKeyName(LogiLed::EIGHT, redPercentage, greenPercentage, bluePercentage);
            LogiLedSetLightingForKeyWithKeyName(LogiLed::I, redPercentage, greenPercentage, bluePercentage);
            LogiLedSetLightingForKeyWithKeyName(LogiLed::K, redPercentage, greenPercentage, bluePercentage);
            LogiLedSetLightingForKeyWithKeyName(LogiLed::COMMA, redPercentage, greenPercentage, bluePercentage);
        }
        else if (line_position == LinePosition::VERTICAL_RIGHT){
            LogiLedSetLightingForKeyWithKeyName(LogiLed::F8, redPercentage, greenPercentage, bluePercentage);
            LogiLedSetLightingForKeyWithKeyName(LogiLed::ZERO, redPercentage, greenPercentage, bluePercentage);
            LogiLedSetLightingForKeyWithKeyName(LogiLed::P, redPercentage, greenPercentage, bluePercentage);
            LogiLedSetLightingForKeyWithKeyName(LogiLed::SEMICOLON, redPercentage, greenPercentage, bluePercentage);
            LogiLedSetLightingForKeyWithKeyName(LogiLed::FORWARD_SLASH, redPercentage, greenPercentage, bluePercentage);
        }
        else if (line_position == LinePosition::HORIZONTAL_TOP){
            LogiLedSetLightingForKeyWithKeyName(LogiLed::F6, redPercentage, greenPercentage, bluePercentage);
            LogiLedSetLightingForKeyWithKeyName(LogiLed::F7, redPercentage, greenPercentage, bluePercentage);
            LogiLedSetLightingForKeyWithKeyName(LogiLed::F8, redPercentage, greenPercentage, bluePercentage);
        }
        else if (line_position == LinePosition::HORIZONTAL_MID){
            LogiLedSetLightingForKeyWithKeyName(LogiLed::I, redPercentage, greenPercentage, bluePercentage);
            LogiLedSetLightingForKeyWithKeyName(LogiLed::O, redPercentage, greenPercentage, bluePercentage);
            LogiLedSetLightingForKeyWithKeyName(LogiLed::P, redPercentage, greenPercentage, bluePercentage);
        }
        else if (line_position == LinePosition::HORIZONTAL_BOT){
            LogiLedSetLightingForKeyWithKeyName(LogiLed::COMMA, redPercentage, greenPercentage, bluePercentage);
            LogiLedSetLightingForKeyWithKeyName(LogiLed::PERIOD, redPercentage, greenPercentage, bluePercentage);
            LogiLedSetLightingForKeyWithKeyName(LogiLed::FORWARD_SLASH, redPercentage, greenPercentage, bluePercentage);
        }
    }
}

/*
    Plots a digit on a keyboard
*/
void plot_digit(int digit, DecimalPlace decimal_place, int redPercentage, int greenPercentage, int bluePercentage){
    switch (digit) {
        case 0:
            plot_line(decimal_place, LinePosition::VERTICAL_LEFT, redPercentage, greenPercentage, bluePercentage);
            plot_line(decimal_place, LinePosition::VERTICAL_RIGHT, redPercentage, greenPercentage, bluePercentage);
            plot_line(decimal_place, LinePosition::HORIZONTAL_TOP, redPercentage, greenPercentage, bluePercentage);
            plot_line(decimal_place, LinePosition::HORIZONTAL_BOT, redPercentage, greenPercentage, bluePercentage);
            break;
        case 1:
            plot_line(decimal_place, LinePosition::VERTICAL_RIGHT, redPercentage, greenPercentage, bluePercentage);
            break;
        case 2:
            plot_line(decimal_place, LinePosition::HORIZONTAL_TOP, redPercentage, greenPercentage, bluePercentage);
            plot_line(decimal_place, LinePosition::HORIZONTAL_MID, redPercentage, greenPercentage, bluePercentage);
            plot_line(decimal_place, LinePosition::HORIZONTAL_BOT, redPercentage, greenPercentage, bluePercentage);
            if (decimal_place == DecimalPlace::TENS) {
                LogiLedSetLightingForKeyWithKeyName(LogiLed::FIVE, redPercentage, greenPercentage, bluePercentage);
                LogiLedSetLightingForKeyWithKeyName(LogiLed::D, redPercentage, greenPercentage, bluePercentage);                    
            }
            else if (decimal_place == DecimalPlace::ONES) {
                LogiLedSetLightingForKeyWithKeyName(LogiLed::ZERO, redPercentage, greenPercentage, bluePercentage);
                LogiLedSetLightingForKeyWithKeyName(LogiLed::K, redPercentage, greenPercentage, bluePercentage);
            }
            break;
        case 3:
            plot_line(decimal_place, LinePosition::VERTICAL_RIGHT, redPercentage, greenPercentage, bluePercentage);
            plot_line(decimal_place, LinePosition::HORIZONTAL_TOP, redPercentage, greenPercentage, bluePercentage);
            plot_line(decimal_place, LinePosition::HORIZONTAL_MID, redPercentage, greenPercentage, bluePercentage);
            plot_line(decimal_place, LinePosition::HORIZONTAL_BOT, redPercentage, greenPercentage, bluePercentage);
            break;
        case 4:
            plot_line(decimal_place, LinePosition::VERTICAL_RIGHT, redPercentage, greenPercentage, bluePercentage);
            plot_line(decimal_place, LinePosition::HORIZONTAL_MID, redPercentage, greenPercentage, bluePercentage);
            if (decimal_place == DecimalPlace::TENS) {
                LogiLedSetLightingForKeyWithKeyName(LogiLed::F2, redPercentage, greenPercentage, bluePercentage);
                LogiLedSetLightingForKeyWithKeyName(LogiLed::THREE, redPercentage, greenPercentage, bluePercentage);                    
            }
            else if (decimal_place == DecimalPlace::ONES) {
                LogiLedSetLightingForKeyWithKeyName(LogiLed::F6, redPercentage, greenPercentage, bluePercentage);
                LogiLedSetLightingForKeyWithKeyName(LogiLed::EIGHT, redPercentage, greenPercentage, bluePercentage);
            }
            break;    
        case 5:
            plot_line(decimal_place, LinePosition::HORIZONTAL_TOP, redPercentage, greenPercentage, bluePercentage);
            plot_line(decimal_place, LinePosition::HORIZONTAL_MID, redPercentage, greenPercentage, bluePercentage);
            plot_line(decimal_place, LinePosition::HORIZONTAL_BOT, redPercentage, greenPercentage, bluePercentage);
            if (decimal_place == DecimalPlace::TENS) {
                LogiLedSetLightingForKeyWithKeyName(LogiLed::THREE, redPercentage, greenPercentage, bluePercentage);
                LogiLedSetLightingForKeyWithKeyName(LogiLed::G, redPercentage, greenPercentage, bluePercentage);    
            }
            else if (decimal_place == DecimalPlace::ONES) {
                LogiLedSetLightingForKeyWithKeyName(LogiLed::EIGHT, redPercentage, greenPercentage, bluePercentage);
                LogiLedSetLightingForKeyWithKeyName(LogiLed::SEMICOLON, redPercentage, greenPercentage, bluePercentage);
            }
            break;
        case 6:
            plot_line(decimal_place, LinePosition::VERTICAL_LEFT, redPercentage, greenPercentage, bluePercentage);
            plot_line(decimal_place, LinePosition::HORIZONTAL_TOP, redPercentage, greenPercentage, bluePercentage);
            plot_line(decimal_place, LinePosition::HORIZONTAL_MID, redPercentage, greenPercentage, bluePercentage);
            plot_line(decimal_place, LinePosition::HORIZONTAL_BOT, redPercentage, greenPercentage, bluePercentage);
            if (decimal_place == DecimalPlace::TENS) {
                LogiLedSetLightingForKeyWithKeyName(LogiLed::G, redPercentage, greenPercentage, bluePercentage);    
            }
            else if (decimal_place == DecimalPlace::ONES) {
                LogiLedSetLightingForKeyWithKeyName(LogiLed::SEMICOLON, redPercentage, greenPercentage, bluePercentage);
            }
            break;
        case 7:
            plot_line(decimal_place, LinePosition::VERTICAL_RIGHT, redPercentage, greenPercentage, bluePercentage);
            plot_line(decimal_place, LinePosition::HORIZONTAL_TOP, redPercentage, greenPercentage, bluePercentage);
            break;
        case 8:
            plot_line(decimal_place, LinePosition::VERTICAL_LEFT, redPercentage, greenPercentage, bluePercentage);
            plot_line(decimal_place, LinePosition::VERTICAL_RIGHT, redPercentage, greenPercentage, bluePercentage);
            plot_line(decimal_place, LinePosition::HORIZONTAL_TOP, redPercentage, greenPercentage, bluePercentage);
            plot_line(decimal_place, LinePosition::HORIZONTAL_MID, redPercentage, greenPercentage, bluePercentage);
            plot_line(decimal_place, LinePosition::HORIZONTAL_BOT, redPercentage, greenPercentage, bluePercentage);
            break;
        case 9:
            plot_line(decimal_place, LinePosition::VERTICAL_RIGHT, redPercentage, greenPercentage, bluePercentage);
            plot_line(decimal_place, LinePosition::HORIZONTAL_TOP, redPercentage, greenPercentage, bluePercentage);
            plot_line(decimal_place, LinePosition::HORIZONTAL_MID, redPercentage, greenPercentage, bluePercentage);
            plot_line(decimal_place, LinePosition::HORIZONTAL_BOT, redPercentage, greenPercentage, bluePercentage);            
            if (decimal_place == DecimalPlace::TENS) {
                LogiLedSetLightingForKeyWithKeyName(LogiLed::THREE, redPercentage, greenPercentage, bluePercentage);    
            }
            else if (decimal_place == DecimalPlace::ONES) {
                LogiLedSetLightingForKeyWithKeyName(LogiLed::EIGHT, redPercentage, greenPercentage, bluePercentage);
            }
            break;
    }
}

void plot_number(int num) { 
    if (num < 100 && num > -100) {
        int first_digit = abs(num / 10);
        int second_digit = abs(num % 10);
        

        // the following code changes the color of digits depending on the temperature
        int red = 255; 
        int green = 255;
        int blue = 255;
        
        int coef = 0;
        if (abs(num) > 30) {
            coef = (abs(num) / 5) * 10;
        }
        else {
            coef = 6*10; // I'm too lazy to explain this
        }

        if (num < 0) { 
            red = 60 - coef;
            green = 60 - coef;
        }
        else if (num > 0){
            green =  60 - coef;
            blue = 60 - coef;
        }

        printf("%i, %i, %i \n", red, green, blue);
        plot_digit(first_digit, DecimalPlace::TENS, red, green, blue);
        plot_digit(second_digit, DecimalPlace::ONES, red, green, blue);
    }
}

void display_weather_data(int bg_redPercentage, int bg_greenPercentage, int bg_bluePercentage) {
    
    for (int i = -40; i <= 40; i += 1) {
            // LogiLedRestoreLighting();
            LogiLedSetTargetDevice(LOGI_DEVICETYPE_ALL);
            LogiLedSetLighting(bg_redPercentage, bg_greenPercentage, bg_bluePercentage);
            LogiLedSetTargetDevice(LOGI_DEVICETYPE_PERKEY_RGB);
            plot_number(i);
            printf("%i \n", i);
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}
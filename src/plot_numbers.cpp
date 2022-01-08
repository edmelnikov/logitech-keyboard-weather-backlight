#include <stdio.h>
#include <chrono>
#include <thread>

#include "LogitechLEDLib/LogitechLEDLib.h"
#include "logitech_keyboard_weather_backlight/plot_numbers.h"

/* 
    Plots lines for a digit 
*/
void plot_line(DecimalPlace decimal_place, LinePosition line_position, int red, int green, int blue) { 
    if (decimal_place == DecimalPlace::TENS) {
        if (line_position == LinePosition::VERTICAL_LEFT) {
            LogiLedSetLightingForKeyWithKeyName(LogiLed::F2, red, green, blue);
            LogiLedSetLightingForKeyWithKeyName(LogiLed::THREE, red, green, blue);
            LogiLedSetLightingForKeyWithKeyName(LogiLed::E, red, green, blue);
            LogiLedSetLightingForKeyWithKeyName(LogiLed::D, red, green, blue);
            LogiLedSetLightingForKeyWithKeyName(LogiLed::C, red, green, blue);
        }
        else if (line_position == LinePosition::VERTICAL_RIGHT){
            LogiLedSetLightingForKeyWithKeyName(LogiLed::F4, red, green, blue);
            LogiLedSetLightingForKeyWithKeyName(LogiLed::FIVE, red, green, blue);
            LogiLedSetLightingForKeyWithKeyName(LogiLed::T, red, green, blue);
            LogiLedSetLightingForKeyWithKeyName(LogiLed::G, red, green, blue);
            LogiLedSetLightingForKeyWithKeyName(LogiLed::B, red, green, blue);
        }
        else if (line_position == LinePosition::HORIZONTAL_TOP){
            LogiLedSetLightingForKeyWithKeyName(LogiLed::F2, red, green, blue);
            LogiLedSetLightingForKeyWithKeyName(LogiLed::F3, red, green, blue);
            LogiLedSetLightingForKeyWithKeyName(LogiLed::F4, red, green, blue);
        }
        else if (line_position == LinePosition::HORIZONTAL_MID){
            LogiLedSetLightingForKeyWithKeyName(LogiLed::E, red, green, blue);
            LogiLedSetLightingForKeyWithKeyName(LogiLed::R, red, green, blue);
            LogiLedSetLightingForKeyWithKeyName(LogiLed::T, red, green, blue);
        }
        else if (line_position == LinePosition::HORIZONTAL_BOT){
            LogiLedSetLightingForKeyWithKeyName(LogiLed::C, red, green, blue);
            LogiLedSetLightingForKeyWithKeyName(LogiLed::V, red, green, blue);
            LogiLedSetLightingForKeyWithKeyName(LogiLed::B, red, green, blue);
        }
    }
    else if (decimal_place == DecimalPlace::ONES) {        
        if (line_position == LinePosition::VERTICAL_LEFT) {
            LogiLedSetLightingForKeyWithKeyName(LogiLed::F6, red, green, blue);
            LogiLedSetLightingForKeyWithKeyName(LogiLed::EIGHT, red, green, blue);
            LogiLedSetLightingForKeyWithKeyName(LogiLed::I, red, green, blue);
            LogiLedSetLightingForKeyWithKeyName(LogiLed::K, red, green, blue);
            LogiLedSetLightingForKeyWithKeyName(LogiLed::COMMA, red, green, blue);
        }
        else if (line_position == LinePosition::VERTICAL_RIGHT){
            LogiLedSetLightingForKeyWithKeyName(LogiLed::F8, red, green, blue);
            LogiLedSetLightingForKeyWithKeyName(LogiLed::ZERO, red, green, blue);
            LogiLedSetLightingForKeyWithKeyName(LogiLed::P, red, green, blue);
            LogiLedSetLightingForKeyWithKeyName(LogiLed::SEMICOLON, red, green, blue);
            LogiLedSetLightingForKeyWithKeyName(LogiLed::FORWARD_SLASH, red, green, blue);
        }
        else if (line_position == LinePosition::HORIZONTAL_TOP){
            LogiLedSetLightingForKeyWithKeyName(LogiLed::F6, red, green, blue);
            LogiLedSetLightingForKeyWithKeyName(LogiLed::F7, red, green, blue);
            LogiLedSetLightingForKeyWithKeyName(LogiLed::F8, red, green, blue);
        }
        else if (line_position == LinePosition::HORIZONTAL_MID){
            LogiLedSetLightingForKeyWithKeyName(LogiLed::I, red, green, blue);
            LogiLedSetLightingForKeyWithKeyName(LogiLed::O, red, green, blue);
            LogiLedSetLightingForKeyWithKeyName(LogiLed::P, red, green, blue);
        }
        else if (line_position == LinePosition::HORIZONTAL_BOT){
            LogiLedSetLightingForKeyWithKeyName(LogiLed::COMMA, red, green, blue);
            LogiLedSetLightingForKeyWithKeyName(LogiLed::PERIOD, red, green, blue);
            LogiLedSetLightingForKeyWithKeyName(LogiLed::FORWARD_SLASH, red, green, blue);
        }
    }
}

/* 
    Plots a digit on the keyboard 
*/
void plot_digit(int digit, DecimalPlace decimal_place, int red, int green, int blue){
    switch (digit) {
        case 0:
            plot_line(decimal_place, LinePosition::VERTICAL_LEFT, red, green, blue);
            plot_line(decimal_place, LinePosition::VERTICAL_RIGHT, red, green, blue);
            plot_line(decimal_place, LinePosition::HORIZONTAL_TOP, red, green, blue);
            plot_line(decimal_place, LinePosition::HORIZONTAL_BOT, red, green, blue);
            break;
        case 1:
            plot_line(decimal_place, LinePosition::VERTICAL_RIGHT, red, green, blue);
            break;
        case 2:
            plot_line(decimal_place, LinePosition::HORIZONTAL_TOP, red, green, blue);
            plot_line(decimal_place, LinePosition::HORIZONTAL_MID, red, green, blue);
            plot_line(decimal_place, LinePosition::HORIZONTAL_BOT, red, green, blue);
            if (decimal_place == DecimalPlace::TENS) {
                LogiLedSetLightingForKeyWithKeyName(LogiLed::FIVE, red, green, blue);
                LogiLedSetLightingForKeyWithKeyName(LogiLed::D, red, green, blue);                    
            }
            else if (decimal_place == DecimalPlace::ONES) {
                LogiLedSetLightingForKeyWithKeyName(LogiLed::ZERO, red, green, blue);
                LogiLedSetLightingForKeyWithKeyName(LogiLed::K, red, green, blue);
            }
            break;
        case 3:
            plot_line(decimal_place, LinePosition::VERTICAL_RIGHT, red, green, blue);
            plot_line(decimal_place, LinePosition::HORIZONTAL_TOP, red, green, blue);
            plot_line(decimal_place, LinePosition::HORIZONTAL_MID, red, green, blue);
            plot_line(decimal_place, LinePosition::HORIZONTAL_BOT, red, green, blue);
            break;
        case 4:
            plot_line(decimal_place, LinePosition::VERTICAL_RIGHT, red, green, blue);
            plot_line(decimal_place, LinePosition::HORIZONTAL_MID, red, green, blue);
            if (decimal_place == DecimalPlace::TENS) {
                LogiLedSetLightingForKeyWithKeyName(LogiLed::F2, red, green, blue);
                LogiLedSetLightingForKeyWithKeyName(LogiLed::THREE, red, green, blue);                    
            }
            else if (decimal_place == DecimalPlace::ONES) {
                LogiLedSetLightingForKeyWithKeyName(LogiLed::F6, red, green, blue);
                LogiLedSetLightingForKeyWithKeyName(LogiLed::EIGHT, red, green, blue);
            }
            break;    
        case 5:
            plot_line(decimal_place, LinePosition::HORIZONTAL_TOP, red, green, blue);
            plot_line(decimal_place, LinePosition::HORIZONTAL_MID, red, green, blue);
            plot_line(decimal_place, LinePosition::HORIZONTAL_BOT, red, green, blue);
            if (decimal_place == DecimalPlace::TENS) {
                LogiLedSetLightingForKeyWithKeyName(LogiLed::THREE, red, green, blue);
                LogiLedSetLightingForKeyWithKeyName(LogiLed::G, red, green, blue);    
            }
            else if (decimal_place == DecimalPlace::ONES) {
                LogiLedSetLightingForKeyWithKeyName(LogiLed::EIGHT, red, green, blue);
                LogiLedSetLightingForKeyWithKeyName(LogiLed::SEMICOLON, red, green, blue);
            }
            break;
        case 6:
            plot_line(decimal_place, LinePosition::VERTICAL_LEFT, red, green, blue);
            plot_line(decimal_place, LinePosition::HORIZONTAL_TOP, red, green, blue);
            plot_line(decimal_place, LinePosition::HORIZONTAL_MID, red, green, blue);
            plot_line(decimal_place, LinePosition::HORIZONTAL_BOT, red, green, blue);
            if (decimal_place == DecimalPlace::TENS) {
                LogiLedSetLightingForKeyWithKeyName(LogiLed::G, red, green, blue);    
            }
            else if (decimal_place == DecimalPlace::ONES) {
                LogiLedSetLightingForKeyWithKeyName(LogiLed::SEMICOLON, red, green, blue);
            }
            break;
        case 7:
            plot_line(decimal_place, LinePosition::VERTICAL_RIGHT, red, green, blue);
            plot_line(decimal_place, LinePosition::HORIZONTAL_TOP, red, green, blue);
            break;
        case 8:
            plot_line(decimal_place, LinePosition::VERTICAL_LEFT, red, green, blue);
            plot_line(decimal_place, LinePosition::VERTICAL_RIGHT, red, green, blue);
            plot_line(decimal_place, LinePosition::HORIZONTAL_TOP, red, green, blue);
            plot_line(decimal_place, LinePosition::HORIZONTAL_MID, red, green, blue);
            plot_line(decimal_place, LinePosition::HORIZONTAL_BOT, red, green, blue);
            break;
        case 9:
            plot_line(decimal_place, LinePosition::VERTICAL_RIGHT, red, green, blue);
            plot_line(decimal_place, LinePosition::HORIZONTAL_TOP, red, green, blue);
            plot_line(decimal_place, LinePosition::HORIZONTAL_MID, red, green, blue);
            plot_line(decimal_place, LinePosition::HORIZONTAL_BOT, red, green, blue);            
            if (decimal_place == DecimalPlace::TENS) {
                LogiLedSetLightingForKeyWithKeyName(LogiLed::THREE, red, green, blue);    
            }
            else if (decimal_place == DecimalPlace::ONES) {
                LogiLedSetLightingForKeyWithKeyName(LogiLed::EIGHT, red, green, blue);
            }
            break;
    }
}

/* 
    Plots positive or negative sign
 */
void plot_sign(Sign sign, int red, int green, int blue) {
    LogiLedSetLightingForKeyWithKeyName(LogiLed::TAB, red, green, blue);
    LogiLedSetLightingForKeyWithKeyName(LogiLed::Q, red, green, blue);
    LogiLedSetLightingForKeyWithKeyName(LogiLed::W, red, green, blue);
    if (sign == Sign::POSITIVE) { 
        LogiLedSetLightingForKeyWithKeyName(LogiLed::ONE, red, green, blue);
        LogiLedSetLightingForKeyWithKeyName(LogiLed::A, red, green, blue);
    }
}

/* 
    Plots temperature value on the keyboard and automatically calculates the color
*/
void plot_temperature(int num) { 
    if (num < 100 && num > -100) {
        int first_digit = abs(num / 10);
        int second_digit = abs(num % 10);
        
        /* the following code changes the color of digits depending on the temperature */        
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

        plot_digit(first_digit, DecimalPlace::TENS, red, green, blue);
        plot_digit(second_digit, DecimalPlace::ONES, red, green, blue);
        if (num > 0) {
            plot_sign(Sign::POSITIVE, red, green, blue);
        }
        else if (num < 0) { 
            plot_sign(Sign::NEGATIVE, red, green, blue);
        }
    }
}

/*
    Overload of the previous function that allows custom colors
*/
void plot_temperature(int num, int num_red, int num_green, int num_blue, int sign_red, int sign_green, int sign_blue) {
    int first_digit = abs(num / 10);
    int second_digit = abs(num % 10);
    plot_digit(first_digit, DecimalPlace::TENS, num_red, num_green, num_blue);
    plot_digit(second_digit, DecimalPlace::ONES, num_red, num_green, num_blue);
    if (num > 0) {
        plot_sign(POSITIVE, sign_red, sign_green, sign_blue);
    }
    else if (num < 0) { 
        plot_sign(NEGATIVE, sign_red, sign_green, sign_blue);
    }
}

/* 
    WIP 
*/
void display_weather_data(int bg_red, int bg_green, int bg_blue) {
    
    for (int i = -40; i <= 40; i += 1) {
            // LogiLedRestoreLighting();
            LogiLedSetTargetDevice(LOGI_DEVICETYPE_ALL);
            LogiLedSetLighting(bg_red, bg_green, bg_blue);
            LogiLedSetTargetDevice(LOGI_DEVICETYPE_PERKEY_RGB);
            plot_temperature(i);
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}
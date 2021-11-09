#pragma once

typedef enum {
    TENS,
    ONES
}DecimalPlace;

typedef enum{
    VERTICAL_LEFT,
    VERTICAL_RIGHT,
    HORIZONTAL_TOP,
    HORIZONTAL_MID, 
    HORIZONTAL_BOT
}LinePosition;

void plot_line(const DecimalPlace decimal_place, const LinePosition line_position, const int redPercentage, const int greenPercentage, const int bluePercentage);
void plot_digit(int digit, DecimalPlace decimal_place, int redPercentage, int greenPercentage, int bluePercentage);
void plot_number(int num);
void display_weather_data(int bg_redPercentage, int bg_greenPercentage, int bg_bluePercentage);

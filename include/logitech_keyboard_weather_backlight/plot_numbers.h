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

typedef enum {
    POSITIVE,
    NEGATIVE
}Sign;

void plot_line(DecimalPlace decimal_place, LinePosition line_position, int red, int green, int blue);
void plot_digit(int digit, DecimalPlace decimal_place, int red, int green, int blue);
void plot_temperature(int num);
void plot_temperature(int num, int num_red, int num_green, int num_blue, int sign_red, int sign_green, int sign_blue);
void plot_sign(Sign sign, int red, int green, int blue);
void display_weather_data(int bg_red, int bg_green, int bg_blue);

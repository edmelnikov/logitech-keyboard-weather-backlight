# logitech-keyboard-weather-backlight

This is a small pet project enabling a Logitech RGB keyboard to display current outside temperature with its per-key lighting. 

Here is an example of the proposed feature: 

![](https://github.com/edmelnikov/logitech-keyboard-weather-backlight/blob/main/images/1.PNG?raw=true)

The keyboard displays number 23 in a warm color, which means that the outside temperature is +23°C. 

The color of the number is changed depending on the value: the colder it is outside the cooler the color. 
Yellow-red hues signify the positive temperature, and the negative temperature is represented by blue hues. 

## Compilation and launching

$ cd .../logitech-keyboard-weather-backlight
$ cmake -G "Visual Studio 16 2019" -A x64 -S . -B ./build
$ msbuild ./build/logitech_keyboard_weather_backlight.sln

$ ./build/Debug/logitech_keyboard_weather_backlight.exe <api_key> <city_name>

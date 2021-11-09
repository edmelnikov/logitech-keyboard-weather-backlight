cmake_minimum_required(VERSION 3.13)
project(logitech_keyboard_weather_backlight)
set(CMAKE_CXX_STANDARD 14)

add_executable(${PROJECT_NAME} src/main.cpp src/plot_numbers.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/lib/X64/LogitechLEDLib.lib)

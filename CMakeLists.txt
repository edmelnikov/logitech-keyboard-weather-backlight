cmake_minimum_required(VERSION 3.13)
project(logitech_keyboard_weather_backlight)
set(CMAKE_CXX_STANDARD 14)

# set(CMAKE_C_FLAGS_DEBUG "-DCURL_STATICLIB")
# set(CMAKE_C_FLAGS_MINSIZEREL "-DCURL_STATICLIB")
# set(CMAKE_C_FLAGS_RELWITHDEBINFO "-DCURL_STATICLIB")
# set(CMAKE_C_FLAGS_RELEASE "-DCURL_STATICLIB")

# allows to link against libcurl_a.lib
set(CMAKE_CXX_FLAGS_DEBUG "-DCURL_STATICLIB")
set(CMAKE_CXX_FLAGS_MINSIZEREL "-DCURL_STATICLIB")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-DCURL_STATICLIB")
set(CMAKE_CXX_FLAGS_RELEASE "-DCURL_STATICLIB")


add_executable(${PROJECT_NAME} 
    src/main.cpp 
    src/plot_numbers.cpp
    src/weather_data.cpp
)

# target_include_directories(${PROJECT_NAME} PUBLIC     
#     ${CMAKE_CURRENT_SOURCE_DIR}/include/curl
#     ${CMAKE_CURRENT_SOURCE_DIR}/include/logitech_keyboard_weather_backlight
#     ${CMAKE_CURRENT_SOURCE_DIR}/include/LogitechLEDLib
# )

target_include_directories(${PROJECT_NAME} PUBLIC     
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)


TARGET_LINK_LIBRARIES(${PROJECT_NAME} 
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/X64/LogitechLEDLib.lib 
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/libcurl_a.lib
) 

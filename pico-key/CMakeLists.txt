# cmake version!
cmake_minimum_required(VERSION 3.13)

# set path
set(PICO_SDK_PATH "/usr/share/pico-sdk")

# include the sdk
include(pico_sdk_import.cmake)

# project name
project(pico-key)

# start sdk
pico_sdk_init()

# include config
include_directories(config)

# source
add_executable(pico-key
    pico-key.c
)

# pico sdk libraries
target_link_libraries(pico-key
    pico_stdlib
    pico_malloc
    hardware_uart
    hardware_gpio
)

# generate extra files
pico_add_extra_outputs(pico-key)
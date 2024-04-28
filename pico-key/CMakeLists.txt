# cmake version!
cmake_minimum_required(VERSION 3.13)

# set path
# this is assuming you pulled this from github
set(PICO_SDK_FETCH_FROM_GIT ON)

# include the sdk
include(${CMAKE_CURRENT_LIST_DIR}/pico_sdk_import.cmake)

# project name
project(pico-key)

# start sdk
pico_sdk_init()

# source
add_executable(pico-key pico-key.c)

# pico sdk libraries
target_link_libraries(pico-key
    pico_stdio
    pico_stdlib
    pico_malloc
    hardware_uart
    hardware_gpio
)

# generate extra files
pico_add_extra_outputs(pico-key)
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

# source
add_executable(${PROJECT_NAME}
    pico-key.c
)

# pico sdk libraries
target_link_libraries(${PROJECT_NAME}
    pico_stdlib
)

pico_add_extra_outputs(${PROJECT_NAME})
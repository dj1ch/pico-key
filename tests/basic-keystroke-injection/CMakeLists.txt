# cmake version!
cmake_minimum_required(VERSION 3.13)

# set path
set(PICO_SDK_FETCH_FROM_GIT ON)

# include the sdk
include(${CMAKE_CURRENT_LIST_DIR}/pico_sdk_import.cmake)

# project name
project(pico-key)

# start sdk
pico_sdk_init()

# add tinyusb library
add_subdirectory(../pico-key/tinyusb/src)

# source
add_executable(pico-key main.c)

# pico sdk libraries
target_link_libraries(pico-key
    pico_stdio
    tinyusb_device
)

# generate extra files
pico_add_extra_outputs(pico-key)
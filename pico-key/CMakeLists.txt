# cmake version!
cmake_minimum_required(VERSION 3.13)

# set path
# this is assuming you pulled this from github
set(PICO_SDK_FETCH_FROM_GIT ON)
set(CMAKE_MAKE_PROGRAM make)
set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER gcc)
# may not be needed if you install the right packages
# set(PICO_TOOLCHAIN_PATH ~/pico-sdk/tools)
set(cmake_language C)

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
    hardware_flash
    hardware_irq
    hardware_sync
    hardware_pwm
)

# generate extra files
pico_add_extra_outputs(pico-key)
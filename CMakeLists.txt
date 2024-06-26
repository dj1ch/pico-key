# cmake version!
cmake_minimum_required(VERSION 3.13)

# set path
set(PICO_SDK_FETCH_FROM_GIT ON)

# include the sdk
include(${CMAKE_CURRENT_LIST_DIR}/cmake/pico_sdk_import.cmake)

# project name
project(pico-key C CXX ASM)

# start sdk
pico_sdk_init()

# source
add_executable(
  pico-key
  pico-key.c
  config.c
  duckyscript.c
  easter-egg.c
  filesystem.c
  settings.c
  stm.c
  tusb.c
  uid.c
  usb.c)

# pico sdk libraries
target_link_libraries(
  pico-key
  pico_stdio
  pico_stdlib
  pico_malloc
  hardware_uart
  hardware_gpio
  hardware_flash
  hardware_irq
  hardware_sync
  hardware_pwm)

# generate extra files
pico_add_extra_outputs(pico-key)

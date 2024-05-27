/**
 * usb.h
 * header for usb-related social engineering
*/

#ifndef USB_H
#define USB_H

#include "config.h"
#include "pico/stdio.h"
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "tusb.h"
#include "tusb_option.h"

extern void fakeUSB();
extern void spoofID();

#endif // USB_H
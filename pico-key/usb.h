/**
 * usb.h
 * header for usb-related social engineering
*/

#ifndef USB_H
#define USB_H

#include "config.h"
#include "pico/stdio.h"
#include "hardware/gpio.h"
#include "tusb.h"
#include "tusb_option.h"

void fakeUSB(void);
void spoofID(void);

#endif // USB_H
/**
 * boot.h
 * headers for boot.c
*/

#ifndef BOOT_H
#define BOOT_H

#include "config.h"
#include "usb.h"
#include "pico/stdio.h"
#include "pico/malloc.h"

int boot();
void boardInfo();

#endif // BOOT_H
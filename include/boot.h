/**
 * boot.h
 * headers for boot.c
*/

#ifndef BOOT_H
#define BOOT_H

#include "config.h"
#include "usb.h"
#include "duckyscript.h"
#include "pico/stdio.h"
#include "pico/malloc.h"

extern int boot();
extern void boardInfo();

#endif // BOOT_H
/**
 * filesystem.h
 * headers for filesystem related things
*/

#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include "pico/stdio.h"
#include "hardware/flash.h"

int init();
void write();
uint32_t startAddress;
uint32_t sizeBytes;

#endif // FILESYSTEM_H
/**
 * filesystem.h
 * headers for filesystem related things
*/

#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include "config.h"
#include "pico/stdio.h"
#include "pico/stdlib.h"
#include "hardware/flash.h"
#include "hardware/irq.h"
#include "hardware/sync.h"

void format(void);
void seperate(const char *buffer, size_t buflen, char *array);
void write(const void *data, size_t len);

#endif // FILESYSTEM_H
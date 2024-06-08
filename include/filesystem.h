/**
 * filesystem.h
 * "filesystem" headers
*/

#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include "config.h"

#include "pico/stdio.h"
#include "pico/stdlib.h"
#include "hardware/flash.h"
#include "hardware/irq.h"
#include "hardware/sync.h"

#include <iostream>

class filesystem {
public:
    void format();
    void seperate(const char *buffer, size_t buflen, char *array);
    void write(const void *data, size_t len);

private:

};

#endif // FILESYSTEM_H
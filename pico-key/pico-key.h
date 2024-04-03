/**
 * pico-key.h
 * main header for main stuff
*/

#ifndef PICO_KEY_H
#define PICO_KEY_H

#include "config.h"
#include "boot.h"
#include "duckyscript.h"
#include "easter-egg.h"

#include <string>
#include <stdbool.h>
#include <unistd.h>
#include <ctype.h>

#include "pico/stdio.h"
#include "pico/stdlib.h"
#include "hardware/uart.h"
#include "hardware/gpio.h"

int main();
void buildScript();
void testScript();
void read();
void fakeUSB();
void misc();
void options();

#endif // PICO_KEY_H
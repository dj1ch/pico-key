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
#include "pico/stdio.h"

int main();
void buildScript();
void testScript();
void read();
void fakeUSB();
void misc();
void options();

#endif // PICO_KEY_H
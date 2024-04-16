/**
 * filesystem.c
 * handles filesystem related tasks
*/

#include "filesystem.h"

uint32_t startAddress = 0x10000;
uint32_t sizeBytes = 4096;

int init() {
    printf("\nErasing flash...\n");

    // erase memory at specified range
    flash_range_erase(startAddress, sizeBytes);

    printf("Done.\n");
}

void write() {
    
}
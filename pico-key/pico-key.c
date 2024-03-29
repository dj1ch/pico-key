/** 
 * pico-key.c
 * licensed under GPL 3.0
 * built by @dj1ch
 */

// libraries
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <ctype.h>

// sdk
#include "pico/stdio.h"
#include "pico/stdlib.h"
#include "pico/malloc.h"
#include "hardware/flash"
#include "hardware/uart.h"
#include "hardware/gpio.h"

// define area to write payload
#define FILE_CONTENTS_SIZE 256
#define FLASH_TARGET_OFFSET (256 * 1024)

const uint8_t file_contents[FILE_CONTENTS_SIZE] = {
    'H', 'e', 'l', 'l', 'o', ',', ' ', 'w', 'o', 'r', 'l', 'd', '!', '\n', '\0'
};

void boot() {
    // boot logo
    char coolArt[] = "pico-key...";
    char author[] = "by dj1ch";

    // print this ^^
    printf("\n%s\n", coolArt);
    sleep(1);
    printf("%s\n", author);

    // board info
    boardInfo();
}

int main() {
    stdio_init_all();
    boot();

    printf("Erasing memory in target region!\n");
    flash_range_erase(FLASH_TARGET_OFFSET, FLASH_PAGE_SIZE);
    printf("Done.\n");

    printf("Writing to flash...\n")
    flash_range_program(FLASH_TARGET_OFFSET, file_contents, FILE_CONTENTS_SIZE);
    printf("Done.\n")

    return 0;
}

void boardInfo() {
    // we can only really print memory here
    printf("\nBoard info:\n");
    printf(malloc_stats() + " bytes\n");
}
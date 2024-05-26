/**
 * filesystem.c
 * handles filesystem related tasks
*/

#include "filesystem.h"

// define where to erase
uint32_t startAddress = 0x10000;
uint32_t sizeBytes = 4096;

// format the specified area
void format() {
    printf("\nErasing flash...\n");

    // erase memory at specified range
    flash_range_erase(startAddress, sizeBytes);

    printf("Done.\n");
}

// seperate the duckyscript buffer
void separate(const char *buffer, size_t buflen, char *array) {
    // check if the buffer is empty
    if (buflen == 0) {
        printf("Buffer is empty.\n");
        return;
    }

    // index
    size_t index = 0;

    // store in array
    for (size_t i = 0; i < buflen; i++) {
        array[index++] = buffer[i];

        // insert a comma
        if (i < buflen - 1) {
            array[index++] = ',';
        }
    }

    // null-terminate the output
    array[index] = '\0';
}

// write the data and keep it constant
void write(const void *data, size_t len) {
    // format memory
    format()

    // check if the length exceeds the available space
    if (len > sizeBytes) {
        printf("Error: Data exceeds available space :/\n");
        return;
    }

    printf("\nWriting data to flash...\n");

    uint32_t ints = save_and_disable_interrupts();

    // write data to flash
    flash_range_program(startAddress, data, len);

    restore_interrupts(ints);

    printf("Data written successfully.\n");
}

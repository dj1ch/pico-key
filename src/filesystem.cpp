/**
 * filesystem.c
 * handles filesystem related tasks
*/

#include "../include/filesystem.h"

// format the specified area
void filesystem::format() {
    std::cout << "\nErasing flash...\n";

    // erase memory at specified range
    flash_range_erase(config::payload_location, config::size_bytes);

    std::cout << "Done.\n" ;
}

// seperate the duckyscript buffer
void separate(const char *buffer, size_t buflen, char *array) {
    // check if the buffer is empty
    if (buflen == 0) {
        std::cout << "Buffer is empty.\n";
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
    format();

    // check if the length exceeds the available space
    if (len > sizeBytes) {
        std::cout << "Error: Data exceeds available space :/\n";
        return;
    }

    std::cout << "\nWriting data to flash...\n";

    uint32_t ints = save_and_disable_interrupts();

    // write data to flash
    flash_range_program(config::payload_location, data, len);

    restore_interrupts(ints);

    std::cout << "Data written successfully.\n";
}
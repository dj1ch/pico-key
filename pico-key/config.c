/**
 * config.c
 * configuration related things in a source file
*/

#include "config.h"

// define where to write
uint32_t startAddress = 0x10000;
uint32_t sizeBytes = 4096;

void checkConfig(const Configuration& config) {
    printf("\nCurrent Config: \n");
    printf("LED Pin definition: %d\n", config.led_pin);
    printf("Payload location: %s\n", config.payload_location.c_str());
    printf("Run on startup: %s\n", config.run_on_startup ? "true" : "false");
    printf("Current version: %s\n", config.version.c_str());
}
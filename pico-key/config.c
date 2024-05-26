/**
 * config.c
 * configuration related things in a source file
*/

#include "config.h"

// define config
Configuration config;

// define where to write
const uint32_t startAddress = 0x10000;
const uint32_t sizeBytes = 4096;

void initConfig() {
    config->ledPin = LED_PIN;
    config->payloadLocation = startAddress;
    config->runOnStartup = true;
    config->version = "0.1.0-alpha";
}

void checkConfig(const Configuration *config) {
    printf("\nCurrent Config: \n");
    printf("LED Pin definition: %d\n", config->ledPin.c_str());
    printf("Payload location: %s\n", config->payloadLocation);
    printf("Run on startup: %s\n", config->runOnStartup ? "true" : "false");
    printf("Current version: %s\n", config->version.c_str());
}
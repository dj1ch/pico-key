/** 
 * config.h
 * configurations are defined here
*/

#ifndef CONFIG_H
#define CONFIG_H

#include "pico/stdio.h"

// default config params
#define LED_PIN PICO_DEFAULT_LED_PIN
#define DEFAULT_RUN_ON_STARTUP true

// configuration structure
typedef struct {
    const char* ledPin;
    uint32_t payloadLocation;
    bool runOnStartup;
    const char* version;
} Configuration;

void initConfig();
void checkConfig(const Configuration *config);
const uint32_t startAddress;
const uint32_t sizeBytes;

#endif // CONFIG_H

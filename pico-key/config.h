/** 
 * config.h
 * configurations are defined here
*/

#ifndef CONFIG_H
#define CONFIG_H

#include "pico/stdio.h"

// default config params
#define LED_PIN PICO_DEFAULT_LED_PIN
#define DEFAULT_PAYLOAD_LOCATION "/payload.dd"
#define DEFAULT_RUN_ON_STARTUP true

// configuration structure
struct Configuration {
    int led_pin;
    char* payload_location;
    bool run_on_startup;
    char* version;
};

void checkConfig();

#endif // CONFIG_H

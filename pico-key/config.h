/** 
 * config.h
 * configurations are defined here
*/

#ifndef CONFIG_H
#define CONFIG_H

#include <stdio.h>
#include <string>

// default config params
#define LED_PIN PICO_DEFAULT_LED_PIN
#define DEFAULT_PAYLOAD_LOCATION "/payload.dd"
#define DEFAULT_RUN_ON_STARTUP true

// configuration structure
struct Configuration {
    int led_pin;
    std::string payload_location;
    bool run_on_startup;
    std::string version;
};

Configuration load(const char* filename);

#endif // CONFIG_H

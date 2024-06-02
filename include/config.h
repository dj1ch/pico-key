/**
 * config.h
 * configuration header
*/

#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
#include <stdint.h>

class config {
public:
    config(int led, uint32_t location, bool run, char* version);
    ~config(int led, uint32_t location, bool run, char* version);

    void print_config();
private:
    int default_led;
    uint32_t payload_location;
    bool run_on_startup;
    char* version;
};

#endif // CONFIG_H
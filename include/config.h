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

    int default_led;
    uint32_t payload_location;
    uint32_t size_bytes;
    bool run_on_startup;
    char* version;

private:

};

#endif // CONFIG_H
/**
 * config.cpp
 * configuration values for pico-key
*/

#include "../include/config.h"

config::config(int led, uint32_t location, uint32_t size, bool run, char* version) {
    led = config::default_led;
    location = config::payload_location;
    size = config::size_bytes;
    run = config::run_on_startup;
    version = config::version;
}

config::~config(int led, uint32_t location, bool run, char* version) {
    delete led;
    delete location;
    delete size;
    delete run;
    delete version;
}

void config::print_config() {
    std::cout << "Current Config: \n";
    std::cout << "\nDefault LED Pin: " << config::default_led << "\n";
    std::cout << "Payload location: " << config::payload_location << "\n";
    std::cout << "Payload size" << config::size_bytes << "\n";
    std::cout << "Run payloads on startup: " << config::run_on_startup << "\n";
    std::cout << "Pico-key Version: " << config::version << "\n";
}
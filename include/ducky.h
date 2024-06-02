/**
 * ducky.h
 * duckyscript header
*/

#ifndef DUCKY_H
#define DUCKY_H

#include <iostream>
#include <stdint.h>

#include "pico/stdio.h"
#include "tusb.h"
#include "tusb_option.h"

class ducky {
public:
    int run();

    void build_script();
    void test_script();
    void read(uint8_t* array);

private:
    void send_key(uint8_t key_code);
    void send_func_key(uint8_t func_key_code);
    void send_mod_key(uint8_t mod_key_code);

};

#endif // DUCKY_H
/**
 * main.c
 * licensed under GPL 3.0
 * built by @dj1ch
 */

// tinyusb 
#include "pico/stdio.h"
#include "pico/stdlib.h"
#include "bsp/board.h"
#include "../pico-key/tinyusb/src/tusb.h"
#include "../pico-key/tinyusb/src/tusb_option.h"
#include "../pico-key/tinyusb/src/class/hid/hid.h"

#define KEYBOARD_REPORT_SIZE 8
#define REPORT_ID_KEYBOARD 1

// send a key press
void sendKey(uint8_t keycode) {
    uint8_t keyReport[6] = {0};

    keyReport[0] = keycode;

    tud_hid_keyboard_report(REPORT_ID_KEYBOARD, 0, keyReport);
    sleep_ms(10);
    keyReport[0] = 0;
    tud_hid_keyboard_report(REPORT_ID_KEYBOARD, 0, keyReport); 
}

// convert char to HID
uint8_t hid(char c) {
    if (c >= 'a' && c <= 'z') {
        return HID_KEY_A + (c - 'a');
    }
    if (c >= 'A' && c <= 'Z') {
        return HID_KEY_A + (c - 'A');
    }
    if (c == ' ') {
        return HID_KEY_SPACE;
    }
    return 0;
}

int main(void) {
    stdio_init_all();
    board_init();
    tusb_init();

    // define message
    const char message[] = "Hello";

    // type out the message
    while (1) {
        if (tud_hid_ready()) {
            for (int i = 0; message[i] != '\0'; i++) {
                uint8_t keycode = hid(message[i]);
                sendKey(keycode);
                sleep_ms(100);
            }

            // break after typing
            break;
        }

        // run task
        tud_task();
    }

    return 0;
}

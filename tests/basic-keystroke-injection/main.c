/**
 * main.c
 * licensed under GPL 3.0
 * built by @dj1ch
*/

// tinyusb 
#include "../pico-key/tinyusb/src/tusb.h"
#include "../pico-key/tinyusb/src/tusb_option.h"

#define KEYBOARD_REPORT_SIZE 8

int main(void) {
    stdio_init_all();
    tusb_init();

    // define message
    uint8_t message[] = {'H', 'e', 'l', 'l', 'o', '\0'};

    // type out the message
    while (1) {
        if (tud_ready()) {
            for (int i = 0; message[i] != '\0'; i++) {
                // create a report
                hid_keyboard_report(REPORT_ID_KEYBOARD, 0, &message[i], 1);
                tud_hid_keyboard_report(REPORT_ID_KEYBOARD, 0, &message[i], 1);

                for (volatile int delay = 0; delay < 100000; delay++);
            }
            
            // break after typing
            break;
        }

        // run task
        tud_task();
    }

    return 0;
}
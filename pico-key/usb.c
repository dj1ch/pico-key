/**
 * usb.c
 * fake usb related things/disguising
*/

#include "usb.h"

void fakeUSB(void) {
    bool led = false;

    printf("\n1. Start LED blinking\n");
    printf("2. Stop LED blinking\n");
    printf("\n> ");

    int choiceA;
    scanf("%d", &choiceA);
    switch (choiceA) {
        case 1:
            if (led) {
                printf("Already running! :/\n");
            } else {
                led = true;
                while (led) {
                    gpio_put(LED_PIN, 1); // led on
                    sleep_ms(500);
                    gpio_put(LED_PIN, 0); // led off
                    sleep_ms(500);

                    if (scanf("%d", &choiceA) == 1 && choiceA == 2) {
                        led = false;
                    }
                }
            }
            break;

        case 2:
            led = false;
            break;

        default:
            printf("%d: Invalid choice\n", choiceA);
    }
}
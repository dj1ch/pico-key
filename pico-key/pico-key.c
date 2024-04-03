/** 
 * pico-key.c
 * licensed under GPL 3.0
 * built by @dj1ch
 */

/** developer note:
 * old pr w/ python is here: https://github.com/dj1ch/pico-key/pull/1/commits/5d4c65106c6aa490b7eb047827c1ed3a00a21377
*/

#include "pico-key.h"

int main() {
    boot();
    while (true) {
        printf("\n1. Build Bad USB script\n");
        printf("2. Test Bad USB script\n");
        printf("3. Fake USB drive\n");
        printf("4. Misc\n");
        printf("5. Options\n");
        sleep(1);

        int choice;
        printf("\n> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                buildScript();
                break;

            case 2:
                testScript();
                break; 

            case 3:
                fakeUSB();
                break; 

            case 4:
                misc();
                break; 

            case 5:
                options();
                break;

            case 69:
                specialMessage();
                break;

            default: 
                printf("\n%d: Invalid choice :/\n", choice);
                break; 
        }
    }
    return 0;
}                                                

void fakeUSB() {
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
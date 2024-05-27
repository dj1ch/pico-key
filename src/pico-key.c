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
    // main initialization
    stdio_init_all();
    tusb_init();

    boot();
    while (true) {
        printf("\n1. Build Bad USB script\n");
        printf("2. Test Bad USB script\n");
        printf("3. Fake USB drive\n");
        printf("4. STM32F1-Picopwner\n");
        printf("5. Misc\n");
        printf("6. Options\n");
        sleep_ms(1000);

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
                stm();
                break;

            case 5:
                misc();
                break; 

            case 6:
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
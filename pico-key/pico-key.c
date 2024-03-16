/** 
 * pico-key
 * 
 * built by @dj1ch
 */

// libraries
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

// sdk
#include <pico/stdlib.h>
#include <hardware/uart.h>
#include <hardware/gpio.h>

// functions
void buildScript();
void testScript();
void read();
void fakeUSB();
void misc();
void options();

int main() {
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
            default: 
                printf("%d: Invalid choice");
                break; 
        }
    }
    return 0;
}

// tba
void buildScript() {
    
}

void testScript() {

}

void read() {

}

void fakeUSB() {

}
void misc() {
    printf("\nNothing here...");
}

void options() {

}
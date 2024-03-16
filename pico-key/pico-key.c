/** 
 * pico-key
 * 
 * licensed under GPL 3.0
 * 
 * built by @dj1ch
 */

// libraries
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <ctype.h>

// sdk
#include <pico/stdlib.h>
#include <pico/malloc.h>
#include <hardware/uart.h>
#include <hardware/gpio.h>

// led definition
#define LED_PIN PICO_DEFAULT_LED_PIN

// functions
int main();
void boot();
void buildScript();
void testScript();
void read();
void fakeUSB();
void misc();
void options();

void boot() {
    // boot logo
    char coolArt[] = "pico-key...";
    char author[] = "by dj1ch";

    // print this ^^
    printf("\n%s\n", coolArt);
    sleep(1);
    printf("%s\n", author);

    // print memory, cpu freq, etc
    void* ptr = malloc(10 * sizeof(char));

    if (ptr != NULL) {
        // print stats
        malloc_stats();

        free(ptr);
    } else {
        printf("\nMemory allocation failed :(\n");
    }
}

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

            default: 
                printf("\n%d: Invalid choice :/\n", choice);
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

// crap i gotta build a new compiler for this :/
void read() {

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
                printf("Already running!\n");
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


void misc() {
    printf("\nNothing here, for now... :/\n");
    printf("\n> ");

    char choiceB[10];

    // remove whitespace
    fgets(choiceB, sizeof(choiceB), stdin);
    choiceB[strcspn(choiceB, "\n")] = '\0';

    // uppercase and compare it
    for (int i = 0; choiceB[i]; i++) {
        choiceB[i] = toupper(choiceB[i]);
    }

    if (strcmp(choiceB, "EXIT") == 0) {
        return; 
    }
}

void options() {

}
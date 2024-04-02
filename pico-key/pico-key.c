/** 
 * pico-key.c
 * licensed under GPL 3.0
 * built by @dj1ch
 */

/** developer note:
 * old pr w/ python is here: https://github.com/dj1ch/pico-key/pull/1/commits/5d4c65106c6aa490b7eb047827c1ed3a00a21377
*/

// config
#include "config.h"

// duckyscript
#include "duckyscript.h"

// :)
#include "easter-egg.h"

// libraries
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <ctype.h>

// sdk
#include "pico/stdio.h"
#include "pico/stdlib.h"
#include "pico/malloc.h"
#include "hardware/uart.h"
#include "hardware/gpio.h"

void boot() {
    // boot logo
    char coolArt[] = "pico-key...";
    char author[] = "by dj1ch";

    // print this ^^
    printf("\n%s\n", coolArt);
    sleep(1);
    printf("%s\n", author);

    // board info
    boardInfo();

    if (RUN_ON_STARTUP) {
        read();
        return 0;
    } else {
        // do nothing
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

void buildScript() {
    printf("\nPayloads are built here, but can also be modified using a file manager.");
    printf("Every time you press enter it will be written to the file.\n");
    printf("Type 'exit' to stop.\n");

    // assume it's named payload.dd
    FILE *file = fopen(PAYLOAD_LOCATION, "w");

    if (file == NULL) {
        printf("Failed to open payload.dd! :(\n");
        return;
    }

    // 25 chars max!! most of the time commands are shorter.
    const int MAX_LINE_LENGTH = 25;
    char script[MAX_LINE_LENGTH];

    while (true) {
        printf("\n> ");
        // get line and write it
        fgets(script, sizeof(script), stdin);
        script[strcspn(script, "\n")] = '\0';

        for (int i = 0; script[i]; i++) {
            script[i] = toupper(script[i]);
        }

        // exit if command is "exit"
        if (strcmp(script, "EXIT") == 0) {
            break;
        }

        fprintf(file, "%s\n", script);

    }
    fclose(file);
    printf("Script saved to payload.dd!\n");
}

void testScript() {
    printf("\nRemember that testing the script will run this on your machine!\n");
    char userWarning[10];

    while (1) {
        printf("Are you okay with this? (Y/N) > ");

        // get only the characters
        fgets(userWarning, sizeof(userWarning), stdin);
        userWarning[strcspn(userWarning, "\n")] = '\0';

        // convert to uppercase
        for (int i = 0; userWarning[i]; i++) {
            userWarning[i] = toupper(userWarning[i]);
        }

        if (strcmp(userWarning, "Y") == 0) {
            continue;
        } else if (strcmp(userWarning, "N") == 0) {
            break;
        } else {
            printf("%s: Not a valid response\n", userWarning);
            continue;
        }
    }

    char scriptPath[256];
    while (1) {
        printf("Script to test? > ");
        fgets(scriptPath, sizeof(scriptPath), stdin);
        scriptPath[strcspn(scriptPath, "\n")] = '\0';

        if (strcmp(scriptPath, "EXIT") == 0 || strcmp(scriptPath, "exit") == 0) {
            break;
        } else {
            read(scriptPath);
        }
    }
}                                            

// crap i gotta build a new compiler for this :/
void read(const char* filePath) {
    FILE *file = fopen(filePath, "r");

    if (file == NULL) {
        perror("Can't open '%s' :/", filePath);
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char *command = strtok(line, " \t\n");

        char *param = strtok(NULL, "\n");
        while (param && strtok(NULL, "\n")) {
            strcat(command, " ");
            strcat(command, param);
            param = strtok(NULL, "\n");
        }

        run(command);
    }

    fclose(filePath);
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
    printf("\nHere we would put settings to set for the board, see the current board information, etc.\n");
    printf("\n1. Print board info\n")
    printf("\n> ")

    char choiceC[10];
    
    // remove whitespace
    fgets(choiceC, sizeof(choiceC), stdin);
    choiceC[strcspn(choiceC, "\n")] = '\0';

    // uppercase and compare it
    for (int i = 0; choiceC[i]; i++) {
        choiceC[i] = toupper(choiceC[i]);
    }

    if (strcmp(choiceC, "EXIT") == 0) {
        return; 
    }

    if (strcmp(choiceC, "1") == 0) {
        boardInfo(); 
    }
}

void boardInfo() {
    // we can only really print memory here
    printf("\nBoard info:\n");
    printf(malloc_stats() + " bytes");
    printf(checkConfig());
}
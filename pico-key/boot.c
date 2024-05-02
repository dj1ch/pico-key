/**
 * boot.c
 * "bootup" process to run after the firmware is loaded
*/

#include "boot.h"

int boot(void) {
    // boot logo
    char coolArt[] = "pico-key...";
    char author[] = "by dj1ch";

    // print this ^^
    printf("\n%s\n", coolArt);
    sleep(1);
    printf("%s\n", author);

    // board info
    boardInfo(void);

    // spoof id
    spoofID(void);

    if (config.runOnStartup) {
        read(fullScript); // may need to fix that
        return 0;
    } else {
        // do nothing
    }
}

void boardInfo(void) {
    // we can only really print memory here
    printf("\nBoard info:\n");
    printf(malloc_stats() + " bytes");
    initConfig();
    printf(checkConfig(config));
}
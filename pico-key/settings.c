/**
 * settings.c
 * misc and options in pico-key menu
*/

#include "settings.h"

void misc(void) {
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

void options(void) {
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
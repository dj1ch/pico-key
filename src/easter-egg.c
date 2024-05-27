/**
 * easter-egg.c
 * maybe this is an easter egg ;)
*/

#include "easter-egg.h"

void specialMessage() {
    printf("\nWhat did you expect to be here???\n");
    printf("Weirdo...\n");
    printf("\nAnyway, wanna play a game? (Y/N) > \n");

    char specialChoice[10];

    fgets(specialChoice, sizeof(specialChoice), stdin);
    specialChoice[strcspn(specialChoice, "\n")] = '\0';

    for (int i = 0; specialChoice[i]; i++) {
        specialChoice[i] = toupper(specialChoice[i]);
    }

    if (strcmp(specialChoice, "Y") == 0) {
        game();
    } else if (strcmp(specialChoice, "N") == 0) {
        printf("Okay, maybe next time.\n");
    } else {
        printf("%s: Not a valid response\n", specialChoice);
    }
}

void game() {

}

/**
 * egg.c
 * maybe this is an easter egg ;)
*/

#include "easter-egg.h"

void specialMessage() {
    printf("\nWhat did you expect to be here???\n");
    printf("\nAnyway, wanna play a game? (Y/N) > ");

    char* specialChoice[10];

    fgets(specialChoice, sizeof(specialChoice), stdin);
    specialChoice[strcspn(specialChoice, "\n")] = '\0';

    for (int i = 0; specialChoicep[i]; i++) {
        specialChoice[i] = toupper(specialChoice[i]);
    }

    if (strcmp(specialChoice, "Y") == 0) {
        continue;
    } else if (strcmp(specialChoice, "N") == 0) {
        break;
    } else {
        printf("%s: Not a valid response\n", specialChoice);
        continue;
    }

    // cool game
    game();
}

void game() {

}
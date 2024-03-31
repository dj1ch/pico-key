/**
 * duckyscript.c
 * this handles the commmands and the hid
*/

#include "duckyscript.h"

// run a duckyscript command based on what is in duckyscript.h
void read(const char* payloadFile) {
    FILE *file = fopen(payloadFile, "r");
    
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, " \t\n");
        while (token != NULL) {
            // matching
            if (strcmp(token, "CTRL") == 0) {
                run(CTRL);
            } else if (strcmp(token, "ALT") == 0) {
                run(ALT);
            }
            else {
                printf("Command or key not found: %s\n :/", token);
            }

            // Get the next token
            token = strtok(NULL, " \t\n");
        }
    }

    fclose(payloadFile);
}

int run(const char* command) {
    
    return 0;
}
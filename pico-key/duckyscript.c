/**
 * duckyscript.c
 * this handles the commmands and the hid
*/

#include "duckyscript.h"

// run a duckyscript command based on what is in duckyscript.h
int run(const char* command) {
    
    return 0;
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
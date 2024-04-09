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

void buildScript() {
    printf("\nPayloads are built here, but can also be modified using a file manager.\n");
    printf("Every time you press enter it will be written to the file.\n");
    printf("Type 'exit' to stop.\n");

    // assume it's named payload.dd
    FILE *file = fopen(config.payload_location, "w");

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
/**
 * duckyscript.c
 * this handles the commmands and the hid
*/

#include "duckyscript.h"

// set size
uint8_t keyboard_report[KEYBOARD_REPORT_SIZE];

// arrays for keys
RegularKey regularKeys[] = {
    {A}, {B}, {C}, {D}, {E}, {F}, {G}, {H}, {I}, {J}, {K}, {L}, {M},
    {N}, {O}, {P}, {Q}, {R}, {S}, {T}, {U}, {V}, {W}, {X}, {Y}, {Z}
};

FuncKey funcKeys[] = {
    {BREAK}, {PAUSE}, {CAPSLOCK}, {DELETE}, {END}, {ESCAPE}, {HOME}, {INSERT}, {NUMLOCK}, 
    {PAGEUP}, {PAGEDOWN}, {PRINTSCREEN}, {ENTER}, {SCROLLLOCK}, {SPACE}, {TAB}, {BACKSPACE}
};

ModKey modKeys[] = {
    {WINDOWS}, {GUI}, {APP}, {MENU}, {SHIFT}, {ALT}, {CONTROL}, {CTRL},
    {DOWNARROW}, {DOWN}, {LEFTARROW}, {LEFT}, {RIGHTARROW}, {RIGHT}, {UPARROW}, {UP}
};

// run a duckyscript command based on what is in duckyscript.h
int run(const char* command, void* params) {
    // parse command and run
    if (strcmp(command, "regular") == 0) {
        RegularKey* regKey = (RegularKey*)params;
        // send regular key
        keyboard_report[0] = 0; // modifier keys
        keyboard_report[1] = 0; // reserved
        keyboard_report[2] = regKey->key; // key to press
        keyboard_report[3] = 0; // reserved
        keyboard_report[4] = 0; // reserved
        keyboard_report[5] = 0; // reserved
        keyboard_report[6] = 0; // reserved
        keyboard_report[7] = 0; // reserved
    } else if (strcmp(command, "modifier") == 0) {
        ModKey* modKey = (ModKey*)params;
        // send modifier key
        keyboard_report[0] = modKey->code; // modifier keys
        keyboard_report[1] = 0; // reserved
        keyboard_report[2] = 0; // key to press
        keyboard_report[3] = 0; // reserved
        keyboard_report[4] = 0; // reserved
        keyboard_report[5] = 0; // reserved
        keyboard_report[6] = 0; // reserved
        keyboard_report[7] = 0; // reserved
    } else if (strcmp(command, "function") == 0) {
        FuncKey* funcKey = (FuncKey*)params;
        // send function key
        keyboard_report[0] = 0; // modifier keys
        keyboard_report[1] = 0; // reserved
        keyboard_report[2] = funcKey->code; // key to press
        keyboard_report[3] = 0; // reserved
        keyboard_report[4] = 0; // reserved
        keyboard_report[5] = 0; // reserved
        keyboard_report[6] = 0; // reserved
        keyboard_report[7] = 0; // reserved
    }

    printf("\nStarting attack!\n");
    // run attack
    while (1) {
        tud_task();
    }

    printf("\nAttack finished!\n");
    return 0;
}

void sendReport(void) {
    tud_hid_keyboard_report(REPORT_ID_KEYBOARD, 0, keyboard_report, KEYBOARD_REPORT_SIZE);
}

void sendKey(uint8_t keyCode) {
    // send a regular key
    keyboard_report[0] = 0; // no modifier keys
    keyboard_report[2] = keyCode; // key to press
    sendReport();
}

void sendModKey(uint8_t modKeyCode) {
    // send a modifier key
    keyboard_report[0] = modKeyCode; // modifier key code
    sendReport();
}

void sendFuncKey(uint8_t funcKeyCode) {
    // send a function key
    keyboard_report[0] = 0; // no modifier keys
    keyboard_report[2] = funcKeyCode; // function key code
    sendReport();
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

    // define script buffer
    char scriptBuffer[sizeBytes];

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

        // append script line to buffer
        if (strlen(script) + strlen(scriptBuffer) + 1 <= sizeBytes) {
            strcat(scriptBuffer, script);
        } else {
            printf("Script buffer is full. Exiting.\n");
            break;
        }
    }
    printf("Script saved!\n");
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
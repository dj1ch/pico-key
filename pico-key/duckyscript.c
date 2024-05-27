/**
 * duckyscript.c
 * this handles the commmands and the hid
*/

#include "duckyscript.h"

// full script
uint8_t fullScript[SCRIPT_SIZE];

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
    {WINDOWS}, {SHIFT}, {ALT}, {CONTROL},
    {DOWNARROW}, {LEFTARROW}, {RIGHTARROW}, {UPARROW}
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

void sendKey(uint8_t keyCode) {
    // send a regular key
    keyboard_report[0] = 0; // no modifier keys
    keyboard_report[2] = keyCode; // key to press
    tud_hid_keyboard_report(REPORT_ID_KEYBOARD, 0, keyboard_report);
}

void sendModKey(uint8_t modKeyCode) {
    // send a modifier key
    keyboard_report[0] = modKeyCode; // modifier key code
    tud_hid_keyboard_report(REPORT_ID_KEYBOARD, 0, keyboard_report);
}

void sendFuncKey(uint8_t funcKeyCode) {
    // send a function key
    keyboard_report[0] = 0; // no modifier keys
    keyboard_report[2] = funcKeyCode; // function key code
    tud_hid_keyboard_report(REPORT_ID_KEYBOARD, 0, keyboard_report);
}

// crap i gotta build a new compiler for this :/
void read(uint8_t *array) {
    char* token;
    char* rest = array;
    const char commas[] = ",";
    
    // tokenize buffer
    while ((token = strtok_r(rest, commas, &rest))) {
        char* command = strtok(token, " \t\n");
        char* param = strtok(NULL, "\n");

        if (strcmp(command, "regular") == 0 || strcmp(command, "modifier") == 0 || strcmp(command, "function") == 0) {
            run(command, 0);
        } else {
            printf("Unknown command: %s\n", command);
        }
    }
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

    // format memory and write required info there
    format();
    seperate(scriptBuffer, sizeof(scriptBuffer), fullScript);
    write(fullScript, sizeof(fullScript));

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

    // when we pass this we read the script
    read(fullScript);
}
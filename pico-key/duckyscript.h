/**
 * duckyscript.h
 * define duckyscript in C...?
*/

#ifndef DUCKYSCRIPT_H
#define DUCKYSCRIPT_H

#include "config.h"
#include "filesystem.h"
#include "pico/stdio.h"
#include "tinyusb/src/tusb.h"
#include "tinyusb/src/tusb_option.h"

// define hid report size
#define KEYBOARD_REPORT_SIZE 8

/**
 * source:
 * https://docstore.mik.ua/orelly/webprog/DHTML_javascript/0596004672_jvdhtmlckbk-app-b.html
 * https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes?redirectedfrom=MSDN
*/

// mouse things
#define LEFT_CLICK      0x01
#define RIGHT_CLICK     0x02 

/**
 * by default we use the left keys, usually people don't use the right control, alt, windows, etc.
*/

// control keys
#define ALT             0x12
#define WINDOWS         0x5B
#define SHIFT           0x10
#define CONTROL         0x11

// arrows
#define DOWNARROW       0x28
#define LEFTARROW       0x25
#define RIGHTARROW      0x27
#define UPARROW         0x26

// other keys
#define BACKSPACE       0x08
#define CAPSLOCK        0x14
#define DELETE          0x2E
#define END             0x23
#define ESC             0x1B
#define HOME            0x24
#define INSERT          0x2D
#define NUMLOCK         0x90
#define PAGEUP          0x21
#define PAGEDOWN        0x22
#define PRINTSCREEN     0x2C
#define ENTER           0x0D
#define SCROLLLOCK      0x91
#define SPACE           0x20
#define TAB             0x09

// abc's
#define A               0x41
#define B               0x42
#define C               0x43
#define D               0x44
#define E               0x45
#define F               0x46
#define G               0x47
#define H               0x48
#define I               0x49
#define J               0x4A
#define K               0x4B
#define L               0x4C
#define M               0x4D
#define N               0x4E
#define O               0x4F
#define P               0x50
#define Q               0x51
#define R               0x52
#define S               0x53
#define T               0x54
#define U               0x55
#define V               0x56
#define W               0x57
#define X               0x58
#define Y               0x59
#define Z               0x5A

// f keys
#define F1              0x70
#define F2              0x71
#define F3              0x72
#define F4              0x73
#define F5              0x74
#define F6              0x75
#define F7              0x76
#define F8              0x77
#define F9              0x78
#define F10             0x79
#define F11             0x7A
#define F12             0x7B

// regular keys
typedef struct {
    char key;
} RegularKey;

// function keys
typedef struct {
    uint8_t code;
} FuncKey;

// mod keys
typedef struct {
    uint8_t code;
} ModKey;

// mouse actions
typedef enum {
    MOUSE_MOVE,
    CLICK,
    RIGHT_CLICK,
    MIDDLE_CLICK
} mse;

// keyboard actions
typedef enum {
    PRESS_KEY,
    RELEASE_KEY
} key;

// mouse commands
typedef struct {
    mse action;
    int x;
    int y;
} mseCommand;

// keyboard commands
typedef struct {
    key action;
    char key;
} keyCommand;

int run();
void sendReport(void);
void sendKey(uint8_t keyCode);
void sendFuncKey(uint8_t funcKeyCode);
void sendModKey(uint8_t modKeyCode);
void read(uint8_t array[]);
void buildScript(void);
void testScript(void);

uint8_t keyboard_report[];
uint8_t fullScript[];

#endif // DUCKYSCRIPT_H
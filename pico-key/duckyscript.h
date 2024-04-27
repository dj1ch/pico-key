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

// control keys 
#define WINDOWS         0x08
#define GUI             0x10
#define APP             0x20
#define MENU            0x40
#define SHIFT           0x80
#define ALT             0x40
#define CONTROL         0x20
#define CTRL            0x20

// arrows
#define DOWNARROW       0x51
#define DOWN            0x51
#define LEFTARROW       0x50
#define LEFT            0x50
#define RIGHTARROW      0x4F
#define RIGHT           0x4F
#define UPARROW         0x52
#define UP              0x52

// other keys
#define BREAK           0x48
#define PAUSE           0x48
#define CAPSLOCK        0x39
#define DELETE          0x4C
#define END             0x4D
#define ESC             0x29
#define ESCAPE          0x29
#define HOME            0x4A
#define INSERT          0x49
#define NUMLOCK         0x53
#define PAGEUP          0x4B
#define PAGEDOWN        0x4E
#define PRINTSCREEN     0x46
#define ENTER           0x28
#define SCROLLLOCK      0x47
#define SPACE           0x2C
#define TAB             0x2B
#define BACKSPACE       0x2A

// abc's
#define A               0x04
#define B               0x05
#define C               0x06
#define D               0x07
#define E               0x08
#define F               0x09
#define G               0x0A
#define H               0x0B
#define I               0x0C
#define J               0x0D
#define K               0x0E
#define L               0x0F
#define M               0x10
#define N               0x11
#define O               0x12
#define P               0x13
#define Q               0x14
#define R               0x15
#define S               0x16
#define T               0x17
#define U               0x18
#define V               0x19
#define W               0x1A
#define X               0x1B
#define Y               0x1C
#define Z               0x1D

// f keys
#define F1              0x3A
#define F2              0x3B
#define F3              0x3C
#define F4              0x3D
#define F5              0x3E
#define F6              0x3F
#define F7              0x40
#define F8              0x41
#define F9              0x42
#define F10             0x43
#define F11             0x44
#define F12             0x45

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
void sendReport();
void sendKey();
void sendFuncKey();
void sendModKey();
void read();
void buildScript();
void testScript();

uint8_t keyboard_report[];
uint8_t fullScript[];

#endif // DUCKYSCRIPT_H
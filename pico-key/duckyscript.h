/**
 * duckyscript.h
 * define duckyscript in C...?
*/

#ifndef DUCKYSCRIPT_H
#define DUCKYSCRIPT_H

#include "config.h"
#include "filesystem.h"
#include "pico/stdio.h"
#include "tusb.h"
#include "tusb_option.h"
#include <ctype.h>
#include <string.h>
#include <stdio.h>

// define hid report size
#define KEYBOARD_REPORT_SIZE 8

#ifndef REPORT_ID_KEYBOARD
#define REPORT_ID_KEYBOARD 0
#endif

// must be the same as sizeBytes in config.c
#define SCRIPT_SIZE 4096

/**
 * source:
 * https://docstore.mik.ua/orelly/webprog/DHTML_javascript/0596004672_jvdhtmlckbk-app-b.html
 * https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes?redirectedfrom=MSDN
*/

/**
 * by default we use the left keys, usually people don't use the right control, alt, windows, etc.
*/

// control keys
#define ALT             
#define WINDOWS         
#define SHIFT           
#define CONTROL         

// arrows
#define DOWNARROW       
#define LEFTARROW       
#define RIGHTARROW      
#define UPARROW         

// other keys
#define BACKSPACE       
#define CAPSLOCK        
#define DELETE          
#define END             
#define ESCAPE             
#define HOME            
#define INSERT          
#define NUMLOCK         
#define PAGEUP          
#define PAGEDOWN        
#define PRINTSCREEN     
#define ENTER           
#define SCROLLLOCK      
#define SPACE           
#define TAB
#define BREAK
#define PAUSE             

// abc's
#define A               
#define B               
#define C               
#define D               
#define E               
#define F               
#define G               
#define H               
#define I               
#define J               
#define K               
#define L               
#define M               
#define N               
#define O               
#define P               
#define Q               
#define R               
#define S               
#define T               
#define U               
#define V               
#define W               
#define X               
#define Y               
#define Z               

// f keys
#define F1              
#define F2              
#define F3              
#define F4              
#define F5              
#define F6              
#define F7              
#define F8              
#define F9              
#define F10             
#define F11             
#define F12             

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
void sendKey(uint8_t keyCode);
void sendFuncKey(uint8_t funcKeyCode);
void sendModKey(uint8_t modKeyCode);
void read(uint8_t array[]);
void buildScript();
void testScript();

uint8_t keyboard_report[KEYBOARD_REPORT_SIZE];
uint8_t fullScript[SCRIPT_SIZE];

#endif // DUCKYSCRIPT_H
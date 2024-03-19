/**
 * duckyscript.h
 * define duckyscript in C...?
*/

#ifndef DUCKYSCRIPT_H
#define DUCKYSCRIPT_H

// keys are yet to be defined

// control keys 
#define WINDOWS 
#define GUI 
#define APP 
#define MENU 
#define SHIFT 
#define ALT 
#define CONTROL 
#define CTRL 

// arrows
#define DOWNARROW 
#define DOWN 
#define LEFTARROW 
#define LEFT 
#define RIGHTARROW 
#define RIGHT 
#define UPARROW 
#define UP 

// other keys?
#define BREAK 
#define PAUSE 
#define CAPSLOCK 
#define DELETE 
#define END 
#define ESC 
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
#define BACKSPACE 

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

// mouse actions
typedef enum {
    MOUSE_MOVE,
    MOUSE_CLICK,
    MOUSE_RIGHT_CLICK,
    MOUSE_MIDDLE_CLICK
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

#endif // DUCKYSCRIPT_H
/**
 * uid.h
 * headers for priv escalation
*/

#ifndef UID_H
#define UID_H

#include "duckyscript.h"

extern void exploitMenu();

extern void binaryEsc();
extern void suidEsc();
extern void cronEsc();
extern void kernelExp();

extern uint8_t binaryEscScript[100];
extern uint8_t suidEscScript[100];
extern uint8_t cronEscScript[100];
extern uint8_t kernelExpScript[100];

#endif // UID_H
/**
 * uid.h
 * headers for priv escalation
*/

#ifndef UID_H
#define UID_H

#include "duckyscript.h"

extern void exploitMenu();

void binaryEsc();
void suidEsc();
void cronEsc();
void kernelExp();

uint8_t binaryEscScript[100];
uint8_t suidEscScript[100];
uint8_t cronEscScript[100];
uint8_t kernelExpScript[100];

#endif // UID_H
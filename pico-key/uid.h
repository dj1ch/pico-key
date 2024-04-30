/**
 * uid.h
 * headers for priv escalation
*/

#ifndef UID_H
#define UID_H

#include "duckyscript.h"

void exploitMenu(void);
void binaryEsc(void);
void suidEsc(void);
void cronEsc(void);
void kernelExp(void);

uint8_t binaryEsc[100];
uint8_t suidEsc[100];
uint8_t cronEsc[100];
uint8_t kernelExp[100];

#endif // UID_H
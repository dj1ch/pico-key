/**
 * config.c
 * configuration related things in a source file
*/

#include "config.h"

void checkConfig() {
    printf("\nCurrent Config: \n");
    printf("LED Pin definition: ");
    printf(LED_PIN);
    printf("Payload location: ");
    printf(PAYLOAD_LOCATION);
    printf("Current version: ");
    printf(VERSION);
}
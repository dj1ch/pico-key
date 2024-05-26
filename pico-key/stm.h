/**
 * stm.h 
 * headers for stm pico exploit
*/

#ifndef STM_H
#define STM_H

#include "pico/stdio.h"
#include "pico/stdlib.h"
#include "hardware/uart.h"
#include "hardware/pwm.h"

#define LED_PIN PICO_DEFAULT_LED_PIN

#define UART_TX_PIN 0
#define UART_RX_PIN 1
#define POWER_PIN 2
#define RESET_PIN 4
#define BOOT0_PIN 5

#define UART_BAUD 9600
#define UART_ID uart0
#define DATA_BITS 8
#define STOP_BITS 1
#define PARITY UART_PARITY_NONE

#define UART_STALLS_FOR_LED_OFF 10000

void stm(void);
const char DUMP_START_MAGIC[];

#endif // STM_H
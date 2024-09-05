/*
 * UART.h
 *
 * Created: 23/08/2024 11:05:32 م
 *  Author: HP
 */ 


#ifndef UART_H_
#define UART_H_
#include <avr/io.h>


#include <stdlib.h>
#include <stdint.h>
#define F_CPU 1000000UL
#include <avr/delay.h>
#define read_bit(reg,bit) ((reg>>bit)&1)
#define set_bit(reg,bit) reg|=(1<<bit)
#define clear_bit(reg,bit) reg&=~(1<<bit)
void UART_INIT(void);


void UART_SEND(uint8_t data);

uint8_t UART_RECEIVE(void);

void UART_SEND_string(char* string);
char* UART_RECEIVE_STRING();
char UART_Receive_NonBlocking(void);
#endif /* UART_H_ */
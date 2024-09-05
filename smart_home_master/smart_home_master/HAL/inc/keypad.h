

#ifndef KEYPAD_H_
#define KEYPAD_H_
#ifndef F_CPU
#define F_CPU 1000000UL
#endif

//-----------------------------
 //Includes
 //-----------------------------
#include <avr/io.h>
#include <util/delay.h>


 
//-----------------------------
//Macros Configuration References
//-----------------------------
#define R0 00
#define R1 1
#define R2 2
#define R3 3
#define C0 4
#define C1 5
#define C2 6
#define C3 7

#define KEYPAD_PORT PORTB
#define DataDir_KEYPAD_PORT DDRB
#define keypadPIN PINB
/*
* ===============================================
* APIs Supported by "HAL keypad DRIVER"
* ===============================================
*/

void Keypad_init();
char Keypad_getkey();

#endif /* KEYPAD_H_ */
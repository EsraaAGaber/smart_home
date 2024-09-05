/*
 * AVR.h
 *
 * Created: 19/08/2024 04:04:00 م
 *  Author: HP
 */ 


#ifndef AVR_H_
#define AVR_H_


//-----------------------------
//Includes
//-----------------------------

#include <stdlib.h>
#include <stdint.h>


//-----------------------------
//Base addresses for Memories
//-----------------------------

#define Internal_SRAM_BASE          		0x0060UL
#define DATA_ADRESS_BASE  					0x0000UL
#define IO_Registers_BASE 					0x0020UL



//-----------------------------
//Base addresses for BUS Peripherals
//-----------------------------

//----------------------------------------------
// Section: Interrupt Vector Table
//----------------------------------------------
/*
#define RESET              1   // $000  External Pin, Power-on Reset, Brown-out Reset, Watchdog Reset, and JTAG AVR Reset
#define INT0               2   // $002  External Interrupt Request 0
#define INT1               3   // $004  External Interrupt Request 1
#define INT2               4   // $006  External Interrupt Request 2
#define TIMER2_COMP        5   // $008  Timer/Counter2 Compare Match
#define TIMER2_OVF         6   // $00A  Timer/Counter2 Overflow
#define TIMER1_CAPT        7   // $00C  Timer/Counter1 Capture Event
#define TIMER1_COMPA       8   // $00E  Timer/Counter1 Compare Match A
#define TIMER1_COMPB       9   // $010  Timer/Counter1 Compare Match B
#define TIMER1_OVF        10   // $012  Timer/Counter1 Overflow
#define TIMER0_COMP       11   // $014  Timer/Counter0 Compare Match
#define TIMER0_OVF        12   // $016  Timer/Counter0 Overflow
#define SPI_STC           13   // $018  Serial Transfer Complete
#define USART_RXC         14   // $01A  USART, Rx Complete
#define USART_UDRE        15   // $01C  USART Data Register Empty
#define USART_TXC         16   // $01E  USART, Tx Complete
#define ADC               17   // $020  ADC Conversion Complete
#define EE_RDY            18   // $022  EEPROM Ready
#define ANA_COMP          19   // $024  Analog Comparator
#define TWI               20   // $026  Two-wire Serial Interface
#define SPM_RDY           21   // $028  Store Program Memory Ready
*/


//Base addresses for Peripherals
#define GPIOA_BASE							(IO_Registers_BASE+0x19)
#define GPIOB_BASE							(IO_Registers_BASE+0x16UL)
#define GPIOC_BASE							(IO_Registers_BASE+0x13)
#define GPIOD_BASE							(IO_Registers_BASE+0x10)
#define EXIT_BASE							(IO_Registers_BASE+0x34)


#define SREG	*((uint8_t*)(IO_Registers_BASE+ 0x3F))	//The AVR status register



//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:
//-*-*-*-*-*-*-*-*-*-*-*
//GPIO
typedef struct  {
	uint8_t PIN;
	uint8_t DDR;
	uint8_t PORT;
}GPIO_TypeDef;

//////////////////

/*
//EXTI
typedef struct{
	
	uint8_t MCUCSR;		//MCU Control and Status Register
	uint8_t MCUCR;		//MCU Control Register
	uint8_t RESEVED;	//Don't touch
	uint8_t RESEVED2;	//Don't touch
	uint8_t RESEVED3;	//Don't touch
	uint8_t RESEVED4;	//Don't touch
	uint8_t GIFR;		//General Interrupt Flag Register
	uint8_t GICR;		//General Interrupt Control Register
	
}EXIT_TypeDef;*/
//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*
//GPIO
// GPIO Peripheral
#define  GPIOA				((GPIO_TypeDef *)GPIOA_BASE)
#define  GPIOB				((GPIO_TypeDef *)GPIOB_BASE)
#define  GPIOC				((GPIO_TypeDef *)GPIOC_BASE)
#define  GPIOD				((GPIO_TypeDef *)GPIOD_BASE)


// EXTI Peripheral
#define  EXTI				((EXIT_TypeDef *)EXIT_BASE)

//-*-*-*-*-*-*-*-*-*-*-*-
// Macros:
//-*-*-*-*-*-*-*-*-*-*-*
#define General_Interrupt_EN	(SREG |= (1 << 7))




#endif /* AVR_H_ */
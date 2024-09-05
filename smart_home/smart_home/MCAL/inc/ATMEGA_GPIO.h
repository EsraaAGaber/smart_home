
/*
 * ATMEGA_GPIO.h
 *
 * Created: 19/08/2024 04:04:00 م
 *  Author: HP
 */ 


#ifndef ATMEGA_GPIO_H_
#define ATMEGA_GPIO_H_

//-----------------------------
//Includes
//-----------------------------
#include "ATMEGA.h"


//-----------------------------
//User type definitions (structures)
//-----------------------------

typedef struct
{
	// Specifies the GPIO pins to be configured .
	// this parameter must be a value of @ref GPIO_PINS_Define
	uint8_t GPIO_PinNumber ;
	// Specifies the Operating mode of the selected pin .
	// this parameter must be a value of @ref GPIO_MODE_Define
	uint8_t GPIO_MODE       ;
	
}GPIO_PinConfig_t;

//-----------------------------
//Macros Configuration References
//-----------------------------

//@ref GPIO_PINS_Define
#define GPIO_PIN_0     0 // Pin 0  selected
#define GPIO_PIN_1     1 // Pin 1  selected
#define GPIO_PIN_2     2 // Pin 2  selected
#define GPIO_PIN_3     3 // Pin 3  selected
#define GPIO_PIN_4     4 // Pin 4  selected
#define GPIO_PIN_5     5 // Pin 5  selected
#define GPIO_PIN_6     6 // Pin 6  selected
#define GPIO_PIN_7     7 // Pin 7  selected

//@ref GPIO_MODE_Define

#define GPIO_MODE_Input_PU				(0) // Input with pull-up
#define GPIO_MODE_Input_PD				(1) // Input with pull-down
#define GPIO_MODE_Output				(2) // General purpose output 


// @ref GPIO_PIN_State
#define GPIO_PIN_SET        		   (1)
#define GPIO_PIN_RESET       		   (0)

//@ref GPIO_RETURN_define
#define GPIO_RETURN_OK        		   (1)
#define GPIO_RETURN_ERROR     		   (0)


/*
 * ===============================================
 * APIs Supported by "MCAL GPIO DRIVER"
 * ===============================================*/

// API's to initialize and reset
void MCAL_GPIO_Init(GPIO_TypeDef *GPIOx , GPIO_PinConfig_t *PinConfig);
void MCAL_GPIO_DeInit(GPIO_TypeDef * GPIOx );

// API's to Read values
uint8_t  MCAL_GPIO_Read_PIN(GPIO_TypeDef * GPIOx ,uint16_t Pin_Number);
uint16_t MCAL_GPIO_Read_PORT(GPIO_TypeDef * GPIOx );

// API's to Write
void   MCAL_GPIO_Write_PIN(GPIO_TypeDef * GPIOx , uint16_t Pin_Number,uint8_t Value);
void   MCAL_GPIO_Write_Port(GPIO_TypeDef * GPIOx , uint16_t Value);

// API's to toggle pin
void   MCAL_GPIO_Toggle_PIN(GPIO_TypeDef * GPIOx ,uint16_t Pin_Number);


#endif   /* ATMEGA_GPIO_H_*/
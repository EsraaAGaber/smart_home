/*
 * ATMEGA_GPIO.c
 *
 * Created: 19/08/2024 04:03:38 م
 *  Author: HP
 */ 
#include "inc/ATMEGA_GPIO.h"
/**================================================================
 * @Fn			-MCAL_GPIO_Init
 * @brief 		-initialize GPIO port
 * @param [in] 	-GPIOx (x=a,b,c,d,e)
 * @param [in] 	-PinConfig struct contain config. of the port
 * @retval 		-none
 * Note			-none
 */

void MCAL_GPIO_Init(GPIO_TypeDef * GPIOx , GPIO_PinConfig_t *PinConfig)
{
	/*
	The DDxn bit in the DDRx Register selects the direction of this pin. If DDxn is written logic one,
	Pxn is configured as an output pin. If DDxn is written logic zero, Pxn is configured as an input
	pin.
	If PORTxn is written logic one when the pin is configured as an input pin, the pull-up resistor is
	activated. To switch the pull-up resistor off, PORTxn has to be written logic zero or the pin has to
	be configured as an output pin. The port pins are tri-stated when a reset condition becomes
	active, even if no clocks are running.
	If PORTxn is written logic one when the pin is configured as an output pin, the port pin is driven
	high (one). If PORTxn is written logic zero when the pin is configured as an output pin, the port
	pin is driven low (zero).
	*/
	if (PinConfig->GPIO_MODE==GPIO_MODE_Output)
	{
		GPIOx->DDR|=(1<<PinConfig->GPIO_PinNumber);
	}
	else if (PinConfig->GPIO_MODE==GPIO_MODE_Input_PU)
	{
		GPIOx->DDR&=~(1<<PinConfig->GPIO_PinNumber);
		GPIOx->PORT|=(1<<PinConfig->GPIO_PinNumber);
	}
	else if (PinConfig->GPIO_MODE==GPIO_MODE_Input_PD)
	{
		GPIOx->DDR&=~(1<<PinConfig->GPIO_PinNumber);
		GPIOx->PORT&=~(1<<PinConfig->GPIO_PinNumber);
	}
}


/**================================================================
 * @Fn			-MCAL_GPIO_DeInit
 * @brief 		-deinitialize GPIO pin
 * @param [in] 	-GPIOx (x=a,b,c,d,e)
 * @retval 		-none
 * Note			-none
 */
void MCAL_GPIO_DeInit(GPIO_TypeDef * GPIOx )
{
	GPIOx->DDR=0;
	GPIOx->PIN=0;
	GPIOx->PORT=0;
}


// API's to Read values
/**================================================================
 * @Fn			-MCAL_GPIO_Read_PIN
 * @brief 		-read pin value
 * @param [in] 	-GPIOx (x=a,b,c,d,e)
 * @param [in] 	-Pin_Number @ref GPIO_PINS_Define
 * @retval 		-pin value @ref GPIO_PIN_State
 * Note			-none
 */
uint8_t  MCAL_GPIO_Read_PIN(GPIO_TypeDef * GPIOx ,uint16_t Pin_Number){
	if ((GPIOx->PIN)&(1<<Pin_Number))
	{
		return  GPIO_PIN_SET;
	}
	return GPIO_PIN_RESET;
}

/**================================================================
 * @Fn			-MCAL_GPIO_Read_PORT
 * @brief 		-read all port  value
 * @param [in] 	-GPIOx (x=a,b,c,d,e)
 * @retval 		-pin value @ref GPIO_PIN_State
 * Note			-none
 */
uint16_t MCAL_GPIO_Read_PORT(GPIO_TypeDef * GPIOx )
{
	return GPIOx->PIN;
}

// API's to Write
/**================================================================
 * @Fn			-MCAL_GPIO_Write_PIN
 * @brief 		-write  pin value
 * @param [in] 	-GPIOx (x=a,b,c,d,e)
 * @param [in] 	-Pin_Number @ref GPIO_PINS_Define
 * @param [in]  	-pin value @ref GPIO_PIN_State
 * @retval 		-none
 * Note			-none
 */
void   MCAL_GPIO_Write_PIN(GPIO_TypeDef * GPIOx , uint16_t Pin_Number,uint8_t Value){
	if (Value==GPIO_PIN_SET)
	{
		GPIOx->PORT|=1<<(Pin_Number);
	}
	else GPIOx->PORT&=~(1<<(Pin_Number));
}
/**================================================================
 * @Fn			-MCAL_GPIO_Write_Port
 * @brief 		-write port value
 * @param [in] 	-GPIOx (x=a,b,c,d,e)
 * @param [in]  	-port value
 * @retval 		-none
 * Note			-none
 */
void   MCAL_GPIO_Write_Port(GPIO_TypeDef * GPIOx , uint16_t Value){

	GPIOx->PORT = Value ;
}

// API's to toggle pin
/**================================================================
 * @Fn			-MCAL_GPIO_Toggle_PIN
 * @brief 		-toggle pin value
 * @param [in] 	-GPIOx (x=a,b,c,d,e)
 * @param [in] 	-Pin_Number @ref GPIO_PINS_Define
 * @retval 		-none
 * Note			-none
 */
void   MCAL_GPIO_Toggle_PIN(GPIO_TypeDef * GPIOx ,uint16_t Pin_Number){

	GPIOx->PORT^=(1<<(uint32_t)Pin_Number);


}

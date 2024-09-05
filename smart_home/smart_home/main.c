/*
 * smart_home.c
 *
 * Created: 03/09/2024 12:46:57 ص
 * Author : HP
 */ 

#include <avr/io.h>
#include "MCAL/inc/ATMEGA.h"
#include "MCAL/inc/ATMEGA_GPIO.h"
#include "MCAL/inc/ADC_interface.h"
#include "MCAL/inc/UART.h"
#include <util/delay.h>
void led1(void)
{
		
			
			while (1)
			{
				char x =UART_RECEIVE();
				if (x != 0)  // Ensure a valid character is received
				{
					if (x == '1')
					{
						MCAL_GPIO_Write_PIN(GPIOB,GPIO_PIN_0,GPIO_PIN_SET);
						UART_SEND('0');  // Send confirmation to the master that LED is ON

						
					}
					else if (x == '2')
					{
						MCAL_GPIO_Write_PIN(GPIOB,GPIO_PIN_0,GPIO_PIN_RESET);
						UART_SEND('0');  // Send confirmation to the master that LED is ON

					}
					else if (x=='?')
					{
						UART_SEND('1');  // Send confirmation to the master
						return;
					}
					x=0;
				}
			}
		
}
void fan1(void)
{
	//	MCAL_GPIO_Write_PIN(GPIOA,GPIO_PIN_1,GPIO_PIN_SET);
while (1)
{	
	
	char x = UART_RECEIVE();
	if (x != 0)  // Ensure a valid character is received
	{
		if (x == '1')
		{
			MCAL_GPIO_Write_PIN(GPIOA,GPIO_PIN_1,GPIO_PIN_SET);
			UART_SEND('0');  // Send confirmation to the master that LED is ON

		}
		else if (x == '2')
		{
			MCAL_GPIO_Write_PIN(GPIOA,GPIO_PIN_1,GPIO_PIN_RESET);
			UART_SEND('0');  // Send confirmation to the master that LED is ON

		}
		else if (x=='?')
		{
			UART_SEND('1');  // Send confirmation to the master
			return;
		}
		x=0;
	}
}

	
}
void room1(void)
{
		
			while (1)
			{
				char x = UART_RECEIVE();
				if (x != 0)  // Ensure a valid character is received
				{
					if (x == '1')
					{
						UART_SEND('3');  // Send confirmation to the master

						led1();  // Handle room 1
						
					}
					else if (x == '2')
					{
						UART_SEND('4');  // Send confirmation to the master

						fan1();  // Handle room 2
						
					}
					else if (x=='?')
					{
						UART_SEND('+');  // Send confirmation to the master

						return;
					}
				}
			}
			
}
/////////



void led2(void)
{
	
	
	while (1)
	{
		char x =UART_RECEIVE();
		if (x != 0)  // Ensure a valid character is received
		{
			if (x == '1')
			{
				MCAL_GPIO_Write_PIN(GPIOB,GPIO_PIN_1,GPIO_PIN_SET);
				UART_SEND('0');  // Send confirmation to the master that LED is ON

				
			}
			else if (x == '2')
			{
				MCAL_GPIO_Write_PIN(GPIOB,GPIO_PIN_1,GPIO_PIN_RESET);
				UART_SEND('0');  // Send confirmation to the master that LED is ON

			}
			else if (x=='?')
			{
				UART_SEND('1');  // Send confirmation to the master
				return;
			}
		}
	}
	
}
void fan2(void)
{
	//	MCAL_GPIO_Write_PIN(GPIOA,GPIO_PIN_1,GPIO_PIN_SET);
	while (1)
	{
		
		char x = UART_RECEIVE();
		if (x != 0)  // Ensure a valid character is received
		{
			if (x == '1')
			{
				MCAL_GPIO_Write_PIN(GPIOA,GPIO_PIN_3,GPIO_PIN_SET);
				UART_SEND('0');  // Send confirmation to the master that LED is ON

			}
			else if (x == '2')
			{
				MCAL_GPIO_Write_PIN(GPIOA,GPIO_PIN_3,GPIO_PIN_RESET);
				UART_SEND('0');  // Send confirmation to the master that LED is ON

			}
			else if (x=='?')
			{
				UART_SEND('1');  // Send confirmation to the master
				return;
			}
		}
	}

	
}
void room2(void)
{
	
	while (1)
	{
		char x = UART_RECEIVE();
		if (x != 0)  // Ensure a valid character is received
		{
			if (x == '1')
			{
				UART_SEND('3');  // Send confirmation to the master

				led2();  // Handle room 1
				
			}
			else if (x == '2')
			{
				UART_SEND('4');  // Send confirmation to the master

				fan2();  // Handle room 2
				
			}
			else if (x=='?')
			{
				UART_SEND('+');  // Send confirmation to the master

				return;
			}
		}
	}
	
}












void main(void)
{
	ADC_voidInit();
	//room1
	//led config.
	GPIO_PinConfig_t LED;
	LED.GPIO_PinNumber=GPIO_PIN_0;
	LED.GPIO_MODE=GPIO_MODE_Output;
	MCAL_GPIO_Init(GPIOB,&LED);
	
	//Fan config.
	GPIO_PinConfig_t FAN={GPIO_PIN_1,GPIO_MODE_Output};
	MCAL_GPIO_Init(GPIOA,&FAN);
	MCAL_GPIO_Write_PIN(GPIOA,GPIO_PIN_1,GPIO_PIN_SET);
	
	//temp config
	//uint16_t t_value= ADC_u16GetChannalResult(ADC_CHANNAL_0);
	//t_value=(t_value*5000.0)/10230;
	//room2
	//led config.
	
	LED.GPIO_PinNumber=GPIO_PIN_1;
	LED.GPIO_MODE=GPIO_MODE_Output;
	MCAL_GPIO_Init(GPIOB,&LED);
	
	//Fan config.
	FAN.GPIO_PinNumber=GPIO_PIN_3;
	FAN.GPIO_MODE=GPIO_MODE_Output;
	MCAL_GPIO_Init(GPIOA,&FAN);
	MCAL_GPIO_Write_PIN(GPIOA,GPIO_PIN_3,GPIO_PIN_SET);
	
	//temp config
	//uint16_t t_value= ADC_u16GetChannalResult(ADC_CHANNAL_2);
	//t_value=(t_value*5000.0)/10230;
	
	
	//enable uart 
	UART_INIT();
     while (1)
     {
	     char x = UART_RECEIVE();  // Non-blocking receive
	     if (x != 0)  // Ensure a valid character is received
	     {
			 
		     if (x == '1')
		     {
			     UART_SEND('1');  // Send confirmation to the master
			     room1();         // Handle room 1
		     }
		     else if (x == '2')
		     {
			     UART_SEND('1');  // Send confirmation to the master
			     room2();         // Handle room 2
		     }
		     
	     }
		 x = 0;  // Clear variable for the next iteration
     }

}
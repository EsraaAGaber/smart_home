/*
 * smart_home_master.c
 *
 * Created: 05/09/2024 01:07:03 ص
 * Author : HP
 */ 

#include <string.h>
#include "MCAL/inc/ATMEGA.h"
#include "MCAL/inc/ATMEGA_GPIO.h"
#include "HAL/inc/keypad.h"
#include "HAL/inc/lcd.h"
#include "MCAL/inc/UART.h"
#include <avr/io.h>
unsigned char key_pressed;
uint8_t screen[4];
uint8_t count=0;
uint8_t users[2][2][4] = {{"123", "456"}, {"111", "000"}};
uint8_t ENTER_PASS(char* string)
{
	LCD_WRITE_STRING(string);
		   LCD_GOTO_XY(2,0);

	uint8_t c=3;
	while (1&&c){
		key_pressed = Keypad_getkey();
		switch(key_pressed){
			case 'A':
			break;
			case '?':
			if (count)
			{
				c++;
				count--;
				LCD_GOTO_XY(2, count + 1);
				LCD_WRITE_CHAR(' ');
				LCD_GOTO_XY(2, count + 1);
			}
			break;
			default:
			if (count<3){
				c--;
				screen[count] = key_pressed;
				count++;
				LCD_GOTO_XY(2, count);
				LCD_WRITE_CHAR('*');
			}
			break;
		}
		
	}
	count=0;
	LCD_clear_screen();
    if (strcmp((char*)screen, (char*)users[0][1]) == 0 || strcmp((char*)screen, (char*)users[1][1]) == 0) 
	return 0;
	return -1;
}
uint8_t ENTER(char* string)
{
	LCD_WRITE_STRING(string);
		   LCD_GOTO_XY(2,0);

	uint8_t c=3;
	while (1&&c){
	key_pressed = Keypad_getkey();
	switch(key_pressed){
		case 'A':
		break;
		case '?':
		if (count)
		{
			c++;
			count--;
		LCD_GOTO_XY(2, count + 1);
		LCD_WRITE_CHAR(' ');
		LCD_GOTO_XY(2, count + 1);
		}
		break;
		default:
		if (count<3){
			c--;
			screen[count] = key_pressed;
			count++;
			LCD_GOTO_XY(2, count);
			LCD_WRITE_CHAR(key_pressed);
		}
		break;
	}
	
	}
	LCD_clear_screen();
	count=0;
    if (strcmp((char*)screen, (char*)users[0][0]) == 0 || strcmp((char*)screen, (char*)users[1][0]) == 0) 
	return 0;
	return -1;
}
int main(void)
{
	UART_INIT();
   LCD_INIT();
   Keypad_init();   
  count=0;
   while(1){	   

	   count=0;
	   
	   LCD_clear_screen();
	   LCD_WRITE_STRING("Hello visitor!");
	   _delay_ms(1000);
	   LCD_clear_screen();
	   
	   if (ENTER("Enter your id :")!=0)	   {
		   
			   LCD_WRITE_STRING("wrong Id!!!!");
			   LCD_GOTO_XY(2,0);
			   LCD_WRITE_STRING(" closed...");
			   _delay_ms(1000);
			   continue;
		   
	   }
	   
	   uint8_t c=3;
	   while (c--)
	   {
		   if (ENTER_PASS("Enter your pass")!=0)
		   {
			   LCD_WRITE_STRING("Wrong password");
			   _delay_ms(100);
			   LCD_clear_screen();
			   continue;
		   }
		   LCD_WRITE_STRING("in system.");
		   _delay_ms(1000);
		   LCD_clear_screen();
		   break;
	   }
	    LCD_clear_screen();
	    LCD_WRITE_STRING("1)room 1");
	    LCD_GOTO_XY(2,0);
	    LCD_WRITE_STRING("2)room 2");
	  while (1)
	  {
		  key_pressed = Keypad_getkey();
		  switch(key_pressed){
			  case 'A':
			  break;
			  default:
			  UART_SEND(key_pressed);

			  // Expect a response
			  char received_data = UART_RECEIVE();
			  
			  if (received_data == '1')
			  {
				  LCD_clear_screen();
				 LCD_WRITE_STRING("1)led control");
				 LCD_GOTO_XY(2,0);
				 LCD_WRITE_STRING("2)fan control");
				  
			  }
			  else if (received_data == '+')
			  {
				   LCD_clear_screen();
				   LCD_WRITE_STRING("1)room 1");
				   LCD_GOTO_XY(2,0);
				   LCD_WRITE_STRING("2)room 2");
			  }
			  else if (received_data=='3')
			  {
				  
				  LCD_clear_screen();
				  	 LCD_WRITE_STRING("1)led on");
					  LCD_GOTO_XY(2,0);
					  LCD_WRITE_STRING("2)led off");


			  }
			  else if  (received_data=='4')
			  {
				  LCD_clear_screen();
				  LCD_WRITE_STRING("1)fan on");
				  LCD_GOTO_XY(2,0);
				  LCD_WRITE_STRING("2)fan off");


			  }
			   else if  (received_data=='0')
			   {
				   
			   }
			   
			  else
			  {
				  LCD_WRITE_STRING("Invalid Response");
			  }
			  break;
		  }
	  }
	   
   
   }
   }
/*
 * HLCD_Program.c
 *  
 *      Author: Eng Ahmed Tarek
 */
#include "STD_TYPES.h"
#include "MDIO_Interface.h"
#include "BIT_MATH.h"
#include <util/delay.h>




void HLCD_VoidSendChar(u8 Copy_U8Data)
{
	 /*Set Rs=1 , to send data*/
	MDIO_VoidSetPinValue(PORTB,PIN0,1);
	
	/*Set Rw=0 , to write on LCD*/
	MDIO_VoidSetPinValue(PORTB,PIN1,0);
	
	 /*Write Data On LCD*/
	MDIO_VoidSetPinValue(PORTC,PIN4,GET_BIT(Copy_U8Data,4));
	MDIO_VoidSetPinValue(PORTC,PIN5,GET_BIT(Copy_U8Data,5));
	MDIO_VoidSetPinValue(PORTC,PIN6,GET_BIT(Copy_U8Data,6));
	MDIO_VoidSetPinValue(PORTC,PIN7,GET_BIT(Copy_U8Data,7));
	
	/*set low to enable*/
	MDIO_VoidSetPinValue(PORTB,PIN2,0);
	
	/*wait 1 Ms*/
	
	_delay_ms(1); 
	
	 /*set Hi to enable*/
	MDIO_VoidSetPinValue(PORTB,PIN2,1);
	
	 /*wait 1 ms*/
	_delay_ms(1);
	
	 /*set low to enable*/
	MDIO_VoidSetPinValue(PORTB,PIN2,0);
	
	/*wait 2 ms*/
	_delay_ms(2);
	
	MDIO_VoidSetPinValue(PORTC,PIN4,GET_BIT(Copy_U8Data,0));
	MDIO_VoidSetPinValue(PORTC,PIN5,GET_BIT(Copy_U8Data,1));
	MDIO_VoidSetPinValue(PORTC,PIN6,GET_BIT(Copy_U8Data,2));
	MDIO_VoidSetPinValue(PORTC,PIN7,GET_BIT(Copy_U8Data,3));

	/*set low to enable*/
	MDIO_VoidSetPinValue(PORTB,PIN2,0);

	/*wait 1 Ms*/

	_delay_ms(1);

	 /*set Hi to enable*/
	MDIO_VoidSetPinValue(PORTB,PIN2,1);

	 /*wait 1 ms*/
	_delay_ms(1);

	 /*set low to ennable*/
	MDIO_VoidSetPinValue(PORTB,PIN2,0);

	/*wait 2 ms*/
	_delay_ms(2);



}
/* if init is 1 or 0*/
static char init;

void HLCD_VoidSendCommand(u8 Copy_U8Command)
{
	/*Set Rs=0 , to send command*/
	MDIO_VoidSetPinValue(PORTB,PIN0,0);
	
	/*Set Rw=0 , to write on LCD*/
	MDIO_VoidSetPinValue(PORTB,PIN1,0);
	
	  /*DO command On LCD*/
	MDIO_VoidSetPinValue(PORTC,PIN4,GET_BIT(Copy_U8Command,4));
	MDIO_VoidSetPinValue(PORTC,PIN5,GET_BIT(Copy_U8Command,5));
	MDIO_VoidSetPinValue(PORTC,PIN6,GET_BIT(Copy_U8Command,6));
	MDIO_VoidSetPinValue(PORTC,PIN7,GET_BIT(Copy_U8Command,7));
	
	/*set low to enable*/
	MDIO_VoidSetPinValue(PORTB,PIN2,0);
	
	 /*wait 1 ms*/
	_delay_ms(1);
	
	/*set Hi to enable*/
	MDIO_VoidSetPinValue(PORTB,PIN2,1);
	
	 /*wait 1 ms*/
	_delay_ms(1);
	
	/*set low to enable*/
	MDIO_VoidSetPinValue(PORTB,PIN2,0);
	
	/*wait 2 ms*/
	_delay_ms(2);
	if(init)
	{
	/*DO command On LCD*/
	MDIO_VoidSetPinValue(PORTC,PIN4,GET_BIT(Copy_U8Command,0));
	MDIO_VoidSetPinValue(PORTC,PIN5,GET_BIT(Copy_U8Command,1));
	MDIO_VoidSetPinValue(PORTC,PIN6,GET_BIT(Copy_U8Command,2));
	MDIO_VoidSetPinValue(PORTC,PIN7,GET_BIT(Copy_U8Command,3));

	/*set low to enable*/
	MDIO_VoidSetPinValue(PORTB,PIN2,0);

	 /*wait 1 ms*/
	_delay_ms(1);

	/*set Hi to enable*/
	MDIO_VoidSetPinValue(PORTB,PIN2,1);

	 /*wait 1 ms*/
	_delay_ms(1);

	/*set low to enable*/
	MDIO_VoidSetPinValue(PORTB,PIN2,0);

	/*wait 2 ms*/
	_delay_ms(2);
	}
	else
	{

	}



}

void HLCD_VoidSendString(char* str)
{
	u8 i=0;
	while(str[i]!='\0')
	{
		HLCD_VoidSendChar(str[i]);
		i++;
	}
}
void HLCD_VoidSetPosition(u8 Copy_U8Row,u8 Copy_U8Col)
{

	if(Copy_U8Row==0)
	{
		HLCD_VoidSendCommand(Copy_U8Col+128);
	}
	else if(Copy_U8Row==1)
	{
		HLCD_VoidSendCommand(Copy_U8Col+128+64);

	}
}

void HLCD_VoidShiftingLeftLcd()
{
	 HLCD_VoidSendCommand(0b00011000);
}
void HLCD_VoidShiftingRightLcd()
{
	 HLCD_VoidSendCommand(0b00011100);
}


void HLCD_VoidInit_4Bit(void)
{
	/*power on */
	MDIO_VoidSetPinDirection(PORTB,PIN0,1);
	MDIO_VoidSetPinDirection(PORTB,PIN1,1);
	MDIO_VoidSetPinDirection(PORTB,PIN2,1);
	MDIO_VoidSetPinDirection(PORTC,PIN4,1);
	MDIO_VoidSetPinDirection(PORTC,PIN5,1);
	MDIO_VoidSetPinDirection(PORTC,PIN6,1);
	MDIO_VoidSetPinDirection(PORTC,PIN7,1);

	/*wait 40 ms*/
	_delay_ms(40);
	
	/*function set (5*8) (4 bits) (2 lines)*/
	HLCD_VoidSendCommand(0b00100000);
	HLCD_VoidSendCommand(0b00100000);
	HLCD_VoidSendCommand(0b10000000);
	
	/*wait 45 us*/
	_delay_us(45);
	
	/*Display on Display on Cursor on  Blinking on*/
	HLCD_VoidSendCommand(0b00000000);
	HLCD_VoidSendCommand(0b11110000);
	
	/*wait 45 us*/
	_delay_us(45);

	/*Display Clear*/
	HLCD_VoidSendCommand(0b00000000);
	HLCD_VoidSendCommand(0b00010000);
	
	/*wait 2 ms*/
	_delay_ms(2);
	
	init=1;
}

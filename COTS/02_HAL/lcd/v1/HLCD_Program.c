/*
 * HLCD_Program.c
 *  
 *      Author: Eng Ahmed Tarek
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "HLCD_Private.h"
#include <avr/delay.h>

void HLCD_VoidSendChar(u8 Copy_U8Data)
{
	/*Set RS=1, to send data*/
	MDIO_VoidSetPinValue(PORTB,PIN0,1);
	/*Set Rw=0, to write */
	MDIO_VoidSetPinValue(PORTB,PIN1,0);
	/*Portc = data*/
	MDIO_VoidSetPortValue(PORTC, Copy_U8Data);
	/*En_seq*/
	MDIO_VoidSetPinValue(PORTB,PIN2,0);
	/* wait 1ms */
	_delay_ms(1);
	/*set High to enable*/
	MDIO_VoidSetPinValue(PORTB,PIN2,1);
	/* wait 1ms */
	_delay_ms(1);
	/*set low to enable*/
	MDIO_VoidSetPinValue(PORTB,PIN2,0);
	/* wait 1ms */
	_delay_ms(2);
}
void HLCD_VoidSendCommand(u8 Copy_U8Command)
{
	/*Set RS=1, to send data*/
	MDIO_VoidSetPinValue(PORTB,PIN0,0);
	/*Set Rw=0, to write */
	MDIO_VoidSetPinValue(PORTB,PIN1,0);
	/*Portc = data*/
	MDIO_VoidSetPortValue(PORTC, Copy_U8Data);
	/*En_seq*/
	MDIO_VoidSetPinValue(PORTB,PIN2,0);
	/* wait 1ms */
	_delay_ms(1);
	/*set High to enable*/
	MDIO_VoidSetPinValue(PORTB,PIN2,1);
	/* wait 1ms */
	_delay_ms(1);
	/*set low to enable*/
	MDIO_VoidSetPinValue(PORTB,PIN2,0);
	/* wait 1ms */
	_delay_ms(2);
}
void HLCD_VoidInit(void)
{
	/*power on*/
	MDIO_VoidSetPortDirection(PORTC,0b11111111);
	MDIO_VoidSetPinDirection(PORTB,PIN0,1);
	MDIO_VoidSetPinDirection(PORTB,PIN1,1);
	MDIO_VoidSetPinDirection(PORTB,PIN2,1);
	/*wait 40ms*/
	_delay_ms(40);
	
	/*Function set 8bit mode ... 2 line mode ... 5*8 mode */
	
	HLCD_VoidSendCommand(0b00111000);
	
	/*wait for more than 1ms*/
 _delay_ms(1);

/*on display..on cursor...on bluting*/

HLCD_VoidSendCommand(0b00001111);

/*wait more than 1.53*/

_delay_ms(1);

/*display clear*/

HLCD_VoidSendCommand(0b00000001);
	
	/*delay more than 1.53ms*/
	
	_delay_ms(2);
	
}
void HLCD_VoidStringChar (char* str)
{
	u8 i=0;
	
	while (str[i]!=('\0'))
	{
		HLCD_VoidSendChar(str[i]);
		i++;
	}
	
}
void HLCD_VoidSetPostion(u8 Copy_U8Row,u8 Copy_U8Col)
{
	
	if (Copy_U8Row == 0)
	{
		HLCD_VoidSendCommand(Copy_U8Col+128);
	}
	else if (Copy_U8Row == 1)
	{
		HLCD_VoidSendCommand(Copy_U8Col+128+64);
	}
	
	
}


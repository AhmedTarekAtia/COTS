/*
 * HLCD_Interface.h
 *  
 *      Author: Eng Ahmed Tarek
 */
#ifndef HLCD_INTERFACE_H
#define HLCD_INTERFACE_H

void HLCD_VoidSendChar(u8 Copy_U8Data);

void HLCD_VoidSendCommand(u8 Copy_U8Command);

void HLCD_VoidSendString(char* str);

void HLCD_VoidSetPosition(u8 Copy_U8Row,u8 Copy_U8Col);

void HLCD_VoidShiftingLeftLcd();

void HLCD_VoidShiftingRightLcd();

void HLCD_VoidInit_4Bit(void);

#endif

/*
 * HLCD_Interface.h
 *  
 *      Author: Eng Ahmed Tarek
 */
#ifndef HLCD_Interface_H
#define HLCD_Interface_H

void HLCD_VoidSendChar(u8 Copy_U8Data);
void HLCD_VoidSendCommand(u8 Copy_U8Command);
void HLCD_VoidInit(void);
void HLCD_VoidStringChar (char* str);
void HLCD_VoidSetPostion(u8 Copy_U8Row,u8 Copy_U8Col);


#endif

#ifndef _DIO_INTERFACE_H_

#define _DIO_INTERFACE_H_


#define PORTA	0
#define PORTB	1
#define PORTC	2
#define PORTD	3

#define PIN0	0
#define PIN1	1
#define PIN2	2
#define PIN3	3
#define PIN4	4
#define PIN5	5
#define PIN6	6
#define PIN7	7

#define INPUT	0
#define OUTPUT	1

#define HIGH	1
#define LOW		0


void DIO_VidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Dir);
void DIO_VidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Val);
u8 DIO_U8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin);
void DIO_VidTogglePinValue(u8 Copy_u8Port, u8 Copy_u8Pin);
void DIO_VidSetPortDirection(u8 Copy_u8Port, u8 Copy_u8Val);
void DIO_VidSetPortValue(u8 Copy_u8Port, u8 Copy_u8Val);


#endif
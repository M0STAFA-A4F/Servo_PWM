#ifndef _STD_TYPES_h_
#include "STD_TYPES.h"
#endif

#ifndef _BIT_MATH_h_
#include "BIT_MATH.h"
#endif

#include "DIO_Register.h"


void DIO_VidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Dir)
{
	if(Copy_u8Pin >= 0 && Copy_u8Pin <= 7)
	{
		if(0 == Copy_u8Dir)
		{
			switch(Copy_u8Port)
			{
				case 0: CLR_BIT(DDRA,Copy_u8Pin); break;
				case 1: CLR_BIT(DDRB,Copy_u8Pin); break;
				case 2: CLR_BIT(DDRC,Copy_u8Pin); break;
				case 3: CLR_BIT(DDRD,Copy_u8Pin); break;
			}
		}
		else if(1 == Copy_u8Dir)
		{
			switch(Copy_u8Port)
			{
				case 0: SET_BIT(DDRA,Copy_u8Pin); break;
				case 1: SET_BIT(DDRB,Copy_u8Pin); break;
				case 2: SET_BIT(DDRC,Copy_u8Pin); break;
				case 3: SET_BIT(DDRD,Copy_u8Pin); break;
			}
		}
	}
}

void DIO_VidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Val)
{
	if(Copy_u8Pin >= 0 && Copy_u8Pin <= 7)
	{
		if(0 == Copy_u8Val)
		{
			switch(Copy_u8Port)
			{
				case 0: CLR_BIT(_PORTA,Copy_u8Pin); break;
				case 1: CLR_BIT(_PORTB,Copy_u8Pin); break;
				case 2: CLR_BIT(_PORTC,Copy_u8Pin); break;
				case 3: CLR_BIT(_PORTD,Copy_u8Pin); break;
			}
		}
		else if(1 == Copy_u8Val)
		{
			switch(Copy_u8Port)
			{
				case 0: SET_BIT(_PORTA,Copy_u8Pin); break;
				case 1: SET_BIT(_PORTB,Copy_u8Pin); break;
				case 2: SET_BIT(_PORTC,Copy_u8Pin); break;
				case 3: SET_BIT(_PORTD,Copy_u8Pin); break;
			}
		}
	}
}

u8 DIO_U8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	u8 Ret_Value;
	
	if(Copy_u8Pin >= 0 && Copy_u8Pin <= 7)
	{
		switch(Copy_u8Port)
		{
			case 0: Ret_Value = GET_BIT(PINA,Copy_u8Pin); break;
			case 1: Ret_Value = GET_BIT(PINB,Copy_u8Pin); break;
			case 2: Ret_Value = GET_BIT(PINC,Copy_u8Pin); break;
			case 3: Ret_Value = GET_BIT(PIND,Copy_u8Pin); break;
		}
	}
	
	return Ret_Value;
}

void DIO_VidTogglePinValue(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	if(Copy_u8Pin >= 0 && Copy_u8Pin <= 7)
	{
		switch(Copy_u8Port)
		{
			case 0: Toggle_BIT(_PORTA,Copy_u8Pin); break;
			case 1: Toggle_BIT(_PORTB,Copy_u8Pin); break;
			case 2: Toggle_BIT(_PORTC,Copy_u8Pin); break;
			case 3: Toggle_BIT(_PORTD,Copy_u8Pin); break;
		}		
	}
}

void DIO_VidSetPortDirection(u8 Copy_u8Port, u8 Copy_u8Val)
{
	switch(Copy_u8Port)
	{
		case 0: DDRA = Copy_u8Val; break;
		case 1: DDRB = Copy_u8Val; break;
		case 2: DDRC = Copy_u8Val; break;
		case 3: DDRD = Copy_u8Val; break;
	}
}

void DIO_VidSetPortValue(u8 Copy_u8Port, u8 Copy_u8Val)
{
	switch(Copy_u8Port)
	{
		case 0: _PORTA = Copy_u8Val; break;
		case 1: _PORTB = Copy_u8Val; break;
		case 2: _PORTC = Copy_u8Val; break;
		case 3: _PORTD = Copy_u8Val; break;
	}
}
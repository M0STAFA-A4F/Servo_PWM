#ifndef _STD_TYPES_h_
#include "STD_TYPES.h"
#endif

#ifndef _BIT_MATH_h_
#include "BIT_MATH.h"
#endif

#include "TIMER_Register.h"


#define NULL	0

#define NormalMode		0
#define CTC				1
#define FastPWM			2

#define TimerMode		FastPWM

#define Prescaler_256	1	

#define PrescalerSelect	Prescaler_256




void static (* Timer0CallBackPtr)(void) = NULL;


void TIMER0_VidInit()
{
	#if TimerMode == NormalMode
	
	// Normal Mode
	CLR_BIT(TCCR0,6);
	CLR_BIT(TCCR0,3);
	
	// prescaling   --> clk/256
	SET_BIT(TCCR0,2);
	CLR_BIT(TCCR0,1);
	CLR_BIT(TCCR0,0);
	
	// preload value of timer0
	TCNT0 = 238;
	
	// Timer/Counter0 Overflow Interrupt Enable (TOIE)
	SET_BIT(TIMSK,0);
	
	// GIE=1
	SET_BIT(SREG,7);
	
	//--------------------------------------------------------------------------	
	
	#elif TimerMode == CTC
	
	// CTC Mode
	CLR_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);
	
	// prescaling   --> clk/256
	SET_BIT(TCCR0,2);
	CLR_BIT(TCCR0,1);
	CLR_BIT(TCCR0,0);
	
	// preload value of timer0

	OCR0 = 128;
	
	//  Timer/Counter0 Overflow Interrupt Enable (TOIE)
	SET_BIT(TIMSK,1);
	
	// GIE=1
	SET_BIT(SREG,7);
	
	//--------------------------------------------------------------------------
	
	#elif TimerMode == FastPWM
	
	// PWM Mode
	SET_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);
	
	// Clear OC0 on compare match
	SET_BIT(TCCR0,5);
	CLR_BIT(TCCR0,4);
	
	#endif
	
	//==========================================================================
	
	#if PrescalerSelect == Prescaler_256
	
	SET_BIT(TCCR0,2);
	CLR_BIT(TCCR0,1);
	CLR_BIT(TCCR0,0);
	
	#endif
}

void Timer0_VidSetDutyCycle(u8 Copy_U8DutyCycleValue)
{
	OCR0 = Copy_U8DutyCycleValue;
}

void Timer0_VidSetCallBackFun(void (* PFun)(void))
{
	Timer0CallBackPtr = PFun;
}

void __vector_10(void)
{
	Timer0CallBackPtr();
}

void __vector_11(void)
{
	Timer0CallBackPtr();
}










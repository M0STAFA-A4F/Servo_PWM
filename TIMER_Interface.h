#ifndef _TIMER_REGISTER_H_

#define _TIMER_REGISTER_H_


void Timer0_VidSetDutyCycle(u8 Copy_U8DutyCycleValue);
void Timer0_VidSetCallBackFun(void (* PFun)(void));
void TIMER0_VidInit();


#endif

#ifndef _TIMER_REGISTER_H_

#define _TIMER_REGISTER_H_


#define TCCR0	*((u8*)0x53)
#define TCNT0	*((u8*)0x52)
#define OCR0	*((u8*)0x5c)
#define TIMSK	*((u8*)0x59)
#define TIFR	*((u8*)0x58)

#define SREG	*((u8*)0x5F)
void __vector_10(void)       __attribute__((signal));
void __vector_11(void)       __attribute__((signal));

#endif
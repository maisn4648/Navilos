#include "stdint.h"
#include "Timer.h"
#include "HalTimer.h"
#include "HalInterrupt.h"

extern volatile Timer_t* Timer;

static void interrupt_handler(void);

static uint32_t internal_1ms_counter;

void Hal_timer_init(void)
{
	//interface reset
	Timer->timerxcontrol.bits.TimerEn=0;
	Timer->timerxcontrol.bits.TimerMode=0;
	Timer->timerxcontrol.bits.OneShot =0;
	Timer->timerxcontrol.bits.TimerSize=0;
	Timer->timerxcontrol.bits.TimerPre=0;
	Timer->timerxcontrol.bits.IntEnable=1;
	Timer->timerxload=0;
	Timer->timerxvalue=0xFFFFFFFF;

	Timer->timerxcontrol.bits.TimerMode=TIMER_PERIOIC;
	Timer->timerxcontrol.bits.TimerSize=TIMER_32BIT_COUNTER;
	Timer->timerxcontrol.bits.OneShot=0;
	Timer->timerxcontrol.bits.TimerPre=0;
	Timer->timerxcontrol.bits.IntEnable=1;

	uint32_t interval_1ms = TIMER_1MZ_INTERVAL / 1000;

	Timer->timerxload = interval_1ms;
	Timer->timerxcontrol.bits.TimerEn=1;

	Hal_interrupt_enable(TIMER_INTERRUPT);
	Hal_interrupt_register_handler(interrupt_handler,TIMER_INTERRUPT);
}

static void interrupt_handler(void)
{
	internal_1ms_counter++;

	Timer->timerxintclr=1;
}

uint32_t Hal_timer_get_1ms_counter(void)
{
	return internal_1ms_counter;
}

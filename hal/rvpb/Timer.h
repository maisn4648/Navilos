#ifndef HAL_TIMER_H_
#define HAL_TIMER_H_


typedef union TimerXControl_t
{
	uint32_t all;

	struct {
		uint32_t OneShot:1;
		uint32_t TimerSize:1;
		uint32_t TimerPre:2;
		uint32_t Reserved0:1;
		uint32_t IntEnable:1;
		uint32_t TimerMode:1;
		uint32_t TimerEn:1;
		uint32_t Reserved1:24;
	} bits;

} TimerXControl_t;

typedef union TimerXRIS_t
{
	uint32_t all;

	struct {
		uint32_t TimerXRIS:1;
		uint32_t Reserved:31;
	} bits;

} TimerXRIS_t;

typedef union TimerXMIS_t
{
	uint32_t all;

	struct {
		uint32_t TimerXMIS:1;
		uint32_t Reserved:31;
	} bits;

} TimerXMIS_t;

typedef struct Timer_t
{
	uint32_t timerxload; //0x00
	uint32_t timerxvalue;
	TimerXControl_t timerxcontrol;
	uint32_t timerxintclr;
	TimerXRIS_t timerxris;
	TimerXMIS_t timerxmis;
	uint32_t timerxbgload;
} Timer_t;

#define TIMER_CPU_BASE 0x10011000
#define TIMER_INTERRUPT 36

#define TIMER_FREERUNNING 0
#define TIMER_PERIOIC 1

#define TIMER_16BIT_COUNTER 0
#define TIMER_32BIT_COUNTER 1

#define TIMER_1MZ_INTERVAL (1024*1024)

#endif /* HAL_TIMER_H_ */

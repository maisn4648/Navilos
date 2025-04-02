#include "stdint.h"
#include "stdbool.h"
#include "HalTimer.h"

void delay(uint32_t ms)
{
	uint32_t goal = Hal_timer_get_1ms_counter() + ms;

	while(Hal_timer_get_1ms_counter()!=goal);

}

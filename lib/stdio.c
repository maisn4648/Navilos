#include "stdint.h"
#include "HalUart.h"
#include "stdio.h"

uint32_t putstr(const char* s)
{
	uint32_t cnt=0;
	while(*s)
	{
		Hal_uart_put_char(*s++);
		cnt++;
	}	

	return cnt;
}



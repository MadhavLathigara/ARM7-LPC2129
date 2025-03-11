#include <LPC21xx.h>
#include "delay.h"

int main()
{
	IODIR0 |=0xFFFFFF;

		while(1)
		{
			IOSET0=0xFFFFFFFF;
			delay_ms(100);
			IOCLR0=0xFFFFFFFF;
			delay_ms(100);
		}
}

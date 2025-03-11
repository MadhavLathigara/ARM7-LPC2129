//seg.c
#include <LPC21xx.h>
#include "delay.h"
#include "types.h"
#include "seg_defines.h"
#include "defines.h"
u8 ca7seg_lut[10]=
{
0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90
//0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F
};

void Init7Segs(void)
{
	IODIR0 |= ( 0xFF << CA7SEG_2_MUX | (1<< DSEL1) | (1<< DSEL2));
}

void disp_2_mux_segs(u8 num)
{
				IOPIN0=((IOPIN0&~(0xFF<<CA7SEG_2_MUX))|(ca7seg_lut[num/10]<<CA7SEG_2_MUX));
				IOSET0=1<<DSEL1;
				delay_ms(1);
				IOCLR0=1<<DSEL1;
				
				IOPIN0=((IOPIN0&~(0xFF<<CA7SEG_2_MUX))|(ca7seg_lut[num%10]<<CA7SEG_2_MUX));
				IOSET0=1<<DSEL2;
				delay_ms(1);
				IOCLR0=1<<DSEL2;
}

void Init_4_mux_Segs(void)
{
	//cfg a to dp of mux segs as gpio out
	//cfg commons of 2 mux segs as gpio out
	
	IODIR0 |= (0xFF<<CA7SEG_4_MUX) | (1<<DSEL1) | (1<<DSEL2) | (1<<DSEL3) | (1<<DSEL4);
}

void disp_time(u32 t1,u32 t2)
{
				IOPIN0=((IOPIN0&~(0xFF<<CA7SEG_4_MUX))|(ca7seg_lut[t1]<<CA7SEG_4_MUX));
				IOSET0=1<<DSEL1;
				delay_ms(1);
				IOCLR0=1<<DSEL1;
				
				IOPIN0=((IOPIN0&~(0xFF<<CA7SEG_4_MUX))|(ca7seg_lut[t2/100]<<CA7SEG_4_MUX));
				IOSET0=1<<DSEL2;
				delay_ms(1);
				IOCLR0=1<<DSEL2;
	
				IOPIN0=((IOPIN0&~(0xFF<<CA7SEG_4_MUX))|(ca7seg_lut[(t2/10)%10]<<CA7SEG_4_MUX));
				IOSET0=1<<DSEL3;
				delay_ms(1);
				IOCLR0=1<<DSEL3;
				
				IOPIN0=((IOPIN0&~(0xFF<<CA7SEG_4_MUX))|(ca7seg_lut[t2%10]<<CA7SEG_4_MUX));
				IOSET0=1<<DSEL4;
				delay_ms(1);
				IOCLR0=1<<DSEL4;
}



//stopwatch_60sec.c
#include <LPC21xx.h>
#include "types.h"
#include "delay.h"
#include "seg.h"
#define TRIG_SW_AL 16 //p1.16
main()
{
	u32 time =0 ,flag=0,dly;
	Init7Segs();
	while(1)
	{
		while(flag==0)
		{
		disp_2_mux_segs(time);
		if(((IOPIN1>>TRIG_SW_AL)&1)==0)
		{
			flag=1;
			while(((IOPIN1>>TRIG_SW_AL)&1)==0)
			{
				disp_2_mux_segs(time);
			}
		}
		}
		while(flag==1)
		{
			if(flag==1)
				time++;
			for(dly=500;dly>0;dly--)
			{
				disp_2_mux_segs(time);
				if(((IOPIN1>>TRIG_SW_AL)&1)==0)
				{
					flag=0;
					while(((IOPIN1>>TRIG_SW_AL)&1)==0)
					{
						disp_2_mux_segs(time);
					}
					break;
				}	
			}
		}
		while((flag==0)&&(time!=0))
		{
			disp_2_mux_segs(time);
			if(((IOPIN1>>TRIG_SW_AL)&1)==0)
			{
				time=0;
				while(((IOPIN1>>TRIG_SW_AL)&1)==0)
				{
					disp_2_mux_segs(time);
				}
			}
		}
	}
}


#ifndef __BSP__bsp_delay_H
#define __BSP__bsp_delay_H 			   
#include "./sys/bsp_sys.h" 


//如果使用ucosII,delay_init会自动设置SYSTICK的值,使之与ucos的TICKS_PER_SEC对应.
//delay_us可以在ucos下使用,而且准确度很高,更重要的是没有占用额外的定时器.
//delay_ms在ucos下,可以当成OSTimeDly来用,在未启动ucos时,它采用delay_us实现,从而准确延时
//可以用来初始化外设,在启动了ucos之后delay_ms根据延时的长短,选择OSTimeDly实现或者delay_us实现.
	 
void InitDelay(u8 SYSCLK);
void DelayMs(u16 nms);
void DelayUs(u32 nus);

#endif    /* __BSP_bsp_delay_H */






























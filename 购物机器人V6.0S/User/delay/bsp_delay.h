#ifndef __BSP__bsp_delay_H
#define __BSP__bsp_delay_H 			   
#include "./sys/bsp_sys.h" 


//���ʹ��ucosII,delay_init���Զ�����SYSTICK��ֵ,ʹ֮��ucos��TICKS_PER_SEC��Ӧ.
//delay_us������ucos��ʹ��,����׼ȷ�Ⱥܸ�,����Ҫ����û��ռ�ö���Ķ�ʱ��.
//delay_ms��ucos��,���Ե���OSTimeDly����,��δ����ucosʱ,������delay_usʵ��,�Ӷ�׼ȷ��ʱ
//����������ʼ������,��������ucos֮��delay_ms������ʱ�ĳ���,ѡ��OSTimeDlyʵ�ֻ���delay_usʵ��.
	 
void InitDelay(u8 SYSCLK);
void DelayMs(u16 nms);
void DelayUs(u32 nus);

#endif    /* __BSP_bsp_delay_H */






























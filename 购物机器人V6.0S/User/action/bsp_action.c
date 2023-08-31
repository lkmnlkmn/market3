/**
  ******************************************************************************
  * @file    bsp_action.c
  * @author  林文豪（Vince）
  * @version V5.0
  * @date    2021-7-10
  * @brief   行为规划整合
  ******************************************************************************
  * @attention
  *
  * 实验平台:F103ZET6主控 裘老板画的底板  LSC-16舵机控制器 小幻熊K210模块
	* QQ      :850321718
  *
  ******************************************************************************
  */ 

#include <stdio.h>
#include <math.h>
#include "./usart2/bsp_usart.h"
#include "./motor_control\bsp_motor_control.h"
#include "./LobotServoController/bsp_LobotServoController.h"
#include "./usart/bsp_debug_usart.h"
#include "./tracers/bsp_tracers.h"
#include "./trailing/bsp_trailing.h"
#include "./wondercam/bsp_wondercam.h"
#include "./IIC/bsp_iic.h"
#include "./delay/bsp_delay.h"
#include "./action/bsp_action.h"
#include "./vision/bsp_vision.h"
#include "./delay/bsp_delay.h"

/*
机械臂定点动作组说明
四周柜子从上到下从左到右
分别为1，2，3，4，5，6号位置
复位为7，普通抓取为8
回家放置为9,调整视角为10
四周柜子从上到下从左到右识别的后抓取放车上
分别为11，12，13，14，15，16
四周柜子从上到下从左到右识别的后抓取放购物车
分别为21，22，23，24，25，26
夹取购物车为27,夹取e区为28
购物车区放下爪子夹取货物29，放下携带货物30
位置2到5为31，位置2到1为32，位置1到3为33,位置3到4为34
位置5到4为35，位置4到6为36
*/

int c_goods=0;//携带物品数标志
int e_goods=1;//当前货架代检测物品标志

/**
  * @brief  到点检测抓取货架固定点物品（测试用）
  * @param  无
  * @retval 无
  */
void go_to_catch_certain(int x,int y,int m)
{
	int times=0;
  go_to_certain_position_test_edition(x,y);

   runActionGroup(m,1);
	 times=visual_identity();
	 if(times>5)
	  	runActionGroup(20+m,1);
	 else if(times>1)
	 {
	  //runActionGroup(10,1);
	  times=visual_identity();	
	  if(times>6)
		runActionGroup(20+m,1);
	 }
		 runActionGroup(0,1);
}

/**
  * @brief  到点检测抓取货架物品（测试用）
  * @param  无
  * @retval 无
  */
void go_to_catch_test(int x,int y)
{
	e_goods=0;
	int times=0,ct=11;
  go_to_certain_position(x,y);
for(int i=0;i<6;i++)
	{
   runActionGroup(e_goods,1);
	 times=visual_identity();
	 if(times>6)
	  	runActionGroup(ct,1);
	 else if(times>2)
	 {
	  runActionGroup(10,1);
	  times=visual_identity();	
	  if(times>6)
		runActionGroup(ct,1);
	 }
	 else
		runActionGroup(7,1); 
	 ct++;
	 e_goods++;
  }
}

/**
  * @brief  到点检测对应四周货架并抓取（有2物品上限版）
  * @param  无
  * @retval 无
  */
void go_to_catch1(int x,int y)
{
	int times=0,ct=11;
	e_goods=1;
  go_to_certain_position_test_edition(x,y);
	
for(int i=0;i<6;i++)
	{
   runActionGroup(e_goods,1);
	 times=visual_identity();
	 if(times>6)
	 {
	  	runActionGroup(ct,1);
	    c_goods++;
	 }
	 else if(times>4)
	 {
	  runActionGroup(10,1);
	  times=visual_identity();	
	  if(times>6)
		 {
	  	runActionGroup(ct,1);
	    c_goods++;
	   }
		 
		if(c_goods==2)
		{
			go_to_certain_position_test_edition(0,2);
		  runActionGroup(9,1);
		  if(e_goods==6)
			go_to_certain_position_no_ajust(x,y);
			else
			go_to_certain_position_test_edition(x,y);
		}		
	 }
	 else
		runActionGroup(7,1); 
	 ct++;
	 e_goods++;
  }
	runActionGroup(0,1);
}

/**
  * @brief  到点检测对应四周货架并抓取（购物车版）
  * @param  无
  * @retval 无
  */
void go_to_catch2(int x,int y)
{
	int times=0,ct=21;
	e_goods=1;
  go_to_certain_position_test_edition(x,y);
	
for(int i=0;i<3;i++)
	{
   runActionGroup(e_goods,1);
	 times=visual_identity();
	 if(times>5)
	 {
	  	runActionGroup(ct,1);
	 }
//	 else if(times>2)
//	 {
//	  runActionGroup(10,1);
//	  times=visual_identity();	
//	  if(times>4)
//		 {
//	  	runActionGroup(ct,1);
//	   }
//	 }	 
//	 else
//		runActionGroup(7,1); 
	 ct++;
	 e_goods++;
  }
	for(int i=0;i<3;i++)
	{
   runActionGroup(10-e_goods,1);
	 times=visual_identity();
	 if(times>5)
	 {
	  	runActionGroup(50-ct,1);
	 }
//	 else if(times>2)
//	 {
//	  runActionGroup(10,1);
//	  times=visual_identity();	
//	  if(times>4)
//		 {
//	  	runActionGroup(ct,1);
//	   }
//	 }	 
//	 else
//		runActionGroup(7,1); 
	 ct++;
	 e_goods++;
  }
	 runActionGroup(0,1);
}



/**
  * @brief  到点检测对应四周货架并抓取（有2物品上限版）（有检测矫正）
  * @param  无
  * @retval 无
  */
void go_to_catch1_ajust(int x,int y)
{
	int times1=0,times2=0,times3=0,ct=11;
	e_goods=1;
  go_to_certain_position_test_edition(x,y);
	
for(int i=0;i<2;i++)
	{
   for(int j=0;j<3;j++)
	{
		runActionGroup(e_goods+2,1);
	 times1=visual_identity();
    if(times1>3&&times1<=5)
	 {
	  runActionGroup(10,1);
	  times1=visual_identity();	
	  }
		runActionGroup(e_goods+1,1);
	 times2=visual_identity();
		if(times2>3&&times2<=5)
	 {
	  runActionGroup(10,1);
	  times2=visual_identity();	
	  }
		runActionGroup(e_goods,1);
	 times3=visual_identity();
				if(times3>3&&times3<=5)
	 {
	  runActionGroup(10,1);
	  times3=visual_identity();	
	  }
	 if((times1>5&&times2>5)||(times1>5&&times3>5)||(times2>5&&times3>5))
	 {
	  for(int k=0;k<3;k++)
	{	
		runActionGroup(ct,1);
		ct++;
		e_goods++;
		if(c_goods==2)
		{
			go_to_certain_position_test_edition(0,2);
		  runActionGroup(9,1);
		  if(e_goods==6)
			go_to_certain_position_no_ajust(x,y);
			else
			go_to_certain_position_test_edition(x,y);
		}		
	}
	 }
	 else
	 {
		ct=14;
	 }
	 e_goods=4;
  }
  }
		runActionGroup(0,1);
}

/**
  * @brief  到点检测对应四周货架并抓取（购物车版）（有检测矫正）(tracer版)
  * @param  无
  * @retval 无
  */
void go_to_catch2_ajust(int x,int y)
{
	int times1=0,times2=0,times3=0,ct=21;
	e_goods=1;
  go_to_certain_position_test_edition(x,y);
	
for(int i=0;i<2;i++)
	{
   for(int j=0;j<3;j++)
	{
		runActionGroup(e_goods+2,1);
	 times1=visual_identity();
    if(times1>1&&times1<=4)
	 {
	  runActionGroup(10,1);
	  times1=visual_identity();	
	  }
		runActionGroup(e_goods+1,1);
	 times2=visual_identity();
		if(times2>1&&times2<=4)
	 {
	  runActionGroup(10,1);
	  times2=visual_identity();	
	  }
		runActionGroup(e_goods,1);
	 times3=visual_identity();
				if(times3>1&&times3<=4)
	 {
	  runActionGroup(10,1);
	  times3=visual_identity();	
	  }
	 if((times1>4&&times2>4)||(times1>4&&times3>4)||(times2>4&&times3>4))
	 {
	  for(int k=0;k<3;k++)
	{	
		runActionGroup(ct,1);
		ct++;
		e_goods++;	
	}
	 }
	 else
	 {
		ct=14;
	 }
	 e_goods=4;
  }
  }
		runActionGroup(0,1);
}

/**
  * @brief  定点检测对应左侧货架并抓取（购物车版）
  * @param  无
  * @retval 无
  */
void catch_g_goods(void)
{
		int times=0,ct=21;
	e_goods=1;
	
for(int i=0;i<6;i++)
	{
   runActionGroup(e_goods,1);
	 times=visual_identity();
	 if(times>6)
	 {
	  	runActionGroup(ct,1);
	 }
	 else if(times>4)
	 {
	  runActionGroup(10,1);
	  times=visual_identity();	
	  if(times>6)
		 {
	  	runActionGroup(ct,1);
	   }
	 }	 
	 else
		runActionGroup(7,1); 
	 ct++;
	 e_goods++;
  }
		runActionGroup(0,1);
}

/**
  * @brief  定点检测对应左侧货架并抓取（购物车版）考虑中间优先（比赛适应）
  * @param  无
  * @retval 无
  */
void catch_g_goods_judge(void)
{
	int times=0;
	runActionGroup(2,1); 
	times=visual_identity();
	if(times>5)
	{
		runActionGroup(22,1); 
		runActionGroup(3,1); 
		times=visual_identity();
		if(times>2)
			runActionGroup(23,1); 
		runActionGroup(1,1); 
  times=visual_identity();
		if(times>2)
		{
			runActionGroup(21,1); 
		}
		runActionGroup(5,1); 
	}
	else
	runActionGroup(5,1); 
	times=visual_identity();
	if(times>5)
	{
		runActionGroup(25,1); 
		runActionGroup(6,1); 
		times=visual_identity();
		if(times>2)
			runActionGroup(26,1); 
		runActionGroup(4,1); 
		times=visual_identity();
		if(times>2)
			runActionGroup(24,1);  
	}
	runActionGroup(0, 1);
}

/**
  * @brief  到定点检测对应左侧货架并抓取（购物车版）考虑中间优先（比赛适应）
  * @param  无
  * @retval 无
  */
void go_to_catch_g_goods_judge(int x,int y)
{
	go_to_certain_position_test_edition(x,y);
	int times=0;
	runActionGroup(2,1); 
	times=visual_identity();
	if(times>5)
	{
		runActionGroup(22,1); 
		runActionGroup(3,1); 
		times=visual_identity();
		if(times>2)
			runActionGroup(23,1); 
		runActionGroup(1,1); 
  times=visual_identity();
		if(times>2)
		{
			runActionGroup(21,1); 
		}
		runActionGroup(5,1); 
	}
	else
	runActionGroup(5,1); 
	times=visual_identity();
	if(times>5)
	{
		runActionGroup(25,1); 
		runActionGroup(6,1); 
		times=visual_identity();
		if(times>2)
			runActionGroup(26,1); 
		runActionGroup(4,1); 
		times=visual_identity();
		if(times>2)
			runActionGroup(24,1);  
	}
		runActionGroup(0,1);
}

/**
  * @brief  到定点检测对应左侧货架并抓取（购物车版）考虑中间优先（比赛适应）（带货架视觉矫正）
  * @param  无
  * @retval 无
  */
void go_to_catch_g_goods_vison_judge(int x,int y)
{
	go_to_certain_position_test_edition(x,y);
	int times=0;
	runActionGroup(2,1); 
	times=visual_identity_judge();
	if(times>5)
	{
		runActionGroup(22,1); 
		runActionGroup(3,1); 
		times=visual_identity_judge();
		if(times>2)
			runActionGroup(23,1); 
		runActionGroup(1,1); 
  times=visual_identity_judge();
		if(times>2)
		{
			runActionGroup(21,1); 
		}
		runActionGroup(5,1); 
	}
	else
	runActionGroup(5,1); 
	times=visual_identity_judge();
	if(times>5)
	{
		runActionGroup(25,1); 
		runActionGroup(6,1); 
		times=visual_identity_judge();
		if(times>2)
			runActionGroup(26,1); 
		runActionGroup(4,1); 
		times=visual_identity_judge();
		if(times>2)
			runActionGroup(24,1);  
	}
		runActionGroup(0,1);
}

/**
  * @brief  到定点检测对应左侧货架并抓取（购物车版）考虑中间优先（比赛适应）(记录夹取动作次数)
  * @param  无
  * @retval 无
  */
int go_to_catch_g_goods_judge_count(int x,int y)
{
	int count=0;
	go_to_certain_position_test_edition(x,y);
	int times=0;
	runActionGroup(2,1); 
	times=visual_identity();
	if(times>5)
	{
		runActionGroup(22,1); 
		count++;
		runActionGroup(3,1); 
		times=visual_identity();
		if(times>2)
		{
			runActionGroup(23,1); 
					count++;
		}
		runActionGroup(1,1); 
  times=visual_identity();
		if(times>2)
		{
			runActionGroup(21,1); 
					count++;
		}
		runActionGroup(5,1); 
	}
	else
	runActionGroup(5,1); 
	times=visual_identity();
	if(times>5)
	{
		runActionGroup(25,1); 
				count++;
		runActionGroup(6,1); 
		times=visual_identity();
		if(times>2)
		{
			runActionGroup(26,1); 
					count++;
		}
		runActionGroup(4,1); 
		times=visual_identity();
		if(times>2)
		{
			runActionGroup(24,1);  
					count++;
		}
	}
		runActionGroup(0,1);
	return count;
}

/**
  * @brief  到定点检测对应左侧货架并抓取（二物品上限版）考虑中间优先（比赛适应）
  * @param  无
  * @retval 无
  */
void go_to_catch_g_goods_judge_limit(int x,int y)
{
	go_to_certain_position_test_edition(x,y);
	int times=0;
	runActionGroup(2,1); 
	times=visual_identity();
	if(times>5)
	{
		runActionGroup(22,1); 
		carry_goods_judge(x,y);
		runActionGroup(3,1); 
		times=visual_identity();
		if(times>2)
		{
			runActionGroup(23,1); 
				carry_goods_judge(x,y);
		}
		runActionGroup(1,1); 
  times=visual_identity();
		if(times>2)
		{
			runActionGroup(21,1);  
			carry_goods_judge(x,y);
		}
		runActionGroup(5,1); 
	}
	else
	runActionGroup(5,1); 
	times=visual_identity();
	if(times>5)
	{
		runActionGroup(25,1); 
		carry_goods_judge(x,y);
		runActionGroup(6,1); 
		times=visual_identity();
		if(times>2)
		{
			runActionGroup(26,1); 
			carry_goods_judge(x,y);
		}
		runActionGroup(4,1); 
		times=visual_identity();
		if(times>2)
		{
			runActionGroup(24,1);  
			carry_goods_judge(x,y);
		}
	}
		runActionGroup(0,1);
}

/**
  * @brief  到定点检测对应左侧货架并抓取（单物品上限版）考虑中间优先（比赛适应）
  * @param  无
  * @retval 无
  */
void go_to_catch_g_goods_judge_limit_only(int x,int y)
{
	go_to_certain_position_test_edition(x,y);
	int times=0;
	runActionGroup(2,1); 
	times=visual_identity();
	if(times>5)
	{
		runActionGroup(22,1); 
		send_goods_back(x,y);
		runActionGroup(3,1); 
		times=visual_identity();
		if(times>2)
		{
			runActionGroup(23,1); 
		send_goods_back(x,y);
		}
		runActionGroup(1,1); 
  times=visual_identity();
		if(times>2)
		{
			runActionGroup(21,1);  
		send_goods_back(x,y);
		}
			runActionGroup(5,1); 
	}
	runActionGroup(5,1); 
	times=visual_identity();
	if(times>5)
	{
		runActionGroup(25,1); 
		send_goods_back(x,y);
		runActionGroup(6,1); 
		times=visual_identity();
		if(times>2)
		{
			runActionGroup(26,1); 
		send_goods_back(x,y);
		}
		runActionGroup(1,1); 
		times=visual_identity();
		if(times>2)
		{
			runActionGroup(21,1);  
		send_goods_back(x,y);
		}
	}
		runActionGroup(0,1);
}

/**
  * @brief  携带货物判断
  * @param  无
  * @retval 无
  */
void carry_goods_judge(int x,int y)
{
	c_goods++;
	if(c_goods==2)
	{
			go_to_certain_position(1,1);
			runActionGroup(29,1); 
			runActionGroup(30,1); 
			go_to_certain_position_test_edition(x,y);
	}
}		

/**
  * @brief  单物品送回
  * @param  无
  * @retval 无
  */
void send_goods_back(int x,int y)
{
			go_to_certain_position(1,1);
			runActionGroup(29,1);
		runActionGroup(0,1);
			go_to_certain_position_test_edition(x,y);
}		


/*********************************************another special edition**********************/
/**
  * @brief  定点检测对应左侧货架并抓取（购物车版）考虑中间优先（比赛适应）(货架矫正)
  * @param  无
  * @retval 无
  */
void catch_g_goods_judge2(void)
{
	int times=0;
	runActionGroup(2,1); 
	times=visual_identity_judge();
	if(times>3)
	{
		runActionGroup(22,1); 
		runActionGroup(1,1); 
		times=visual_identity_judge();
		if(times>1)
			runActionGroup(21,1); 
		runActionGroup(3,1); 
  times=visual_identity_judge();
		if(times>1)
		{
			runActionGroup(23,1); 
		}
		runActionGroup(5,1); 
	}
	else
	runActionGroup(5,1); 
	times=visual_identity_judge();
	if(times>3)
	{
		runActionGroup(25,1); 
		runActionGroup(4,1); 
		times=visual_identity_judge();
		if(times>1)
			runActionGroup(24,1); 
		runActionGroup(6,1); 
		times=visual_identity_judge();
		if(times>1)
			runActionGroup(26,1);  
	}
	runActionGroup(0, 1);
}

/**
  * @brief  到定点检测对应左侧货架并抓取（购物车版）考虑中间优先（比赛适应）(货架矫正)
  * @param  无
  * @retval 无
  */
void go_to_catch_g_goods_judge2(int x,int y)
{
	go_to_certain_position_test_edition(x,y);
	int times=0;
	runActionGroup(2,1); 
	times=visual_identity_judge();
	if(times>3)
	{
		runActionGroup(22,1); 
		runActionGroup(1,1); 
		times=visual_identity_judge();
		if(times>1)
			runActionGroup(21,1); 
		runActionGroup(3,1); 
  times=visual_identity_judge();
		if(times>1)
		{
			runActionGroup(23,1); 
		}
		runActionGroup(5,1); 
	}
	else
	runActionGroup(5,1); 
	times=visual_identity_judge();
	if(times>3)
	{
		runActionGroup(25,1); 
		runActionGroup(4,1); 
		times=visual_identity_judge();
		if(times>1)
			runActionGroup(24,1); 
		runActionGroup(6,1); 
		times=visual_identity_judge();
		if(times>1)
			runActionGroup(26,1);  
	}
		runActionGroup(0,1);
}

/**
  * @brief  到定点检测对应左侧货架并抓取（二物品上限版）考虑中间优先（比赛适应）(货架矫正)
  * @param  无
  * @retval 无
  */
void go_to_catch_g_goods_judge_limit2(int x,int y)
{
	go_to_certain_position_test_edition(x,y);
	int times=0;
	runActionGroup(2,1); 
	times=visual_identity_judge();
	if(times>3)
	{
		runActionGroup(22,1); 
		carry_goods_judge(x,y);
		runActionGroup(1,1); 
		times=visual_identity_judge();
		if(times>1)
		{
			runActionGroup(21,1); 
				carry_goods_judge(x,y);
		}
		runActionGroup(3,1); 
  times=visual_identity_judge();
		if(times>1)
		{
			runActionGroup(23,1);  
			carry_goods_judge(x,y);
		}
		runActionGroup(5,1); 
	}
	else
	runActionGroup(5,1); 
	times=visual_identity_judge();
	if(times>3)
	{
		runActionGroup(25,1); 
		carry_goods_judge(x,y);
		runActionGroup(4,1); 
		times=visual_identity_judge();
		if(times>1)
		{
			runActionGroup(24,1); 
			carry_goods_judge(x,y);
		}
		runActionGroup(6,1); 
		times=visual_identity_judge();
		if(times>1)
		{
			runActionGroup(26,1);  
			carry_goods_judge(x,y);
		}
	}
		runActionGroup(0,1);
}

/**
  * @brief  到定点检测对应左侧货架并抓取（单物品上限版）考虑中间优先（比赛适应）(货架矫正)
  * @param  无
  * @retval 无
  */
void go_to_catch_g_goods_judge_limit_only2(int x,int y)
{
	go_to_certain_position_test_edition(x,y);
	int times=0;
	runActionGroup(2,1); 
	times=visual_identity_judge();
	if(times>4)
	{
		runActionGroup(22,1); 
		send_goods_back(x,y);
		runActionGroup(1,1); 
		times=visual_identity_judge();
		if(times>2)
		{
			runActionGroup(21,1); 
		send_goods_back(x,y);
		}
		runActionGroup(33,1); 
  times=visual_identity_judge();
		if(times>2)
		{
			runActionGroup(23,1);  
		send_goods_back(x,y);
		}
			runActionGroup(5,1); 
	}
	runActionGroup(5,1); 
	times=visual_identity_judge();
	if(times>4)
	{
		runActionGroup(25,1); 
		send_goods_back(x,y);
		runActionGroup(4,1); 
		times=visual_identity_judge();
		if(times>2)
		{
			runActionGroup(24,1); 
		send_goods_back(x,y);
		}
		runActionGroup(6,1); 
		times=visual_identity_judge();
		if(times>2)
		{
			runActionGroup(26,1);  
		send_goods_back(x,y);
		}
	}
		runActionGroup(0,1);
	
}

/*********************************************END OF FILE**********************/

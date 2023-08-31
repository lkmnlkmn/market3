/**
  ******************************************************************************
  * @file    bsp_dial.c
  * @author  林文豪（Vince）
  * @version V2.0
  * @date    2021-7-10
  * @brief   拨码器函数
  ******************************************************************************
  * @attention
  *
  * 实验平台:F103ZET6主控 裘老板画的底板  LSC-16舵机控制器 小幻熊K210模块
	* QQ      :850321718
  *
  ******************************************************************************
  */ 
	
#include "./LobotServoController/bsp_LobotServoController.h"
#include "./action/bsp_action.h"
#include "./dial/bsp_dial.h"
#include "./delay/bsp_delay.h"
#include <stdio.h>
#include "./path/bsp_path.h"
#include "./wondercam/bsp_wondercam.h"
int Dial_data[8];

/**
  * @brief 初始化设置
  * @param 无
  * @retval 无
  */

void DIAL_GPIO_Config(void)
{				
    /*定义一个GPIO_InitTypeDef类型的结构体*/
    GPIO_InitTypeDef  GPIO_InitStruct;

    /*开启循迹相关的GPIO外设时钟*/
    Trailing_B_GPIO_CLK_ENABLE();
    Trailing_D_GPIO_CLK_ENABLE();

    /*设置引脚的输出类型为上拉输入*/
    GPIO_InitStruct.Mode  = GPIO_MODE_INPUT; 
    /*设置引脚速率为高速 */   
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	
    /*初始化--拨码器--的GPIO引脚*/															   
    GPIO_InitStruct.Pin = DIAL_Pin_0;	
    HAL_GPIO_Init(DIAL_GPIO_Port_0, &GPIO_InitStruct);														   
    GPIO_InitStruct.Pin = DIAL_Pin_1;	
    HAL_GPIO_Init(DIAL_GPIO_Port_1, &GPIO_InitStruct);														   
    GPIO_InitStruct.Pin = DIAL_Pin_2;	
    HAL_GPIO_Init(DIAL_GPIO_Port_2, &GPIO_InitStruct);												   
    GPIO_InitStruct.Pin = DIAL_Pin_3;	
    HAL_GPIO_Init(DIAL_GPIO_Port_3, &GPIO_InitStruct);								   
    GPIO_InitStruct.Pin = DIAL_Pin_4;	
    HAL_GPIO_Init(DIAL_GPIO_Port_4, &GPIO_InitStruct);															   
    GPIO_InitStruct.Pin = DIAL_Pin_5;	
    HAL_GPIO_Init(DIAL_GPIO_Port_5, &GPIO_InitStruct);														   
    GPIO_InitStruct.Pin = DIAL_Pin_6;	
    HAL_GPIO_Init(DIAL_GPIO_Port_6, &GPIO_InitStruct);										
    GPIO_InitStruct.Pin = DIAL_Pin_7;	
    HAL_GPIO_Init(DIAL_GPIO_Port_7, &GPIO_InitStruct);

}

/**
  * @brief 储存红拨码器的数据到一个数组
  * @param huart: UART handle
  * @retval 无
  */

void scanf_dial_data()
{
		  Dial_data[0]=HAL_GPIO_ReadPin(DIAL_GPIO_Port_0,DIAL_Pin_0);
			Dial_data[1]=HAL_GPIO_ReadPin(DIAL_GPIO_Port_1,DIAL_Pin_1);
			Dial_data[2]=HAL_GPIO_ReadPin(DIAL_GPIO_Port_2,DIAL_Pin_2);
			Dial_data[3]=HAL_GPIO_ReadPin(DIAL_GPIO_Port_3,DIAL_Pin_3);
			Dial_data[4]=HAL_GPIO_ReadPin(DIAL_GPIO_Port_4,DIAL_Pin_4);
			Dial_data[5]=HAL_GPIO_ReadPin(DIAL_GPIO_Port_5,DIAL_Pin_5);
			Dial_data[6]=HAL_GPIO_ReadPin(DIAL_GPIO_Port_6,DIAL_Pin_6);
			Dial_data[7]=HAL_GPIO_ReadPin(DIAL_GPIO_Port_7,DIAL_Pin_7);
}

/**
  * @brief 扫描数据选择
  * @param 
  * @retval 无
  */
void path_chose(void)
{	
	int done=0;
	int done2=0;
	int i_path=0,c_path=1,i_chose=0;
			printf("\r\n拨码器start");
	while(i_path < c_path)
	{	
		i_chose=0;
			scanf_dial_data();
		
		for(int i=0;i<5;i++)
	{
    if(Dial_data[i]==0u)
			if(i!=2)
			i_chose++;
	}
//	printf("\r\n%d",i_chose);
	
	if(Dial_data[0]==0u&&i_chose==1&&done==0)
		{
	   	printf("\r\n拨码器1启用：路径1 ");
      for_delay();
		get_g_path_auto_shop();//取四周货架-自主路径版——购物车版
			printf("\r\ndone ");
			done++;
		}
	else if(Dial_data[1]==0u&&i_chose==1&&done==0)
		{
		printf("\r\n拨码器2启用：路径2");
			for_delay();
			 get_g_path_auto_shop_with_g_judge();//取四周货架-自主路径版——购物车版(货架对应)
						printf("\r\ndone ");
			done++;
		}
	else if(Dial_data[3]==0u&&i_chose==1&&done==0)
		{
				printf("\r\n拨码器4启用：路径3");
	    for_delay();
			get_g_path_auto_shop_with_move_count();//取四周货架-自主路径版——购物车版(夹取计数)
						printf("\r\ndone ");
			done++;
		}	
else if(Dial_data[4]==0u&&i_chose==1&&done==0)
		{
		 printf("\r\n拨码器5启用：路径4");
			for_delay();
		      get_g_path_auto_shop_mini();//取四周货架-自主路径版——购物车版-少四点
						printf("\r\ndone ");
			done++;

		}	
if(Dial_data[5]==0u&&done==0)
		{
			printf("\r\n拨码器6启用：路径5");
     get_g_path_auto_shop_restart();//取四周货架-自主路径版——购物车版-重启用
						printf("\r\ndone ");
			done++;
		}	
 if(Dial_data[6]==0u&&done2==0)
		{
 	printf("\r\n拨码器7启用：测试");
		//entire_run_test();
			catch_g_goods_judge();
			catch_g_goods_judge();
			done2++;
    }	
		 if(Dial_data[6]!=0u&&done2==1)
		{
 	printf("\r\n拨码器7启、复用：复位");
		//entire_run_test();
runActionGroup(0,1); 
			done2=0;
    }
		if(Dial_data[7]==0u)
		{
setLed(false);	
//			//	printf("\r\n拨码器扫描");
//		//	i_path++;
		}
		else
		{
setLed(true);	
//			//	printf("\r\n111111");
		}
		DelayMs(500);
}
}

/**
  * @brief dial扫描数据
  * @param 
  * @retval 无
  */
void debug_dial(void)
{	
	scanf_dial_data();
	
	printf("\r\n拨码器扫描：");
	for(int i = 0 ; i<8 ; i ++)
	{ 
	printf("%d",Dial_data[i]);
	}

DelayMs(1000);
}

/**
  * @brief dial扫描数据
  * @param 
  * @retval 无
  */
int debug_now(void)
{	
	int i_chose=0;
	scanf_dial_data();
		for(int i=0;i<9;i++)
	{
    if(Dial_data[i]!=0u)
			i_chose++;
	}
	if(i_chose==8) 
		return 1;
else
	return 0;
}

/**
  * @brief s顺手的一个延时
  * @param 
  * @retval 无
  */
int for_delay(void)
{	
		   DelayMs(10000);
			 DelayMs(10000);
			 DelayMs(10000);
			 DelayMs(10000);
			 DelayMs(10000);
			 DelayMs(10000);
			 DelayMs(10000);
			 DelayMs(10000);
			 DelayMs(10000);
			 DelayMs(10000);
			 DelayMs(10000);
			 DelayMs(10000);
			 DelayMs(10000);
			 DelayMs(10000);
			 DelayMs(10000);
}

/*********************************************END OF FILE**********************/

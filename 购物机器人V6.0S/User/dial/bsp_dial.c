/**
  ******************************************************************************
  * @file    bsp_dial.c
  * @author  ���ĺ���Vince��
  * @version V2.0
  * @date    2021-7-10
  * @brief   ����������
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:F103ZET6���� ���ϰ廭�ĵװ�  LSC-16��������� С����K210ģ��
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
  * @brief ��ʼ������
  * @param ��
  * @retval ��
  */

void DIAL_GPIO_Config(void)
{				
    /*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
    GPIO_InitTypeDef  GPIO_InitStruct;

    /*����ѭ����ص�GPIO����ʱ��*/
    Trailing_B_GPIO_CLK_ENABLE();
    Trailing_D_GPIO_CLK_ENABLE();

    /*�������ŵ��������Ϊ��������*/
    GPIO_InitStruct.Mode  = GPIO_MODE_INPUT; 
    /*������������Ϊ���� */   
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	
    /*��ʼ��--������--��GPIO����*/															   
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
  * @brief ����첦���������ݵ�һ������
  * @param huart: UART handle
  * @retval ��
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
  * @brief ɨ������ѡ��
  * @param 
  * @retval ��
  */
void path_chose(void)
{	
	int done=0;
	int done2=0;
	int i_path=0,c_path=1,i_chose=0;
			printf("\r\n������start");
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
	   	printf("\r\n������1���ã�·��1 ");
      for_delay();
		get_g_path_auto_shop();//ȡ���ܻ���-����·���桪�����ﳵ��
			printf("\r\ndone ");
			done++;
		}
	else if(Dial_data[1]==0u&&i_chose==1&&done==0)
		{
		printf("\r\n������2���ã�·��2");
			for_delay();
			 get_g_path_auto_shop_with_g_judge();//ȡ���ܻ���-����·���桪�����ﳵ��(���ܶ�Ӧ)
						printf("\r\ndone ");
			done++;
		}
	else if(Dial_data[3]==0u&&i_chose==1&&done==0)
		{
				printf("\r\n������4���ã�·��3");
	    for_delay();
			get_g_path_auto_shop_with_move_count();//ȡ���ܻ���-����·���桪�����ﳵ��(��ȡ����)
						printf("\r\ndone ");
			done++;
		}	
else if(Dial_data[4]==0u&&i_chose==1&&done==0)
		{
		 printf("\r\n������5���ã�·��4");
			for_delay();
		      get_g_path_auto_shop_mini();//ȡ���ܻ���-����·���桪�����ﳵ��-���ĵ�
						printf("\r\ndone ");
			done++;

		}	
if(Dial_data[5]==0u&&done==0)
		{
			printf("\r\n������6���ã�·��5");
     get_g_path_auto_shop_restart();//ȡ���ܻ���-����·���桪�����ﳵ��-������
						printf("\r\ndone ");
			done++;
		}	
 if(Dial_data[6]==0u&&done2==0)
		{
 	printf("\r\n������7���ã�����");
		//entire_run_test();
			catch_g_goods_judge();
			catch_g_goods_judge();
			done2++;
    }	
		 if(Dial_data[6]!=0u&&done2==1)
		{
 	printf("\r\n������7�������ã���λ");
		//entire_run_test();
runActionGroup(0,1); 
			done2=0;
    }
		if(Dial_data[7]==0u)
		{
setLed(false);	
//			//	printf("\r\n������ɨ��");
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
  * @brief dialɨ������
  * @param 
  * @retval ��
  */
void debug_dial(void)
{	
	scanf_dial_data();
	
	printf("\r\n������ɨ�裺");
	for(int i = 0 ; i<8 ; i ++)
	{ 
	printf("%d",Dial_data[i]);
	}

DelayMs(1000);
}

/**
  * @brief dialɨ������
  * @param 
  * @retval ��
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
  * @brief s˳�ֵ�һ����ʱ
  * @param 
  * @retval ��
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

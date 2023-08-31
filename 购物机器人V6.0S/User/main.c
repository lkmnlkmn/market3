/**
  ******************************************************************************
  * @file       main.c
  * @author     ���ĺ���Vince��
  * @version    V10.0
  * @date       2021-7-10
  * @brief      ���������V6.0S�������ļ������ձ����棩
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:F103ZET6���� ���ϰ廭�ĵװ�  LSC-16��������� С����K210ģ��
  * QQ      :850321718
  *
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include <stdlib.h>
#include "./usart2/bsp_usart.h"
#include "./motor_control\bsp_motor_control.h"
#include "./LobotServoController/bsp_LobotServoController.h"
#include "./usart/bsp_debug_usart.h"
#include "./tracers/bsp_tracers.h"
#include "./trailing/bsp_trailing.h"
#include "./wondercam/bsp_wondercam.h"
#include "./IIC/bsp_iic.h"
#include "./delay/bsp_delay.h"
#include "./vision/bsp_vision.h"
#include "./action/bsp_action.h"
#include "./delay/bsp_delay.h"
#include "./path/bsp_path.h"
#include "./dial/bsp_dial.h"
/**
  * @brief  ������
  * @param  ��
  * @retval ��
  */
int main(void) 
{
  /* HAL ���ʼ�� */
  HAL_Init();
	
	/* ��ʼ��ϵͳʱ��Ϊ72MHz */
	SystemClock_Config();

	//��ʼ����ʱ����
	InitDelay(72); 
	
	/* �������üĴ���ʱ�� */
	__HAL_RCC_SYSCFG_CLK_ENABLE();
	
	/* ��ʼ��GPIO */
	TRAILING_GPIO_Config();
	DIAL_GPIO_Config();
  /* ��ʼ������ */
  DEBUG_USART_Config();
	SERVO_USART_Config();
	
  /* �����ʼ�� */
  motor_init();
 
  //HAL_UART_MspInit(&UartHandle);
  //HAL_UART_MspInit(1);
  //runActionGroup(0, 1);
  //moveServo(0,1500,1000);
  //DelayMs(3000);
  //moveServo(0,2000,1000);
	
	//i2c��ʼ��
	IIC_Init();
			
  //�ж�����
  //HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_2);
  //�Ӿ�����ѡ��
	changeFunc(APPLICATION_CLASSIFICATION);
  //�Ӿ�ģ��led��
	setLed(true);
 
  /* ����ѭ��·������ */
  //go_straight_to_normal_position2(4,2);
  //go_to_certain_position(6,5);
  //go_to_certain_position(9,9);
  //go_to_certain_position(0,2);
 
  /* �Ӿ����� */

	//visual_identity_circle();
 // visual_identity();
 
  /* ���϶������� */
  //go_to_catch1(0,5);
  //go_to_catch2(0,5);
//	DelayMs(500);
//  runActionGroup(2, 1);
//	DelayMs(1500);
//  if (times>=3)
//	runActionGroup(27, 1);
//	printf("\r\n%d \r\n",times);
//  get_shop_run_test();

	  /* ���Բ��� */
//	runActionGroup(0, 1);
//	runActionGroup(28, 1);
//	runActionGroup(27, 1);
//	first_step();
//	get_shop_car();
//	go_to_catch_g_goods_judge(0,4);
//	go_to_catch_g_goods_judge(0,5);
//	go_to_catch_g_goods_judge(0,5);
//  runActionGroup(3,1);
//  DelayMs(200);
//	runActionGroup(2,1);
//	runActionGroup(22,1);
//	runActionGroup(1,1);
//	runActionGroup(21,1);
//	runActionGroup(3,1);
//	runActionGroup(23,1);
//	runActionGroup(5,1);
//	runActionGroup(25,1);
//	runActionGroup(4,1);
//	runActionGroup(24,1);
//	runActionGroup(6,1);
//	runActionGroup(26,1);
	//catch_g_goods_judge();
	
	/* ����·������ */
	
//	get_g_path_auto_shop();
//DelayMs(1000);
	//		runActionGroup(1, 1);
	
	/* ������� */

//	path_chose();
	//debug_dial();
	
	/* ���� */
	
	path_chose();
	
	
  /* ѭ������ */
while(1)
	{	
		

//		if(debug_now()==1)
//		path_chose();
	//debug_dial();
	//entire_run_test();
	//go_to_certain_position(0,2);
//  if (times>=3)
//	runActionGroup(0, 1);
	//	DelayMs(1000);
  	//Circle_Running(1);
    //debug_trailing();
  //  debug_running(2);
	//	go_straight(1000);
	//	motor_control_close_ahead();
	//	motor_control_away_back();
	//	motor_control_Gostraight_back();
		

//		runActionGroup(0, 1);
		//motor_control_Gostraight_ahead();
//		catch_g_goods_judge();
//		motor_control_Certain_Step_back(1);
//				catch_g_goods_judge();
//		motor_control_Certain_Step_back(1);
//				catch_g_goods_judge();
//		motor_control_Certain_Step_back(1);
//				catch_g_goods_judge();
//		motor_control_Certain_Step_back(1);
//				catch_g_goods_judge();
//		motor_control_Certain_Step_back(1);
//		catch_g_goods_judge();
//		runActionGroup(0, 1);
		//motor_control_Gostraight_back();
//	motor_control_Certain_Step_ahead(1);	
//	DelayMs(100);
//		motor_control_Certain_Step_ahead(2);
//		DelayMs(100);
	//  motor_control_Certain_Step_back(1);
//   motor_control_Right_correct(1);
//		DelayMs(100);
	//	motor_control_Left_correct(1);
  //	first_step();
   //DelayMs(1000);
	//  Usart_SendByte(2);
	//  DelayMs(1000);
  //  Usart_SendByte(2);
	}	
	
}


/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follow : 
  *            System Clock source            = PLL (HSE)
  *            SYSCLK(Hz)                     = 72000000
  *            HCLK(Hz)                       = 72000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 2
  *            APB2 Prescaler                 = 1
  *            HSE Frequency(Hz)              = 
8000000
  *            HSE PREDIV1                    = 2
  *            PLLMUL                         = 9
  *            Flash Latency(WS)              = 0
  * @param  None
  * @retval None
  */


void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef clkinitstruct = {0};
  RCC_OscInitTypeDef oscinitstruct = {0};
  
  /* Enable HSE Oscillator and activate PLL with HSE as source */
  oscinitstruct.OscillatorType  = RCC_OSCILLATORTYPE_HSE;
  oscinitstruct.HSEState        = RCC_HSE_ON;
  oscinitstruct.HSEPredivValue  = RCC_HSE_PREDIV_DIV1;
  oscinitstruct.PLL.PLLState    = RCC_PLL_ON;
  oscinitstruct.PLL.PLLSource   = RCC_PLLSOURCE_HSE;
  oscinitstruct.PLL.PLLMUL      = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&oscinitstruct)!= HAL_OK)
  {
    /* Initialization Error */
    while(1); 
  }

  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2 
     clocks dividers */
  clkinitstruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  clkinitstruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  clkinitstruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  clkinitstruct.APB2CLKDivider = RCC_HCLK_DIV1;
  clkinitstruct.APB1CLKDivider = RCC_HCLK_DIV2;  
  if (HAL_RCC_ClockConfig(&clkinitstruct, FLASH_LATENCY_2)!= HAL_OK)
  {
    /* Initialization Error */
    while(1); 
  }
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

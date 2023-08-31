/**
  ******************************************************************************
  * @file    GPIO/GPIO_EXTI/Src/stm32f3xx_it.c 
  * @author  MCD Application Team
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2017 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f1xx_it.h"
#include "./tim/bsp_motor_tim.h"
#include "./usart/bsp_debug_usart.h"
#include "./LobotServoController/bool.h"
#include "./LobotServoController/bsp_LobotServoController.h"
#include "./usart2/bsp_usart.h"
#include "stm32f1xx_hal_uart.h"

//��������ָ��
extern unsigned char UART_RxPtr;
unsigned short int  UART_RX_BUF[16];
unsigned short int  UART_TX_BUF[16];
bool isUartRxCompleted = false;
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M3 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief   This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
    HAL_IncTick();
}
  
/******************************************************************************/
/*                 STM32F7xx Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f7xx.s).                                               */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

/**
  * @brief  This function handles TIM interrupt request.
  * @param  None
  * @retval None
  */

// ����1�жϷ�����

void DEBUG_USART_IRQHandler(void)
{
  __IO uint8_t data;
  
  if(__HAL_UART_GET_IT_SOURCE(&Debug_UartHandle, UART_IT_RXNE) != RESET)
	{
    data = Debug_UartHandle.Instance->DR;
    
    //���Ϊ�˸��
    if(data == '\b')
    {
      //���ָ�벻������Ŀ�ʼλ��
      if(UART_RxPtr)
      {
        Usart_SendByte('\b');
        Usart_SendByte(' ');
        Usart_SendByte('\b');
        UART_RxPtr--;
        UART_RxBuffer[UART_RxPtr]=0x00;
      }
    }
    //��������˸��
    else
    {
      //��������������UART_RxBuffer
      //���ҽ������һ��Ԫ�������������������д�����һ��Ԫ��Ϊֹ
      if(UART_RxPtr < (UART_RX_BUFFER_SIZE - 1))
      {
        UART_RxBuffer[UART_RxPtr] = data;
        UART_RxBuffer[UART_RxPtr + 1]=0x00;
        UART_RxPtr++;
      }
      else
      {
        UART_RxBuffer[UART_RxPtr - 1] = data;
        Usart_SendByte('\b');
      }
      //���Ϊ�س�������ʼ����������
      if(data == 13 || data == 10)
      {
        receive_cmd = 1;
      }
      else
      {
        Usart_SendByte(data);
      }
    } 
    
    __HAL_UART_CLEAR_FLAG(&Debug_UartHandle, UART_IT_RXNE);
  }
  
//  HAL_UART_Receive_IT(&UartHandle, &data, sizeof(data));
  
  HAL_UART_IRQHandler(&Debug_UartHandle);
}

// ����2�жϷ�����
extern uint8_t LobotRxBuf[16];

void SERVO_USART_IRQHandler(void)
{
	uint8_t Res;
	static bool isGotFrameHeader = false;
	static uint8_t frameHeaderCount = 0;
	static uint8_t dataLength = 2;
	static uint8_t dataCount = 0;
	if (__HAL_UART_GET_IT_SOURCE(&Servo_UartHandle, UART_IT_RXNE) != RESET) 
	{ //�жϽ����ж�
		Res = Servo_UartHandle.Instance->DR;//(USART2->DR);	//ȡ�����ռĴ�������
//		printf("  %x||,",Res);
		if (!isGotFrameHeader) //�ж�֡ͷ
		{			
			if (Res == FRAME_HEADER) 
			{
				frameHeaderCount++;				
				if (frameHeaderCount == 2) 
				{
					frameHeaderCount = 0;
					isGotFrameHeader = true;
					dataCount = 1;
//					dataCount_Step=1;
				}
			} else //���ǿ�ͷ����
			  {
				isGotFrameHeader = false;
				dataCount = 0;
//				dataCount_Step= 0;
				frameHeaderCount = 0;
			  }
		}
		if (isGotFrameHeader) 
		{ //���ս������ݲ���
//			if(dataCount_Step % 2 == 0 )
//			{	
//				dataCount = dataCount_Step /2;
				UART_RX_BUF[dataCount] = Res;
//				printf("  %x  ,",UART_RX_BUF[dataCount]);
			if (dataCount == 2) 
				{
					dataLength = UART_RX_BUF[dataCount];
					if (dataLength < 2 || dataLength > 8) 
					{
						dataLength = 2;
						isGotFrameHeader = false;
					}
				}
				dataCount ++;
			
//			dataCount_Step++;
			if (dataCount == dataLength + 2) 
			{
				if (isUartRxCompleted == false) 
				{
					isUartRxCompleted = true;
					//memcpy(LobotRxBuf, UART_RX_BUF, dataCount);
						for(int i  = 1 ; i < 8;i ++)
						{
							printf("  %x  ,",UART_RX_BUF[i]);
						}
						printf("\r\n");
				}
				isGotFrameHeader = false;
			}
			
		}
	__HAL_UART_CLEAR_FLAG(&Servo_UartHandle, UART_IT_RXNE);
	
	}

	receiveHandle();
	HAL_UART_IRQHandler(&Servo_UartHandle);
}










/**
  * @}
  */ 

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

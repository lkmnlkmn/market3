#ifndef __BSP_DIAL_H
#define	__BSP_DIAL_H

#include "stm32f1xx.h"
#include ".\motor_control\bsp_motor_control.h"
#include "./usart/bsp_debug_usart.h"

//0~7 		XJ3_0~XJ3_7, 拨码器 初始化
//从左往右 0~7
#define DIAL_Pin_0  						GPIO_PIN_11
#define DIAL_GPIO_Port_0  	    GPIOD
#define DIAL_Pin_1  						GPIO_PIN_10
#define DIAL_GPIO_Port_1  	    GPIOD
#define DIAL_Pin_2  						GPIO_PIN_9
#define DIAL_GPIO_Port_2 	      GPIOD
#define DIAL_Pin_3 							GPIO_PIN_8
#define DIAL_GPIO_Port_3 	      GPIOD
#define DIAL_Pin_4 							GPIO_PIN_15
#define DIAL_GPIO_Port_4      	GPIOB
#define DIAL_Pin_5  						GPIO_PIN_14
#define DIAL_GPIO_Port_5  	    GPIOB
#define DIAL_Pin_6  						GPIO_PIN_13
#define DIAL_GPIO_Port_6      	GPIOB
#define DIAL_Pin_7 							GPIO_PIN_12
#define DIAL_GPIO_Port_7 	      GPIOB

//初始化GPIO的时钟
#define Trailing_B_GPIO_CLK_ENABLE()   __HAL_RCC_GPIOB_CLK_ENABLE()
#define Trailing_D_GPIO_CLK_ENABLE()   __HAL_RCC_GPIOD_CLK_ENABLE()

void scanf_dial_data(void);
void DIAL_GPIO_Config(void);
void path_chose(void);
void debug_dial(void);
int debug_now(void);
int for_delay(void);
#endif   /* __BSP_DIAL_H */

#ifndef __BSP_TRAILING_H
#define	__BSP_TRAILING_H

#include "stm32f1xx.h"
#include ".\motor_control\bsp_motor_control.h"
#include "./usart/bsp_debug_usart.h"

//0~7 		XJ1_0~XJ1_7, 头前(head)循迹模块 初始化
//从左往右 0~7
#define Tra_H_Pin_0  						GPIO_PIN_4
#define Tra_H_GPIO_Port_0  	    GPIOA
#define Tra_H_Pin_1  						GPIO_PIN_4
#define Tra_H_GPIO_Port_1  	    GPIOC
#define Tra_H_Pin_2  						GPIO_PIN_5
#define Tra_H_GPIO_Port_2 	      GPIOA
#define Tra_H_Pin_3 							GPIO_PIN_5
#define Tra_H_GPIO_Port_3 	      GPIOC
#define Tra_H_Pin_4 							GPIO_PIN_6
#define Tra_H_GPIO_Port_4      	GPIOA
#define Tra_H_Pin_5  						GPIO_PIN_0
#define Tra_H_GPIO_Port_5  	    GPIOB
#define Tra_H_Pin_6  						GPIO_PIN_7
#define Tra_H_GPIO_Port_6      	GPIOA
#define Tra_H_Pin_7 							GPIO_PIN_1
#define Tra_H_GPIO_Port_7 	      GPIOB

//8~15 		XJ5, 尾部(back)循迹模块	初始化
//从左往右 0~7
#define Tra_B_Pin_0  						GPIO_PIN_14
#define Tra_B_GPIO_Port_0  	    GPIOG
#define Tra_B_Pin_1  						GPIO_PIN_10
#define Tra_B_GPIO_Port_1  	    GPIOG
#define Tra_B_Pin_2  						GPIO_PIN_13
#define Tra_B_GPIO_Port_2 	     GPIOG
#define Tra_B_Pin_3 							GPIO_PIN_9
#define Tra_B_GPIO_Port_3 	      GPIOG
#define Tra_B_Pin_4 							GPIO_PIN_12
#define Tra_B_GPIO_Port_4      	GPIOG
#define Tra_B_Pin_5  						GPIO_PIN_7
#define Tra_B_GPIO_Port_5  	    GPIOD
#define Tra_B_Pin_6  						GPIO_PIN_11
#define Tra_B_GPIO_Port_6      	GPIOG
#define Tra_B_Pin_7							GPIO_PIN_6
#define Tra_B_GPIO_Port_7 	      GPIOD

// 			XJ4, 左侧(left)循迹模块	 初始化
// 靠近头方向为零
#define Tra_L_Pin_0  						GPIO_PIN_3
#define Tra_L_GPIO_Port_0  	    GPIOG
#define Tra_L_Pin_1  						GPIO_PIN_2
#define Tra_L_GPIO_Port_1  	    GPIOG
#define Tra_L_Pin_2  						GPIO_PIN_15
#define Tra_L_GPIO_Port_2 	     GPIOD
#define Tra_L_Pin_3 							GPIO_PIN_14
#define Tra_L_GPIO_Port_3 	      GPIOD
#define Tra_L_Pin_4 							GPIO_PIN_7
#define Tra_L_GPIO_Port_4      	GPIOG
#define Tra_L_Pin_5  						GPIO_PIN_6
#define Tra_L_GPIO_Port_5  	    GPIOG
#define Tra_L_Pin_6  						GPIO_PIN_5
#define Tra_L_GPIO_Port_6      	GPIOG
#define Tra_L_Pin_7							GPIO_PIN_4
#define Tra_L_GPIO_Port_7 	      GPIOG

// 			XJ2, 右侧(right)循迹模块	 初始化 
// 靠近头方向为零
#define Tra_R_Pin_0							GPIO_PIN_13
#define Tra_R_GPIO_Port_0 	      GPIOF
#define Tra_R_Pin_1  						GPIO_PIN_14
#define Tra_R_GPIO_Port_1      	GPIOF
#define Tra_R_Pin_2  			    	GPIO_PIN_15
#define Tra_R_GPIO_Port_2 	    GPIOF
#define Tra_R_Pin_3 						GPIO_PIN_0
#define Tra_R_GPIO_Port_3 	    GPIOG
#define Tra_R_Pin_4			    		GPIO_PIN_1
#define Tra_R_GPIO_Port_4 			GPIOG
#define Tra_R_Pin_5  						GPIO_PIN_7
#define Tra_R_GPIO_Port_5 	    GPIOE
#define Tra_R_Pin_6  						GPIO_PIN_11
#define Tra_R_GPIO_Port_6 			GPIOF
#define Tra_R_Pin_7							GPIO_PIN_12
#define Tra_R_GPIO_Port_7 			GPIOF

//初始化GPIO的时钟
#define Trailing_A_GPIO_CLK_ENABLE()   __HAL_RCC_GPIOA_CLK_ENABLE()
#define Trailing_B_GPIO_CLK_ENABLE()   __HAL_RCC_GPIOB_CLK_ENABLE()
#define Trailing_D_GPIO_CLK_ENABLE()   __HAL_RCC_GPIOD_CLK_ENABLE()
#define Trailing_E_GPIO_CLK_ENABLE()   __HAL_RCC_GPIOE_CLK_ENABLE()
#define Trailing_F_GPIO_CLK_ENABLE()   __HAL_RCC_GPIOF_CLK_ENABLE()
#define Trailing_G_GPIO_CLK_ENABLE()   __HAL_RCC_GPIOG_CLK_ENABLE()

void pid_motor_speed(int dir);
void pid_motor_speed_control(int dir,int v);
void TRAILING_GPIO_Config(void);
void scanf_trailing_data(void);
void scanf_head_trailing_data(void);
void debug_trailing(void);

void motor_control_close_ahead(void);
void motor_control_close_back(void);
void motor_control_away_back(void);

void motor_control_Certain_Step_ahead(int c_step);
void motor_control_Certain_Step_back(int c_step);

void motor_control_Gostraight_ahead(void);
void motor_control_Gostraight_back(void);

void motor_control_Gostraight_ahead_control(int speed);
void motor_control_Gostraight_back_control(int speed);
	
void motor_control_Left_correct(int circle);
void motor_control_Right_correct(int circle);
void first_step(void);
void first_step_with_car(void);

void go_back_home_dead(void);
#endif   /* __BSP_TRAILING_H */


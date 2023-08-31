#ifndef __BSP_MOTOR_CONTROL_H
#define	__BSP_MOTOR_CONTROL_H

#include "stm32f1xx.h"
#include "./tim/bsp_motor_tim.h"
#include "main.h"


/* 电机正反转控制脚 */
#define Motor1_FWD_PIN                  GPIO_PIN_6
#define Motor1_FWD_GPIO_PORT            GPIOC
#define Motor1_FWD_GPIO_CLK_ENABLE()    __HAL_RCC_GPIOC_CLK_ENABLE()

#define Motor1_REV_PIN                  GPIO_PIN_7
#define Motor1_REV_GPIO_PORT            GPIOC
#define Motor1_REV_GPIO_CLK_ENABLE()    __HAL_RCC_GPIOC_CLK_ENABLE()

#define Motor2_FWD_PIN                  GPIO_PIN_8
#define Motor2_FWD_GPIO_PORT            GPIOC
#define Motor2_FWD_GPIO_CLK_ENABLE()    __HAL_RCC_GPIOC_CLK_ENABLE()

#define Motor2_REV_PIN                  GPIO_PIN_9
#define Motor2_REV_GPIO_PORT            GPIOC
#define Motor2_REV_GPIO_CLK_ENABLE()    __HAL_RCC_GPIOC_CLK_ENABLE()

/** 控制电机正反转的宏，
	* 若motor低电平所接方向使能，设置ON=0，OFF=1
	* 若motor高电平所接方向使能，把宏设置成ON=1 ，OFF=0 即可
	* 这里的ON就是高电平、OFF就是低电平
	*/
#define ON  GPIO_PIN_RESET
#define OFF GPIO_PIN_SET

/* 带参宏，可以像内联函数一样使用， 控制电机的正反转*/
#define Motor1_FWD(a)	HAL_GPIO_WritePin(Motor1_FWD_GPIO_PORT,Motor1_FWD_PIN,a)

#define Motor1_REV(a)	HAL_GPIO_WritePin(Motor1_REV_GPIO_PORT,Motor1_REV_PIN,a)


#define Motor2_FWD(a)	HAL_GPIO_WritePin(Motor2_FWD_GPIO_PORT,Motor2_FWD_PIN,a)

#define Motor2_REV(a)	HAL_GPIO_WritePin(Motor2_REV_GPIO_PORT,Motor2_REV_PIN,a)


/* 电机方向控制枚举，FWD为0，REV为1 */
typedef enum
{
  MOTOR_FWD = 0,
  MOTOR_REV,
}motor_dir_t;

/* 设置速度（占空比） */
#define SET_MOTOR1_COMPAER(ChannelPulse)        TIM1_SetPWM_pulse(PWM_CHANNEL_1,ChannelPulse)    // 设置比较寄存器的值

/* 使能输出 */
#define MOTOR1_ENABLE()                         HAL_TIM_PWM_Start(&TIM_TimeBaseStructure,PWM_CHANNEL_1);    // 使能 PWM 通道 1

/* 禁用输出 */
#define MOTOR1_DISABLE()                        HAL_TIM_PWM_Stop(&TIM_TimeBaseStructure,PWM_CHANNEL_1);     // 禁用 PWM 通道 1

/* 设置速度（占空比）2 */
#define SET_MOTOR2_COMPAER(ChannelPulse)       TIM1_SetPWM2_pulse(PWM2_CHANNEL_1,ChannelPulse)    // 设置比较寄存器的值

/* 使能输出2 */
#define MOTOR2_ENABLE()                         HAL_TIM_PWM_Start(&TIM_TimeBaseStructure2,PWM2_CHANNEL_1);    // 使能 PWM2 通道 1

/* 禁用输出2 */
#define MOTOR2_DISABLE()                        HAL_TIM_PWM_Stop(&TIM_TimeBaseStructure2,PWM2_CHANNEL_1);     // 禁用 PWM2 通道 1

void motor_init(void);//电机初始化

//电机1的速度、转向、使能、失效控制
void set_motor1_speed(uint16_t v);
void set_motor1_direction(motor_dir_t dir);
void set_motor1_enable(void);
void set_motor1_disable(void);

//电机2的速度、转向、使能、失效控制
void set_motor2_speed(uint16_t v);
void set_motor2_direction(motor_dir_t dir);
void set_motor2_enable(void);
void set_motor2_disable(void);

//电机运行
void go_straight(unsigned int speed);
void go_back(unsigned int speed);
void left_turn(unsigned int speed);
void right_turn(unsigned int speed);
void stop(void);

#endif /* __BSP_MOTOR_CONTROL_H */


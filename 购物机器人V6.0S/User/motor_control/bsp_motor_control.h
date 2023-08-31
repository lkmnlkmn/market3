#ifndef __BSP_MOTOR_CONTROL_H
#define	__BSP_MOTOR_CONTROL_H

#include "stm32f1xx.h"
#include "./tim/bsp_motor_tim.h"
#include "main.h"


/* �������ת���ƽ� */
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

/** ���Ƶ������ת�ĺ꣬
	* ��motor�͵�ƽ���ӷ���ʹ�ܣ�����ON=0��OFF=1
	* ��motor�ߵ�ƽ���ӷ���ʹ�ܣ��Ѻ����ó�ON=1 ��OFF=0 ����
	* �����ON���Ǹߵ�ƽ��OFF���ǵ͵�ƽ
	*/
#define ON  GPIO_PIN_RESET
#define OFF GPIO_PIN_SET

/* ���κ꣬��������������һ��ʹ�ã� ���Ƶ��������ת*/
#define Motor1_FWD(a)	HAL_GPIO_WritePin(Motor1_FWD_GPIO_PORT,Motor1_FWD_PIN,a)

#define Motor1_REV(a)	HAL_GPIO_WritePin(Motor1_REV_GPIO_PORT,Motor1_REV_PIN,a)


#define Motor2_FWD(a)	HAL_GPIO_WritePin(Motor2_FWD_GPIO_PORT,Motor2_FWD_PIN,a)

#define Motor2_REV(a)	HAL_GPIO_WritePin(Motor2_REV_GPIO_PORT,Motor2_REV_PIN,a)


/* ����������ö�٣�FWDΪ0��REVΪ1 */
typedef enum
{
  MOTOR_FWD = 0,
  MOTOR_REV,
}motor_dir_t;

/* �����ٶȣ�ռ�ձȣ� */
#define SET_MOTOR1_COMPAER(ChannelPulse)        TIM1_SetPWM_pulse(PWM_CHANNEL_1,ChannelPulse)    // ���ñȽϼĴ�����ֵ

/* ʹ����� */
#define MOTOR1_ENABLE()                         HAL_TIM_PWM_Start(&TIM_TimeBaseStructure,PWM_CHANNEL_1);    // ʹ�� PWM ͨ�� 1

/* ������� */
#define MOTOR1_DISABLE()                        HAL_TIM_PWM_Stop(&TIM_TimeBaseStructure,PWM_CHANNEL_1);     // ���� PWM ͨ�� 1

/* �����ٶȣ�ռ�ձȣ�2 */
#define SET_MOTOR2_COMPAER(ChannelPulse)       TIM1_SetPWM2_pulse(PWM2_CHANNEL_1,ChannelPulse)    // ���ñȽϼĴ�����ֵ

/* ʹ�����2 */
#define MOTOR2_ENABLE()                         HAL_TIM_PWM_Start(&TIM_TimeBaseStructure2,PWM2_CHANNEL_1);    // ʹ�� PWM2 ͨ�� 1

/* �������2 */
#define MOTOR2_DISABLE()                        HAL_TIM_PWM_Stop(&TIM_TimeBaseStructure2,PWM2_CHANNEL_1);     // ���� PWM2 ͨ�� 1

void motor_init(void);//�����ʼ��

//���1���ٶȡ�ת��ʹ�ܡ�ʧЧ����
void set_motor1_speed(uint16_t v);
void set_motor1_direction(motor_dir_t dir);
void set_motor1_enable(void);
void set_motor1_disable(void);

//���2���ٶȡ�ת��ʹ�ܡ�ʧЧ����
void set_motor2_speed(uint16_t v);
void set_motor2_direction(motor_dir_t dir);
void set_motor2_enable(void);
void set_motor2_disable(void);

//�������
void go_straight(unsigned int speed);
void go_back(unsigned int speed);
void left_turn(unsigned int speed);
void right_turn(unsigned int speed);
void stop(void);

#endif /* __BSP_MOTOR_CONTROL_H */


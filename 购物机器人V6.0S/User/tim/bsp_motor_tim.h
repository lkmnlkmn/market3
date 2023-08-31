#ifndef __BSP_MOTOR_TIM_H
#define	__BSP_MOTOR_TIM_H

#include "stm32f1xx.h"

/* ��� 1 ��ض��� */
/*�궨��*/
#define PWM_TIM                        	TIM1
#define PWM_TIM_GPIO_AF_ENALBE()        __HAL_AFIO_REMAP_TIM1_ENABLE();
#define PWM_TIM_CLK_ENABLE()  					__HAL_RCC_TIM1_CLK_ENABLE()

#define PWM_CHANNEL_1                   TIM_CHANNEL_1
#define PWM_CHANNEL_2                   TIM_CHANNEL_2

/* �ۼ� TIM_Period�������һ�����»����ж�*/		
/* ����ʱ����0������PWM_PERIOD_COUNT����ΪPWM_PERIOD_COUNT+1�Σ�Ϊһ����ʱ���� */
#define PWM_PERIOD_COUNT     (3600)

/* ͨ�ÿ��ƶ�ʱ��ʱ��ԴTIMxCLK = HCLK=72MHz */
/* �趨��ʱ��Ƶ��Ϊ=TIMxCLK/(PWM_PRESCALER_COUNT+1) */
#define PWM_PRESCALER_COUNT     (2)

/* ���Ƚ�ֵ */
#define PWM_MAX_PERIOD_COUNT              (PWM_PERIOD_COUNT - 100)

/*PWM����*/
//TIM1 CH1 CH2�� ��ʱ��1Ϊ�߼���ʱ�������������·ռ�ձȲ�ͬ��PWM���Σ�����ֻ����PE9��PWM��������ҪPE11Ҳ�򿪣�����������
#define PWM_TIM_CH1_GPIO_CLK()             __HAL_RCC_GPIOE_CLK_ENABLE();
#define PWM_TIM_CH1_GPIO_PORT              GPIOE
#define PWM_TIM_CH1_PIN                    GPIO_PIN_9

#define PWM_TIM_CH2_GPIO_CLK()             __HAL_RCC_GPIOE_CLK_ENABLE();
#define PWM_TIM_CH2_GPIO_PORT              GPIOE
#define PWM_TIM_CH2_PIN                    GPIO_PIN_11

/* ��� 2 ��ض��� */
/*�궨��*/
#define PWM2_TIM                        TIM1
#define PWM2_TIM_GPIO_AF_ENALBE()        __HAL_AFIO_REMAP_TIM1_ENABLE();
#define PWM2_TIM_CLK_ENABLE()  					__HAL_RCC_TIM1_CLK_ENABLE()

#define PWM2_CHANNEL_1                   TIM_CHANNEL_3
#define PWM2_CHANNEL_2                   TIM_CHANNEL_4

/* �ۼ� TIM_Period�������һ�����»����ж�*/		
/* ����ʱ����0������PWM_PERIOD_COUNT����ΪPWM_PERIOD_COUNT+1�Σ�Ϊһ����ʱ���� */
#define PWM2_PERIOD_COUNT     (3600)

/* ͨ�ÿ��ƶ�ʱ��ʱ��ԴTIMxCLK = HCLK=72MHz */
/* �趨��ʱ��Ƶ��Ϊ=TIMxCLK/(PWM_PRESCALER_COUNT+1) */
#define PWM2_PRESCALER_COUNT     (2)

/* ���Ƚ�ֵ */
#define PWM2_MAX_PERIOD_COUNT              (PWM2_PERIOD_COUNT - 100)

/*PWM2����*/
//TIM1 CH3 CH4������ֻ����PE13��PWM��������ҪPE14Ҳ�򿪣�����������
#define PWM2_TIM_CH1_GPIO_CLK()          __HAL_RCC_GPIOE_CLK_ENABLE();
#define PWM2_TIM_CH1_GPIO_PORT           GPIOE
#define PWM2_TIM_CH1_PIN                 GPIO_PIN_13

#define PWM2_TIM_CH2_GPIO_CLK()          __HAL_RCC_GPIOE_CLK_ENABLE();
#define PWM2_TIM_CH2_GPIO_PORT           GPIOE
#define PWM2_TIM_CH2_PIN                 GPIO_PIN_14

/*ռ�ձ����ã�����Ĭ������Ϊ1800����50%��Ƶ��Ϊ3600��motorpulse/3600��Ϊռ�ձ�*/
#define motor1pulse 											1800
#define motor2pulse 											1800 


extern TIM_HandleTypeDef  TIM_TimeBaseStructure;
extern TIM_HandleTypeDef  TIM_TimeBaseStructure2;

extern void TIMx_Configuration(void);
extern void TIM1_SetPWM_pulse(uint32_t channel,int compare);
extern void TIMx_Configuration2(void);
extern void TIM1_SetPWM2_pulse(uint32_t channel,int compare);

#endif   /* __BSP_MOTOR_TIM_H */

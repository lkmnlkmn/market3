#ifndef __BSP_USART_H
#define	__BSP_USART_H

#include "stm32f1xx.h"
#include <stdio.h>

//串口接收缓冲数组大小
#define SERVOUART_RX_BUFFER_SIZE 256 

extern unsigned char SERVOUART_RxBuffer[SERVOUART_RX_BUFFER_SIZE];
extern uint8_t servoreceive_cmd;

//舵机串口2波特率
#define SERVO_USART_BAUDRATE                   9600

//引脚定义
/*******************************************************/
///*宏定义舵机串口2*/
#define SERVO_USART                            USART2
#define SERVO_USART_CLK_ENABLE()               __HAL_RCC_USART2_CLK_ENABLE();

#define RCC_PERIPHCLK_UART2                    RCC_PERIPHCLK_USART2
#define RCC_UART2CLKSOURCE_SYSCLK              RCC_USART2CLKSOURCE_SYSCLK

#define SERVO_USART_RX_GPIO_PORT               GPIOA
#define SERVO_USART_RX_GPIO_CLK_ENABLE()       __HAL_RCC_GPIOA_CLK_ENABLE()
#define SERVO_USART_RX_PIN                     GPIO_PIN_3

#define SERVO_USART_TX_GPIO_PORT               GPIOA
#define SERVO_USART_TX_GPIO_CLK_ENABLE()       __HAL_RCC_GPIOA_CLK_ENABLE()
#define SERVO_USART_TX_PIN                     GPIO_PIN_2

#define SERVO_USART_IRQHandler                 USART2_IRQHandler
#define SERVO_USART_IRQ                 		   USART2_IRQn

void servouart_FlushRxBuffer(void);
void Usart_SendByte(uint8_t str);
void Usart_SendString(uint8_t *str);
void SERVO_USART_Config(void);
void uartWriteBuf(uint8_t *buf, uint8_t len);
int fputc(int ch, FILE *f);
int fgetc(FILE *f);
extern UART_HandleTypeDef ServoUartHandle;
#endif /* __SERVO_USART_H */

#ifndef __DEBUG_USART_H
#define	__DEBUG_USART_H

#include "stm32f1xx.h"
#include <stdio.h>

//串口接收缓冲数组大小
#define UART_RX_BUFFER_SIZE 256 

extern unsigned char UART_RxBuffer[UART_RX_BUFFER_SIZE];
extern uint8_t receive_cmd;

//蓝牙串口1波特率
#define DEBUG_USART_BAUDRATE                    115200

//引脚定义
/*******************************************************/
/*宏定义蓝牙串口1*/
#define DEBUG_USART                             USART1
#define DEBUG_USART_CLK_ENABLE()                __HAL_RCC_USART1_CLK_ENABLE();

#define RCC_PERIPHCLK_UARTx                     RCC_PERIPHCLK_USART1
#define RCC_UARTxCLKSOURCE_SYSCLK               RCC_USART1CLKSOURCE_SYSCLK

#define DEBUG_USART_RX_GPIO_PORT                GPIOA
#define DEBUG_USART_RX_GPIO_CLK_ENABLE()        __HAL_RCC_GPIOA_CLK_ENABLE()
#define DEBUG_USART_RX_PIN                      GPIO_PIN_10

#define DEBUG_USART_TX_GPIO_PORT                GPIOA
#define DEBUG_USART_TX_GPIO_CLK_ENABLE()       __HAL_RCC_GPIOA_CLK_ENABLE()
#define DEBUG_USART_TX_PIN                      GPIO_PIN_9

#define DEBUG_USART_IRQHandler                  USART1_IRQHandler
#define DEBUG_USART_IRQ                 		    USART1_IRQn

/*宏定义舵机串口2*/
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

/************************************************************/

void uart_FlushRxBuffer(void);
void Usart_SendByte(uint8_t str);
void Usart_SendString(uint8_t *str);
void DEBUG_USART_Config(void);
int fputc(int ch, FILE *f);
int fgetc(FILE *f);
extern UART_HandleTypeDef Debug_UartHandle;
extern UART_HandleTypeDef Servo_UartHandle;
#endif /* __DEBUG_USART_H */

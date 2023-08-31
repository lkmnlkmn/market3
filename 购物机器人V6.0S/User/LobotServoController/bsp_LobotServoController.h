#ifndef __BSP_LOBOTSERVOCONTROLLER_H_
#define __BSP_LOBOTSERVOCONTROLLER_H_

#include "stm32f1xx.h"
#include "./LobotServoController/bool.h"
#include "./usart2/bsp_usart.h"

#define FRAME_HEADER 0x55             //֡ͷ
#define CMD_SERVO_MOVE 0x03           //����ƶ�ָ��
#define CMD_ACTION_GROUP_RUN 0x06     //���ж�����ָ��
#define CMD_ACTION_GROUP_STOP 0x07    //ֹͣ������ָ��
#define CMD_ACTION_GROUP_COMPLETE 0x08 //��Ȼ������ָֹͣ��
#define CMD_ACTION_GROUP_SPEED 0x0B   //���ö����������ٶ�
#define CMD_GET_BATTERY_VOLTAGE 0x0F  //��ȡ��ص�ѹָ��

#define CMD_REGISTER_POSITION  6

extern bool isUartRxCompleted;
extern uint8_t LobotRxBuf[16];
extern uint8_t LobotTxBuf_SALVE[16];
extern uint16_t batteryVolt;
extern void receiveHandle(void);

typedef struct _lobot_servo_ {  //���ID,���Ŀ��λ��
	uint8_t ID;
	uint16_t Position;
} LobotServo;


void moveServo(uint8_t servoID, uint16_t Position, uint16_t Time);
void moveServosByArray(LobotServo servos[], uint8_t Num, uint16_t Time);
void moveServos(uint8_t Num, uint16_t Time, ...);
void runActionGroup(uint8_t numOfAction, uint16_t Times);
void stopActionGroup(void);
void setActionGroupSpeed(uint8_t numOfAction, uint16_t Speed);
void setAllActionGroupSpeed(uint16_t Speed);
void getBatteryVoltage(void);


#endif



#ifndef __IIC_H
#define __IIC_H

//*****���ģ��IIC��
//*****�޸ĺ궨�弴��
//*****��ͬоƬʱע��ʱ�Ӻ���ʱ����
#define    IIC_IO_SDA      GPIO_Pin_12  //SDA��IO��
#define    IIC_IO_SCL      GPIO_Pin_1  //SCL��IO��
#define    GPIOX           GPIOB       //GPIOxѡ��
#define    CLOCK		   RCC_APB2Periph_GPIOB //ʱ���ź�
 
#define    IIC_SCL         PBout(1) //SCL
#define    IIC_SDA         PBout(12) //���SDA
#define    READ_SDA        PBin(12)  //����SDA


void I2C_SDA_OUT(void);
void I2C_SDA_IN(void);
void IIC_init(void);
void IIC_start(void);
void IIC_stop(void);
void IIC_ack(void);
void IIC_noack(void);
u8 IIC_wait_ack(void);
void IIC_send_byte(u8 txd);
u8 IIC_read_byte(u8 ack);
#endif

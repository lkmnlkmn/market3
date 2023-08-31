/**
  ******************************************************************************
  * @file    bsp_vision.c
  * @author  ���ĺ���Vince��
  * @version V4.0
  * @date    2021-7-10
  * @brief   �Ӿ����ƺ���
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:F103ZET6���� ���ϰ廭�ĵװ�  LSC-16��������� С����K210ģ��
	* QQ      :850321718
  *
  ******************************************************************************
  */ 

#include <stdio.h>
#include "./IIC/bsp_iic.h"
#include "./delay/bsp_delay.h"
#include "./wondercam/bsp_wondercam.h"
#include "./vision/bsp_vision.h"
#include "./tracers/bsp_tracers.h"

/**
  * @brief  �Ӿ�ʶ��ִ��8��
  * @param  ��
  * @retval �������������
  */
int visual_identity(void)
{
	DelayMs(100);
	int times=0;
	int back=0;
	int place=get_position();
  int goods[13] ={0};//0-12����Ϊ��ɫ����ѩ��ơ��1�������գ���ţ��ѩ��ơ��2����ɫ���飬��ɫ���飬ħ�����޹�����ѩ��ơ��3��ѩ��ơ��4��ѩ��ơ��5
	//	int redblock=0,blueblock=0,bear1=0,bear2=0,redbull=0,ball=0,ad=0,milk=0,magiccube=0;
	for(int i=0;i<8;i++)//������
	{	
  updateResult(); 
  int class_id =classIdOfMaxProb();
  float prob = classMaxProb();
	//printf("\r\n%d %f\r\n",class_id,prob);
  if (prob > 0.81) {
    if (class_id < 2) {
      //printf("��\r\n");
			back++;
    } else if (class_id == 2) {
        //printf("��ɫ����\r\n");
			goods[0]++;
    } else if (class_id == 3) {
			goods[1]++;
        //printf("ѩ��ơ��1\r\n");
    } else if (class_id == 4) {
			goods[2]++;
       // printf("������\r\n");
    } else if (class_id == 5
		) {
			goods[3]++;
      //  printf("��ţ\r\n");
    } else if (class_id == 6) {
			goods[4]++;
      //  printf("ѩ��ơ��2\r\n");
    } else if (class_id == 7) {
			goods[5]++;
       // printf("��ɫ����\r\n");
    } else if (class_id == 8) {
			goods[6]++;
       // printf("��ɫ����\r\n");
    } else if (class_id == 9) {
			goods[7]++;
      //  printf("ħ��\r\n");
    } else if (class_id == 10){
			goods[8]++;
       // printf("�޹���\r\n");
    }else if (class_id == 11) {
			goods[9]++;
      //  printf("ѩ��ơ��3\r\n");
    } else if (class_id == 12) {
			goods[10]++;
      //  printf("ѩ��ơ��4\r\n");
    } else if (class_id == 13) {
			goods[11]++;
      //  printf("ѩ��ơ��5\r\n");
    } 
  }
  DelayMs(50);
  }
	if(place==1)
		goods[2]=0;
	if(place==1)
		goods[9]=0;
	for(int i=0;i<13;i++)
	{
    if(goods[i]>times)
			times=goods[i];
	}
	
		//printf("\r\n%d \r\n",times);
	return times;

}

/**
  * @brief  �Ӿ�ʶ��ִ��8��,�ж�Ӧ���ܽ���
  * @param  ��
  * @retval �������������
  */
int visual_identity_judge(void)
{
	DelayMs(100);
	int times=0;
	int back=0;
		int place=get_position();
  int goods[13] ={0};//0-12����Ϊ��ɫ����ѩ��ơ��1�������գ���ţ��ѩ��ơ��2����ɫ���飬��ɫ���飬ħ�����޹�����ѩ��ơ��3��ѩ��ơ��4��ѩ��ơ��5
	//	int redblock=0,blueblock=0,bear1=0,bear2=0,redbull=0,ball=0,ad=0,milk=0,magiccube=0;
	for(int i=0;i<8;i++)//������
	{	
  updateResult(); 
  int class_id =classIdOfMaxProb();
  float prob = classMaxProb();
	//printf("\r\n%d %f\r\n",class_id,prob);
  if (prob > 0.82) {
    if (class_id < 2 ) {
      //printf("��\r\n");
			back++;
    } else if (class_id == 2&& place ==1) {
        //printf("��ɫ����\r\n");
			goods[0]++;
    } else if (class_id == 3&& place ==1) {
			goods[1]++;
        //printf("ѩ��ơ��1\r\n");
    } else if (class_id == 4&& place ==3) {
			goods[2]++;
       // printf("������\r\n");
    } else if (class_id == 5&& place ==1
		) {
			goods[3]++;
      //  printf("��ţ\r\n");
    } else if (class_id == 6&& place ==1) {
			goods[4]++;
      //  printf("ѩ��ơ��2\r\n");
    } else if (class_id == 7&& place ==2) {
			goods[5]++;
       // printf("��ɫ����\r\n");
    } else if (class_id == 8&& place ==2) {
			goods[6]++;
       // printf("��ɫ����\r\n");
    } else if (class_id == 9&& place ==2) {
			goods[7]++;
      //  printf("ħ��\r\n");
    } else if (class_id == 10&& place ==3){
			goods[8]++;
       // printf("�޹���\r\n");
    }else if (class_id == 11&& place ==1) {
			goods[9]++;
      //  printf("ѩ��ơ��3\r\n");
    } else if (class_id == 12&& place ==1) {
			goods[10]++;
      //  printf("ѩ��ơ��4\r\n");
    } else if (class_id == 13&& place ==1) {
			goods[11]++;
      //  printf("ѩ��ơ��5\r\n");
    } 
  }
  DelayMs(100);
  }
	
	for(int i=0;i<13;i++)
	{
    if(goods[i]>times)
			times=goods[i];
	}
	
		//printf("\r\n%d \r\n",times);
	return times;

}

/**
  * @brief  ѭ���Ӿ�ʶ��
  * @param  ��
  * @retval ��
  */
void visual_identity_circle(void)
{
	while(1)
	{	
  updateResult(); 
  int class_id =classIdOfMaxProb();
  float prob = classMaxProb();
	printf("\r\n%d %f\r\n",class_id,prob);
  if (prob > 0.7) {
    if (class_id < 2) {
      printf("��\r\n");
    } else if (class_id == 2) {
        printf("��ɫ����\r\n");
    } else if (class_id == 4) {
        printf("ѩ��ơ��1\r\n");
    } else if (class_id == 5) {
        printf("������\r\n");
    } else if (class_id == 10) {
        printf("��ţ\r\n");
    } else if (class_id == 6) {
        printf("ѩ��ơ��2\r\n");
    } else if (class_id == 7) {
        printf("��ɫ����\r\n");
    } else if (class_id == 8) {
        printf("ħ��\r\n");
    } else if (class_id == 9) {
        printf("������\r\n");
    } else {
        printf("�޹���\r\n");
    }
  }
  DelayMs(10000);
  }
}

/*********************************************END OF FILE**********************/

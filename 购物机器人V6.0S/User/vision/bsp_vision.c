/**
  ******************************************************************************
  * @file    bsp_vision.c
  * @author  林文豪（Vince）
  * @version V4.0
  * @date    2021-7-10
  * @brief   视觉控制函数
  ******************************************************************************
  * @attention
  *
  * 实验平台:F103ZET6主控 裘老板画的底板  LSC-16舵机控制器 小幻熊K210模块
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
  * @brief  视觉识别执行8次
  * @param  无
  * @retval 输出最高相符次数
  */
int visual_identity(void)
{
	DelayMs(100);
	int times=0;
	int back=0;
	int place=get_position();
  int goods[13] ={0};//0-12依次为黄色网球，雪花啤酒1，特仑苏，红牛，雪花啤酒2，红色方块，蓝色方块，魔方，娃哈哈，雪花啤酒3，雪花啤酒4，雪花啤酒5
	//	int redblock=0,blueblock=0,bear1=0,bear2=0,redbull=0,ball=0,ad=0,milk=0,magiccube=0;
	for(int i=0;i<8;i++)//检测次数
	{	
  updateResult(); 
  int class_id =classIdOfMaxProb();
  float prob = classMaxProb();
	//printf("\r\n%d %f\r\n",class_id,prob);
  if (prob > 0.81) {
    if (class_id < 2) {
      //printf("无\r\n");
			back++;
    } else if (class_id == 2) {
        //printf("黄色网球\r\n");
			goods[0]++;
    } else if (class_id == 3) {
			goods[1]++;
        //printf("雪花啤酒1\r\n");
    } else if (class_id == 4) {
			goods[2]++;
       // printf("特仑苏\r\n");
    } else if (class_id == 5
		) {
			goods[3]++;
      //  printf("红牛\r\n");
    } else if (class_id == 6) {
			goods[4]++;
      //  printf("雪花啤酒2\r\n");
    } else if (class_id == 7) {
			goods[5]++;
       // printf("红色方块\r\n");
    } else if (class_id == 8) {
			goods[6]++;
       // printf("蓝色方块\r\n");
    } else if (class_id == 9) {
			goods[7]++;
      //  printf("魔方\r\n");
    } else if (class_id == 10){
			goods[8]++;
       // printf("娃哈哈\r\n");
    }else if (class_id == 11) {
			goods[9]++;
      //  printf("雪花啤酒3\r\n");
    } else if (class_id == 12) {
			goods[10]++;
      //  printf("雪花啤酒4\r\n");
    } else if (class_id == 13) {
			goods[11]++;
      //  printf("雪花啤酒5\r\n");
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
  * @brief  视觉识别执行8次,有对应货架矫正
  * @param  无
  * @retval 输出最高相符次数
  */
int visual_identity_judge(void)
{
	DelayMs(100);
	int times=0;
	int back=0;
		int place=get_position();
  int goods[13] ={0};//0-12依次为黄色网球，雪花啤酒1，特仑苏，红牛，雪花啤酒2，红色方块，蓝色方块，魔方，娃哈哈，雪花啤酒3，雪花啤酒4，雪花啤酒5
	//	int redblock=0,blueblock=0,bear1=0,bear2=0,redbull=0,ball=0,ad=0,milk=0,magiccube=0;
	for(int i=0;i<8;i++)//检测次数
	{	
  updateResult(); 
  int class_id =classIdOfMaxProb();
  float prob = classMaxProb();
	//printf("\r\n%d %f\r\n",class_id,prob);
  if (prob > 0.82) {
    if (class_id < 2 ) {
      //printf("无\r\n");
			back++;
    } else if (class_id == 2&& place ==1) {
        //printf("黄色网球\r\n");
			goods[0]++;
    } else if (class_id == 3&& place ==1) {
			goods[1]++;
        //printf("雪花啤酒1\r\n");
    } else if (class_id == 4&& place ==3) {
			goods[2]++;
       // printf("特仑苏\r\n");
    } else if (class_id == 5&& place ==1
		) {
			goods[3]++;
      //  printf("红牛\r\n");
    } else if (class_id == 6&& place ==1) {
			goods[4]++;
      //  printf("雪花啤酒2\r\n");
    } else if (class_id == 7&& place ==2) {
			goods[5]++;
       // printf("红色方块\r\n");
    } else if (class_id == 8&& place ==2) {
			goods[6]++;
       // printf("蓝色方块\r\n");
    } else if (class_id == 9&& place ==2) {
			goods[7]++;
      //  printf("魔方\r\n");
    } else if (class_id == 10&& place ==3){
			goods[8]++;
       // printf("娃哈哈\r\n");
    }else if (class_id == 11&& place ==1) {
			goods[9]++;
      //  printf("雪花啤酒3\r\n");
    } else if (class_id == 12&& place ==1) {
			goods[10]++;
      //  printf("雪花啤酒4\r\n");
    } else if (class_id == 13&& place ==1) {
			goods[11]++;
      //  printf("雪花啤酒5\r\n");
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
  * @brief  循环视觉识别
  * @param  无
  * @retval 无
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
      printf("无\r\n");
    } else if (class_id == 2) {
        printf("黄色网球\r\n");
    } else if (class_id == 4) {
        printf("雪花啤酒1\r\n");
    } else if (class_id == 5) {
        printf("特仑苏\r\n");
    } else if (class_id == 10) {
        printf("红牛\r\n");
    } else if (class_id == 6) {
        printf("雪花啤酒2\r\n");
    } else if (class_id == 7) {
        printf("红色方块\r\n");
    } else if (class_id == 8) {
        printf("魔方\r\n");
    } else if (class_id == 9) {
        printf("特仑苏\r\n");
    } else {
        printf("娃哈哈\r\n");
    }
  }
  DelayMs(10000);
  }
}

/*********************************************END OF FILE**********************/

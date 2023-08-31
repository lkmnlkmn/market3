#include "include.h"


/******************************************************
//	Company:深圳幻尔科技有限公司										   //	
//	我们的店铺:lobot-zone.taobao.com                  //
//	我们的官网：www.lobot-robot.com                   //
******************************************************/

uint8_t obj_names[20][16] = {
  "Aeroplane",
  "Bicycle",
  "Bird",
  "Boat",
  "Bottle",
  "Bus",
  "Car",
  "Cat",
  "Chair",
  "Cow",
  "Diningtable",
  "Dog",
  "Horse",
  "Motorbike",
  "Person",
  "Pottedplant",
  "Sheep",
  "Sofa",
  "Train",
  "Monitor"
};


int main(void)
{
uint8_t x;
	SystemInit(); 		//系统时钟初始化为72M	  SYSCLK_FREQ_72MHz
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	//设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	InitDelay(72); 		//初始化延时函数
	IIC_init();		//IIC初始化
	DelayMs(100);
	Usart1_Init(); //串口初始化
	DelayMs(1000);
	printf(" ");
	printf("start\r\n");
	changeFunc(APPLICATION_CLASSIFICATION);
	setLed(true);
	while(1)
	{
  updateResult();
  int class_id = classIdOfMaxProb();
  float prob = classMaxProb();
  if (prob > 0.4) {
    if (class_id < 2) {
      printf("None\r\n");
    } else if (class_id < 5) {
        printf("Harmful Waste\r\n");
    } else if (class_id < 8) {
        printf("Recyclable waste\r\n");
    } else if (class_id < 11) {
        printf("Wet garbage\r\n");
    } else {
        printf("Dry garbage\r\n");
    }
  }
  DelayMs(100);
  }
}
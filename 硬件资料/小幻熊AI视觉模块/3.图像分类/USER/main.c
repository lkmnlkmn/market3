#include "include.h"


/******************************************************
//	Company:���ڻö��Ƽ����޹�˾										   //	
//	���ǵĵ���:lobot-zone.taobao.com                  //
//	���ǵĹ�����www.lobot-robot.com                   //
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
	SystemInit(); 		//ϵͳʱ�ӳ�ʼ��Ϊ72M	  SYSCLK_FREQ_72MHz
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	//����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	InitDelay(72); 		//��ʼ����ʱ����
	IIC_init();		//IIC��ʼ��
	DelayMs(100);
	Usart1_Init(); //���ڳ�ʼ��
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
/**
  ******************************************************************************
  * @file    bsp_path.c
  * @author  ���ĺ���Vince��
  * @version V4.0
  * @date    2021-7-10
  * @brief   ������·���滮
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:F103ZET6���� ���ϰ廭�ĵװ�  LSC-16��������� С����K210ģ�� 
	* QQ      :850321718
  *
  ******************************************************************************
  */ 

#include <stdio.h>
#include <math.h>
#include "./usart2/bsp_usart.h"
#include "./motor_control\bsp_motor_control.h"
#include "./LobotServoController/bsp_LobotServoController.h"
#include "./usart/bsp_debug_usart.h"
#include "./tracers/bsp_tracers.h"
#include "./trailing/bsp_trailing.h"
#include "./wondercam/bsp_wondercam.h"
#include "./IIC/bsp_iic.h"
#include "./delay/bsp_delay.h"
#include "./action/bsp_action.h"
#include "./vision/bsp_vision.h"
#include "./delay/bsp_delay.h"
#include "./path/bsp_path.h"
#include "./dial/bsp_dial.h"

/**
  * @brief  �����ܲ���
  * @param  ��
  * @retval ��
  */
void entire_run_test(void)
{
//			catch_g_goods_judge();
//		motor_control_Certain_Step_ahead(1);
//  	catch_g_goods_judge();
//	
//		motor_control_Certain_Step_back(1);
	

	first_step_with_car();
	//ȡ˳ʱ���һ������	
	  go_to_catch_g_goods_judge(0,4);
		go_to_catch_g_goods_judge(0,5);
		go_to_catch_g_goods_judge(0,6);
		go_to_catch_g_goods_judge(0,7);
		go_to_catch_g_goods_judge(0,8);	
		go_to_catch_g_goods_judge(0,9);
		//ȡ˳ʱ��ڶ�������
		go_to_catch_g_goods_judge(4,9);
		go_to_catch_g_goods_judge(5,9);
		go_to_catch_g_goods_judge(6,9);
		go_to_catch_g_goods_judge(7,9);
		go_to_catch_g_goods_judge(8,9);
		go_to_catch_g_goods_judge(9,9);
		//ȡ˳ʱ�����������
	  go_to_catch_g_goods_judge(9,5);
		go_to_catch_g_goods_judge(9,4);
		go_to_catch_g_goods_judge(9,3);
		go_to_catch_g_goods_judge(9,2);
		go_to_catch_g_goods_judge(9,1);	
		go_to_catch_g_goods_judge(9,0);
		//ȡ˳ʱ����ĸ�����
		go_to_catch_g_goods_judge(5,0);
		go_to_catch_g_goods_judge(4,0);
		go_to_catch_g_goods_judge(3,0);
		go_to_catch_g_goods_judge(2,0);
		go_to_catch_g_goods_judge(1,0);
		go_to_catch_g_goods_judge(0,0);	

 		
//	  runActionGroup(0, 1);
//	 	runActionGroup(28, 1);
////	  runActionGroup(27, 1);
//	 first_step_with_car();
//	
//		motor_control_Certain_Step_ahead(1);	
//		catch_g_goods_judge();
//		motor_control_Certain_Step_ahead(1);		
//		catch_g_goods_judge();
//		motor_control_Certain_Step_ahead(1);		
//		catch_g_goods_judge();
//		motor_control_Certain_Step_ahead(1);		
//		catch_g_goods_judge();
//		motor_control_Certain_Step_ahead(1);		

//				catch_g_goods_judge();
//		motor_control_Certain_Step_back(1);
//				catch_g_goods_judge();
//		motor_control_Certain_Step_back(1);
//				catch_g_goods_judge();
//		motor_control_Certain_Step_back(1);
//				catch_g_goods_judge();
//		motor_control_Certain_Step_back(1);
//		catch_g_goods_judge();
		
//	go_to_catch_g_goods_judge(0,6);
//	go_to_catch_g_goods_judge(0,7);
//	go_to_catch_g_goods_judge(0,8);
//	go_to_catch_g_goods_judge(0,9);
	
//		go_to_certain_position_test_edition(4,9);
//		DelayMs(100);
// runActionGroup(2, 1);
//			DelayMs(1000);
//int times=visual_identity();
// if (times>=3)
//	runActionGroup(22, 1);
// runActionGroup(0, 1);
// 		go_to_certain_position_test_edition(7,9);
//  runActionGroup(2, 1);
//			DelayMs(1000);
// times=visual_identity();
// if (times>=3)
//	runActionGroup(22, 1);
// runActionGroup(0, 1);
// 		go_to_certain_position_test_edition(9,4);
//  runActionGroup(2, 1);
//			DelayMs(1000);
// times=visual_identity();
// if (times>=3)
//	runActionGroup(22, 1);
// runActionGroup(0, 1);
//  		go_to_certain_position_test_edition(3,0);
//  runActionGroup(2, 1);
//			DelayMs(1000);
// times=visual_identity();
// if (times>=3)
//	runActionGroup(22, 1);
// runActionGroup(0, 1);
//   		go_to_certain_position_test_edition(0,2);
//DelayMs(1500);
}


/*********************************************edition for competition**********************/
/**
  * @brief  1  ȡ���ܻ���-����·���桪�����ﳵ��
  * @param  ��
  * @retval ��
  */
void get_g_path_auto_shop(void)
{
			   	printf("\r\n·��1 ");
		first_step_with_car();
	//ȡ˳ʱ���һ������	
	  go_to_catch_g_goods_judge(0,4);
		go_to_catch_g_goods_judge(0,5);
		go_to_catch_g_goods_judge(0,6);
		go_to_catch_g_goods_judge(0,7);
		go_to_catch_g_goods_judge(0,8);	
		go_to_catch_g_goods_judge(0,9);
		//ȡ˳ʱ��ڶ�������
		go_to_catch_g_goods_judge(4,9);
		go_to_catch_g_goods_judge(5,9);
		go_to_catch_g_goods_judge(6,9);
		go_to_catch_g_goods_judge(7,9);
		go_to_catch_g_goods_judge(8,9);
		go_to_catch_g_goods_judge(9,9);
		//ȡ˳ʱ�����������
	  go_to_catch_g_goods_judge(9,5);
		go_to_catch_g_goods_judge(9,4);
		go_to_catch_g_goods_judge(9,3);
		go_to_catch_g_goods_judge(9,2);
		go_to_catch_g_goods_judge(9,1);	
		go_to_catch_g_goods_judge(9,0);
		//ȡ˳ʱ����ĸ�����
		go_to_catch_g_goods_judge(5,0);
		go_to_catch_g_goods_judge(4,0);
		go_to_catch_g_goods_judge(3,0);
		go_to_catch_g_goods_judge(2,0);
		go_to_catch_g_goods_judge(1,0);
		go_to_catch_g_goods_judge(0,0);	
		
			//			go_back_home_dead();
		//go_back_home_back();
}

/**
  * @brief  2  ȡ���ܻ���-����·���桪�����ﳵ��(�Ӿ����ܶ�Ӧ)
  * @param  ��
  * @retval ��
  */
void get_g_path_auto_shop_with_g_judge(void)
{
			   	printf("\r\n·��2 ");
		first_step_with_car();
	//ȡ˳ʱ���һ������	
	  go_to_catch_g_goods_vison_judge(0,4);
		go_to_catch_g_goods_vison_judge(0,5);
		go_to_catch_g_goods_vison_judge(0,6);
		go_to_catch_g_goods_vison_judge(0,7);
		go_to_catch_g_goods_vison_judge(0,8);	
		go_to_catch_g_goods_vison_judge(0,9);
		//ȡ˳ʱ��ڶ�������
		go_to_catch_g_goods_vison_judge(4,9);
		go_to_catch_g_goods_vison_judge(5,9);
		go_to_catch_g_goods_vison_judge(6,9);
		go_to_catch_g_goods_vison_judge(7,9);
		go_to_catch_g_goods_vison_judge(8,9);
		go_to_catch_g_goods_vison_judge(9,9);
		//ȡ˳ʱ�����������
	  go_to_catch_g_goods_vison_judge(9,5);
		go_to_catch_g_goods_vison_judge(9,4);
		go_to_catch_g_goods_vison_judge(9,3);
		go_to_catch_g_goods_vison_judge(9,2);
		go_to_catch_g_goods_vison_judge(9,1);	
		go_to_catch_g_goods_vison_judge(9,0);
		//ȡ˳ʱ����ĸ�����
		go_to_catch_g_goods_vison_judge(5,0);
		go_to_catch_g_goods_vison_judge(4,0);
		go_to_catch_g_goods_vison_judge(3,0);
		go_to_catch_g_goods_vison_judge(2,0);
		go_to_catch_g_goods_vison_judge(1,0);
		go_to_catch_g_goods_vison_judge(0,0);	
		
			//			go_back_home_dead();
		//go_back_home_back();
}

/**
  * @brief  3  ȡ���ܻ���-����·���桪�����ﳵ��(��ȡ����)
  * @param  ��
  * @retval ��
  */
void get_g_path_auto_shop_with_move_count(void)
{
	printf("\r\n·��3 ");
		first_step_with_car();
int times=0,stop=0;
	//ȡ˳ʱ���һ������	
for(int i=0;i<6;i++)
	{
	   times=times+go_to_catch_g_goods_judge_count(0,4+i);
	}
		//ȡ˳ʱ��ڶ�������
	for(int i=0;i<6;i++)
	{
	   times=times+go_to_catch_g_goods_judge_count(4+i,9);
		if(times>=30)
		{
      go_straight_to_normal_position2(2,9);
			ajust_position(2,8);
			go_straight_to_normal_position2(2,0);
			ajust_position(1,0);
			go_to_catch_g_goods_judge(0,1);
			go_to_catch_g_goods_judge(0,0);
			stop++;
			   for_delay();
			i=10;
		}	
	}
		//ȡ˳ʱ�����������
		if(stop==0)
	for(int i=0;i<6;i++)
	{
	  times=times+go_to_catch_g_goods_judge_count(9,5-i);
		if(times>=30)
		{
      go_straight_to_normal_position2(9,0);
			ajust_position(8,0);
			go_to_catch_g_goods_judge(0,1);
			go_to_catch_g_goods_judge(0,0);
			stop++;
			   for_delay();
			i=10;
		}	
	}
		//ȡ˳ʱ����ĸ�����
		if(stop==0)
	for(int i=0;i<6;i++)
	{
	  times=times+go_to_catch_g_goods_judge_count(5-i,0);
		if(times>=30&&i<3)
		{
			go_to_catch_g_goods_judge(0,1);
			go_to_catch_g_goods_judge(0,0);
			stop++;
			   for_delay();
			i=10;
		}	
	}	
		
			//			go_back_home_dead();
		//go_back_home_back();
}

/**
  * @brief  4  ȡ���ܻ���-����·���桪�����ﳵ��-���ĵ�
  * @param  ��
  * @retval ��
  */
void get_g_path_auto_shop_mini(void)
{
			   	printf("\r\n·��4 ");
		first_step_with_car();
	//ȡ˳ʱ���һ������	
	  go_to_catch_g_goods_judge(0,4);
		go_to_catch_g_goods_judge(0,5);
		go_to_catch_g_goods_judge(0,6);
		go_to_catch_g_goods_judge(0,7);
		go_to_catch_g_goods_judge(0,8);	
		go_to_catch_g_goods_judge(0,9);
		//ȡ˳ʱ��ڶ�������
		go_to_catch_g_goods_judge(4,9);
		go_to_catch_g_goods_judge(5,9);
		go_to_catch_g_goods_judge(6,9);
		go_to_catch_g_goods_judge(7,9);
		go_to_catch_g_goods_judge(8,9);
		go_to_catch_g_goods_judge(9,9);
		//ȡ˳ʱ�����������
	  go_to_catch_g_goods_judge(9,5);
		go_to_catch_g_goods_judge(9,4);
		go_to_catch_g_goods_judge(9,3);
		go_to_catch_g_goods_judge(9,2);
		go_to_catch_g_goods_judge(9,1);	
		go_to_catch_g_goods_judge(9,0);
		//ȡ˳ʱ����ĸ�����
//		go_to_catch_g_goods_judge(5,0);
//		go_to_catch_g_goods_judge(4,0);
//		go_to_catch_g_goods_judge(3,0);
//		go_to_catch_g_goods_judge(2,0);
		go_to_catch_g_goods_judge(1,0);
		go_to_catch_g_goods_judge(0,0);	
		
			//			go_back_home_dead();
		//go_back_home_back();
}

/**
  * @brief  5  ȡ���ܻ���-����·���桪�����ﳵ��-������
  * @param  ��
  * @retval ��
  */
void get_g_path_auto_shop_restart(void)
{
			   	printf("\r\n·��5 ");
		first_step();
	runActionGroup(28,1); 
	go_to_certain_position_test_edition(1,2);
	go_to_certain_position_test_edition(1,1);
	runActionGroup(27,1);
	go_to_certain_position_test_edition(7,1);	
	go_to_certain_position_test_edition(7,5);	
	go_to_certain_position_test_edition(9,5);	
	//ȡ˳ʱ���һ������	
//	  go_to_catch_g_goods_judge(0,4);
//		go_to_catch_g_goods_judge(0,5);
//		go_to_catch_g_goods_judge(0,6);
//		go_to_catch_g_goods_judge(0,7);
//		go_to_catch_g_goods_judge(0,8);	
//		go_to_catch_g_goods_judge(0,9);
	
		//ȡ˳ʱ��ڶ�������
//		go_to_catch_g_goods_judge(4,9);
//		go_to_catch_g_goods_judge(5,9);
//		go_to_catch_g_goods_judge(6,9);
//		go_to_catch_g_goods_judge(7,9);
//		go_to_catch_g_goods_judge(8,9);
//		go_to_catch_g_goods_judge(9,9);
		//ȡ˳ʱ�����������
//	  go_to_catch_g_goods_judge(9,5);
		go_to_catch_g_goods_judge(9,4);
		go_to_catch_g_goods_judge(9,3);
		go_to_catch_g_goods_judge(9,2);
		go_to_catch_g_goods_judge(9,1);	
		go_to_catch_g_goods_judge(9,0);
		//ȡ˳ʱ����ĸ�����
		go_to_catch_g_goods_judge(5,0);
		go_to_catch_g_goods_judge(4,0);
		go_to_catch_g_goods_judge(3,0);
		go_to_catch_g_goods_judge(2,0);
		go_to_catch_g_goods_judge(1,0);
		go_to_catch_g_goods_judge(0,0);	
		
			//			go_back_home_dead();
		//go_back_home_back();
}


/*********************************************others edition**********************/


/**
  * @brief  �����ﳵ�ܲ���
  * @param  ��
  * @retval ��
  */
void get_shop_run_test(void)
{
	 runActionGroup(27,1);
	go_to_certain_position(1,5);
	go_to_certain_position(4,2);
	go_to_certain_position(2,5);
	go_to_certain_position(0,2);
}

/**
  * @brief  ȡ���ܻ���-����·���桪������Ʒ���ް�
  * @param  ��
  * @retval ��
  */
void get_g_path_auto_limit(void)
{
		   	printf("\r\n·��1 ");
	  first_step();
	//ȡ˳ʱ���һ������
	  go_to_catch_g_goods_judge_limit(0,4);
		go_to_catch_g_goods_judge_limit(0,5);
		go_to_catch_g_goods_judge_limit(0,6);
		go_to_catch_g_goods_judge_limit(0,7);
		go_to_catch_g_goods_judge_limit(0,8);	
		go_to_catch_g_goods_judge_limit(0,9);
	//ȡ˳ʱ��ڶ�������	
		go_to_catch_g_goods_judge_limit(4,9);
		go_to_catch_g_goods_judge_limit(5,9);
		go_to_catch_g_goods_judge_limit(6,9);
		go_to_catch_g_goods_judge_limit(7,9);
		go_to_catch_g_goods_judge_limit(8,9);
		go_to_catch_g_goods_judge_limit(9,9);
	//ȡ˳ʱ�����������	
	  go_to_catch_g_goods_judge_limit(9,5);
		go_to_catch_g_goods_judge_limit(9,4);
		go_to_catch_g_goods_judge_limit(9,3);
		go_to_catch_g_goods_judge_limit(9,2);
		go_to_catch_g_goods_judge_limit(9,1);	
		go_to_catch_g_goods_judge_limit(9,0);
	//ȡ˳ʱ����ĸ�����	
		go_to_catch_g_goods_judge_limit(5,0);
		go_to_catch_g_goods_judge_limit(4,0);
		go_to_catch_g_goods_judge_limit(3,0);
		go_to_catch_g_goods_judge_limit(2,0);
		go_to_catch_g_goods_judge_limit(1,0);
		go_to_catch_g_goods_judge_limit(0,0);	

			//	go_back_home_dead();
   // go_back_home_back();
}



/**
  * @brief  ȡ���ܻ���-д��·���桪�����ﳵ��
  * @param  ��
  * @retval ��
  */
void get_g_path_certain_shop(void)
{		   	printf("\r\n·��3 ");
		first_step_with_car();

for(int i=0;i<4;i++)	
	{
	  if(i==0)
		  motor_control_Certain_Step_ahead(1);
		else
			motor_control_Certain_Step_ahead(4);
	  catch_g_goods_judge();
	  motor_control_Certain_Step_ahead(1);
	  catch_g_goods_judge();
	
//	  motor_control_Right_correct(1);
//	  motor_control_Certain_Step_ahead(2);
//	  motor_control_close_ahead();
//	  .............
//	  motor_control_away_back();
//	  motor_control_Certain_Step_back(2);
//	  motor_control_Left_correct(1);
	
	  motor_control_Certain_Step_ahead(1);
	  catch_g_goods_judge();
	  motor_control_Certain_Step_ahead(1);
	  catch_g_goods_judge();
	 	motor_control_Certain_Step_ahead(1);
	  catch_g_goods_judge();
	  motor_control_Certain_Step_ahead(1);
	  catch_g_goods_judge();
		if(i!=3)
			motor_control_Right_correct(1);
	}
 			//	go_back_home_dead();
}

/**
  * @brief  ȡ���ܻ���-д��·���桪������Ʒ���ް�
  * @param  ��
  * @retval ��
  */
void get_g_path_certain_limit(void)
{
		first_step();
	//��̫��Ҫ����ʱ����
	//  go_back_home_back();
}


/**
  * @brief  ȡ���ܻ���-����·���桪��������Ʒ��
  * @param  ��
  * @retval ��
  */
void get_g_path_certain_single(void)
{		   	printf("\r\n·��4 ");
		first_step();
	
		//ȡ˳ʱ���һ������
	  go_to_catch_g_goods_judge_limit_only(0,4);
		go_to_catch_g_goods_judge_limit_only(0,5);
		go_to_catch_g_goods_judge_limit_only(0,6);
		go_to_catch_g_goods_judge_limit_only(0,7);
		go_to_catch_g_goods_judge_limit_only(0,8);	
		go_to_catch_g_goods_judge_limit_only(0,9);
	//ȡ˳ʱ��ڶ�������	
		go_to_catch_g_goods_judge_limit_only(4,9);
		go_to_catch_g_goods_judge_limit_only(5,9);
		go_to_catch_g_goods_judge_limit_only(6,9);
		go_to_catch_g_goods_judge_limit_only(7,9);
		go_to_catch_g_goods_judge_limit_only(8,9);
		go_to_catch_g_goods_judge_limit_only(9,9);
	//ȡ˳ʱ�����������	
	  go_to_catch_g_goods_judge_limit_only(9,5);
		go_to_catch_g_goods_judge_limit_only(9,4);
		go_to_catch_g_goods_judge_limit_only(9,3);
		go_to_catch_g_goods_judge_limit_only(9,2);
		go_to_catch_g_goods_judge_limit_only(9,1);	
		go_to_catch_g_goods_judge_limit_only(9,0);
	//ȡ˳ʱ����ĸ�����	
		go_to_catch_g_goods_judge_limit_only(5,0);
		go_to_catch_g_goods_judge_limit_only(4,0);
		go_to_catch_g_goods_judge_limit_only(3,0);
		go_to_catch_g_goods_judge_limit_only(2,0);
		go_to_catch_g_goods_judge_limit_only(1,0);
		go_to_catch_g_goods_judge_limit_only(0,0);	
	
	  //go_back_home_back();
				//		go_back_home_dead();
}

/*********************************************another special edition**********************/


/*********************************************END OF FILE**********************/

#ifndef __BSP_tracers_H
#define	__BSP_tracers_H



void go_to_certain_position(int x,int y);
void go_to_certain_position_no_ajust(int x,int y);
void go_to_certain_position_test_edition(int x,int y);

void point_ajust(int x,int y);
void go_to_normal_position(int x,int y);
void go_to_normal_position_no_ajust(int x,int y);
void go_to_e_main_position(int x,int y);
void go_to_e_corner_position(int x,int y);
void go_back_home(void);
void go_back_home_back(void);
void ajust_position(int x,int y);
void ajust_position_to_g_test_edition(void);
void go_straight_to_normal_position1(int x,int y);
void go_straight_to_normal_position2(int x,int y);
void near_E(void);
void left_E(void);
void ajust_position_to_g(void);
void ajust_position_to_e(void);

void get_shop_car(void);
int get_position(void);
int get_position_to_g(void);
#endif   /* __BSP_tracers_H */

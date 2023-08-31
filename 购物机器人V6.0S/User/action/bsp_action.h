#ifndef __BSP_action_H
#define	__BSP_action_H

void catch_g_goods(void);
void go_to_catch1(int x,int y);
void go_to_catch2(int x,int y);
void go_to_catch_test(int x,int y);
void go_to_catch_certain(int x,int y,int m);
void go_to_catch1_ajust(int x,int y);
void go_to_catch2_ajust(int x,int y);

void go_to_catch_g_goods_judge(int x,int y);
void go_to_catch_g_goods_vison_judge(int x,int y);
int go_to_catch_g_goods_judge_count(int x,int y);
void go_to_catch_g_goods_judge_limit(int x,int y);
void go_to_catch_g_goods_judge_limit_only(int x,int y);
void catch_g_goods_judge(void);
void carry_goods_judge(int x,int y);
void send_goods_back(int x,int y);

void go_to_catch_g_goods_judge2(int x,int y);
void go_to_catch_g_goods_judge_limit2(int x,int y);
void go_to_catch_g_goods_judge_limit_only2(int x,int y);
void catch_g_goods_judge2(void);
#endif   /* __BSP_action_H */

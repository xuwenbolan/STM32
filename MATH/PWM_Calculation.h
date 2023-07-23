#ifndef __PWM_CALCULATION_H__
#define __PWM_CALCULATION_H__


#include "main.h"
#include "calculate_D_H.h"


#define stand_Dx 0.0f
#define stand_Dy  0.15f




extern int angle_turn2[6];

void character_turning(int *pwm);
int* angle_turn_pwm(float *angle_in);
int angle_turn_pwm_2(angle *ARM_STATE);
void test_PWM(int flag1,int angle1,int flag2,int angle2,int flag3,int angle3,int flag4,int angle4);

int ROB_GO_STR(angle *state);
void set_ARM_state_test(int flag1 ,int x,int flag2,int y,int flag3,int z);
void ARM_REC(float *rec_coor);
void set_angle_fun(int t1, int t2, int t3,int t4,int t5,int t6);
void all_set_Fun(void);
void test_angle_turn(void);
void mo_2(angle *ARM);
int mo(float x, float y,float z);

#endif



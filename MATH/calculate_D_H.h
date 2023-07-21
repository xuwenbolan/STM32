#ifndef __CALCULATE_D_H_H__
#define __CALCULATE_D_H_H__
#include "main.h"
#include "arm_math.h"
#include "arm_const_structs.h"
//#include "PWM_Calculation.h"


#define l0 0.150f
#define l1 0.099f
#define l2 0.175f
#define Ratio 5.111f
extern 	float angle_Gamma;
void inti_ROB(void);

//extern float an1[180],an2[180],an3[180];


//typedef struct
//{
//	float m;
//	float n;
//	float k;
//	float a;
//	float b;
//	float c;
//	float theta1;
//	float theta2;
//	float theta3;
//	float s1ps2;
//	float Alpha ;
//}D_H_;



//u8 Kinematic_Analysis(float x,float y);



typedef struct
{
	float theta1;
	float theta2;
	float theta3;
	float theta4;
	float t1;
	float t2;
	float t3;
	float t4;
	float a1;
	float a2;
	float a3;
	float Bx;
	float By;
	float Gamma;
	float Gamma_r;
	float beta;
	float alpha;
	float L_bo;
	float r_x, r_y, r_z;
	float G_x,G_y,G_z;
	float res_x,res_y,res_z;

}angle;

extern angle ROB_ARM;

int mo_3(float x, float y,float z,float Gamma);


#endif  /*__CALCULATE_D_H_H__*/



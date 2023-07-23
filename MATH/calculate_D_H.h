#ifndef __CALCULATE_D_H_H__
#define __CALCULATE_D_H_H__
#include "main.h"
#include "arm_math.h"
#include "arm_const_structs.h"

#define l0 0.150f
#define l1 0.099f
#define l2 0.175f
#define Ratio 5.111f
extern 	float angle_Gamma;
void inti_ROB(void);

typedef struct
{
	float theta1;
	float theta2;
	float theta3;
	float theta4;
	float theta5;
	float theta6;
	float t1;
	float t2;
	float t3;
	float t4;
	float t5;
	float t6;
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



#ifndef __ANGLE_PID_H__
#define __ANGLE_PID_H__

#include "calculate_D_H.h"

typedef struct
{
	float Kp;
	float Ki;
	float Kd;
	float _err;
	float _last_err;
	float Integral_err;
	float actual_num;
	float target_num;
}__PID_ANGLE;

//extern __PID_ANGLE servo_motor1;
extern __PID_ANGLE v_pid;

float Position_PID1 (float Encoder,float Target);
void Angle1_init(void);
float Val_PID(float Encoder, float Target, __PID_ANGLE* servo_motor);
void _pid_init(__PID_ANGLE * state_init);


#endif/*__ANGLE_PID_H__*/


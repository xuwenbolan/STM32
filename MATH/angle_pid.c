#include "angle_pid.h"



__PID_ANGLE servo_motor1;
__PID_ANGLE v_pid;


void _pid_init(__PID_ANGLE * state_init)
{



	state_init->Kp = 0.045f;
	state_init->Ki = 0.020f;
	state_init->Kd = 0.020f;
	state_init->_err = 0.0f;
	state_init->_last_err = 0.0f;
	state_init->Integral_err = 0.0f;
	state_init->actual_num=0.0f;
	state_init->target_num=0.0f;
}






void Angle1_init(void)
{
		servo_motor1._err = 0.0f;
	servo_motor1._last_err = 0.0f;
	servo_motor1.Integral_err = 0.0f;
	servo_motor1.Kp = 0.5f;
	servo_motor1.Ki = 0.1f;
	servo_motor1.Kd = 0.01f;
}


float Position_PID1 (float Encoder,float Target)
{ 	

	float Pwm;

	
	servo_motor1._err = Target - Encoder;                                  //计算偏差
	servo_motor1.Integral_err += servo_motor1._err;	                                 //求出偏差的积分
	Pwm = servo_motor1.Kp * servo_motor1._err + servo_motor1.Ki * servo_motor1.Integral_err + servo_motor1.Kd * (servo_motor1._err - servo_motor1._last_err);       //位置式PID控制器
	servo_motor1._last_err = servo_motor1._err;                                       //保存上一次偏差 
	return Pwm;                                           //增量输出
}







float Val_PID(float Encoder, float Target, __PID_ANGLE* servo_motor)
{

	float Pwm;

	servo_motor->actual_num = Encoder;
	servo_motor->target_num = Target;
	servo_motor->_err = servo_motor->target_num - servo_motor->actual_num; 


	//计算偏差
//	if((servo_motor->_err<0.001f)&&(servo_motor->_err>-0.001f))
//	{
//		servo_motor->_err=0;
//	}
	servo_motor->Integral_err += servo_motor->_err;	
if(servo_motor->_err>100000.0f)servo_motor->_err=100000.0f;
	if(servo_motor->_err<-100000.0f)servo_motor->_err=-100000.0f;
	//求出偏差的积分
	Pwm = servo_motor->Kp * servo_motor->_err + servo_motor->Ki * servo_motor->Integral_err + servo_motor->Kd * (servo_motor->_err - servo_motor->_last_err);       //位置式PID控制器
	servo_motor->_last_err = servo_motor->_err;                                       //保存上一次偏差 
	return Pwm;                                           //增量输出
}





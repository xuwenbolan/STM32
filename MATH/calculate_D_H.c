#include "calculate_D_H.h"




	angle ROB_ARM;


void mo_parm_init(angle* rob_arm_state)
{
	rob_arm_state->a1 = 0.1045f;
	rob_arm_state->a2 = 0.0985f;
	rob_arm_state->a3 = 0.1741f;
	rob_arm_state->r_x = 0;
	rob_arm_state->r_y = 0;
	rob_arm_state->r_z = 0;
}


void inti_ROB(void)
{
	ROB_ARM.theta1=0.0f;
	ROB_ARM.theta2=0.0f;
	ROB_ARM.theta3=0.0f;
	ROB_ARM.theta4=0.0f;
	ROB_ARM.t1=0.0f;
	ROB_ARM.t2=0.0f;
	ROB_ARM.t3=0.0f;
	ROB_ARM.t4=0.0f;
	ROB_ARM.a1 = 0.1045f;
	ROB_ARM.a2 = 0.0985f;
	ROB_ARM.a3 = 0.268f;
	ROB_ARM.r_x = 0.0f;
	ROB_ARM.r_y = 0.0f;
	ROB_ARM.r_z = 0.1045f+0.0985f+0.1741f;
	ROB_ARM.G_x=0.0f;
	ROB_ARM.G_y=0.0f;
	ROB_ARM.G_z=0.1045f+0.0985f+0.1741f;
	ROB_ARM.res_x=0.0f;
	ROB_ARM.res_y=0.0f;
	ROB_ARM.res_z=0.1045f+0.0985f+0.1741f;
}






/*

作用:姿态解算
用法:输入目标坐标和爪子与水平面的夹角（如90）

*/
int mo_3(float x, float y,float z,float Gamma)
{
	if (x * x + y * y + z * z > 0.1422f)
	{

		return 0;
	}
	u8 Lo_Flag = 0;
	
	float delta_Gamma;
	ROB_ARM.theta4 = (180.0f / PI) * atan2(y, x);
	x = sqrt(x * x + y * y);
	//Gamma=angle_Gamma;
	do
	{
		Lo_Flag = 0;
		ROB_ARM.Gamma = Gamma;
		



		ROB_ARM.Gamma_r = ROB_ARM.Gamma / (180.0f / PI);
		ROB_ARM.Bx = x - ROB_ARM.a3 * cos(ROB_ARM.Gamma_r);
		ROB_ARM.By = z - ROB_ARM.a3 * sin(ROB_ARM.Gamma_r);
		ROB_ARM.L_bo = sqrt(ROB_ARM.Bx * ROB_ARM.Bx + ROB_ARM.By * ROB_ARM.By);
		if (((ROB_ARM.a1 + ROB_ARM.a2) < ROB_ARM.L_bo) || ((ROB_ARM.a1 - ROB_ARM.a2) >= ROB_ARM.L_bo))
		{
			Lo_Flag = 1;
			Gamma++;

			if(Gamma>100)
			{
			return 0;

			}

		}
	} while (Lo_Flag);
		ROB_ARM.theta2 = (180.0f / PI) * acos((ROB_ARM.Bx * ROB_ARM.Bx + ROB_ARM.By * ROB_ARM.By - ROB_ARM.a1 * ROB_ARM.a1 - ROB_ARM.a2 * ROB_ARM.a2) / (2.0f * ROB_ARM.a1 * ROB_ARM.a2));
		ROB_ARM.alpha = acos((ROB_ARM.a1 * ROB_ARM.a1 + ROB_ARM.Bx * ROB_ARM.Bx + ROB_ARM.By * ROB_ARM.By - ROB_ARM.a2 * ROB_ARM.a2) / (2 * ROB_ARM.a1 * ROB_ARM.L_bo));
		ROB_ARM.beta = atan2(ROB_ARM.By, ROB_ARM.Bx);
		ROB_ARM.theta1 = 90 - (180.0f / PI) * (ROB_ARM.alpha + ROB_ARM.beta);
		ROB_ARM.theta3 = 90 - ROB_ARM.Gamma - ROB_ARM.theta2 - ROB_ARM.theta1;
	
		if(ROB_ARM.theta1>90.0f)ROB_ARM.theta1=90.0f;
		else if(ROB_ARM.theta1<-90.0f)ROB_ARM.theta1=-90.0f;
	
	if(ROB_ARM.theta2>135.0f)ROB_ARM.theta2=135.0f;
		else if(ROB_ARM.theta2<-135.0f)ROB_ARM.theta2=-135.0f;
	
		if(ROB_ARM.theta3>135.0f)ROB_ARM.theta3=135.0f;
		else if(ROB_ARM.theta3<-135.0f)ROB_ARM.theta3=-135.0f;
	
		if(ROB_ARM.theta4>135.0f)ROB_ARM.theta4=135.0f;
		else if(ROB_ARM.theta4<-135.0f)ROB_ARM.theta4=-135.0f;
		//an1[flag1] = (theta1 * 1.0f);
		//an2[flag1] = (theta2 * 1.0f);
		//an3[flag1] = (theta3 * 1.0f);
	//	printf("%f,%f,%f,%f,%f\n", ROB_ARM.theta1, ROB_ARM.theta2, ROB_ARM.theta3, ROB_ARM.theta4, ROB_ARM.Gamma);

		
		return 1;

	
}




#include "PWM_Calculation.h"
#include "itoa_turn.h"
#include "USART2.h"
#include "angle_pid.h"

	float ang[4];
	int cal_flag=1; 
	int angle_turn[4];
	int angle_turn2[6];
	float angle_Gamma=0.0f;
int* angle_turn_pwm(float *angle_in)
{

	if(angle_turn[0]>0)
	{
		angle_turn[0]=1500-(int)(angle_in[0]*7.40f+0.50f);
	}
	else
	{
		angle_turn[0]=1500-(int)(angle_in[0]*7.40f+0.50f);
	}
	
	
		if(angle_turn[1]>0)
	{
		angle_turn[1]=1234-(int)(angle_in[1]*7.40f+0.50f);
	}
	else
	{
		angle_turn[1]=1234-(int)(angle_in[1]*7.40f+0.50f);
	}
	
		if(angle_turn[2]>0)
	{
		angle_turn[2]=1500+(int)(angle_in[2]*7.40f+0.50f);
	}
	else
	{
		angle_turn[2]=1500+(int)(angle_in[2]*7.40f+0.50f);
	}
	
	
			if(angle_turn[3]>0)
	{
		angle_turn[3]=1500+(int)(angle_in[3]*7.40f+0.50f);
	}
	else
	{
		angle_turn[3]=1500+(int)(angle_in[3]*7.40f+0.50f);
	}

	printf("%d,%d,%d,%d\r\n",angle_turn[0],angle_turn[1],angle_turn[2],angle_turn[3]);
	
	
	
return angle_turn;
}

int angle_turn_pwm_2(angle *ARM_STATE)
{

	if(angle_turn2[0]>0)
	{
		angle_turn2[0]=1500-(int)(ARM_STATE->theta4*7.40f+0.50f);
	}
	else
	{
		angle_turn2[0]=1500-(int)(ARM_STATE->theta4*7.40f+0.50f);
	}
	
	
		if(angle_turn2[1]>0)
	{
		angle_turn2[1]=1234-(int)(ARM_STATE->theta1*7.40f+0.50f);
	}
	else
	{
		angle_turn2[1]=1234-(int)(ARM_STATE->theta1*7.40f+0.50f);
	}
	
		if(angle_turn2[2]>0)
	{
		angle_turn2[2]=1500+(int)((ARM_STATE->theta2-10)*7.40f+0.50f);
	}
	else
	{
		angle_turn2[2]=1500+(int)((ARM_STATE->theta2-10)*7.40f+0.50f);
	}
	
	
			if(angle_turn2[3]>0)
	{
		angle_turn2[3]=1500+(int)((ARM_STATE->theta3+5)*7.40f+0.50f);
	}
	else
	{
		angle_turn2[3]=1500+(int)((ARM_STATE->theta3+5)*7.40f+0.50f);
	}
	
	if(angle_turn2[4]>0)
	{
		angle_turn2[4]=1500+(int)((ARM_STATE->theta5+5)*7.40f+0.50f);
	}
	else
	{
		angle_turn2[4]=1500+(int)((ARM_STATE->theta5+5)*7.40f+0.50f);
	}
	
	if(ARM_STATE->t6>=90)
	{
		angle_turn2[5]=500;
	}
	else angle_turn2[5]=1500;

//	printf("%d,%d,%d,%d\r\n",angle_turn[0],angle_turn[1],angle_turn[2],angle_turn[3]);
	
	
	
return 1;
}

 void character_turning(int *pwm)
{

	char str1[50] = {'\0'};
	char *head[4]={"#1P","#2P","#3P","#4P"};

	char *_end = "T1000D100\r\n";
	char str3[5];
	for(int i=0;i<=3;i++)
	{
	itoa(pwm[i], str3,10);
	strcat(str1, head[i]);
	strcat(str1, str3);
	}
	

	strcat(str1 ,_end);
	Usart_SendString(USART2,str1);
	printf("%s",str1);
}




void test_PWM(int flag1,int angle1,int flag2,int angle2,int flag3,int angle3,int flag4,int angle4)
{

	int *turn;
	
	printf("%d,%d,%d,%d\r\n",angle1,angle2,angle3,angle4);
	if(flag1)
	{
		angle1=-angle1;
	}
		if(flag2)
	{
		angle2=-angle2;
	}
		if(flag3)
	{
		angle3=-angle3;
	}
		if(flag4)
	{
		angle4=-angle4;
	}
	ang[0]=angle1;
	ang[1]=angle2;
	ang[2]=angle3;
	ang[3]=angle4;
		printf("\r\n...............\r\n");
	
	printf("%f,%f,%f,%f\r\n",ang[0],ang[1],ang[2],ang[3]);
	turn=angle_turn_pwm(ang);
character_turning(turn);
}




	float ROB_R;
	float Sx, Sy, Sz,T_temp,_S,_G;

int ROB_GO_STR(angle *state)
{
	float temp_IN_ERR;
	
	
	if(cal_flag)
	{
		state->G_x=state->res_x;
		state->G_y=	state->res_y;
		state->G_z=state->res_z;
	
	Sx =state->G_x-state->r_x;
	Sy =state-> G_y- state->r_y;
	Sz =state-> G_z-state->r_z ;
	_S = Sx;
	_G =state-> G_x;
	//ROB_target = state->G_x;
	ROB_R = state->r_x;
	//_temp = state->r_x;

	if ((_S<0.05f)&&(_S>-0.05f))
	{
			state->r_x=state->G_x;
			//_temp = state->r_y;
			_S = Sy;
			_G = state->G_y;
			ROB_R = state->r_y;
			
		
		 if ((_S<0.05f)&&(_S>-0.05f))
		{
			state->r_y=state->G_y;
			_S = Sz;
			_G = state->G_z;
			ROB_R = state->r_z;
			
		}
		
		
		 if ((_S<0.05f)&&(_S>-0.05f))
		{
			 state->r_z=state->G_z;
			 return 0;

		}

		
	}

	cal_flag=0;
}

	if(_S>0)
	{
		ROB_R+=0.01;
	}
	else
	{
		ROB_R-=0.01;
	}

		T_temp = (ROB_R - _G) / _S;
		state->r_x = Sx * T_temp + state->G_x;
		state->r_y = Sy * T_temp +	state->G_y;
		state->r_z = Sz * T_temp +	state->G_z;
		
		if(((ROB_R-_G)<=0.08)
			&&((ROB_R-_G)>=-0.08))
		{
			ROB_R=_G;
		}
		//printf("ROB: %f",ROB_R);


		//printf("%f,%f,%f\n", state->r_x, state->r_y, state->r_z);


	return 1;
}






void all_set_Fun(void)
{
	ROB_GO_STR(&ROB_ARM);
	//mo_3(ROB_ARM.r_x, ROB_ARM.r_y,ROB_ARM.r_z,0.0f);
	mo(ROB_ARM.r_x,ROB_ARM.r_y,ROB_ARM.r_z);
	//printf("%f,%f,%f,%f,%f\r\n",ROB_ARM.theta4,ROB_ARM.theta1,ROB_ARM.theta2,ROB_ARM.theta3,ROB_ARM.Gamma);
	angle_turn_pwm_2(&ROB_ARM);
	printf("%f,%f,%f,%f\r\n",ROB_ARM.r_x,ROB_ARM.r_y,ROB_ARM.r_z,ROB_ARM.Gamma);
	LL_TIM_OC_SetCompareCH1(TIM3,angle_turn2[0]);
	LL_TIM_OC_SetCompareCH2(TIM3,angle_turn2[1]);
	LL_TIM_OC_SetCompareCH3(TIM3,angle_turn2[2]);
	LL_TIM_OC_SetCompareCH4(TIM3,angle_turn2[3]);
	//printf("%d,%d,%d,%d\r\n",angle_turn2[0],angle_turn2[1],angle_turn2[2],angle_turn2[3]);
	
}

void test_angle_turn(void)
{
	mo_2(&ROB_ARM);
	angle_turn_pwm_2(&ROB_ARM);
	printf("%f,%f,%f,%f,%f,%f\r\n",ROB_ARM.theta4,ROB_ARM.theta1,ROB_ARM.theta2,ROB_ARM.theta3,ROB_ARM.theta5,ROB_ARM.theta6);
	LL_TIM_OC_SetCompareCH1(TIM3,angle_turn2[0]);
	LL_TIM_OC_SetCompareCH2(TIM3,angle_turn2[1]);
	LL_TIM_OC_SetCompareCH3(TIM3,angle_turn2[2]);
	LL_TIM_OC_SetCompareCH4(TIM3,angle_turn2[3]);
	LL_TIM_OC_SetCompareCH1(TIM9,angle_turn2[4]);
	LL_TIM_OC_SetCompareCH2(TIM9,angle_turn2[5]);
}

void mo_2(angle *ARM)
{
	float i =0;
	
	if( ARM->t1 - ARM->theta1 > 0.05 )
	{
		ARM->theta1+=0.4;
		i+=0.4;
	}
	else if(ARM->theta1 - ARM->t1>0.05)
	{
		ARM->theta1-=0.4;
		i+=0.4;
	}
	
	if(ARM->t2 - ARM->theta2> 0.05 )
	{
		ARM->theta2+=0.4;
		i+=0.4;
	}
	else if(ARM->theta2 - ARM->t2> 0.05 )
	{
		ARM->theta2-=0.4;
		i+=0.4;
	}
	if(ARM->t3 - ARM->theta3> 0.05 && i==0)i=0.4;
	//printf("i: %f\n",i);
	if(ARM->t3 - ARM->theta3> 0.05)ARM->theta3+=i;
	else if(ARM->theta3 - ARM->t3> 0.05)ARM->theta3-=i;
	
	if(ARM->t4 - ARM->theta4> 0.05)ARM->theta4+=0.4;
	else if(ARM->theta4 - ARM->t4> 0.05 )ARM->theta4-=0.4;
	
	if(ARM->t5 - ARM->theta5> 0.05)ARM->theta5+=0.4;
	else if(ARM->theta5 - ARM->t5> 0.05 )ARM->theta5-=0.4;
	
	if(ARM->t6 - ARM->theta6> 0.05)ARM->theta6+=0.4;
	else if(ARM->theta6 - ARM->t6> 0.05 )ARM->theta6-=0.4;
}

int mo(float x, float y,float z)
{
	ROB_ARM.theta4 = (180.0f / PI) * atan2(y, x);
	float a1=0.1045f,a2=0.0985f,a3=0.1741f;
	float t1 = 0, t2 = 0, t3 = 0,c=0;
	//if(ROB_ARM.theta1+ROB_ARM.theta3>=90)return 0;
	float state = x - a3 * cos((90 - ROB_ARM.theta3) * PI / 180);
	//printf("%f\n",state);
	if(state<=0|ROB_ARM.theta3==0)
	{
		
		c = (a3*a3 - (a1 + a2) * (a1 + a2) - x * x - z * z) / (2 * (a1 + a2));
		t1 = (180 / PI) * 2 * atan((x - sqrt(x * x + z* z - c * c)) / (c - z));
		if(t1<0)t1 = (180 / PI) * 2 * atan((x + sqrt(x * x + z * z - c * c)) / (c - z));
		t3 = 90 + t1 - (180 / PI)*asin((z - (a1 + a2) * cos(t1 * PI / 180)) / a3);
		if(t1>0)
		{
			ROB_ARM.theta1 = -t1;
			ROB_ARM.theta2 = t2;
			ROB_ARM.theta3 = t3;
		}
	}
	else
	{
		c = (a3*a3 - (a1 + a2) * (a1 + a2) - x * x - z * z) / (-2 * (a1 + a2));
		t1 = (180 / PI) * 2 * atan((x - sqrt(x * x + z * z - c * c)) / (c + z));
		if(t1<0)t1 = (180 / PI) * 2 * atan((x + sqrt(x * x + z * z - c * c)) / (c + z));
		t3 = 90 - t1 - (180 / PI)*asin((z - (a1 + a2) * cos(t1 * PI / 180)) / a3);
		if(ROB_ARM.theta1+ROB_ARM.theta3<=90 || 1)
		{
			ROB_ARM.theta1 = t1;
			ROB_ARM.theta2 = t2;
			ROB_ARM.theta3 = t3;
		}
	}
	printf("%f %f\n", ROB_ARM.theta1,ROB_ARM.theta3);
}

void set_ARM_state_test(int flag1 ,int x,int flag2,int y,int flag3,int z)
{
	float save_num[3];
	save_num[0]=x/100.0f;
	save_num[1]=y/100.0f;
	save_num[2]=z/100.0f;
	
	
	
	
		if(flag1==1)
		{
			save_num[0]=-save_num[0];
		}
			if(flag2==1)
		{
			save_num[1]=-save_num[1];
		}
			if(flag3==1)
		{
			save_num[2]=-save_num[2];
		}
		
		ROB_ARM.res_x=save_num[0];
		ROB_ARM.res_y=save_num[1];
		ROB_ARM.res_z=save_num[2];

	cal_flag=1;
}

void ARM_REC(float *rec_coor)
{

		rec_coor[1]=(180.0f-rec_coor[1])*0.00125f-stand_Dy;
	  rec_coor[2]=-(rec_coor[1]-180.0f)*0.125f;
	  rec_coor[0]=0.25f;
}



void set_angle_fun(int t1, int t2, int t3,int t4,int t5,int t6)
{
	ROB_ARM.t4 = t1;
	ROB_ARM.t1 = t2;
	ROB_ARM.t2 = t3;
	ROB_ARM.t3 = 90-t2-t3;
	ROB_ARM.t5 = t5;
	ROB_ARM.t6 = t6;  
}






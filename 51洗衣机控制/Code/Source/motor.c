#include"pbdata.h"
extern unsigned int mode;
unsigned char pwm_flag;

void Time0_init()                                //ʹ�ö�ʱ��0ʵ��1MS�Ķ�ʱ
{
        TMOD = (TMOD & 0XF0)  | 0X01;       //ѡ��ʱ��0�Թ���ģʽ1����
        TL0 =(65536-1000);		
        TH0 = (62236-1000)/256;
        TR0 = 1;                                     //�򿪶�ʱ��0
        ET0 = 1;                                        //�򿪶�ʱ���ж�
        EA = 1;                                         //�����ж�
}

void Timer_0() interrupt 1      //��ʱ��0���жϺ���
{
        TL0 =(65536-1000);		
        TH0 = (62236-1000)/256;          //��װ��ֵ
        pwm_flag++;

//����Ϊʵ��PWM��������  
      if(pwm_flag>10)   pwm_flag = 0;
      //����Ϊ��ƶ�Ӧ����ռ�ձȣ�����ʵ�ֵ�Ч�� 
        if(pwm_flag<mode)  
        {
            Motor_IO = 1;
        }
        else 
        {
            Motor_IO = 0;
        }     
}
   
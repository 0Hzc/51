#ifndef __PBDATA_H__
#define __PBDATA_H__

#include<reg51.h>
#include"lcd1602.h"
#include"button.h"
#include"motor.h"

sbit BEEP = P1^4;
sbit LED = P3^2;


char* data_str(unsigned int dat);        //��������ת�ַ�������,��������ֵ��Ϊ�ַ�������
void Time1_init();//��ʱ��1��ʼ������
void delay(unsigned long ten_us);     //��ʱdelay_ten   ms
//char *Dis_Str(char *str1,char *str2);
char* data_str(unsigned int dat);

#endif
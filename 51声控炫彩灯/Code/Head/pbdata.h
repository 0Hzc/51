#ifndef __PBDATA_H__
#define __PBDATA_H__

#include<reg51.h>
#include"lcd1602.h"
#include"adc0832.h"
#include"led.h"




char* data_str(unsigned long dat);        //��������ת�ַ�������,��������ֵ��Ϊ�ַ�������
//void Time1_init();//��ʱ��1��ʼ������
void delay(unsigned long delay_ten);     //��ʱdelay_ten   ms
char *Dis_Str(char *str1,char *str2);

#endif
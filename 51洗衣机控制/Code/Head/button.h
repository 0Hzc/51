#ifndef __BUTTON_H__
#define __BUTTON_H__

#include<reg51.h>

sbit key1 = P1^0;
sbit key2 = P1^1;
sbit key3 = P1^2;
sbit key4 = P1^3;

/*
Button_Init()����Ϊ������ʼ�����������������������£�dir(1~4)++��
����dirʱ��Ҫ�ٴ����� extern unsigned int dir1,dir2,dir3,dir4;
����ֵΪ0��1��2��3��4��Ӧ��������
*/
extern unsigned char Button_Init();   

#endif
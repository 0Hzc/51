#ifndef __ADC0832_H__
#define __ADC0832_H__

#include<reg51.h>

sbit ADC_CS =   P1^0;
sbit ADC_CLK = P1^1;
sbit ADC_D = P1^2;



unsigned char Adc_Conv(); //ADCģ��ת������������ֵΪת����Ľ��

#endif 
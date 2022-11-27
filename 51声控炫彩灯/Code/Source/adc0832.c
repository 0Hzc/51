#include"pbdata.h"
#include"intrins.h"
void Adc_Init()     //ADC��ʼ������
{       
        ADC_CS = 1;     //��Ƭѡ�ø�
        ADC_CLK = 0;        
        ADC_D = 0;  
}
unsigned char Adc_Conv()        //ADCģ��ת��
{   
     unsigned char i;
     unsigned char ad_result1;
     unsigned char ad_result2;
    Adc_Init();
       ADC_CS = 0;      // Ƭѡʹ�ܣ��͵�ƽʱ����
       ADC_D = 1;      //��ʱ�ӵ�һ��������֮ǰ�����ߣ������ڵ�һ���½���֮ǰ��ȻҪ����Ϊ��
       ADC_CLK = 1;
       _nop_();
       ADC_CLK = 0; //������һ�����壬��һ������Ϊ��֤Ƭѡ��������
        //�ڶ����������������������ѡͨ��
        //ADC_D��������������  1  0  ѡ��ͨ��1����ģ����
       ADC_D = 1;
       _nop_();
       ADC_CLK = 1;
       _nop_();
       ADC_CLK = 0;     //�ڶ����������
        
       ADC_D = 0;
       _nop_();
       ADC_CLK = 1;
       _nop_();
       ADC_CLK = 0;    //����������������˺��������� ��ADC_D�������������
       
       ADC_D = 1;   //�����������ߣ�׼����������
      //��һ�ζ�ȡ����,MSB
      for(i = 0;i<8;i++)
       {
         //ADC_D���½���ʱ��������
         ADC_CLK = 1;
           _nop_();
         ADC_CLK = 0;
         ad_result1 = ad_result1<<1; //���ƣ���������ѭ���д���
         if(ADC_D ==1)      //��1����ad_result1
             ad_result1 = ad_result1 | 0x01;           
       }
     //�ڶ��ζ�ȡ���ݣ�LSB
       for(i = 0;i<8;i++)
       {
         ad_result2 = ad_result2>>1; //���ƣ���������ѭ���д���  
         if(ADC_D ==1)      //��1����ad_result1
         ad_result2 = ad_result2 | 0x80;    
         //ADC_D���½���ʱ��������
         ADC_CLK = 1;
           _nop_();
         ADC_CLK = 0;      
       }                    
        //�����һ�β���,׼��Ч��ת��ֵ�Ƿ���ȷ     
       return (ad_result1 == ad_result2) ? ad_result1:0;  //��ǰ����������һ�£����ⷵ��һ�����ɣ�����һ�£�����0
}
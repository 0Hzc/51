#include"pbdata.h"
unsigned char ad_result= 0;
unsigned char flag = 0;
unsigned int time1= 1;
unsigned int time2= 1;
void Time0_Init();

void main()
{
    Time0_Init();
    LED = 0x00;//��ʼ��LED��ȫ��Ϩ��
    Lcd1602_Init(); //LCD��ʼ��
while(1)
{      
    ad_result = Adc_Conv();     //���ɼ���ģ���������Ŵ��·�Լ�ģ��ת�������ad_result������
    Lcd1602_Show_string(0,0,"Voice:");      //��LCD��Ļ����ʾVoice
    Lcd1602_Show_string(11,0,"dB");     //��LCD��Ļ����ʾdB
    Lcd1602_Show_string(2,1,"T1:");
    Lcd1602_Show_string(8,1,"T2:");
    Lcd1602_Show_string(7,0,data_str(ad_result));       //��LCD��Ļ����ʾ����ֵ
    
        if(ad_result>10)
        { 
            TR0 = 1;
        Lcd1602_Show_string(5,1,Dis_Str(data_str(time1),"s"));   
        }
        else if(ad_result>20)
        {
            TR0 = 1;
        Lcd1602_Show_string(10,1,Dis_Str(data_str(time2),"s"));
        }
        else 
            TR0 = 0;

    //���²���Ϊʵ�ִﵽһ���ֱ���LCD����ʾ��Ӧ�ַ�
//    if(ad_result==50)       
//    flag=1;
//    if(ad_result==100)
//    flag=2;
//    if(ad_result==150)
//    flag=3;
//    switch(flag)
//    {
//        case 1:Lcd1602_Clear();Lcd1602_Show_string(0,1,"Didn't you eat?");flag = 0;delay(5000);break;
//        case 2:Lcd1602_Clear();Lcd1602_Show_string(0,1,"Louder");flag = 0;delay(5000);break;
//        case 3:Lcd1602_Clear();Lcd1602_Show_string(0,1,"Just so so");flag = 0;delay(5000);break;   
//    }
    Led_Show();     //ִ���Ųʵ�
}

}

void Time0_Init()
{
        TMOD = (TMOD & 0XF0)  | 0X01;      
        TL0 =(65536-1000);		
        TH0 = (62236-1000)/256;
        TF0 = 0;
//        TR0 = 1;
        EA = 1;
        ET0 = 1;
}


void Time0() interrupt 1
{
   static  unsigned int time_flag = 0;
        TH0 = (65536-1000)/256;
        TL0 = (65536-1000);
        TF0 = 0;
        time_flag++;
    if(time_flag==1000)
    {
        time_flag = 0;
        time1++;
        time2++;
    }
}

#include"pbdata.h"
unsigned int distence;
void Timer_Init()//���ö�ʱ��0��1����ģʽ1����  ��16λ��ʱ/����  ���ڼǸߵ�ƽʱ��
{
    TMOD=0X01; 
	TH0=0;
	TL0=0;	
	EA=1; 
	ET0=1; 
	TR0=0;
	TRIG = 0;
}

void StartModule()      //���ڷ��䲨��ʹ�ú������ã�ÿ��ִ��ʱ���ܷ��Ͳ�����while��ʵ�ֲ��Ϸ���
 {
 	TRIG = 1;
	delay(1844);        //��ʱһ��ʱ�䣬��֤�иߵ�ƽ
	TRIG = 0;
 }
 
  void Conut(void)          //���ڼ���ز��ľ���
{	

	unsigned int time;      
	time=TH0*256+TL0;
	TH0=0;
	TL0=0;
	distence=(time)/58;
}
unsigned int Get_Distence()     //ģ����ú�������÷��ؾ��룬��������ֵ��Ϊ����
{           
            Timer_Init();
            StartModule();
			while(!ECHO); 
			TR0=1; 
			while(ECHO); 
			TR0=0; 
            Conut(); 
            TH0=0;	 
            TL0=0;  
            return distence;
}
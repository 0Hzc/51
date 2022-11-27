#include"pbdata.h"
unsigned int mode = 0;
unsigned char start_button = 0;
extern unsigned int time;  
extern  unsigned  int   dir1 ;
extern  unsigned  int   dir2 ;
extern  unsigned  int   dir3 ;
unsigned char warn_flag;
void main()
{      
        BEEP = 0;       
        LED = 1;        
        Time1_init();       //��ʱ��1��ʼ�������ڶ�ʱ
        Time0_init();       //��ʱ��0��ʼ��,����PWM���Ƶ��ת��
        Lcd1602_Init();        //LCD1602��ʼ��
        Lcd1602_Show_string(5,1,"Waiting...");
        Lcd1602_Show_string(0,0,"Press Start");
    while(1)
    {   
        if(Button_Init()==4)    //���¿�ʼ��ť�����ҽ�ԭ��ʾ���
        {
            start_button = 1;
            Lcd1602_Clear();
            Lcd1602_Show_string(2,0,"Select Mode:");
            Lcd1602_Show_string(2,1,"HI/MED/LED");           
        }
        if(start_button==1)      //��ʼ���������º����ѡ���Ӧģʽ
    {           
        //����Ǹ����������£���Ӧִ�иð������� ִ�е��߼�
        if(Button_Init()==1)        //����1���£���Mode����ΪHI
        {          
            Lcd1602_Clear(); //��LCD1602ԭ����ʾ�����
            Lcd1602_Show_string(2,0,"Mode: HI");
            Lcd1602_Show_string(2,1,"Time:");   //LCD1602����ʾTime: 
            Lcd1602_Show_string(12,1,"s");//LCD1602��λS
            mode = 9;               //����ռ�ձ�Ϊ50%
            time = 0;
            TR1 = 1;    //�򿪶�ʱ��1;               
        }                     
        
        else if(Button_Init()==2)
        {
            Lcd1602_Clear(); 
            Lcd1602_Show_string(2,0,"Mode: MED");
            Lcd1602_Show_string(2,1,"Time:");   //LCD1602����ʾTime:
            Lcd1602_Show_string(12,1,"s");//LCD1602��λS            
            mode = 5;               //����ռ�ձ�Ϊ30%
            time = 0;
            TR1 = 1;
        }
        else if(Button_Init()==3)
        {
            Lcd1602_Clear(); 
            Lcd1602_Show_string(2,0,"Mode: LOW");
            Lcd1602_Show_string(2,1,"Time:");   //LCD1602����ʾTime:   
            Lcd1602_Show_string(12,1,"s");//LCD1602��λS          
            mode = 3;               //����ռ�ձ�Ϊ20%
            time = 0;
            TR1 = 1;
        }  
    
        Lcd1602_Show_string(8,1,data_str(time));//LCD1602��Ӧ��ʾϴ��ʱ��

            if((dir1 == 1)&&(time==60)) //�˴�Ϊ����ʱ�������㣬ִ�н��������߼�
            {
                dir1 = 0;
                TR1 = 0;
                time = 0;
                Lcd1602_Clear(); //��LCD1602ԭ����ʾ�����
                Lcd1602_Show_string(5,0,"Over");//LCD1602��Ӧ��ʾϴ��ʱ��    
                mode = 0;
                warn_flag = 1;

            }
             else if((dir2 == 2)&&(time==30)) //�˴�Ϊ����ʱ��������,ִ�н��������߼�
            {
                dir2 = 0;
                TR1 = 0;
                time = 0;
                Lcd1602_Clear(); //��LCD1602ԭ����ʾ�����
                Lcd1602_Show_string(5,0,"Over");//LCD1602��Ӧ��ʾϴ��ʱ�� 
                mode = 0;
                warn_flag = 1;
            }
            else  if((dir3 == 3)&&(time==20)) //�˴�Ϊ����ʱ�������㣬ִ�н��������߼�
            {
                dir3 = 0;
                TR1 = 0;
                time = 0;
                Lcd1602_Clear(); //��LCD1602ԭ����ʾ�����
                Lcd1602_Show_string(5,0,"Over");//LCD1602��Ӧ��ʾϴ��ʱ��  
                mode = 0;
                warn_flag = 1;
            }
     } 
    //����Ϊ���������߼�����
        if((start_button==1)&&(warn_flag ==1))      //��ʼ��ť�����£����ҽ�����overʱ��Ż����
        {
            LED = 0;
            BEEP = !BEEP;
            delay(450);
            LED = 1; 
            BEEP = 0;
            delay(450);            
        }
        
       }
 }


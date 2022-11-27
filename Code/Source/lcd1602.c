#include"pbdata.h"

void LCD1602_BusyCheck()       
{       
        unsigned int sta ;
        LCD1602_DATAPORT = 0XFF;   
        LCD1602_RS = 0;
        LCD1602_RW = 1;  
       do {     
        LCD1602_E = 1;
        sta = LCD1602_DATAPORT;
        LCD1602_E = 0;    
       }while((sta & 0x80 )== 0x80);    
}

void delay_lcd1602(unsigned int  ten_us)
{
        while(ten_us--);

}

void Lcd1602_Init()         //LCD��ʼ������
{
      Lcd1602_Write_cmd(0X38);      //��������8λ����ʾ2��
      Lcd1602_Write_cmd(0x0c);      //��ʾ���ܴ򿪣��޹�꣬�����˸
      Lcd1602_Write_cmd(0x06);      //д�������ݺ������ƣ���ʾ�����ƶ�
      Lcd1602_Write_cmd(0X01);      //����
      Lcd1602_Show_string(0,0,"      ");//����ʾ�հף����LCD1602��һ����ʾ����ʱǰ6�в���ʾ��bug
}
    

void Lcd1602_Write_cmd(unsigned int cmd)        //����ʱ��ͼ��дlcdд�����
{
    LCD1602_RS = 0; //ѡ��д����     ���������������ݣ����
    LCD1602_RW = 0;//ѡ��д    ���߶���д
    LCD1602_E = 0;
    LCD1602_DATAPORT = cmd;
    delay_lcd1602(1);
    LCD1602_E = 1;//������д��
    delay_lcd1602(1);
    LCD1602_E = 0;//д����ɣ���E����
}

void Lcd1602_Write_data(unsigned int dat)    //����ʱ��ͼ��дlcdд���ݺ���
{
    LCD1602_RS = 1; //ѡ��д����     ���������������ݣ����
    LCD1602_RW = 0;//ѡ��д    ���߶���д
    LCD1602_E = 0;
    LCD1602_DATAPORT = dat;
    delay_lcd1602(1);
    LCD1602_E = 1;//������д��
    delay_lcd1602(1);
    LCD1602_E = 0;//д����ɣ���E����
}

void Lcd1602_Clear()
{
    Lcd1602_Write_cmd(0x01);
}    

void Lcd1602_Show_string(unsigned char x,unsigned char y,unsigned char *str)//xΪ�У�yΪ��,strΪҪ��ʾ���ַ���
{
        unsigned char i = 0;//��¼��ǰΪ�ַ����ĵڼ����ַ�   
    LCD1602_BusyCheck();
    if(y>1||x>15)return;    //  ��������һ�У����ߵ�15�У�lcd�޷���ʾ����ֱ���˳�����
    
    if(y<1) //��һ����ʾ
    {
        while(*str!='\0')    //�ַ�����βΪ\0
        {
            if(i<16-x)//�ַ���������15�У����ڵ�һ����ʾ
            {
                    Lcd1602_Write_cmd(0x80+i+x);                
            }
            else//�ַ�������15�У������ڵڶ��м�����ʾ
            {
                    Lcd1602_Write_cmd(0x40+0x80+i+x-16);
            }
            Lcd1602_Write_data(*str);//���ַ����ĵ�һ����ʾ
            str++;//����ַ����һ���ƣ�������ʾֱ���Ƶ��ַ�����βΪ\0�Ƴ�ѭ��
            i++;        
        }        
    }
    else    //�ڶ�����ʾ
    {
         while(*str!='\0')    //�ַ�����βΪ\0
        {
            if(i<16-x)  //����ַ����Ȳ������ڶ��У����ڵڶ�����ʾ
            {
                    Lcd1602_Write_cmd(0x80+0x40+i+x);                
            }
            else//����ַ����ȳ����ڶ��У����ڵ�һ�м�����ʾ
            {
                    Lcd1602_Write_cmd(0x80+i+x-16);
            }
            Lcd1602_Write_data(*str);//���ַ����ĵ�һ����ʾ
            str++;//����ַ����һ���ƣ�������ʾֱ���Ƶ��ַ�����βΪ\0�Ƴ�ѭ��
            i++;        
        }    
    }
    
}
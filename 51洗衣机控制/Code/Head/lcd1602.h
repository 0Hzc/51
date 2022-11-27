#ifndef __LCD1602_H__
#define __LCD1602_H__

#include<reg51.h>
sbit LCD1602_RS = P2^6;
sbit LCD1602_RW = P2^5;
sbit LCD1602_E = P2^7;

#define LCD1602_DATAPORT P0

void Lcd1602_Init();//LCD��ʼ������
void Lcd1602_Write_cmd(unsigned int cmd);//lcdд�����
void Lcd1602_Write_data(unsigned int dat);//lcdд���ݺ���
void Lcd1602_Clear();//lcd��������
void Lcd1602_Show_string(unsigned char x,unsigned char y,unsigned char *str);//xΪ�У�yΪ��,strΪҪ��ʾ���ַ���
#endif
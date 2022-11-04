#ifndef __12864_H__
#define __12864_H__
#include  "reg52.h"
#define uchar unsigned char
#define uint  unsigned int
#define LCD_data  P0             //数据口   
sbit LCD_RS  =  P2^5;            //寄存器选择输入 
sbit LCD_RW  =  P2^6;            //液晶读/写控制
sbit LCD_EN  =  P2^7; 
sbit LCD_psb  = P3^2;           //液晶使能控制
#define delayNOP(); {_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();};
void  dataconv();
void lcd_pos(uchar X,uchar Y);  //确定显示位置
bit lcd_busy();
void lcd_wcmd(uchar cmd);
void lcd_wdat(uchar dat);
void lcd_init();
void display_welcome2();
void display_cardnum();
void display_cardnum1();
void display_cardnum2();
void display_type();//寻到卡后显示出该卡的类型	 
void display_xiaofeicarddat(unsigned char table[],unsigned char date);
void display_carddat();    //余额
void delay(int ms);
void diaplay(unsigned char addr,unsigned char *p);
#endif

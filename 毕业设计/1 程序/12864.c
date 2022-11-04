#include <intrins.h>	
#include <12864.h>
#include <stdio.h>
//#Include <string>
extern unsigned char g_ucTempbuf[20]; 
extern unsigned char receive[16];
extern unsigned char g_ucTempbuf1[10]; 
uchar code table3[]={"卡号:"};
uchar code table4[]={"卡类型: 门禁卡"};
float f_temp;
unsigned char bai,shi,ge;
void STC_send_bluetooth(unsigned char a);
/*******************************************************************/
/*                                                                 */
/*  延时函数                                                       */
/*                                                                 */
/*******************************************************************/
void delay(int ms)
{
    while(ms--)
	{
      uchar i;
	  for(i=0;i<250;i++)  
	   {
	    _nop_();			   
		_nop_();
		_nop_();
		_nop_();
	   }
	}
}

/*******************************************************************/
/*                                                                 */
/*检查LCD忙状态                                                    */
/*lcd_busy为1时，忙，等待。lcd-busy为0时,闲，可写指令与数据。      */
/*                                                                 */
/*******************************************************************/
bit lcd_busy()
 {                          
    bit result;
    LCD_RS = 0;
    LCD_RW = 1;
    LCD_EN = 1;
    delayNOP();
    result = (bit)(P0&0x80);
    LCD_EN = 0;
    return(result); 
 }
/*******************************************************************/
/*                                                                 */
/*写指令数据到LCD                                                  */
/*RS=L，RW=L，E=高脉冲，D0-D7=指令码。                             */
/*                                                                 */
/*******************************************************************/
void lcd_wcmd(uchar cmd)
{                          
    LCD_RS = 0;
    LCD_RW = 0;
    LCD_EN = 0;
    _nop_();
    _nop_(); 
    P0 = cmd;
    delayNOP();
    LCD_EN = 1;//下降沿写入
    delayNOP();
    LCD_EN = 0;  
}
/*******************************************************************/
/*                                                                 */
/*写显示数据到LCD                                                  */
/*RS=H，RW=L，E=高脉冲，D0-D7=数据。                               */
/*                                                                 */
/*******************************************************************/
void lcd_wdat(uchar dat)
{                          
    LCD_RS = 1;
    LCD_RW = 0;
    LCD_EN = 0;
    P0 = dat;
    delayNOP();
    LCD_EN = 1;
    delayNOP();
    LCD_EN = 0; 
}
/*******************************************************************/
/*                                                                 */
/*  LCD初始化设定                                                  */
/*                                                                 */
/*******************************************************************/
void lcd_init()
{ 
     LCD_psb = 1;
    lcd_wcmd(0x34);      //扩充指令操作
    delay(5);
    lcd_wcmd(0x30);      //基本指令操作
    delay(5);
    lcd_wcmd(0x0C);      //显示开，关光标
    delay(5);
    lcd_wcmd(0x01);      //清除LCD的显示内容
    delay(5);
}

/*********************************************************/
/*                                                       */
/* 设定显示位置                                          */
/*                                                       */
/*********************************************************/
void lcd_pos(uchar X,uchar Y)
{                          
   uchar  pos;
   if (X==0)
     {X=0x80;}
   else if (X==1)
     {X=0x90;}
   else if (X==2)
     {X=0x88;}
   else if (X==3)
     {X=0x98;}
   pos = X+Y ;  
   lcd_wcmd(pos);     //显示地址
}

void LCD_Data(unsigned char LCDbyte )
{		 //unsigned char bai,shi,ge;
		//十进制
	 bai=LCDbyte/100;
	 shi=LCDbyte%100/10;
	 ge=LCDbyte%100%10;
	
	 
	 //STC_send_bluetooth(0x43);		  //字符C的ASCII码，作为此次发送完毕的结束标志

}

void display_type()//寻到卡后显示出该卡的类型
{
	unsigned char num;
    lcd_wcmd(0x01);      //清除LCD的显示内容
    delay(5);
    lcd_pos(1,0);             //设置显示位置为第四行的第1个字符
	for(num=0;num<14;num++)    //第一行要显示的11个字符
	{
	lcd_wdat(table4[num]);	
		
	}

}

void display_cardnum()	//读卡号
{	 	unsigned char i = 0;
       	//  unsigned char shu0,shu1,shu2,shu3;
	unsigned char num;
    lcd_pos(2,0);             //设置显示位置为第四行的第1个字符
	for(num=0;num<6;num++)    //第一行要显示的11个字符
	{
	 lcd_wdat(table3[num]);	
	}
		 // STC_send_bluetooth('A');
	 //delay(35);
	for(num=0;num<4;num++)//第一行要显示的11个字符
	{
		lcd_pos(2,num+3);
		LCD_Data(g_ucTempbuf[num]);//写数
		
		
		
	// STC_send_bluetooth(bai+0x30);
	// STC_send_bluetooth(shi+0x30);
	 //STC_send_bluetooth(ge+0x30);
		 lcd_wdat(bai+0x30);
	 lcd_wdat(shi+0x30);
	// lcd_wdat(ge+0x30);
				  	}
}


void display_cardnum1()	//读卡号
{	 	unsigned char i = 0;
       	//  unsigned char shu0,shu1,shu2,shu3;
	unsigned char num;
	 STC_send_bluetooth('A');
	 delay(35);
	for(num=0;num<4;num++)//第一行要显示的11个字符
	{

		LCD_Data(g_ucTempbuf[num]);//写数
	 STC_send_bluetooth(bai+0x30);
	 STC_send_bluetooth(shi+0x30);
				  	}
}
void display_cardnum2()	
{
unsigned char num;
	
for(num=1;num<9;num++)//第一行要显示的11个字符
	{
	 STC_send_bluetooth(g_ucTempbuf1[num]);
}
     

}
void diaplay(unsigned char addr,unsigned char *str)
{
	lcd_pos(addr,0);             //设置显示位置为第四行的第1个字符
    while(*str!='\0')
	{
	  lcd_wdat(*str);
	  str++;
	}

}

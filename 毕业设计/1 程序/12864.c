#include <intrins.h>	
#include <12864.h>
#include <stdio.h>
//#Include <string>
extern unsigned char g_ucTempbuf[20]; 
extern unsigned char receive[16];
extern unsigned char g_ucTempbuf1[10]; 
uchar code table3[]={"����:"};
uchar code table4[]={"������: �Ž���"};
float f_temp;
unsigned char bai,shi,ge;
void STC_send_bluetooth(unsigned char a);
/*******************************************************************/
/*                                                                 */
/*  ��ʱ����                                                       */
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
/*���LCDæ״̬                                                    */
/*lcd_busyΪ1ʱ��æ���ȴ���lcd-busyΪ0ʱ,�У���дָ�������ݡ�      */
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
/*дָ�����ݵ�LCD                                                  */
/*RS=L��RW=L��E=�����壬D0-D7=ָ���롣                             */
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
    LCD_EN = 1;//�½���д��
    delayNOP();
    LCD_EN = 0;  
}
/*******************************************************************/
/*                                                                 */
/*д��ʾ���ݵ�LCD                                                  */
/*RS=H��RW=L��E=�����壬D0-D7=���ݡ�                               */
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
/*  LCD��ʼ���趨                                                  */
/*                                                                 */
/*******************************************************************/
void lcd_init()
{ 
     LCD_psb = 1;
    lcd_wcmd(0x34);      //����ָ�����
    delay(5);
    lcd_wcmd(0x30);      //����ָ�����
    delay(5);
    lcd_wcmd(0x0C);      //��ʾ�����ع��
    delay(5);
    lcd_wcmd(0x01);      //���LCD����ʾ����
    delay(5);
}

/*********************************************************/
/*                                                       */
/* �趨��ʾλ��                                          */
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
   lcd_wcmd(pos);     //��ʾ��ַ
}

void LCD_Data(unsigned char LCDbyte )
{		 //unsigned char bai,shi,ge;
		//ʮ����
	 bai=LCDbyte/100;
	 shi=LCDbyte%100/10;
	 ge=LCDbyte%100%10;
	
	 
	 //STC_send_bluetooth(0x43);		  //�ַ�C��ASCII�룬��Ϊ�˴η�����ϵĽ�����־

}

void display_type()//Ѱ��������ʾ���ÿ�������
{
	unsigned char num;
    lcd_wcmd(0x01);      //���LCD����ʾ����
    delay(5);
    lcd_pos(1,0);             //������ʾλ��Ϊ�����еĵ�1���ַ�
	for(num=0;num<14;num++)    //��һ��Ҫ��ʾ��11���ַ�
	{
	lcd_wdat(table4[num]);	
		
	}

}

void display_cardnum()	//������
{	 	unsigned char i = 0;
       	//  unsigned char shu0,shu1,shu2,shu3;
	unsigned char num;
    lcd_pos(2,0);             //������ʾλ��Ϊ�����еĵ�1���ַ�
	for(num=0;num<6;num++)    //��һ��Ҫ��ʾ��11���ַ�
	{
	 lcd_wdat(table3[num]);	
	}
		 // STC_send_bluetooth('A');
	 //delay(35);
	for(num=0;num<4;num++)//��һ��Ҫ��ʾ��11���ַ�
	{
		lcd_pos(2,num+3);
		LCD_Data(g_ucTempbuf[num]);//д��
		
		
		
	// STC_send_bluetooth(bai+0x30);
	// STC_send_bluetooth(shi+0x30);
	 //STC_send_bluetooth(ge+0x30);
		 lcd_wdat(bai+0x30);
	 lcd_wdat(shi+0x30);
	// lcd_wdat(ge+0x30);
				  	}
}


void display_cardnum1()	//������
{	 	unsigned char i = 0;
       	//  unsigned char shu0,shu1,shu2,shu3;
	unsigned char num;
	 STC_send_bluetooth('A');
	 delay(35);
	for(num=0;num<4;num++)//��һ��Ҫ��ʾ��11���ַ�
	{

		LCD_Data(g_ucTempbuf[num]);//д��
	 STC_send_bluetooth(bai+0x30);
	 STC_send_bluetooth(shi+0x30);
				  	}
}
void display_cardnum2()	
{
unsigned char num;
	
for(num=1;num<9;num++)//��һ��Ҫ��ʾ��11���ַ�
	{
	 STC_send_bluetooth(g_ucTempbuf1[num]);
}
     

}
void diaplay(unsigned char addr,unsigned char *str)
{
	lcd_pos(addr,0);             //������ʾλ��Ϊ�����еĵ�1���ַ�
    while(*str!='\0')
	{
	  lcd_wdat(*str);
	  str++;
	}

}

#include "reg52.h"
#include"12864.h"
#include "MFRC522.h"
#include <intrins.h>
bit  flag_REC=0; 
bit  flag    =0; 
unsigned char  ii=0,mm=0,m1=20;
int  key_bit=0,YY=-2;//��λ������
int objTemp,envTemp,Tem;	 //�����¶Ⱥͻ����¶�
unsigned int  dat=0;
sbit     LED1  =    P2^2;//���Ƶ�
sbit     LED  =     P2^3;//���Ƽ̵���
sbit     beep  =    P2^4;//���Ʒ�����
uchar code dis77[] = {"  ϵͳ�Ѿ�����  "};
uchar code dis88[] = {"  ����ϵ����Ա"};
uchar code dis1[] = {"  �ﻶӭʹ�á�  "};
uchar code dis2[] = {"�Ž�������ϵͳ  "};
uchar code dis11[] = {"*              "};
uchar code dis12[] = {"* * * * * * * * "};
uchar code dis4[] = {"  ���������  "};
uchar code dis13[] ={"�������λ���룺"};
uchar code dis5[] ={"  ������IC����  "};
uchar code dis14[] ={"    �������   "};
uchar code dis15[] ={"    �������    "};
uchar code table8[]={"ע��ɹ�:      "};
uchar code table9[]={"�����ɹ�:      "};
uchar code table10[]={"��Ч��:        "};
uchar code dis8[] = {"                "};
uchar code dis3[] = {"                "};
uchar code dis7[] = {"                "};
uchar code table33[]={"  ����:"};
unsigned char code data1[16] = {0x12,0x34,0x56,0x78,0xED,0xCB,0xA9,0x87,0x12,0x34,0x56,0x78,0x01,0xFE,0x01,0xFE};
unsigned char code  Yankey[6]  = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}; //ԭʼ����
unsigned char code  XiugaiYunKey[16]= {0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0xFF,0x07,0x80,0x69,0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};	 //�޸ĺ������
unsigned char code  Nowkey[6]  = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE}; //xianzia ����
unsigned char code  XiugaiNowKey[16]= {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x07,0x80,0x69,0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};	 //�޸ĺ������
unsigned char g_ucTempbuf[20];
unsigned char g_ucTempbuf1[10];
char code tab[4][4]={	
												
							{ 'A','8','4','0'},
                  			{'B','9','5','1'},
                  			{'C','D','6','2'},
                  			{'E','*','7','3'}
                                           };       //0��F��16����ֲ

unsigned char receive[16];
void InitializeSystem();
void Zhu_Ce();//ע�� �˻�
void Ce_Xiao();//������
void YunXingZhong();  
void WaitCardOff(void); 
void send_ss();
sbit SCL=P2^0;//ʱ����
sbit SDA=P2^1;//������ 
void start_bit(); //MLX90614 ����ʼλ�ӳ���
void stop_bit(); //MLX90614 ������λ�ӳ���
unsigned char rx_byte(void); //MLX90614 �����ֽ��ӳ���
void send_bit(void); //MLX90614 ����λ�ӳ���
void tx_byte(unsigned char dat_byte); //MLX90614 �����ֽ��ӳ���
void receive_bit(void); //MLX90614 ����λ�ӳ���
unsigned int ReadObjectTemp(void); //���¶�����
unsigned int ReadEnvironTemp(void);
#define Nack_counter 10
//************���ݶ���****************
unsigned char bit_out=1;
unsigned char bit_in=1;
unsigned char DataH,DataL,Pecreg;
void STC_send_bluetooth(unsigned char a)	
{							//ע�⣺����Ƭ��TXD��P3.1��������������������P3.1�˽��������衣���β�����Ҫ����������
	TI=0;	
	SBUF=a;
	while(TI==0);
	TI=0;}
void start_bit(void)
{
	SDA=1;
	_nop_();_nop_();_nop_();_nop_();_nop_();
	SCL=1;
	_nop_();_nop_();_nop_();_nop_();_nop_();
	SDA=0;
	_nop_();_nop_();_nop_();_nop_();_nop_();
	SCL=0;
	_nop_();_nop_();_nop_();_nop_();_nop_();
}

void stop_bit(void)
{
	SCL=0;
	_nop_();_nop_();_nop_();_nop_();_nop_();
	SDA=0;
	_nop_();_nop_();_nop_();_nop_();_nop_();
	SCL=1;
	_nop_();_nop_();_nop_();_nop_();_nop_();
	SDA=1;
}


//---------����һ���ֽ�---------
void tx_byte(unsigned char dat_byte)
{
	char i,n,dat;
	n=Nack_counter;

	dat=dat_byte;
	for(i=0;i<8;i++)
	{
		if(dat&0x80)
		bit_out=1;
		else
		bit_out=0;
		send_bit();
		dat=dat<<1;
	}
	receive_bit();
	if(bit_in==1)
	{
		stop_bit();
		if(n!=0)
		{n--;}
		else
			return;
	}
	else
		return;
	start_bit();
	tx_byte(dat_byte);		//��������ص�
}

////---------����һ���ֽ�---------
//void tx_byte(unsigned char dat_byte)
//{
//	char i,n,dat;
//	n=Nack_counter;
//	TX_again:
//	dat=dat_byte;
//	for(i=0;i<8;i++)
//	{
//		if(dat&0x80)
//		bit_out=1;
//		else
//		bit_out=0;
//		send_bit();
//		dat=dat<<1;
//	}
//	receive_bit();
//	if(bit_in==1)
//	{
//		stop_bit();
//		if(n!=0)
//		{n--;goto Repeat;}
//		else
//		goto exit;
//	}
//	else
//	goto exit;
//	Repeat:
//	start_bit();
//	goto TX_again;
//	exit: ;
//}
//-----------����һ��λ---------
void send_bit(void)
{
	if(bit_out==0)
		SDA=0;
	else
		SDA=1;
	_nop_();
	SCL=1;
	_nop_();_nop_();_nop_();_nop_();
	_nop_();_nop_();_nop_();_nop_();
	SCL=0;
	_nop_();_nop_();_nop_();_nop_();
	_nop_();_nop_();_nop_();_nop_();
}
//----------����һ���ֽ�--------
unsigned char rx_byte(void)
{
	unsigned char i,dat;
	dat=0;
	for(i=0;i<8;i++)
	{
		dat=dat<<1;
		receive_bit();
		if(bit_in==1)
		dat=dat+1;
	}
	send_bit();
	return dat;
}
//----------����һ��λ----------
void receive_bit(void)
{
	SDA=1;bit_in=1;
	SCL=1;
	_nop_();_nop_();_nop_();_nop_();
	_nop_();_nop_();_nop_();_nop_();
	bit_in=SDA;
	_nop_();
	SCL=0;
	_nop_();_nop_();_nop_();_nop_();
	_nop_();_nop_();_nop_();_nop_();
}

//------------------------------
unsigned int ReadObjectTemp(void)
{
	start_bit();
	tx_byte(0x00); //Send SlaveAddress
	tx_byte(0x07); //Send Command
	start_bit();
	tx_byte(0x01);
	bit_out=0;
	DataL=rx_byte();
	bit_out=0;
	DataH=rx_byte();
	bit_out=1;
	Pecreg=rx_byte();
	stop_bit();
	return(DataH*256+DataL);
}

unsigned int ReadEnvironTemp(void)
{
	start_bit();
	tx_byte(0x00); //Send SlaveAddress
	tx_byte(0x06); //Send Command
	start_bit();
	tx_byte(0x01);
	bit_out=0;
	DataL=rx_byte();
	bit_out=0;
	DataH=rx_byte();
	bit_out=1;
	Pecreg=rx_byte();
	stop_bit();
	return(DataH*256+DataL);
}        
void kbscan()          //����ɨ��
	{
 	unsigned char hang,lie,key,num; //��������� ��  ����  key ����
	if(P1!=0x0f)  //��ⰴ������
	delay(5);//����
	if(P1!=0x0f) //ȷ�ϰ�������
		{
		switch(P1&0x0f) //�����
				{
				case 0x0e:lie=0;break; //��ֵlie=0;
				case 0x0d:lie=1;break;  //��ֵlie=1;
				case 0x0b:lie=2;break;   //��ֵlie=2;
				case 0x07:lie=3;break;     //��ֵlie=3;
				} 
		P1=0xf0;
		P1=0xf0;
		switch(P1&0xf0)  //�����
				{
				case 0xe0:hang=0;break;//��ֵhang=0;
				case 0xd0:hang=1;break;//��ֵhang=1;
				case 0xb0:hang=2;break;//��ֵhang=2
				case 0x70:hang=3;break;//��ֵhang=3;
				}
		P1=0x0f;
		if(key_bit==2) YY=YY+2;	
		while(P1!=0x0f);
		key=tab[hang][lie];  //�������Ӧ�Ҿ��󰴼�ֵ
		if((key_bit==0)||(key_bit==1))
		if(key=='A'){++key_bit;if(key_bit==2) { key_bit=0;YY=0; }}  //�˵�����
		if(key=='B'){Ce_Xiao();YY=0;} //��������
		if(key=='C'){Zhu_Ce();YY=0; } //ע�ᰴ��
		if(key_bit==2)  //�����λ����
		 {
		if(key=='D'){YY=0; diaplay(2,dis3);}  //ɾ������
		if((key=='0')||(key=='1')||(key=='2')||(key=='3')||(key=='4')||(key=='5')||(key=='6')||(key=='7')||(key=='8')||(key=='9'))//����ֵ0��9
        if(YY<17){lcd_pos(2,0); for(num=0;num<YY;num++){lcd_wdat(dis12[num]);} g_ucTempbuf1[YY/2]=key; } //�ж�����С��8λ
        if(key=='*') {
          STC_send_bluetooth('C');
	      delay(10);
		  STC_send_bluetooth(objTemp/100%10+0x30);
	      STC_send_bluetooth(objTemp/10%10+0x30);
		  STC_send_bluetooth('.'); 
		  STC_send_bluetooth(objTemp%10+0x30);
		  delay(10);
		  display_cardnum2();
		  }
		   } //����ȷ�ϰ��� ���Ͱ�λ�������λ��
		if(key=='E'){LED=0;LED1=0;beep=0;	delay(200);beep=1; LED1=1;LED=1; } //���ƿ���

}
	else
		key=0;
	//return (key);
	}
	
	void wendu()
{
  	unsigned char num;
    lcd_pos(3,0);             //������ʾλ��Ϊ�����еĵ�1���ַ�
	for(num=0;num<8;num++)    //��һ��Ҫ��ʾ��11���ַ�
	{
	 lcd_wdat(table33[num]);	
	}
  Tem=ReadObjectTemp();	 //��ȡʵ���¶�
  objTemp=((float)(Tem)*0.02-271.15)*10;
	Tem=ReadEnvironTemp();	 //��ȡ�����¶�
	envTemp=((float)(Tem)*0.02-271.15)*10;
		lcd_pos(3,4);
	 lcd_wdat(objTemp/100%10+0x30);
	 lcd_wdat(objTemp/10%10+0x30);
	 lcd_wdat('.');
	 lcd_wdat(objTemp%10+0x30);
	 lcd_wdat('C');
 }														
void main()
{	  
    lcd_init();	 //Һ����ʼ��
    InitializeSystem( );//���ڳ�ʼ��
    PcdReset();		 //��Ƶ��λ
    PcdAntennaOff();   //��Ƶ�ر�����
    PcdAntennaOn();	   //��Ƶ������
    M500PcdConfigISOType( 'A' );
    LED=1;
	LED1=1;
	beep=1;
	m1=45;
   while(1)
    { 
	   	m1++;
		if(m1>50)
		{
	   wendu();m1=0;}
	   if(objTemp<372)
	   {
	   beep=1;
	   kbscan();
	   if(key_bit==0)//�ϵ����
	   {
	    diaplay(0,dis8);
	    diaplay(1,dis1);
	    diaplay(2,dis2);
	   // diaplay(3,dis8);
	    YunXingZhong();
		}
		 if(key_bit==1)//�������
	   {  
	    diaplay(0,dis3);
	    diaplay(1,dis5);
	    diaplay(2,dis4);
		delay(2);
	    //diaplay(3,dis3);
		}
		if(key_bit==2)//�����λ����
		{
        diaplay(0,dis3);
	    diaplay(1,dis13);
	   // diaplay(3,dis3);
     }
		 if(key_bit==3)  //�������
		{
        diaplay(0,dis3);
		diaplay(1,dis3);
	    diaplay(2,dis14);
	    //diaplay(3,dis3);
		beep=0;	delay(600);beep=1;
		key_bit=0;
     }
		 if(key_bit==4) //�������
		{
        diaplay(0,dis3);
		diaplay(1,dis3);
	    diaplay(2,dis15);
	    //diaplay(3,dis3);
		mm=0; LED=0;LED1=0;beep=0;	delay(200);beep=1; LED1=1;LED=1;ii=0;delay(400); //�򿪼̵���
		key_bit=0;
     }
		 if(mm==3)
		 {
      while(1)
			{
        diaplay(0,dis3);
		diaplay(1,dis77);
	    diaplay(2,dis88);
	   // diaplay(3,dis3);
          }
    } 
	}
	else {beep=0;}	
	}
  
}




/////////////////////////////////////////////////////////////////////
//ϵͳ��ʼ��
/////////////////////////////////////////////////////////////////////
void InitializeSystem()
{
	P0 = 0xFF; P1 = 0xFF; P3 = 0xFF;P2 = 0xFF;
    TMOD = 0x21;  
    TH1 = 0xFd;  		   //11.0592M����9600������
    TL1 = 0xFd;
    TH0 = 0xfe;  		   //11.0592M����9600������
    TL0 = 0x33; 	
	
	ET0 = 1;
    TR0 = 1;

	SM0 = 0;
	SM1 = 1;
	REN = 1;//�����ڽ��� 
	TR1 = 1;
	ES = 1;//������ �ж�
	EA = 1; 

}  

void timer0() interrupt 1          /* T0�жϷ������ */
{
	TH0=0xfe;  		   //11.0592M����9600������
    TL0=0xee;
}

void sint() interrupt 4	  //�жϽ���3���ֽ�
{ 
   
	if(RI)	                 //�Ƿ�����ж�
    {
       RI=0;
       dat=SBUF;	
			if(dat=='D')	//����IC���Ƿ���Ч�� 
          {
			 ii=0;
              }
	   	if(dat=='E')    //
          {						
			 ii=2;
              }
		if(dat=='F')    //
          {						
			 ii=3;
              }
		if(dat=='G')    //
          {						
			     ii=4;
             }
			if(ii==0){beep=0;	delay(400);beep=1; YY=0;}
	        if(ii==2){key_bit=2;diaplay(2,dis3);YY=0;}
			if(ii==4){key_bit=4;YY=0;}//��Ч�� ���ҿ��Ƽ̵�������
			if(ii==3){key_bit=3; YY=0;mm++;}
	 }
}

void Zhu_Ce()//ע�� �˻�
{		
         while(1){
  	     unsigned char status;
         status = PcdRequest(PICC_REQALL, g_ucTempbuf);//Ѱ��
         if (status != MI_OK)
         {    
			  break;
         }
		display_type();//Ѱ��������ʾ���ÿ�������
	    status = PcdAnticoll(g_ucTempbuf);//����ײ
         if (status != MI_OK)
         {     break;   }
	    display_cardnum();//��ʾѰ���Ŀ������к�
		status = PcdSelect(g_ucTempbuf);//ѡ����Ƭ
         if (status != MI_OK)
         {      break;    }        
         status = PcdAuthState(PICC_AUTHENT1A,23,Yankey, g_ucTempbuf);//��֤��Ƭ���루ԭʼ�����룩FF
         if (status != MI_OK)
        {    	  break;    }//	 LED_GREEN = 1;
		 status = PcdWrite(22, data1);//д��
         if (status != MI_OK)
         {     break;  }
		 status = PcdWrite(23,XiugaiYunKey);//д��//�޸ĺ������ FE
         if (status != MI_OK)
         {     break;    }
	      diaplay(3,table8);
		   beep=0; //��������һ��	
			delay(40);
			beep=1; 
		  WaitCardOff();//�ȴ����뿪����			 	         
	   	  PcdHalt();//��ֹ
		  }
		  	 
}
void Ce_Xiao()//������
{
        unsigned char status;
		while(1)
		{
         status = PcdRequest(PICC_REQALL, g_ucTempbuf);//Ѱ��
         if (status != MI_OK)
         {    
			    break;
         }
		display_type();//Ѱ��������ʾ���ÿ�������
	    status = PcdAnticoll(g_ucTempbuf);//����ײ
         if (status != MI_OK)
         {     break;    }
	    display_cardnum();//��ʾѰ���Ŀ������к�
		status = PcdSelect(g_ucTempbuf);//ѡ����Ƭ
         if (status != MI_OK)
         {    break;   }        
         status = PcdAuthState(PICC_AUTHENT1A,23, Nowkey, g_ucTempbuf);//��֤��Ƭ���루ԭʼ�����룩FE
         if (status != MI_OK)
        {    	  break;    }
		 status = PcdWrite(23,XiugaiNowKey);//д��//�޸ĺ������FF
         if (status != MI_OK)
         {     break;    }
		    beep=0; //��������һ��	
			delay(40);
			beep=1; 
          diaplay(3,table9);
		  WaitCardOff();//�ȴ����뿪����			 	         
	   	  PcdHalt();//��ֹ	
		  } 
}


void YunXingZhong()	//����������
{  
  unsigned char status;
   while(1)
   {
   	     status = PcdRequest(PICC_REQALL, g_ucTempbuf);//Ѱ��
         if (status != MI_OK)
         {     
			  break;
         }
		  display_type();//Ѱ��������ʾ���ÿ�������
	      status = PcdAnticoll(g_ucTempbuf);//����ײ
           if (status != MI_OK)
            {    break;    }
           display_cardnum();//��ʾѰ���Ŀ������к�
				
		 status = PcdSelect(g_ucTempbuf);//ѡ����Ƭ
         if (status != MI_OK)
         {    break;   }
         
         status = PcdAuthState(PICC_AUTHENT1A,23,Nowkey,g_ucTempbuf);//��֤��Ƭ����
         if (status != MI_OK)
         {  diaplay(3,table10);
		    beep=0;  //������������	
			delay(40);
			beep=1;
			delay(40); 
			beep=0; 	
			delay(40);
			beep=1; 
		    WaitCardOff();//�ȴ����뿪����
		    break; 
		 }
		  display_cardnum1();
      // display_cardnum();//��ʾѰ���Ŀ������к�
		    if (status != MI_OK)
         { // LED_GREEN = 1;
		  break;   }   
     //  display_cardnum();//��ʾѰ���Ŀ������к�
		 status = PcdBakValue(22, 21);//�鱸��
         if (status != MI_OK)
         {   break;   }
         status = PcdRead(21, g_ucTempbuf);//����
         if (status != MI_OK)	
         {   break;   }
		    beep=0; //��������һ��	
			delay(40);
			beep=1; 
	      WaitCardOff();//�ȴ����뿪����			 	         
		  PcdHalt();
		  
   }
}


void WaitCardOff(void)	//�ȴ����뿪
{
  char  status;
  unsigned char	TagType[2];

	while(1)
	{
		status = PcdRequest(PICC_REQALL , TagType);
		if(status)
		{
			status = PcdRequest(PICC_REQALL , TagType);
			if(status)
			{
				status = PcdRequest(PICC_REQALL , TagType);
				if(status)
				{
					return;
				}
			}
		}
		delay(100);
	}
}

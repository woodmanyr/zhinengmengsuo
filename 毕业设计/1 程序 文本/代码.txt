#include "reg52.h"
#include"12864.h"
#include "MFRC522.h"
#include <intrins.h>
bit  flag_REC=0; 
bit  flag    =0; 
unsigned char  ii=0,mm=0,m1=20;
int  key_bit=0,YY=-2;//上位机按键
int objTemp,envTemp,Tem;	 //物体温度和环境温度
unsigned int  dat=0;
sbit     LED1  =    P2^2;//控制灯
sbit     LED  =     P2^3;//控制继电器
sbit     beep  =    P2^4;//控制蜂鸣器
uchar code dis77[] = {"  系统已经锁定  "};
uchar code dis88[] = {"  请联系管理员"};
uchar code dis1[] = {"  ★欢迎使用★  "};
uchar code dis2[] = {"门禁卡管理系统  "};
uchar code dis11[] = {"*              "};
uchar code dis12[] = {"* * * * * * * * "};
uchar code dis4[] = {"  ★管理界面★  "};
uchar code dis13[] ={"请输入八位密码："};
uchar code dis5[] ={"  ★智能IC卡★  "};
uchar code dis14[] ={"    密码错误   "};
uchar code dis15[] ={"    密码符合    "};
uchar code table8[]={"注册成功:      "};
uchar code table9[]={"撤销成功:      "};
uchar code table10[]={"无效卡:        "};
uchar code dis8[] = {"                "};
uchar code dis3[] = {"                "};
uchar code dis7[] = {"                "};
uchar code table33[]={"  体温:"};
unsigned char code data1[16] = {0x12,0x34,0x56,0x78,0xED,0xCB,0xA9,0x87,0x12,0x34,0x56,0x78,0x01,0xFE,0x01,0xFE};
unsigned char code  Yankey[6]  = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}; //原始密码
unsigned char code  XiugaiYunKey[16]= {0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0xFF,0x07,0x80,0x69,0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};	 //修改后的密码
unsigned char code  Nowkey[6]  = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE}; //xianzia 密码
unsigned char code  XiugaiNowKey[16]= {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x07,0x80,0x69,0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};	 //修改后的密码
unsigned char g_ucTempbuf[20];
unsigned char g_ucTempbuf1[10];
char code tab[4][4]={	
												
							{ 'A','8','4','0'},
                  			{'B','9','5','1'},
                  			{'C','D','6','2'},
                  			{'E','*','7','3'}
                                           };       //0到F的16个键植

unsigned char receive[16];
void InitializeSystem();
void Zhu_Ce();//注册 账户
void Ce_Xiao();//撤销卡
void YunXingZhong();  
void WaitCardOff(void); 
void send_ss();
sbit SCL=P2^0;//时钟线
sbit SDA=P2^1;//数据线 
void start_bit(); //MLX90614 发起始位子程序
void stop_bit(); //MLX90614 发结束位子程序
unsigned char rx_byte(void); //MLX90614 接收字节子程序
void send_bit(void); //MLX90614 发送位子程序
void tx_byte(unsigned char dat_byte); //MLX90614 接收字节子程序
void receive_bit(void); //MLX90614 接收位子程序
unsigned int ReadObjectTemp(void); //读温度数据
unsigned int ReadEnvironTemp(void);
#define Nack_counter 10
//************数据定义****************
unsigned char bit_out=1;
unsigned char bit_in=1;
unsigned char DataH,DataL,Pecreg;
void STC_send_bluetooth(unsigned char a)	
{							//注意：若单片机TXD（P3.1）无上拉能力，必须在P3.1端接上拉电阻。本次测试需要接上拉电阻
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


//---------发送一个字节---------
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
	tx_byte(dat_byte);		//函数自身回调
}

////---------发送一个字节---------
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
//-----------发送一个位---------
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
//----------接收一个字节--------
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
//----------接收一个位----------
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
void kbscan()          //键盘扫描
	{
 	unsigned char hang,lie,key,num; //定义变量行 列  按键  key 变量
	if(P1!=0x0f)  //检测按键按下
	delay(5);//消抖
	if(P1!=0x0f) //确认按键按下
		{
		switch(P1&0x0f) //检测列
				{
				case 0x0e:lie=0;break; //赋值lie=0;
				case 0x0d:lie=1;break;  //赋值lie=1;
				case 0x0b:lie=2;break;   //赋值lie=2;
				case 0x07:lie=3;break;     //赋值lie=3;
				} 
		P1=0xf0;
		P1=0xf0;
		switch(P1&0xf0)  //检测行
				{
				case 0xe0:hang=0;break;//赋值hang=0;
				case 0xd0:hang=1;break;//赋值hang=1;
				case 0xb0:hang=2;break;//赋值hang=2
				case 0x70:hang=3;break;//赋值hang=3;
				}
		P1=0x0f;
		if(key_bit==2) YY=YY+2;	
		while(P1!=0x0f);
		key=tab[hang][lie];  //在数组对应找矩阵按键值
		if((key_bit==0)||(key_bit==1))
		if(key=='A'){++key_bit;if(key_bit==2) { key_bit=0;YY=0; }}  //菜单按键
		if(key=='B'){Ce_Xiao();YY=0;} //撤销按键
		if(key=='C'){Zhu_Ce();YY=0; } //注册按键
		if(key_bit==2)  //输入八位密码
		 {
		if(key=='D'){YY=0; diaplay(2,dis3);}  //删除按键
		if((key=='0')||(key=='1')||(key=='2')||(key=='3')||(key=='4')||(key=='5')||(key=='6')||(key=='7')||(key=='8')||(key=='9'))//按键值0到9
        if(YY<17){lcd_pos(2,0); for(num=0;num<YY;num++){lcd_wdat(dis12[num]);} g_ucTempbuf1[YY/2]=key; } //判断密码小于8位
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
		   } //按键确认按键 发送八位密码给上位机
		if(key=='E'){LED=0;LED1=0;beep=0;	delay(200);beep=1; LED1=1;LED=1; } //控制开关

}
	else
		key=0;
	//return (key);
	}
	
	void wendu()
{
  	unsigned char num;
    lcd_pos(3,0);             //设置显示位置为第四行的第1个字符
	for(num=0;num<8;num++)    //第一行要显示的11个字符
	{
	 lcd_wdat(table33[num]);	
	}
  Tem=ReadObjectTemp();	 //读取实物温度
  objTemp=((float)(Tem)*0.02-271.15)*10;
	Tem=ReadEnvironTemp();	 //读取环境温度
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
    lcd_init();	 //液晶初始化
    InitializeSystem( );//串口初始化
    PcdReset();		 //射频复位
    PcdAntennaOff();   //射频关闭天线
    PcdAntennaOn();	   //射频打开天线
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
	   if(key_bit==0)//上电界面
	   {
	    diaplay(0,dis8);
	    diaplay(1,dis1);
	    diaplay(2,dis2);
	   // diaplay(3,dis8);
	    YunXingZhong();
		}
		 if(key_bit==1)//管理界面
	   {  
	    diaplay(0,dis3);
	    diaplay(1,dis5);
	    diaplay(2,dis4);
		delay(2);
	    //diaplay(3,dis3);
		}
		if(key_bit==2)//输入八位密码
		{
        diaplay(0,dis3);
	    diaplay(1,dis13);
	   // diaplay(3,dis3);
     }
		 if(key_bit==3)  //密码错误
		{
        diaplay(0,dis3);
		diaplay(1,dis3);
	    diaplay(2,dis14);
	    //diaplay(3,dis3);
		beep=0;	delay(600);beep=1;
		key_bit=0;
     }
		 if(key_bit==4) //密码符合
		{
        diaplay(0,dis3);
		diaplay(1,dis3);
	    diaplay(2,dis15);
	    //diaplay(3,dis3);
		mm=0; LED=0;LED1=0;beep=0;	delay(200);beep=1; LED1=1;LED=1;ii=0;delay(400); //打开继电器
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
//系统初始化
/////////////////////////////////////////////////////////////////////
void InitializeSystem()
{
	P0 = 0xFF; P1 = 0xFF; P3 = 0xFF;P2 = 0xFF;
    TMOD = 0x21;  
    TH1 = 0xFd;  		   //11.0592M晶振，9600波特率
    TL1 = 0xFd;
    TH0 = 0xfe;  		   //11.0592M晶振，9600波特率
    TL0 = 0x33; 	
	
	ET0 = 1;
    TR0 = 1;

	SM0 = 0;
	SM1 = 1;
	REN = 1;//允许串口接收 
	TR1 = 1;
	ES = 1;//开串口 中断
	EA = 1; 

}  

void timer0() interrupt 1          /* T0中断服务程序 */
{
	TH0=0xfe;  		   //11.0592M晶振，9600波特率
    TL0=0xee;
}

void sint() interrupt 4	  //中断接收3个字节
{ 
   
	if(RI)	                 //是否接收中断
    {
       RI=0;
       dat=SBUF;	
			if(dat=='D')	//区别IC卡是否有效卡 
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
			if(ii==4){key_bit=4;YY=0;}//有效卡 并且控制继电器开关
			if(ii==3){key_bit=3; YY=0;mm++;}
	 }
}

void Zhu_Ce()//注册 账户
{		
         while(1){
  	     unsigned char status;
         status = PcdRequest(PICC_REQALL, g_ucTempbuf);//寻卡
         if (status != MI_OK)
         {    
			  break;
         }
		display_type();//寻到卡后显示出该卡的类型
	    status = PcdAnticoll(g_ucTempbuf);//防冲撞
         if (status != MI_OK)
         {     break;   }
	    display_cardnum();//显示寻到的卡的序列号
		status = PcdSelect(g_ucTempbuf);//选定卡片
         if (status != MI_OK)
         {      break;    }        
         status = PcdAuthState(PICC_AUTHENT1A,23,Yankey, g_ucTempbuf);//验证卡片密码（原始的密码）FF
         if (status != MI_OK)
        {    	  break;    }//	 LED_GREEN = 1;
		 status = PcdWrite(22, data1);//写块
         if (status != MI_OK)
         {     break;  }
		 status = PcdWrite(23,XiugaiYunKey);//写块//修改后的密码 FE
         if (status != MI_OK)
         {     break;    }
	      diaplay(3,table8);
		   beep=0; //蜂鸣器响一声	
			delay(40);
			beep=1; 
		  WaitCardOff();//等待卡离开天线			 	         
	   	  PcdHalt();//中止
		  }
		  	 
}
void Ce_Xiao()//撤销卡
{
        unsigned char status;
		while(1)
		{
         status = PcdRequest(PICC_REQALL, g_ucTempbuf);//寻卡
         if (status != MI_OK)
         {    
			    break;
         }
		display_type();//寻到卡后显示出该卡的类型
	    status = PcdAnticoll(g_ucTempbuf);//防冲撞
         if (status != MI_OK)
         {     break;    }
	    display_cardnum();//显示寻到的卡的序列号
		status = PcdSelect(g_ucTempbuf);//选定卡片
         if (status != MI_OK)
         {    break;   }        
         status = PcdAuthState(PICC_AUTHENT1A,23, Nowkey, g_ucTempbuf);//验证卡片密码（原始的密码）FE
         if (status != MI_OK)
        {    	  break;    }
		 status = PcdWrite(23,XiugaiNowKey);//写块//修改后的密码FF
         if (status != MI_OK)
         {     break;    }
		    beep=0; //蜂鸣器响一声	
			delay(40);
			beep=1; 
          diaplay(3,table9);
		  WaitCardOff();//等待卡离开天线			 	         
	   	  PcdHalt();//中止	
		  } 
}


void YunXingZhong()	//程序运行中
{  
  unsigned char status;
   while(1)
   {
   	     status = PcdRequest(PICC_REQALL, g_ucTempbuf);//寻卡
         if (status != MI_OK)
         {     
			  break;
         }
		  display_type();//寻到卡后显示出该卡的类型
	      status = PcdAnticoll(g_ucTempbuf);//防冲撞
           if (status != MI_OK)
            {    break;    }
           display_cardnum();//显示寻到的卡的序列号
				
		 status = PcdSelect(g_ucTempbuf);//选定卡片
         if (status != MI_OK)
         {    break;   }
         
         status = PcdAuthState(PICC_AUTHENT1A,23,Nowkey,g_ucTempbuf);//验证卡片密码
         if (status != MI_OK)
         {  diaplay(3,table10);
		    beep=0;  //蜂鸣器响两声	
			delay(40);
			beep=1;
			delay(40); 
			beep=0; 	
			delay(40);
			beep=1; 
		    WaitCardOff();//等待卡离开天线
		    break; 
		 }
		  display_cardnum1();
      // display_cardnum();//显示寻到的卡的序列号
		    if (status != MI_OK)
         { // LED_GREEN = 1;
		  break;   }   
     //  display_cardnum();//显示寻到的卡的序列号
		 status = PcdBakValue(22, 21);//块备份
         if (status != MI_OK)
         {   break;   }
         status = PcdRead(21, g_ucTempbuf);//读块
         if (status != MI_OK)	
         {   break;   }
		    beep=0; //蜂鸣器响一声	
			delay(40);
			beep=1; 
	      WaitCardOff();//等待卡离开天线			 	         
		  PcdHalt();
		  
   }
}


void WaitCardOff(void)	//等待卡离开
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

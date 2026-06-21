#include <LPC21xx.H>

#include"header.h"
int temp,flag;
CAN1 HL_msg,RI_msg,LI_msg;
int main()
{
	//uart0_init(9600);
	config_eintrs();
	config_vic_for_eintrs();
	can1_init();
	HL_msg.ff=RI_msg.ff=LI_msg.ff=0;  //  FF=0; select standard frame format
	HL_msg.rtr=RI_msg.rtr=LI_msg.rtr=0;	   //  RTR=0; select data frame
	HL_msg.dlc=RI_msg.dlc=LI_msg.dlc=1;    // dlc=1 bytes 
	HL_msg.byteB=RI_msg.byteB=LI_msg.byteB=0;  // Higher byte data is zero
	HL_msg.id=0x151;
	RI_msg.id=0x152;
	LI_msg.id=0x153;
	while(1)
	{
		if(flag)
		{
			flag=0;
			switch(temp)
			{
				case 1 : 
					HL_msg.byteA=0x11;
					can1_tx(HL_msg);
					break;
				case 2 :
					RI_msg.byteA=0x22;
					can1_tx(RI_msg);
					break;
				case 3 :
					LI_msg.byteA=0x33;
					can1_tx(LI_msg);
					break;
			}
		}
	}  
}


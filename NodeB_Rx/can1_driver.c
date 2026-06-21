/* CAN Driver */
#include <LPC21xx.H>
#include"header.h"

void can1_init(void)
{
	VPBDIV=1;
	PINSEL1 |= 0x00040000;
	C1MOD=1;
	C1BTR=0x001C001D;
	AFMR=2;
	C1MOD=0;
}

/*
#define RBS (C1GSR&1)
void can1_rx(CAN1 *p)
{
	while(RBS==0);	
	p->id=C1RID;
	p->ff=((C1RFS>>31)&1);
	p->rtr=((C1RFS>>30)&1);
	p->dlc=((C1RFS>>16)&0xF);
	if(p->rtr==0)
	{
		p->byteA=C1RDA;
		p->byteB=C1RDB;
	}
	C1CMR=0x4;
}

#define TCS ((C1GSR>>3)&1)
void can1_tx(CAN1 v){
	C1TID1=v.id;
	C1TFI1=(v.dlc<<16);//set dlc,rtr=0,ff=0
	if(v.rtr==0){
		C1TDA1=v.byteA;//init data
		C1TDB1=v.byteB;//init data
	}
	else
		C1TFI1|=(1<<30);//rtr=1
	C1CMR=0x21;//Select txbuf1 & start xmission
	while(TCS==0);//wait till data-frame gets
	//transmitted
}
*/

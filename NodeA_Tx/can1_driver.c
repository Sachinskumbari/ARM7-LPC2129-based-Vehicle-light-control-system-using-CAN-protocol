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

#define TCS ((C1GSR>>3)&1)
void can1_tx(CAN1 v)
{
	C1TID1=v.id;
	C1TFI1=(v.dlc<<16);
	if(v.rtr==0)
	{
		C1TDA1=v.byteA;
		C1TDB1=v.byteB;
	}
	else
		C1TFI1 |=(1<<30);

	C1CMR=0x21;
	while(TCS==0);
}

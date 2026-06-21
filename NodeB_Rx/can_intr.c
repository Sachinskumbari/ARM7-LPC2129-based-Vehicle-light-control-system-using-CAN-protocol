/* CAN Rx interrupt ISR */
#include <LPC21xx.H>

#include"header.h"
extern int flag;
extern CAN1 v;
void CAN1_RX_Handler(void) __irq
{
	uart0_tx_string("ISR Triggered\r\n");
	//if(C1ICR&1)   //if(C1GSR&1)
	v.id=C1RID;
	v.dlc=(C1RFS>>16)&0xF;
	v.ff=(C1RFS>>31)&1;
	v.rtr=(C1RFS>>30)&1;
	if(v.rtr==0)
	{

		v.byteA=C1RDA;
		v.byteB=C1RDB;
	}
	C1CMR=(1<<2);
	VICVectAddr=0;
	flag=1;
}

void config_vic_for_can1(void)
{
	VICIntSelect=0;
	VICVectCntl0= 26|(1<<5);
	VICVectAddr0= (u32)CAN1_RX_Handler;
	VICIntEnable=(1<<26);
	C1IER=1;
}

#include <LPC21xx.H>
#include "header.h"
// uart0_driver.c

void uart0_init(unsigned int baud)
{
	int pclk, result=0;
	int a[]={15,60,30,0, 15,};
	pclk=a[VPBDIV]*1000000;
	result=pclk/(16*baud);
	PINSEL0|=0X5;
	U0LCR=0X83;
	U0DLL=result&0xff;
	U0DLM=result>>8&0xff;
	U0LCR=0X03;
}

// transmit 1 byte of Data

#define THRE  (U0LSR>>5&1)
void uart0_tx(unsigned char data)
{
	U0THR=data; // load the data into U0THR Reg
	while(THRE==0);// loop runs until THRE becomes 1
}

// Receive 1byte of Data

#define RDR  (U0LSR&1)
unsigned char uart0_rx(void)
{
	while(RDR==0);
	return U0RBR;
}

void uart0_tx_string(char *ptr)
{
	while(*ptr!=0)
	{
		uart0_tx(*ptr);
		ptr++;
	}
}

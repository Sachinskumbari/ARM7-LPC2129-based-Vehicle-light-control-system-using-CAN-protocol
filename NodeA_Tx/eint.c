#include <LPC21xx.H>

#include"header.h"
extern int temp,flag;
void EINT0_Handler(void)__irq
{
	//delay_ms(50);
	flag=1;
	temp=1;
	EXTINT=1;
	VICVectAddr=0;
}

void EINT1_Handler(void)__irq
{
	//delay_ms(50);
	flag=1;
	temp=2;
	EXTINT=2;
	VICVectAddr=0;
}

void EINT2_Handler(void)__irq
{
	//delay_ms(50);
	flag=1;
	temp=3;
	EXTINT=4;
	VICVectAddr=0;
}

void config_eintrs(void)
{
	PINSEL0 |= 0xA0000000;
	PINSEL1 |= 1;
	EXTMODE = 7;
	EXTPOLAR = 0; 
}

void config_vic_for_eintrs(void)
{
	VICIntSelect=0;

	VICVectCntl0= 14|(1<<5);
	VICVectAddr0=(u32)EINT0_Handler;

	VICVectCntl1= 15|(1<<5);
	VICVectAddr1=(u32)EINT1_Handler;

	VICVectCntl2= 16|(1<<5);
	VICVectAddr2=(u32)EINT2_Handler;

	VICIntEnable = (7<<14);
}

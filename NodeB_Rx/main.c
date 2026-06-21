#include"header.h"
#define HL_S ((IOPIN0>>17)&1)
#define RI_S ((IOPIN0>>18)&1)
#define LI_S ((IOPIN0>>19)&1)
#define HL (1<<17)
#define RI (1<<18)
#define LI (1<<19)
CAN1 v;
int flag;
int main()
{
	IODIR0 |= (7<<17);
	IOSET0 |= (7<<17);

	can1_init();
	config_vic_for_can1();
	uart0_init(9600);
	uart0_tx_string("Uart initialized\r\n"); 
	while(1)
	{
		if(flag)  // isr executed
		{
			flag=0;
			switch(v.id)
			{
				case 0x151 :
					uart0_tx_string("Headlight message\r\n");
					if(HL_S==0)
						IOSET0 |= HL;
					else
						IOCLR0 |= HL;
					break;

				case 0x152 :
					uart0_tx_string("Right Indicator msg\r\n");
					if(RI_S==0)
						IOSET0 |= RI;
					else
					{
						if(LI_S==0)
							IOSET0 |= LI;	
						IOCLR0 |= RI;
					}
					break;

				case 0x153 :
					uart0_tx_string("Left indicator msg\r\n");
					if(LI_S==0)
						IOSET0 |= LI;
					else
					{	
						if(RI_S==0)
							IOSET0 |= RI;
						IOCLR0=LI;
					}
					break;
			}
		}
	}
}

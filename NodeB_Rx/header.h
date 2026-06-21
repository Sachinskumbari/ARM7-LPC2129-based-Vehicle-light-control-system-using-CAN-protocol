#include<lpc21xx.h>
typedef unsigned int u32;
typedef int s32;
typedef unsigned char u8;
typedef char s8;
typedef unsigned short int u16;
typedef short int s16;

void uart0_init(unsigned int baud);
void uart0_tx(unsigned char data);
unsigned char uart0_rx(void);
void uart0_tx_string(char *ptr);

typedef struct CAN_MSG
{
	u8 ff,dlc,rtr;
	u32 byteA,byteB,id;
}CAN1;

void can1_init(void);
void can1_rx(CAN1 *p);

void config_vic_for_can1(void);

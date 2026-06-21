#include<lpc21xx.h>
typedef unsigned int u32;
typedef int s32;
typedef unsigned char u8;
typedef char s8;
typedef unsigned short int u16;
typedef short int s16;

void delay_ms(unsigned int ms);

void config_eintrs(void);
void config_vic_for_eintrs(void);

typedef struct CAN_MSG
{
u8 ff,rtr,dlc;
u32 byteA,byteB,id;
}CAN1;
void can1_init(void);
void can1_tx(CAN1);

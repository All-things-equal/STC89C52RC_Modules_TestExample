#ifndef __DS1302_H__
#define __DS1302_H__

extern unsigned char time_DS1302[];

void DS1302_Init(void);
void DS1302_WriteByte(unsigned char command, unsigned char dataByte);
unsigned char DS1302_ReadByte(unsigned char command);
void DS1302_SetTime(void);
void DS1302_GetTime(void);

#endif
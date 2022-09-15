/*
      * 10-1 DS1302时钟
*/

#include <REGX52.H>
#include "LCD1602.h"
#include "DS1302.h"

void main()
{
      LCD_Init();
      DS1302_Init();
      LCD_ShowString(1, 1, "  -  -  ");
      LCD_ShowString(2, 1, "  :  :  ");

      DS1302_SetTime();

      while (1)
      {
            DS1302_GetTime();

            LCD_ShowNum(1, 1, time_DS1302[0], 2);
            LCD_ShowNum(1, 4, time_DS1302[1], 2);
            LCD_ShowNum(1, 7, time_DS1302[2], 2);
            LCD_ShowNum(2, 1, time_DS1302[3], 2);
            LCD_ShowNum(2, 4, time_DS1302[4], 2);
            LCD_ShowNum(2, 7, time_DS1302[5], 2);
      }
}
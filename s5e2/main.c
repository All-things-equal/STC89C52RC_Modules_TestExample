/*
      * 5-2 LCD1602调试工具
*/

#include <REGX52.H>
#include "LCD1602.h"

void main()
{
      LCD_Init();
      LCD_ShowString(1, 1, "0123456789abcdef");
      LCD_ShowNum(2, 1, 65535, 5);
      while (1)
      {
            ;
      }
}
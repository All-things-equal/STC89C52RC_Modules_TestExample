/*
      * 6-1 矩阵键盘
*/

#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

unsigned char keyNumber;

void main()
{
      LCD_Init();
      LCD_ShowString(1, 1, "MatrixKey:");
      while (1)
      {
            keyNumber = MatrixKey();
            if (keyNumber)
            {
                  LCD_ShowNum(2, 1, keyNumber, 2);
            }
      }
}
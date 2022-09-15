/*
      * 9-2 LED点阵屏显示流动动画
*/

#include <REGX52.H>
#include "Delay.h"
#include "MatrixLED.h"

unsigned char animation[] = {
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0xFF,
    0x08,
    0x08,
    0x08,
    0xFF,
    0x00,
    0x0E,
    0x15,
    0x15,
    0x15,
    0x08,
    0x00,
    0x7E,
    0x01,
    0x02,
    0x00,
    0x7E,
    0x01,
    0x02,
    0x00,
    0x0E,
    0x11,
    0x11,
    0x0E,
    0x00,
    0x7D,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
};

void main()
{

      /*
      // 点阵屏测试
      MATRIX_LED_POST = 0;
      Fun_74HC595_WriteByte(0xAA);
      // */
      unsigned char i;
      unsigned char offset = 0;
      unsigned char count = 0;
      while (1)
      {
            for (i = 0; i < 8; ++i)
            {
                  MatrixLed_ShowColumn(i, animation[i + offset]);
            }

            count++;
            if (count > 10)
            {
                  count = 0;
                  offset++;
                  if (offset > 40)
                  {
                        offset = 0;
                  }
            }
      }
}
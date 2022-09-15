/*
      * 9-3 LED点阵屏显示逐帧动画
*/

#include <REGX52.H>
#include "Delay.h"
#include "MatrixLED.h"

unsigned char code ANIMATION[] = {
    0x3C,
    0x42,
    0xA9,
    0x85,
    0x85,
    0xA9,
    0x42,
    0x3C,
    0x3C,
    0x42,
    0xA1,
    0x85,
    0x85,
    0xA1,
    0x42,
    0x3C,
    0x3C,
    0x42,
    0xA5,
    0x89,
    0x89,
    0xA5,
    0x42,
    0x3C,
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
                  MatrixLed_ShowColumn(i, ANIMATION[i + offset]);
            }

            count++;
            if (count > 15)
            {
                  count = 0;
                  offset += 8;
                  if (offset > 16)
                  {
                        offset = 0;
                  }
            }
      }
}
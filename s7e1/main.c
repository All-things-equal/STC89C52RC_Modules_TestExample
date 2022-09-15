/*
      * 7-1 定时器, 按键控制LED流水灯模式
*/

#include <REGX52.H>
#include <INTRINS.H>
#include "Timer0.h"
#include "Key.h"

unsigned char keyNumber;
unsigned char ledMode;

void main()
{
      P2 = 0xFE;
      Timer0_Init();
      while (1)
      {
            keyNumber = Key();

#if 0
            // 测试按键
            if (keyNumber)
            {
                  if (keyNumber == 1)
                  {
                        P2_1 = ~P2_1;
                  }
                  if (keyNumber == 2)
                  {
                        P2_2 = ~P2_2;
                  }
                  if (keyNumber == 3)
                  {
                        P2_3 = ~P2_3;
                  }
                  if (keyNumber == 4)
                  {
                        P2_4 = ~P2_4;
                  }
            }
#endif

            if (keyNumber)
            {
                  if (keyNumber == 1)
                  {
                        ledMode++;
                        if (ledMode >= 2)
                        {
                              ledMode = 0;
                        }
                  }
            }
      }
}

void Timer0_Routine() interrupt 1
{
      static unsigned int T0Count;
      TL0 = 0x66; //设置定时初始值
      TH0 = 0xFC; //设置定时初始值
      T0Count++;
      if (T0Count >= 500)
      {
            T0Count = 0;
            if (ledMode == 0)
            {
                  P2 = _crol_(P2, 1);
            }
            if (ledMode == 1)
            {
                  P2 = _cror_(P2, 1);
            }
            
      }
}
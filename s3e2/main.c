/*
      * 3-2 独立按键控制LED状态
*/

#include <REGX52.H>
#include <INTRINS.H>

void Delay(unsigned int time) //@11.0592MHz
{
      unsigned char i, j;
      while (--time)
      {
            _nop_();
            i = 2;
            j = 199;
            do
            {
                  while (--j)
                        ;
            } while (--i);
      }
}

void main()
{
      while (1)
      {
            if (P3_1 == 0)
            {
                  Delay(20); // 消除按下抖动
                  while (P3_1 == 0)
                  {
                        ;
                  }
                  Delay(20); // 消除松手抖动

                  P2_0 = ~P2_0;
            }
      }
}
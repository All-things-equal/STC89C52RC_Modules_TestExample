/*
      * 3-3 独立按键控制LED显示二进制
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
      unsigned char ledTag = 0;
      while (1)
      {
            if (P3_1 == 0)
            {
                  Delay(20);
                  while (P3 - 1 == 0)
                  {
                        ;
                  }
                  Delay(20);

                  ledTag++;
                  P2 = ~ledTag;
            }
      }
}
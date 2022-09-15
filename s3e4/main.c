/*
      * 3-4 独立按键控制LED移位
*/

#include <REGX52.H>
#include <INTRINS.H>

unsigned char ledTag;

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
      P2 = ~0x01;
      while (1)
      {
            // K1按键 右移
            if (P3_1 == 0)
            {
                  Delay(20);
                  while (P3_1 == 0)
                  {
                        ;
                  }
                  Delay(20);

                  ledTag++;
                  if (ledTag >= 8)
                  {
                        ledTag = 0;
                  }

                  P2 = ~(0x01 << ledTag);
            }

            // K2按键 左移
            if (P3_0 == 0)
            {
                  Delay(20);
                  while (P3_0 == 0)
                  {
                        ;
                  }
                  Delay(20);

                  if (ledTag == 0)
                  {
                        ledTag = 7;
                  }
                  else
                  {
                        ledTag--;
                  }

                  P2 = ~(0x01 << ledTag);
            }
      }
}
/*
      * 2-3 LED流水灯
*/

#include <REGX52.H>
#include <INTRINS.H>

void Delay500ms() //@11.0592MHz
{
      unsigned char i, j, k;

      _nop_();
      i = 4;
      j = 129;
      k = 119;
      do
      {
            do
            {
                  while (--k)
                        ;
            } while (--j);
      } while (--i);
}

void main()
{
      P2 = 0xFE;
      while (P2 >= 0x7F)
      {
            Delay500ms();
            P2 = P2 << 1;
      }
}
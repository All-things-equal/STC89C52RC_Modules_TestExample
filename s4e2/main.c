/*
      * 4-2 动态数码管显示
*/

#include <REGX52.H>
#include <INTRINS.H>

unsigned char nixieTable[] = {
    0x3f,
    0x06,
    0x5b,
    0x4f,
    0x66,
    0x6d,
    0x7d,
    0x07,
    0x7f,
    0x6f,
};

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

void NixieTube(unsigned char location, unsigned char number)
{
      switch (location)
      {
      case 1:
            P2_4 = 1;
            P2_3 = 1;
            P2_2 = 1;
            break;
      case 2:
            P2_4 = 1;
            P2_3 = 1;
            P2_2 = 0;
            break;
      case 3:
            P2_4 = 1;
            P2_3 = 0;
            P2_2 = 1;
            break;
      case 4:
            P2_4 = 1;
            P2_3 = 0;
            P2_2 = 0;
            break;
      case 5:
            P2_4 = 0;
            P2_3 = 1;
            P2_2 = 1;
            break;
      case 6:
            P2_4 = 0;
            P2_3 = 1;
            P2_2 = 0;
            break;
      case 7:
            P2_4 = 0;
            P2_3 = 0;
            P2_2 = 1;
            break;
      case 8:
            P2_4 = 0;
            P2_3 = 0;
            P2_2 = 0;
            break;

      default:
            break;
      }

      P0 = nixieTable[number];

      Delay(1);
      P0 = 0x00;
}

void main()
{
      // NixieTube(7, 3);
      while (1)
      {
            NixieTube(1, 1);
            // Delay(100);
            NixieTube(2, 2);
            // Delay(100);
            NixieTube(3, 3);
            // Delay(100);
      }
}
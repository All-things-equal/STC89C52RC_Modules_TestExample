/*
      * 3-1 独立按键控制LED亮灭
*/

#include <REGX52.H>

void main()
{
      while (1)
      {
            // P3_1 表 K1按键
            // P3_0 表 K2按键
            if (P3_1 == 0 && P3_0 == 0)
            {
                  P2_0 = 0;
            }
            else
            {
                  P2_0 = 1;
            }
      }
}
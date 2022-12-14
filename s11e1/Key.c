#include <REGX52.H>
#include "Delay.h"

/**
 * @brief 获取独立按键的键码
 * @param 无
 * @return 按键键码, 范围: 0~4, 无按键按下时返回0
 */
unsigned char Key()
{
      unsigned char keyNumber = 0;

      if (P3_1 == 0)
      {
            Delay(20);
            while (P3_1 == 0)
            {
                  ;
            }
            Delay(20);
            keyNumber = 1;
      }

      if (P3_0 == 0)
      {
            Delay(20);
            while (P3_0 == 0)
            {
                  ;
            }
            Delay(20);
            keyNumber = 2;
      }

      if (P3_2 == 0)
      {
            Delay(20);
            while (P3_2 == 0)
            {
                  ;
            }
            Delay(20);
            keyNumber = 3;
      }

      if (P3_3 == 0)
      {
            Delay(20);
            while (P3_3 == 0)
            {
                  ;
            }
            Delay(20);
            keyNumber = 4;
      }

      return keyNumber;
}
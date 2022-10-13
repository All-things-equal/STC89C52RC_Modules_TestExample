#include <INTRINS.H>

/**
 * @brief 延时函数, 适用11.0592Mhz
 * @param time 延时时间，单位ms
 * @retval 无
 */
void Delay(unsigned int time) //@11.0592MHz
{
      unsigned char i, j;
      while (time--)
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

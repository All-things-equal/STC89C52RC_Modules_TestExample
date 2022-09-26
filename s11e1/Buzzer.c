#include <REGX52.H>
#include <INTRINS.H>

/* *****************************************
蜂鸣器端口
****************************************** */
sbit buzzer = P2 ^ 5;

/**
 * @brief 蜂鸣器专用延时函数，延时500us
 * @param 无
 * @retval 无
 */
void Buzzer_Delay500us() //@11.0592MHz
{
      unsigned char i;

      _nop_();
      i = 227;
      while (--i)
      {
            ;
      }
}

/**
 * @brief 蜂鸣器发声
 * @param time 发声的时长, 范围：0~32767, 单位：ms
 * @retval 无
 */
void Buzzer_Time(unsigned int time)
{
      unsigned int i;

      for (i = 0; i < time * 2; i++)
      {
            buzzer = ~buzzer;
            Buzzer_Delay500us();
      }
}
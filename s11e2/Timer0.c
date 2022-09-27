#include <REGX52.H>

/**
 * @brief 定时器0初始化, 1毫秒@11.0592MHz
 * @param 无
 * @return 无
 */
void Timer0_Init(void)
{
      TMOD &= 0xF0; //设置定时器模式
      TMOD |= 0x01; //设置定时器模式
      TL0 = 0x66;   //设置定时初始值
      TH0 = 0xFC;   //设置定时初始值
      TF0 = 0;      //清除TF0标志
      TR0 = 1;      //定时器0开始计时

      // // TMOD = 0x01; // 0000 0001
      // TMOD = TMOD & 0xF0; // 把TMOD的 低四位 清零, 高四位 保持不变
      // TMOD = TMOD | 0x01; // 把TMOD的 最低位 置1, 高四位 保持不变

      // TH0 = 64535 / 256;
      // TL0 = 64535 % 256 + 1;

      ET0 = 1;
      EA = 1;
      PT0 = 0;
}

#if 0
/*
Template: 定时器中断函数
*/
void Timer0_Routine() interrupt 1
{
      static unsigned int T0Count;
      TL0 = 0x66; //设置定时初始值
      TH0 = 0xFC; //设置定时初始值
      T0Count++;
      if (T0Count >= 1000)
      {
            T0Count = 0;
            /*TODO*/
      }
}
#endif
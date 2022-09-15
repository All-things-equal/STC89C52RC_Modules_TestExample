#include <REGX52.H>

/**
 * @brief 串口初始化, 4800bps@11.0592MHz
 * @param 无
 * @retval 无
 */
void UART_Init(void)
{
      PCON &= 0x7F; //波特率不倍速
      SCON = 0x40;  //8位数据,可变波特率
      TMOD &= 0x0F; //设置定时器模式
      TMOD |= 0x20; //设置定时器模式
      TL1 = 0xFA;   //设置定时初始值
      TH1 = 0xFA;   //设置定时重载值
      ET1 = 0;      //禁止定时器%d中断
      TR1 = 1;      //定时器1开始计时
}

/**
 * @brief 串口发送一个字节
 * @param dataByte 要发送的一个字节
 * @retval 无
 */
void UART_SendByte(unsigned char dataByte)
{
      SBUF = dataByte;
      while (TI == 0)
      {
            ;
      }
      TI = 0;
}
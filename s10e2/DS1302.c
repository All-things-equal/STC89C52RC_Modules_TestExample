#include <REGX52.H>

/* -----------------------------------------
引脚定义
------------------------------------------ */
sbit DS1302_SCLK = P3 ^ 6;
sbit DS1302_IO = P3 ^ 4;
sbit DS1302_CE = P3 ^ 5;
/* *************************************** */

/* -----------------------------------------
寄存器 写入地址/指令 定义
------------------------------------------ */
#define DS1302_SECOND 0x80
#define DS1302_MINUTE 0x82
#define DS1302_HOUR 0x84
#define DS1302_DATE 0x86
#define DS1302_MONTH 0x88
#define DS1302_DAY 0x8A
#define DS1302_YEAR 0x8C
#define DS1302_WP 0x8E
/* *************************************** */

/* -----------------------------------------
存储时间的全局数组变量, 索引0~6分别表 年、月、日、时、分、秒、星期
------------------------------------------ */
unsigned char time_DS1302[] = {22, 4, 27, 16, 35, 50, 3};
/* *************************************** */

/**
  * @brief  DS1302初始化
  * @param  无
  * @retval 无
  */
void DS1302_Init(void)
{
      DS1302_CE = 0;
      DS1302_SCLK = 0;
}

/**
 * @brief DS1302写一个字节
 * @param command 命令字/地址
 * @param dataByte 要写入的数据
 * @retval 无
 */
void DS1302_WriteByte(unsigned char command, unsigned char dataByte)
{
      unsigned char i;
      DS1302_CE = 1;

      for (i = 0; i < 8; i++)
      {
            DS1302_IO = command & (0x01 << i);
            DS1302_SCLK = 1;
            DS1302_SCLK = 0;
      }
      for (i = 0; i < 8; i++)
      {
            DS1302_IO = dataByte & (0x01 << i);
            DS1302_SCLK = 1;
            DS1302_SCLK = 0;
      }

      DS1302_CE = 0;
}

/**
 * @brief DS1302读一个字节
 * @param command 命令字/地址
 * @retval 读出的数据
 */
unsigned char DS1302_ReadByte(unsigned char command)
{
      unsigned char i;
      unsigned char dataByte = 0x00;

      command = command | 0x01;
      DS1302_CE = 1;

      for (i = 0; i < 8; i++)
      {
            DS1302_IO = command & (0x01 << i);
            DS1302_SCLK = 0;
            DS1302_SCLK = 1;
      }

      for (i = 0; i < 8; i++)
      {
            DS1302_SCLK = 1;
            DS1302_SCLK = 0;
            if (DS1302_IO)
            {
                  dataByte |= (0x01 << i);
            }
      }

      DS1302_CE = 0;
      DS1302_IO = 0;

      return dataByte;
}

/**
  * @brief  DS1302设置时间, 调用之后, time_DS1302数组的数字会被设置到DS1302中
  * @param  无
  * @retval 无
  */
void DS1302_SetTime(void)
{
      DS1302_WriteByte(DS1302_WP, 0x00); // 解除芯片写保护

      DS1302_WriteByte(DS1302_YEAR, time_DS1302[0] / 10 * 16 + time_DS1302[0] % 10); //十进制转BCD码后写入
      DS1302_WriteByte(DS1302_MONTH, time_DS1302[1] / 10 * 16 + time_DS1302[1] % 10);
      DS1302_WriteByte(DS1302_DATE, time_DS1302[2] / 10 * 16 + time_DS1302[2] % 10);
      DS1302_WriteByte(DS1302_HOUR, time_DS1302[3] / 10 * 16 + time_DS1302[3] % 10);
      DS1302_WriteByte(DS1302_MINUTE, time_DS1302[4] / 10 * 16 + time_DS1302[4] % 10);
      DS1302_WriteByte(DS1302_SECOND, time_DS1302[5] / 10 * 16 + time_DS1302[5] % 10);
      DS1302_WriteByte(DS1302_DAY, time_DS1302[6] / 10 * 16 + time_DS1302[6] % 10);

      DS1302_WriteByte(DS1302_WP, 0x80);
}

/**
  * @brief  DS1302获取时间，调用之后，DS1302中的数据会被读取到time_DS1302数组中
  * @param  无
  * @retval 无
  */
void DS1302_GetTime(void)
{
      unsigned char tmp;

      tmp = DS1302_ReadByte(DS1302_YEAR);
      time_DS1302[0] = tmp / 16 * 10 + tmp % 16; // BCD码转十进制后写入
      tmp = DS1302_ReadByte(DS1302_MONTH);
      time_DS1302[1] = tmp / 16 * 10 + tmp % 16;
      tmp = DS1302_ReadByte(DS1302_DATE);
      time_DS1302[2] = tmp / 16 * 10 + tmp % 16;
      tmp = DS1302_ReadByte(DS1302_HOUR);
      time_DS1302[3] = tmp / 16 * 10 + tmp % 16;
      tmp = DS1302_ReadByte(DS1302_MINUTE);
      time_DS1302[4] = tmp / 16 * 10 + tmp % 16;
      tmp = DS1302_ReadByte(DS1302_SECOND);
      time_DS1302[5] = tmp / 16 * 10 + tmp % 16;
      tmp = DS1302_ReadByte(DS1302_DAY);
      time_DS1302[6] = tmp / 16 * 10 + tmp % 16;
}

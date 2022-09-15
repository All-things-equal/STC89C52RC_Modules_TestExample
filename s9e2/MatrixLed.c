#include <REGX52.H>
#include "Delay.h"

sbit RCK = P3 ^ 5; //RCLK
sbit SCK = P3 ^ 6; //SRCLK
sbit SER = P3 ^ 4; //SER

#define MATRIX_LED_POST P0

/**
 * @brief 74HC595写入一个字节
 * @param dataByte 要写入的一个字节
 * @retval 无
 */
void Fun_74HC595_WriteByte(unsigned char dataByte)
{
      unsigned char i;
      for (i = 0; i < 8; ++i)
      {
            SER = dataByte & (0x80 >> i); // 隐式转换 -> 非0即1
            SCK = 1;
            SCK = 0;
      }
      RCK = 1;
      RCK = 0;
}

/**
 * @brief LED点阵屏显示一列数据
 * @param column 要选择的列, 范围: 0~7, 0在最左边
 * @param dat 选中的列要显示的数据, 高位在上, 1亮0灭
 * @retval 无
 */
void MatrixLed_ShowColumn(unsigned char column, unsigned char dat)
{
      Fun_74HC595_WriteByte(dat);
      MATRIX_LED_POST = ~(0x80 >> column);
      Delay(1);
      MATRIX_LED_POST = 0xFF;
}

/**
 * @brief 点阵屏初始化
 * @param 无
 * @retval 无
 */
void MatrixLed_Init(void)
{
      SCK = 0;
      RCK = 0;
}
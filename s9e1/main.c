/*
      * 9-1 LED点阵屏显示图形
*/

#include <REGX52.H>
#include "Delay.h"

sbit RCK = P3 ^ 5;
sbit SCK = P3 ^ 6;
sbit SER = P3 ^ 4;

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

void main()
{
      SCK = 0;
      RCK = 0;

      /*
      // 点阵屏测试
      MATRIX_LED_POST = 0;
      Fun_74HC595_WriteByte(0xAA);
      // */

      while (1)
      {
            MatrixLed_ShowColumn(0, 0x3C);
            MatrixLed_ShowColumn(1, 0x42);
            MatrixLed_ShowColumn(2, 0xA9);
            MatrixLed_ShowColumn(3, 0x85);
            MatrixLed_ShowColumn(4, 0x85);
            MatrixLed_ShowColumn(5, 0xA9);
            MatrixLed_ShowColumn(6, 0x42);
            MatrixLed_ShowColumn(7, 0x3C);
      }
}
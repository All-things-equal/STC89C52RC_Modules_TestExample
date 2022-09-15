/*
      * 6-2 矩阵键盘密码锁
*/

#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

unsigned char keyNumber;
unsigned int password;
unsigned int count;

void main()
{
      LCD_Init();
      LCD_ShowString(1, 1, "Enter password:");
      while (1)
      {
            keyNumber = MatrixKey();
            if (keyNumber != 0)
            {
                  if (keyNumber <= 10 && count < 4) // 如果S1~S10按键按下, 输入密码
                  {
                        password *= 10;             // 将密码左移一位
                        password += keyNumber % 10; // 获取一位数字
                        count++;
                        LCD_ShowNum(2, 1, password, 4);     // 更新显示密码
                        LCD_ShowString(2, 6, "          "); // 清除显示空格
                  }

                  if (keyNumber == 11) // 如果S11按键按下, 确认密码
                  {
                        if (password == 2345) // 如果密码正确
                        {
                              LCD_ShowString(2, 8, "success");
                        }
                        else
                        {
                              LCD_ShowString(2, 8, " error ");
                        }

                        LCD_ShowNum(2, 1, password, 4); // 更新显示密码
                        // 置零
                        password = 0;
                        count = 0;
                  }

                  if (keyNumber == 12) // 如果S12按键按下, 重置密码
                  {
                        password = 0;
                        count = 0;
                        LCD_ShowString(2, 1, "                ");
                  }
            }
      }
}
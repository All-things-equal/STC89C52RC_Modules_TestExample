/*
      * 10-2 DS1302可调时钟
*/

#include <REGX52.H>
#include "LCD1602.h"
#include "DS1302.h"
#include "Key.h"
#include "Timer0.h"

unsigned char keyNumber;
unsigned char mode;
unsigned char timeSetSelect;
unsigned char timeSetFlashFlag;

/**
 * @brief 显示时间
 * @param 无
 * @retval 无
 */
void TimeShow(void)
{
      DS1302_GetTime();

      LCD_ShowNum(1, 1, time_DS1302[0], 2);
      LCD_ShowNum(1, 4, time_DS1302[1], 2);
      LCD_ShowNum(1, 7, time_DS1302[2], 2);
      LCD_ShowNum(2, 1, time_DS1302[3], 2);
      LCD_ShowNum(2, 4, time_DS1302[4], 2);
      LCD_ShowNum(2, 7, time_DS1302[5], 2);
}

/**
 * @brief 设置时间
 * @param 无
 * @retval 无
 */
void TimeSet(void)
{
      unsigned char day_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

      if (keyNumber == 2)
      {
            timeSetSelect++;
            timeSetSelect %= 6; // 越界清零
      }

      if (keyNumber == 3)
      {
            time_DS1302[timeSetSelect]++;

            if (time_DS1302[0] > 99)
            {
                  time_DS1302[0] = 0;
            }
            if (time_DS1302[1] > 12)
            {
                  time_DS1302[1] = 1;
            }
            day_month[1] = ((time_DS1302[0] % 4 == 0) && (time_DS1302[0] % 100 != 0)) || (time_DS1302[0] % 400 == 0) ? 29 : 28;
            if (time_DS1302[2] > day_month[time_DS1302[1] - 1])
            {
                  time_DS1302[2] = 1;
            }
            if (time_DS1302[3] > 23)
            {
                  time_DS1302[3] = 0;
            }
            if (time_DS1302[4] > 59)
            {
                  time_DS1302[4] = 0;
            }
            if (time_DS1302[5] > 59)
            {
                  time_DS1302[5] = 0;
            }
      }
      if (keyNumber == 4)
      {
            time_DS1302[timeSetSelect]--;

            if (time_DS1302[0] < 0)
            {
                  time_DS1302[0] = 99;
            }
            if (time_DS1302[1] < 1)
            {
                  time_DS1302[1] = 12;
            }
            day_month[1] = ((time_DS1302[0] % 4 == 0) && (time_DS1302[0] % 100 != 0)) || (time_DS1302[0] % 400 == 0) ? 29 : 28;
            if (time_DS1302[2] < 1)
            {
                  time_DS1302[2] = day_month[time_DS1302[1] - 1];
            }
            if (time_DS1302[2] > day_month[time_DS1302[1] - 1])
            {
                  time_DS1302[2] = 1;
            }
            if (time_DS1302[3] < 0)
            {
                  time_DS1302[3] = 23;
            }
            if (time_DS1302[4] < 0)
            {
                  time_DS1302[4] = 59;
            }
            if (time_DS1302[5] < 0)
            {
                  time_DS1302[5] = 59;
            }
      }

      if (timeSetSelect == 0 && timeSetFlashFlag == 1)
      {
            LCD_ShowString(1, 1, "  ");
      }
      else
      {
            LCD_ShowNum(1, 1, time_DS1302[0], 2);
      }
      if (timeSetSelect == 1 && timeSetFlashFlag == 1)
      {
            LCD_ShowString(1, 4, "  ");
      }
      else
      {
            LCD_ShowNum(1, 4, time_DS1302[1], 2);
      }
      if (timeSetSelect == 2 && timeSetFlashFlag == 1)
      {
            LCD_ShowString(1, 7, "  ");
      }
      else
      {
            LCD_ShowNum(1, 7, time_DS1302[2], 2);
      }
      if (timeSetSelect == 3 && timeSetFlashFlag == 1)
      {
            LCD_ShowString(2, 1, "  ");
      }
      else
      {
            LCD_ShowNum(2, 1, time_DS1302[3], 2);
      }
      if (timeSetSelect == 4 && timeSetFlashFlag == 1)
      {
            LCD_ShowString(2, 4, "  ");
      }
      else
      {
            LCD_ShowNum(2, 4, time_DS1302[4], 2);
      }
      if (timeSetSelect == 5 && timeSetFlashFlag == 1)
      {
            LCD_ShowString(2, 7, "  ");
      }
      else
      {
            LCD_ShowNum(2, 7, time_DS1302[5], 2);
      }
}

void main()
{
      LCD_Init();
      DS1302_Init();
      Timer0_Init();

      LCD_ShowString(1, 1, "  -  -  ");
      LCD_ShowString(2, 1, "  :  :  ");

      DS1302_SetTime();

      while (1)
      {
            keyNumber = Key();
            if (keyNumber == 1)
            {
                  mode ? (mode = 0, DS1302_SetTime()) : (mode = 1);
            }

            switch (mode)
            {
            case 0:
                  TimeShow();
                  break;
            case 1:
                  TimeSet();
                  break;
            default:
                  break;
            }
      }
}

void Timer0_Routine() interrupt 1
{
      static unsigned int T0Count;
      TL0 = 0x66; //设置定时初始值
      TH0 = 0xFC; //设置定时初始值
      T0Count++;
      if (T0Count >= 500)
      {
            T0Count = 0;

            timeSetFlashFlag = !timeSetFlashFlag;
      }
}

/*
      * 11-1 蜂鸣器, 独立按键控制蜂鸣器发声
 */

#include <REGX52.H>
#include "Delay.h"
#include "Key.h"
#include "Nixie.h"
#include "Buzzer.h"

unsigned char keyNumber;

void main()
{
      Nixie(1, 0);

      while (1)
      {
            keyNumber = Key();
            if (keyNumber)
            {
                  Buzzer_Time(1000);

                  Nixie(1, keyNumber);
            }
      }
}
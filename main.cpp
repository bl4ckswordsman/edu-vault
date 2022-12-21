// ET 095G : Project
// Amarildo Rajta

#include "mbed.h"
#include "startScreen.h"
#include "background.h"
#include "gameplay.h"
#include "C12832.h"
//#include "LEDs.h"
    int dinoX = 2;
    int dinoY = 17;

C12832 lcd(p5, p7, p6, p8, p11);

InterruptIn center2(p14);
DigitalIn up(p15);
bool centerPressed = false;

void centerPress() {
  centerPressed=true;
}

void jump() {
    for (int i=1; i<4; i++){
        dinoY-=4;
        wait(0.2);
        lcd.cls();
        printBackG(lcd, centerPressed);
        printDino(lcd, centerPressed, dinoX, dinoY);
        lcd.copy_to_lcd();
    }
    for (int i=1; i<4; i++){
        dinoY+=4;
        wait(0.2);
        lcd.cls();
        printBackG(lcd, centerPressed);
        printDino(lcd, centerPressed, dinoX, dinoY);
        lcd.copy_to_lcd();
    }
}


int main() {

  // allLEDs();

  center2.fall(&centerPress);
  //up.fall(&jump);

  while (1) {
    if (centerPressed) {
      printBackG(lcd, centerPressed);
      printDino(lcd, centerPressed, dinoX, dinoY);
    } else {
      printStartS(lcd, centerPressed);
    }

    if (up){
        jump();
    }
        /*dinoY-=4;
        printDino(lcd, centerPressed, dinoX, dinoY);
        lcd.copy_to_lcd();
        wait(0.2);
        dinoY-=4;
        printDino(lcd, centerPressed, dinoX, dinoY);
        lcd.copy_to_lcd();
        wait(0.2);
        dinoY-=4;
        printDino(lcd, centerPressed, dinoX, dinoY);
        lcd.copy_to_lcd();
        wait(0.2);
        dinoY-=4;
        printDino(lcd, centerPressed, dinoX, dinoY);
        lcd.copy_to_lcd();
        wait(0.2);

        dinoY+=4;
        printDino(lcd, centerPressed, dinoX, dinoY);
        lcd.copy_to_lcd();
        wait(0.2);
        dinoY+=4;
        printDino(lcd, centerPressed, dinoX, dinoY);
        lcd.copy_to_lcd();
        wait(0.2);
        dinoY+=4;
        printDino(lcd, centerPressed, dinoX, dinoY);
        lcd.copy_to_lcd();
        wait(0.2);
        dinoY+=4;
        printDino(lcd, centerPressed, dinoX, dinoY);
        lcd.copy_to_lcd();
        wait(0.2);

    }*/

    wait(0.01);
    lcd.copy_to_lcd();
  }
}

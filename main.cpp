// ET 095G : Project
// Amarildo Rajta

#include "mbed.h"
#include "startScreen.h"
#include "background.h"
#include "gameplay.h"
#include "C12832.h"
//#include "LEDs.h"

C12832 lcd(p5, p7, p6, p8, p11);

InterruptIn center2(p14);
InterruptIn up(p15);
bool centerPressed = false;

void centerPress() {
  centerPressed=true;
}

void jump(int &y) {
    for (int i=1; i<16; i++){
        y-=1;
        wait(0.2);
    }
    for (int i=1; i<16; i++){
        y+=1;
        wait(0.2);
    }
}


int main() {
    int dinoX = 2;
    int dinoY = 17;
  // allLEDs();

  center2.fall(&centerPress);
  up.fall(jump(dinoY));

  while (1) {
    if (centerPressed) {
      printBackG(lcd, centerPressed);
      printDino(lcd, centerPressed, dinoX, dinoY);
    } else {
      printStartS(lcd, centerPressed);
    }
    wait(0.01);
    lcd.copy_to_lcd();
  }
}

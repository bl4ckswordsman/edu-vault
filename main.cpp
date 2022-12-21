// ET 095G : Project
// Amarildo Rajta

#include "mbed.h"
#include "startScreen.h"
#include "background.h"
#include "gameplay.h"
#include "C12832.h"
//#include "LEDs.h"

Ticker cactT;

int dinoX = 2;
int dinoY = 17;

double speed = 0.2;     //actually delay, higher value gives lower speed
int cactSpeed = 2;

int cactX = 117;
int cactY = 19;

C12832 lcd(p5, p7, p6, p8, p11);

InterruptIn center2(p14);
DigitalIn up(p15);
bool centerPressed = false;

void centerPress() {
  centerPressed=true;
}

void printAll() {
  lcd.cls();
  printBackG(lcd, centerPressed);
  printDino(lcd, centerPressed, dinoX, dinoY);
  printCactus(lcd, centerPressed, cactX, cactY);
  lcd.copy_to_lcd();
}

void jump() {
    for (int i=1; i<4; i++){
        dinoY-=4;
        wait(speed);
        printAll();
    }
    wait(speed*2);
    for (int i=1; i<4; i++){
        dinoY+=4;
        wait(speed);
        printAll();
    }
}

void cactMove() {
    cactX -= cactSpeed;
}


int main() {
    cactT.attach(&cactMove, speed);

  // allLEDs();

  center2.fall(&centerPress);
  //up.fall(&jump);

  while (1) {
    if (centerPressed) {
      printAll();
    } else {
      printStartS(lcd, centerPressed);
    }

    if (up){
        jump();
    }
 
    wait(0.01);
    lcd.copy_to_lcd();
  }
}

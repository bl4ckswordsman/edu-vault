// ET 095G : Project
// Amarildo Rajta

#include "mbed.h"
#include "startScreen.h"
#include "background.h"
#include "gameplay.h"
#include "C12832.h"
//#include "LEDs.h"

C12832 lcd(p5, p7, p6, p8, p11);
Ticker cactT;
Timer t;
InterruptIn center2(p14);
DigitalIn up(p15);

int dinoX = 2;
int dinoY = 17;
int cactX = 117;
int cactY = 19;

double speed = 0.2;     //actually delay, higher value gives lower speed
int cactSpeed = 2;
double cactDelay = 0.1;

bool centerPressed = false;

void centerPress() {
  centerPressed=true;
}

void time() {
    int ti;
    lcd.locate(55,2);
    ti = t.read();
    lcd.printf("SCORE: %u",ti);
}

void printAll() {
  lcd.cls();
  printBackG(lcd, centerPressed);
  printDino(lcd, centerPressed, dinoX, dinoY);
  printCactus(lcd, centerPressed, cactX, cactY);
  time();
  lcd.copy_to_lcd();
}

void jump() {
    for (int i=0; i<4; i++){
        dinoY-=4;
        wait(speed);
        printAll();
    }
    wait(speed*2);
    for (int i=0; i<4; i++){
        dinoY+=4;
        wait(speed);
        printAll();
    }
}

void cactMove() {
    cactX -= cactSpeed;
    if(cactX==-11){
        cactX=128;
    }
}




int main() {
    cactT.attach(&cactMove, cactDelay);

  // allLEDs();

  center2.fall(&centerPress);
  //up.fall(&jump);

  while (1) {
    if (centerPressed) {
      printAll();
      t.start();
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

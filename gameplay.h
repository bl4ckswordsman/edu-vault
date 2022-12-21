#include "mbed.h"
#include "C12832.h"
AnalogIn ain3(p19);      //Pot 1 will be used

char dinoL[] = {
  0x01,0xC0, // .......###......
  0x03,0x70, // ......##.###....
  0x03,0xC0, // ......####......
  0x83,0xF0, // #.....######....
  0xC7,0x80, // ##...####.......
  0xFF,0xE0, // ###########.....
  0x7F,0xA0, // .########.#.....
  0x3F,0x80, // ..#######.......
  0x1F,0x00, // ...#####........
  0x09,0x00, // ....#..#........
  0x0D,0x80  // ....##.##.......
};

char dinoD[] = {
  0xFE,0x3F, // #######...######
  0xFC,0x8F, // ######..#...####
  0xFC,0x3F, // ######....######
  0x7C,0x0F, // .#####......####
  0x38,0x7F, // ..###....#######
  0x00,0x1F, // ...........#####
  0x80,0x5F, // #........#.#####
  0xC0,0x7F, // ##.......#######
  0xE0,0xFF, // ###.....########
  0xF6,0xFF, // ####.##.########
  0xF2,0x7F  // ####..#..#######
};


char cactusL[] = {
  0x04,0x00, // .....#..........
  0x0E,0x60, // ....###..##.....
  0x6E,0xE0, // .##.###.###.....
  0xEE,0xE0, // ###.###.###.....
  0xEF,0xC0, // ###.######......
  0xEF,0x80, // ###.#####.......
  0x7E,0x00, // .######.........
  0x1E,0x00, // ...####.........
  0x0E,0x00  // ....###.........
};

char cactusD[] = {
  0xFB,0xFF, // #####.##########
  0xF1,0x9F, // ####...##..#####
  0x91,0x1F, // #..#...#...#####
  0x11,0x1F, // ...#...#...#####
  0x10,0x3F, // ...#......######
  0x10,0x7F, // ...#.....#######
  0x81,0xFF, // #......#########
  0xE1,0xFF, // ###....#########
  0xF1,0xFF  // ####...#########
};


bool darkThemeChosen3() {
  if (ain3.read() > 0.0 && ain3.read() < 0.5) {
    return false;
  } else {
    return true;
  }
}

Bitmap dinoLbm = {12, 11, 2, dinoL};
Bitmap dinoDbm = {12, 11, 2, dinoD};

Bitmap cactusLbm = {11, 9, 2, cactusL};
Bitmap cactusDbm = {11, 9, 2, cactusD};

void printDinoL(C12832 &_lcd, int &xLoc, int &yLoc) {
  _lcd.print_bm(dinoLbm, xLoc, yLoc);
}

void printDinoD(C12832 &_lcd, int &xLoc, int &yLoc) {
  _lcd.print_bm(dinoDbm, xLoc, yLoc);
}

void printDino(C12832 &_lcd, bool &centPressed, int &xLoc, int &yLoc) {
  if (centPressed) {
    if (darkThemeChosen3()) {
      printDinoD(_lcd, xLoc, yLoc);
    } else {
      printDinoL(_lcd, xLoc, yLoc);
    }
  }
}


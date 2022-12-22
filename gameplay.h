#include "mbed.h"
#include "C12832.h"
#include <stdio.h>

#include "LEDs.h"
AnalogIn ain3(p19);      //Pot 1 will be used

  LocalFileSystem local("local");
  char filen[] = "/local/scores.txt";


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

char gameOL[] = {
  0x7E,0x18,0x71,0xBF,0x07,0xCE,0x77,0xEF,0x80, // .######....##....###...##.######.....#####..###..###.######.#####.......
  0xFE,0x1C,0x73,0xBF,0x0F,0xE6,0x77,0xEF,0xC0, // #######....###...###..###.######....#######..##..###.######.######......
  0xE0,0x3C,0x7B,0xB8,0x0E,0xE6,0x67,0x0C,0xC0, // ###.......####...####.###.###.......###.###..##..##..###....##..##......
  0xE0,0x3C,0x7B,0xB8,0x0C,0x66,0x67,0x0C,0xC0, // ###.......####...####.###.###.......##...##..##..##..###....##..##......
  0xE0,0x3C,0x7F,0xB8,0x0C,0x67,0xE7,0x0C,0xC0, // ###.......####...########.###.......##...##..######..###....##..##......
  0xEE,0x3E,0x7F,0xBE,0x0C,0x63,0xE7,0xCF,0xC0, // ###.###...#####..########.#####.....##...##...#####..#####..######......
  0xE6,0x7E,0x7D,0xBE,0x0C,0x63,0xC7,0xCF,0x00, // ###..##..######..#####.##.#####.....##...##...####...#####..####........
  0xE6,0x66,0x75,0xB8,0x0C,0x63,0xC7,0x0D,0x80, // ###..##..##..##..###.#.##.###.......##...##...####...###....##.##.......
  0xE6,0x66,0x75,0xB8,0x0E,0xE3,0xC7,0x0D,0x80, // ###..##..##..##..###.#.##.###.......###.###...####...###....##.##.......
  0xFE,0x66,0x71,0xBF,0x0F,0xE1,0xC7,0xED,0xC0, // #######..##..##..###...##.######....#######....###...######.##.###......
  0x7E,0xE7,0x71,0xBF,0x07,0xC1,0x87,0xEC,0xC0  // .######.###..###.###...##.######.....#####.....##....######.##..##......
};

char gameOD[] = {
  0x81,0xE7,0x8E,0x40,0xF8,0x31,0x88,0x10,0x7F, // #......####..####...###..#......#####.....##...##...#......#.....#######
  0x01,0xE3,0x8C,0x40,0xF0,0x19,0x88,0x10,0x3F, // .......####...###...##...#......####.......##..##...#......#......######
  0x1F,0xC3,0x84,0x47,0xF1,0x19,0x98,0xF3,0x3F, // ...#######....###....#...#...#######...#...##..##..##...####..##..######
  0x1F,0xC3,0x84,0x47,0xF3,0x99,0x98,0xF3,0x3F, // ...#######....###....#...#...#######..###..##..##..##...####..##..######
  0x1F,0xC3,0x80,0x47,0xF3,0x98,0x18,0xF3,0x3F, // ...#######....###........#...#######..###..##......##...####..##..######
  0x11,0xC1,0x80,0x41,0xF3,0x9C,0x18,0x30,0x3F, // ...#...###.....##........#.....#####..###..###.....##.....##......######
  0x19,0x81,0x82,0x41,0xF3,0x9C,0x38,0x30,0xFF, // ...##..##......##.....#..#.....#####..###..###....###.....##....########
  0x19,0x99,0x8A,0x47,0xF3,0x9C,0x38,0xF2,0x7F, // ...##..##..##..##...#.#..#...#######..###..###....###...####..#..#######
  0x19,0x99,0x8A,0x47,0xF1,0x1C,0x38,0xF2,0x7F, // ...##..##..##..##...#.#..#...#######...#...###....###...####..#..#######
  0x01,0x99,0x8E,0x40,0xF0,0x1E,0x38,0x12,0x3F, // .......##..##..##...###..#......####.......####...###......#..#...######
  0x81,0x18,0x8E,0x40,0xF8,0x3E,0x78,0x13,0x3F  // #......#...##...#...###..#......#####.....#####..####......#..##..######
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

Bitmap gameOLbm = {66, 11, 9, gameOL};
Bitmap gameODbm = {66, 11, 9, gameOD};

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

void printCactusL(C12832 &_lcd, int &xLoc, int &yLoc) {
  _lcd.print_bm(cactusLbm, xLoc, yLoc);
}

void printCactusD(C12832 &_lcd, int &xLoc, int &yLoc) {
  _lcd.print_bm(cactusDbm, xLoc, yLoc);
}

void printCactus(C12832 &_lcd, bool &centPressed, int &xLoc, int &yLoc) {
  if (centPressed) {
    if (darkThemeChosen3()) {
      printCactusD(_lcd, xLoc, yLoc);
    } else {
      printCactusL(_lcd, xLoc, yLoc);
    }
  }
}

void printGameOL(C12832 &_lcd) { _lcd.print_bm(gameOLbm, 31, 2); }

void printGameOD(C12832 &_lcd) { _lcd.print_bm(gameODbm, 31, 2); }

void printGO(C12832 &_lcd, bool &centPressed) {
  _lcd.cls();
  if (centPressed) {
    if (darkThemeChosen3()) {
      printGameOD(_lcd);
    } else {
      printGameOL(_lcd);
    }
  }
  _lcd.copy_to_lcd();
}

bool collision(int yDin, int xCact) {
  if (xCact <= 12 && xCact > 3) {
    if ((yDin + 12) > 16) {
      return true;
    }
  }
  return false;
}

void viewAndSaveScore(C12832 &_lcd, int &score) {

  FILE *fileR;
  int max = 0;
  int a = 0;
  if ((fileR = fopen(filen, "r")) != NULL) {
    fscanf(fileR, "%d,", &a);
    max = a;
    while (fscanf(fileR, "%d,", &a) > 0) {
      if (max < a) {
        max = a;
      }
    }
    fclose(fileR);
  }

  if (score < max) {
    allLEDs();
    _lcd.locate(30, 13);
    _lcd.printf("YOUR SCORE: %u", score);
    _lcd.locate(34, 22);
    _lcd.printf("HIGHSCORE: %u", max);
    _lcd.copy_to_lcd();
  } else {
    _lcd.locate(23, 18);
    _lcd.printf("NEW HIGHSCORE: %u", score);
  }
  FILE *fp = fopen(filen, "a");
  fprintf(fp, "%u \n", score);
  fclose(fp);
}

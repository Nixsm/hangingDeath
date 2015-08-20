#include <stdio.h>
#include "tutils/tutils.h"

void gotoxy(int x, int y){
    printf("%c[%d;%df", 0x1B, y, x);
}

void printAt(const char* message, int x, int y){
    gotoxy(x, y); printf("%s", message);
}

void clearLine(int y){
    int i;
    for (i = 1; i < MAX_ROW; ++i) {
        printAt(" ", i, y);
    }
}

void drawBorders(char charX, char charY){
    int i, j;
    for (i = 0; i <= MAX_ROW; ++i) {
        gotoxy(i, 0);
        putchar(charX);
    }
    for (j = 0; j <= MAX_COL; ++j) {
        gotoxy(MAX_ROW, j);
        putchar(charY);
    }
    for (j = 0; j <= MAX_COL; ++j) {
        gotoxy(0, j);
        putchar(charY);
    }
    for (i = 0; i <= MAX_ROW; ++i) {
        gotoxy(i, MAX_COL);
        putchar(charX);
    }


}

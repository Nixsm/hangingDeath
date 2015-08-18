#include <stdio.h>
#include "tutils/tutils.h"

void gotoxy(const int& x, const int& y){
    printf("%c[%d;%df", 0x1B, y, x);
}

void drawBorders(const char& charX, const char& charY){
    int i, j;
    for (i = 0; i < MAX_ROW; ++i) {
        gotoxy(i, 0);
        putchar(charX);
    }
    for (j = 0; j < MAX_COL; ++j) {
        gotoxy(MAX_ROW, j);
        putchar(charY);
    }
    for (j = 0; j < MAX_COL; ++j) {
        gotoxy(0, j);
        putchar(charY);
    }
    for (i = 0; i <= MAX_ROW; ++i) {
        gotoxy(i, MAX_COL);
        putchar(charX);
    }


}

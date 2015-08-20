#ifndef TUTILS_H
#define TUTILS_H

#define MAX_ROW 70
#define MAX_COL 20

#ifdef _cplusplus
extern "C" {
#endif
    void gotoxy(int x, int y);
    void drawBorders(char charX, char charY);
    void printAt(const char* message, int x, int y);
    void clearLine(int y);
#ifdef _cplusplus
}
#endif
#endif//TUTILS_H

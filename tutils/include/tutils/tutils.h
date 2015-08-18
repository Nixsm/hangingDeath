#ifndef TUTILS_H
#define TUTILS_H

#define MAX_ROW 70
#define MAX_COL 20

#ifdef _cplusplus
extern "C" {
#endif
    void gotoxy(const int& x, const int& y);
    void drawBorders(const char& charX, const char& charY);
#ifdef _cplusplus
}
#endif
#endif//TUTILS_H

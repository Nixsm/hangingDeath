#ifndef SCREEN_H
#define SCREEN_H

#include "hanger.h"
#include "game_controller.h"

namespace de{

    typedef struct {
        GameController const* gc;
    }Screen;

    Screen createScreen(GameController const* gc);
    
    void drawHanger(const Screen& sc);

    void drawCurrentWord(const Screen& sc);

    void drawGuessedChars(const Screen& sc);

}
#endif//SCREEN_H

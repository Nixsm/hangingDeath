#ifndef SCREEN_H
#define SCREEN_H

#include "hanger.h"
#include "game_controller.h"

namespace de{

    typedef struct {
        GameController* gc;
    }Screen;

    Screen createScreen(GameController* gc);
    
    void clearAlertMessage();
    
    void clearHanged();
    
    void alertMessage(const char* message, const bool& sleep);
    
    void drawInput(Screen& sc);
    
    void drawHanger(const Screen& sc);

    void drawCurrentWord(const Screen& sc);

    void drawGuessedChars(const Screen& sc);

}
#endif//SCREEN_H

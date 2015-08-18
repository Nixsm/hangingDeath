#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "dynamic_list_template.h"
#include "dynamic_list_template.impl.h"
#include <string>
#include "hanger.h"

namespace de{
    
    typedef struct {
        List<List<char> > words;
        List<char> currentWord;
        List<char> charsGuessed;
        List<bool> wordChecker;
        Hanger hanger;
    }GameController;
    
    GameController createGameController(const List<List<char> >& words);

    List<bool> getCheckedChars(const GameController& gc);
    
    void newWord(GameController& gc);
    
    void guessChar(GameController& gc, const char& guess);
    
    List<char> getCharsGuessed(const GameController& gc);
    List<char> getCurrentWord(const GameController& gc);
    unsigned int getCurrentLife(const GameController& gc);
    
    void drawHanged(const GameController& gc);
    
    bool isLettersGuessedRight(const GameController& gc);
    
    
    
}

#endif//GAME_CONTROLLER_H

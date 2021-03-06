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
    
    void reset(GameController& gc);
    
    GameController createGameController(const List<List<char> >& words);

    List<bool> getCheckedChars(const GameController& gc);
    
    void newWord(GameController& gc);
    
    bool guessChar(GameController& gc, const char& guess);
    
    List<char> getCharsGuessed(const GameController& gc);
    List<char> getCurrentWord(const GameController& gc);
    unsigned int getCurrentLife(const GameController& gc);
        
    bool isLettersGuessedRight(const GameController& gc);
    
    
    
}

#endif//GAME_CONTROLLER_H

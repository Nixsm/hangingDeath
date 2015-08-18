#include <iostream>
#include "screen.h"
#include "word_reader.h"
#include "game_controller.h"
#include <tutils/tutils.h>

int main(int argc, char** argv){
    
    system("clear");

    drawBorders('|', '|');
    //    gotoxy(0, 0);
//    std::cout << "Teste";
//    
//    gotoxy(70, 20);
//    std::cout << "Teste2";
//    
    
    
    
//    return 0;
    de::WordReader readedWords = de::createReader("/Users/nicholas/workspace/hangingDeath/build/words");
    
    de::List<de::List<char> > words = de::getWords(readedWords);
        
    if(words.size() == 3){
        std::cout << "Reading Correctly!" << std::endl;
    }
    
    for(auto i = 1u; i <= words.size();++i){
        std::cout << words.at(i) << std::endl;
    }
    
    de::GameController gc = de::createGameController(words);
    
    de::newWord(gc);
    
    std::cout << de::getCurrentWord(gc) << std::endl;
    
    de::Screen sc = de::createScreen(&gc);

    de::drawHanger(sc);

    de::drawGuessedChars(sc);

    while(true){
        std::cout << "Guess a char" << std::endl;
        const char guess = std::cin.get();
        std::cin.get();
        de::guessChar(gc, guess);
        //std::cout << de::getCharsGuessed(gc) << std::endl;
        
        std::cout << de::getCurrentLife(gc) << std::endl;

        de::drawCurrentWord(sc);
        de::drawGuessedChars(sc);
    }
    return 0;
    
        
}

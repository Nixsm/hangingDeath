#include <iostream>
#include "screen.h"
#include "word_reader.h"
#include "game_controller.h"
#include <tutils/tutils.h>

void doBullshit(de::List<int> list){
    de::List<int> teste;
    
    teste = list;

    std::cout << teste << std::endl;
    std::cout << list << std::endl;
    
    std::cout << "Saindo" << std::endl;
    
}

int main(int argc, char** argv){
    de::List<int> list;
    
    for (int i = 1 ;i <= 10; ++i) {
        list.insert(i, i);
    }
    
    list.remove(10);
    
    list.insertOrdered(22);
    
    list.reverse();
    
    list.insert(1, 1);
        
    de::List<int> newList;
    
    newList = list;
    
    std::cout << list << std::endl;
    
    std::cout << newList << std::endl;
    
    doBullshit(list);
    
//    std::cout << list << std::endl;
    
//    list.~List();
//    newList.~List();
    
    return 0;
    
    //
//    system("clear");
//
//    de::WordReader readedWords = de::createReader("/Users/nicholas/workspace/hangingDeath/build/words");
//    
//    de::List<de::List<char> > words = de::getWords(readedWords);
//    
//    de::GameController gc = de::createGameController(words);
//    
//    de::newWord(gc);
//    
//    de::Screen sc = de::createScreen(&gc);
//
//    drawBorders('.', '.');
//    
//    while(true){
//        
//        de::drawCurrentWord(sc);
//        de::drawGuessedChars(sc);
//        
//        de::drawInput(sc);
//    }
//
//
//    gotoxy(MAX_ROW, MAX_COL+2); /* Go the end of console */
//    return 0;
//
//    
//    
////    return 0;
//
//    de::drawGuessedChars(sc);
//
//    while(true){
//        std::cout << "Guess a char" << std::endl;
//        const char guess = std::cin.get();
//        std::cin.get();
//        de::guessChar(gc, guess);
//        //std::cout << de::getCharsGuessed(gc) << std::endl;
//        
//        std::cout << de::getCurrentLife(gc) << std::endl;
//
//        de::drawCurrentWord(sc);
//        de::drawGuessedChars(sc);
//    }
//    return 0;
    
        
}

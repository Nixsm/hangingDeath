#include <iostream>

#include "word_reader.h"
#include "game_controller.h"

int main(int argc, char** argv){
    de::WordReader readedWords = de::createReader("/home/nicholas/words.txt");
    
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
    

    while(true){
        std::cout << "Guess a char" << std::endl;
        const char guess = std::cin.get();
        std::cin.get();
        de::guessChar(gc, guess);
        //std::cout << de::getCharsGuessed(gc) << std::endl;
        
        std::cout << de::getCurrentLife(gc) << std::endl;

        std::cout << gc.wordChecker << std::endl;
        
        if (de::isLettersGuessedRight(gc)){
            break;
        }
        
    }
    
    return 0;
    
        
}

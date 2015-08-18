#include "game.h"
#include <ctype.h>
#include <limits>

namespace de{
    Game createGame(const List<List<char> > words){
        Game game;
        game.gc = createGameController(words);
        game.sc = createScreen(&game.gc);
        return game;
    }
    
    void start(Game& game){
        bool shouldQuit = false;
        
        
        
        while (!shouldQuit){
        
            /* choose a random new word */
            de::newWord(game.gc);
            bool lost = true; /* I predict the player will always loose! mwahahah */
            
            while (true){
                std::cout << "Guess a char ";
                const char guess = std::tolower(std::cin.get());
                std::cin.get();
                de::guessChar(game.gc, guess);
                
                
                std::cout << game.gc.wordChecker << std::endl; /* This should not appear here */
                
                if(de::isLettersGuessedRight(game.gc)){
                    lost = false;
                    break;
                }else if(de::getCurrentLife(game.gc) == 0){
                    break;
                }
            }
            
            if(lost){
                std::cout << "Ooh!! How sad you lost :(" << std::endl;
            }else{
                std::cout << "Congratz!! You won :)" << std::endl;
            }
            
            std::string string;
            std::cout << "Play again? (y/N) ";
            std::getline(std::cin, string);
            char option;
            if (string == ""){
                option = 'N';
            }else if (string.size() < 1){
                option = 'Y';
            }else{
                option = std::toupper(string.at(0));
            }
            
            if (option == 'Y' || option == 'N'){
                shouldQuit = (option == 'Y') ? false : true;
            }
                        
    
        }
    }
    
}
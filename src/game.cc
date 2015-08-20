#include "game.h"
#include <ctype.h>
#include <limits>
#include <tutils/tutils.h>

namespace de{
    Game createGame(const List<List<char> > words){
        Game game;
        game.gc = createGameController(words);
        game.sc = createScreen(&game.gc);
        return game;
    }
    
    void start(Game& game){
        bool shouldQuit = false;
        
        drawBorders('_', '.');
        
        
        while (!shouldQuit){
            
            /* choose a random new word */
            de::newWord(game.gc);
            
            bool lost = true; /* I predict the player will always loose! mwahahah */
            
            de::drawCurrentWord(game.sc);
            de::drawGuessedChars(game.sc);
            
            while (true){
                de::drawInput(game.sc);
                
                de::drawCurrentWord(game.sc);
                de::drawGuessedChars(game.sc);
                
                if(de::isLettersGuessedRight(game.gc)){
                    lost = false;
                    break;
                }else if(de::getCurrentLife(game.gc) == 0){
                    break;
                }
            }
            /* Make the terminal buffer update */
            std::cout << std::endl;
            
            if(lost){
                alertMessage("Ooh!! How sad you lost :(", false);
            }else{
                alertMessage("Congratz!! You won :)", true);
            }
            std::cout << std::endl;
            
            std::string string;
            alertMessage("Play again? (y/N) ", false);
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
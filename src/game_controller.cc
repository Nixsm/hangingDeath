#include "game_controller.h"
#include <random>
#include <iostream>
#include <string>
#include <chrono>

namespace de{
    GameController createGameController(const List<List<char> >& words){
        GameController gc;
        gc.words = words;
        gc.hanger = createHanger(10);
                        
        return gc;
    }
    
    void newWord(GameController& gc){
        /* Create a seed based on time since 1970 */
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        /* Create the default random engine using the seed we created */
        std::default_random_engine generator(seed);
        /* Generate a number with that engine */
        std::uniform_int_distribution<int> distribution(1, (int)gc.words.size());
        /* Roll the dice!! */
        int diceRoll = distribution(generator);  // generates number in the range 1..Size of game words 

        gc.currentWord = gc.words.at(diceRoll);    
        
        /* Tell the program we dont have any word guessed yet */
        for (auto i = 1u; i <= gc.currentWord.size(); ++i){
            gc.wordChecker.insert(false, i);
        }
    }

    List<bool> getCheckedChars(const GameController& gc){
        return gc.wordChecker;
    }
    
    
    void guessChar(GameController& gc, const char& guess){
        gc.charsGuessed.insertOrdered(guess);
        
        /* Check if the element is in our current word */
        if (gc.currentWord.elementExists(guess)){
            List<unsigned int> occurences;
            
            /* Find the occurences of this char in our word */
            gc.currentWord.findOccurences(occurences, guess);
                        
            for (auto i = 1u; i <= occurences.size(); ++i){
                gc.wordChecker[occurences.at(i)] = true;
            }
        }else{
            decreaseHangedLife(gc.hanger);
        }
                
    }
    
    bool isLettersGuessedRight(const GameController& gc){
        for (auto i = 1u; i <= gc.wordChecker.size(); ++i){
            if (gc.wordChecker.at(i) == false){
                return false;
            }
        }
        return true;
    }
    
    List<char> getCharsGuessed(const GameController& gc){
        return gc.charsGuessed;
    }
    
    List<char> getCurrentWord(const GameController& gc){
        return gc.currentWord;
    }
    
    unsigned int getCurrentLife(const GameController& gc){
        return getHangedLife(gc.hanger);
    }
    
    void drawHanged(const GameController& gc){
        de::draw(gc.hanger);
    }
    
}

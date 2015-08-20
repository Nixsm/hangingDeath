#include "screen.h"
#include <sstream>

/* Used for sleep functions */
#include <chrono>
#include <thread>

/* Terminal manipulation */
#include <tutils/tutils.h>

namespace de{

    Screen createScreen(GameController* gc){
        Screen sc;
        sc.gc = gc;
        return sc;
    }
    
    void clearAlertMessage(){
        clearLine(MAX_COL+1);
    }
    
    void alertMessage(const char* message, const bool& sleep){
        clearAlertMessage();
        printAt(message, 0, MAX_COL+1);
        if (sleep) {
            std::cout << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        }

    }
    
    
    void drawHanger(const Screen& sc){
        const unsigned int life = de::getCurrentLife(*sc.gc);

        std::cout << "Current Life: " << life << std::endl;
    }

    void drawInput(Screen& sc){
        printAt("Guess char: ", 5, MAX_COL-1);
        const char guess = std::tolower(std::cin.get());
        std::cin.get();
        const bool result = de::guessChar(*sc.gc, guess);
        if (result) {
            alertMessage("Hit!", false);
        }else{
            alertMessage("Miss!", false);
        }
        
    }

    void drawCurrentWord(const Screen& sc){
        List<char> currentWord = getCurrentWord(*sc.gc);
        List<bool> wordChecker = getCheckedChars(*sc.gc);
        List<char> drawed;
        
        for (auto i = 1; i <= currentWord.size(); ++i){
            if (wordChecker[i]){
                drawed.insert(currentWord[i], i);
            }else{
                drawed.insert('_', i);
            }
        }

        std::stringstream ss;
        ss << "Current word: ";
        ss << drawed;


        printAt(ss.str().c_str(), 30, MAX_COL-15);
    }

    void drawGuessedChars(const Screen& sc){
        std::stringstream ss;
        ss << getCharsGuessed(*sc.gc);
        
        printAt("Chars guessed: ", 30, MAX_COL - 4);
        printAt(ss.str().c_str(), 30, MAX_COL - 3);
    }
}

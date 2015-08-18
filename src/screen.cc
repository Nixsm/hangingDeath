#include "screen.h"

namespace de{

    Screen createScreen(GameController const* gc){
        Screen sc;
        sc.gc = gc;
        return sc;
    }
    
    void drawHanger(const Screen& sc){
        const unsigned int life = de::getCurrentLife(*sc.gc);

        std::cout << "Current Life: " << life << std::endl;
    }

    void drawInput(const Screen& sc){
        std::cout << "Guess a Char" << std::endl;
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

        std::cout << drawed << std::endl;
    }

    void drawGuessedChars(const Screen& sc){
        std::cout << getCharsGuessed(*sc.gc) << std::endl;
    }
}

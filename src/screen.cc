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
    
    void clearHanged() {
        for (auto i = 16; i <= 18; ++i){
            for (auto j = 7; j <= 12; ++j){
                gotoxy(i, j); std::cout << " " << std::endl;
            }
        }
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
        
        clearHanged();
        
        /* draw the hanger */
        for (auto i = 5; i <= 17; ++i){
            gotoxy(i, 4); std::cout << "_" << std::endl;
        }
        
        for(auto i = 5; i <= 6; ++i) {
            gotoxy(17, i); std::cout << "|" << std::endl;
        }
        
        for (auto i = 5; i <= 15; ++i) {
            gotoxy(5, i); std::cout << "|" << std::endl;
        }
        gotoxy(4, 15); std::cout << "/" << std::endl;
        gotoxy(6, 15); std::cout << "\\" << std::endl;
        
        /* Hanged person starts here */
        /* start drawing at 17, 7 */
        
        /* draw head */
        
        if (life > 0){
            gotoxy(16, 7); std::cout << "(" << std::endl;
        }
        if (life > 1){
            gotoxy(18, 7); std::cout << ")" << std::endl;
        }
        
        /* draw heart */
        if (life > 2){
            gotoxy(17, 8); std::cout << "*" << std::endl;
        }
        /* draw arms */
        if (life > 3) {
            gotoxy(16, 8); std::cout << "/" << std::endl;
        }
        
        if (life > 4){
            gotoxy(18, 8); std::cout << "\\" << std::endl;
        }
        
        /* draw body */
        if (life > 5) {
            gotoxy(17, 9); std::cout << "|" << std::endl;
        }
        
        if (life > 6) {
            gotoxy(17, 10); std::cout << "|" << std::endl;
        }
        
        if (life > 7) {
            gotoxy(17, 11); std::cout << "|" << std::endl;
        }
        
      
        /* draw legs */
        if (life > 8) {
            gotoxy(16, 12); std::cout << "/" << std::endl;
        }
        
        if (life > 9){
            gotoxy(18, 12); std::cout << "\\" << std::endl;
        }
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
        
        for (auto i = 1u; i <= currentWord.size(); ++i){
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

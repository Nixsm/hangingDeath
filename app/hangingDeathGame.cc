#include "game.h"
#include "word_reader.h"

void help();

int main(int argc, char** argv){
    if (argc != 2){
        help(); /* not enough args, call for help */
        std::exit(0);
    }
    /* argv[1] should contain the path to words file */
    de::WordReader wordReader = de::createReader(argv[1]);
    
    de::Game game = de::createGame(de::getWords(wordReader));
    
    de::start(game);

    return 0;    
}

void help(){
    std::cout << "<exec> <path/to/words/file>" << std::endl;
}
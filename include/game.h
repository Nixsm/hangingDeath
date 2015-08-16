#ifndef GAME_H
#define GAME_H

#include "game_controller.h"

namespace de{
    typedef struct Game{
        GameController gc;
        //Screen sc;
    }Game;
    
    Game createGame(const List<List<char> > words);
    void start(Game& game);

}
#endif//GAME_H

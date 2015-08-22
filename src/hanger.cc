#include "hanger.h"
#include <iostream>

namespace de{
    Hanger createHanger(const unsigned int& hangedLife){
        Hanger hanger;
        hanger.hangedLife = hangedLife;
        return hanger;
    }
    
    void setLife(Hanger& hanger, const unsigned int& hangedLife){
        hanger.hangedLife = hangedLife;
    }
    
    unsigned int getHangedLife(const Hanger& hanger){
        return hanger.hangedLife;
    }
    
    void decreaseHangedLife(Hanger& hanger){
        hanger.hangedLife--;
    }
}

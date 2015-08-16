#ifndef HANGER_H
#define HANGER_H

namespace de{

    typedef struct{
        unsigned int hangedLife;
    }Hanger;

    Hanger createHanger(const unsigned int& hangedLife);
    
    void draw(const Hanger& hanger);
    void setHangedLife(Hanger& hanger, const unsigned int& life);
    unsigned int getHangedLife(const Hanger& hanger);
    void decreaseHangedLife(Hanger& hanger);
}
#endif//HANGER_H
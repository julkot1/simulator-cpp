//
// Created by julian on 3/29/24.
//

#ifndef SIM_CPP_SHEEP_H
#define SIM_CPP_SHEEP_H


#include "Animal.h"

class Sheep : public Animal{
public:
    static std::string SYMBOL(){return "\033[37mS\033[0m";};
    Sheep(Pos pos, Sim *world);
};


#endif //SIM_CPP_SHEEP_H

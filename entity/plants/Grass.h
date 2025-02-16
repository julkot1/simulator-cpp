//
// Created by julian on 4/17/24.
//

#ifndef SIM_CPP_GRASS_H
#define SIM_CPP_GRASS_H


#include "Plant.h"

class Grass : public Plant{
public:
    Grass(Pos pos, Sim *world);

    static std::string SYMBOL(){return "\033[92mG\033[0m";};

};


#endif //SIM_CPP_GRASS_H

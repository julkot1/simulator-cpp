//
// Created by julian on 4/17/24.
//

#ifndef SIM_CPP_BERRY_H
#define SIM_CPP_BERRY_H


#include "Plant.h"

class Berry : public Plant {
public:
    Berry(Pos pos, Sim *world);

    static std::string SYMBOL(){return "\033[95mB\033[0m";};


    bool respondAttack(Entity &entity) override;
};


#endif //SIM_CPP_BERRY_H

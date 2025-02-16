//
// Created by julian on 4/18/24.
//

#ifndef SIM_CPP_HOGWEED_H
#define SIM_CPP_HOGWEED_H


#include "Plant.h"

class Hogweed : public Plant{
public:
    Hogweed(Pos pos, Sim *world);
    void action() override;
    bool respondAttack(Entity &entity) override;

    static std::string SYMBOL(){return "\033[36mH\033[0m";};

};


#endif //SIM_CPP_HOGWEED_H

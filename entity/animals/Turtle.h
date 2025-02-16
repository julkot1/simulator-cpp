//
// Created by julian on 4/15/24.
//

#ifndef SIM_CPP_TURTLE_H
#define SIM_CPP_TURTLE_H


#include "Animal.h"

class Turtle : public Animal {
public:
    Turtle(Pos pos, Sim *world);

    static std::string SYMBOL(){return "\033[94mT\033[0m";};

    void action() override;
    bool respondAttack(Entity &entity) override;

};


#endif //SIM_CPP_TURTLE_H

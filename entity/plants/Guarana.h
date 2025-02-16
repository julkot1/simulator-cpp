//
// Created by julian on 4/17/24.
//

#ifndef SIM_CPP_GUARANA_H
#define SIM_CPP_GUARANA_H


#include "Plant.h"

class Guarana : public Plant {
private:
    const int STRENGTH_BOOST  = 3;
public:
    Guarana(Pos pos, Sim *world);
    bool respondAttack(Entity &entity) override ;

    static std::string SYMBOL(){return "\033[91mG\033[0m";};

};


#endif //SIM_CPP_GUARANA_H

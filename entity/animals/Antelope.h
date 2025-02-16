//
// Created by julian on 4/15/24.
//

#ifndef SIM_CPP_ANTELOPE_H
#define SIM_CPP_ANTELOPE_H


#include "Animal.h"

class Antelope : public Animal{
public:
    static std::string SYMBOL(){return "\033[33mA\033[0m";};
    Antelope(Pos pos, Sim *world);
    void action() override;
    void attack(Entity &entity) override;

};


#endif //SIM_CPP_ANTELOPE_H

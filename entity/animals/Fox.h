//
// Created by julian on 4/15/24.
//

#ifndef SIM_CPP_FOX_H
#define SIM_CPP_FOX_H


#include "Animal.h"

class Fox : public Animal{
public:
    static std::string SYMBOL(){return "\033[31mF\033[0m";};

    Fox(Pos pos, Sim *world);
    void action() override;

};


#endif //SIM_CPP_FOX_H

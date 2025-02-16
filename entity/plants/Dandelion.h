//
// Created by julian on 4/17/24.
//

#ifndef SIM_CPP_DANDELION_H
#define SIM_CPP_DANDELION_H


#include "Plant.h"

class Dandelion : public Plant {
public:
    Dandelion(Pos pos, Sim *world);

    static std::string SYMBOL(){return "\033[93mD\033[0m";};

    void action() override;
};


#endif //SIM_CPP_DANDELION_H

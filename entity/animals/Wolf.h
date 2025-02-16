//
// Created by julian on 3/28/24.
//

#ifndef SIM_CPP_WOLF_H
#define SIM_CPP_WOLF_H


#include "Animal.h"

class Wolf : public Animal{
public:
    Wolf(Pos pos, Sim *world);

    static std::string SYMBOL(){return  "\033[90mW\033[0m";};

};


#endif //SIM_CPP_WOLF_H

//
// Created by julian on 3/24/24.
//

#ifndef SIM_ANIMAL_H
#define SIM_ANIMAL_H


#include "../../Sim.h"
#include <cstdlib>
#include <ctime>

class Animal : public Entity{
public:
    Animal(Pos pos, int priority, int damage, std::string symbol, Sim *world);
    Animal(const Animal& other);
    void action() override;
    void collision(Entity &entity) override;
    void reproduction(Entity &entity);
    bool respondAttack(Entity &entity) override;
    ~Animal() override;
};


#endif //SIM_ANIMAL_H

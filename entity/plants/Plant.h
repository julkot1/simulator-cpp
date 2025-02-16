//
// Created by julian on 4/17/24.
//

#ifndef SIM_CPP_PLANT_H
#define SIM_CPP_PLANT_H


#include "../../Sim.h"

class Plant : public Entity{
protected:
    const int SPAWN_CHANCE = 10;

    virtual bool trySpawn();
public:
    Plant(Pos pos, int damage, std::string symbol, Sim *world);
    Plant(const Plant& other);

    void action() override;
    void collision(Entity &entity) override;

    bool respondAttack(Entity &entity) override;



    ~Plant() override;
};


#endif //SIM_CPP_PLANT_H

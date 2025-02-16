//
// Created by julian on 4/15/24.
//

#include <iostream>
#include "Antelope.h"


Antelope::Antelope(Pos pos, Sim *world) : Animal(pos, 4, 4, Antelope::SYMBOL(), world) {}

void Antelope::action() {
    prevPos = pos;
    sim::Direction direction = world->getDirection();
    Pos newPos = world->translatePos(pos, direction);
    newPos = world->translatePos(newPos, direction);
    Entity *entity = world->getEntity(newPos);
    pos = newPos;
    if(entity != nullptr){
        Animal::collision(*entity);
    }
}

void Antelope::attack(Entity &entity) {

    std::uniform_int_distribution<> dis(0, 1);
    int d = dis(world->getGen());
    if(d == 0){
        std::vector<Pos> neighbors = pos.getNeighbors(world->getSizeW(), world->getSizeH());
        for(auto &neighbor : neighbors){
            if(world->getEntity(neighbor) == nullptr){
                prevPos = pos;
                pos = neighbor;
                return;
            }
        }
    }

    Animal::attack(entity);
}



//
// Created by julian on 4/18/24.
//

#include <iostream>
#include "Hogweed.h"
#include "../animals/Animal.h"

Hogweed::Hogweed(Pos pos, Sim *world) : Plant(pos, 10, Hogweed::SYMBOL(), world){}

void Hogweed::action() {
    std::vector<Entity *> neighbors = world->getNeighbors(pos);

    for(auto n : neighbors){
        if(n!= nullptr){
            if(auto a = dynamic_cast<Animal *>(n)){
                world->getLog().newLog(world->getTurn()) << *this << " killed " << *n << world->getLog().eol();
                world->removeEntity(n);
            }
        }
    }
    Plant::action();
}

bool Hogweed::respondAttack(Entity &entity) {
    world->getLog().newLog(world->getTurn()) << " ate " << *this << world->getLog().eol();
    world->removeEntity(&entity);
    world->removeEntity(this);
    return true;
}

//
// Created by julian on 4/17/24.
//

#include <iostream>
#include "Berry.h"

Berry::Berry(Pos pos, Sim *world) : Plant(pos, 99, Berry::SYMBOL(), world) {}

bool Berry::respondAttack(Entity &entity) {
    world->getLog().newLog(world->getTurn()) << "Entity " << entity << " ate " << *this << world->getLog().eol();
    world->removeEntity(&entity);
    world->removeEntity(this);
    return true;
}


//
// Created by julian on 4/15/24.
//

#include "Fox.h"


Fox::Fox(Pos pos, Sim *world) : Animal(pos, 7, 3, Fox::SYMBOL(), world){

}


void Fox::action() {
    prevPos = pos;
    std::vector<Pos> neighbors = pos.getNeighbors(world->getSizeW(), world->getSizeH());
    Pos newPos = pos;
    Entity *entity = nullptr;
    for (auto &neighbor : neighbors) {
        if (world->getEntity(neighbor) == nullptr) {
            newPos = neighbor;
            break;
        }else if(world->getEntity(neighbor)->getDamage() > damage){
            newPos = neighbor;
            entity=world->getEntity(neighbor);
            break;
        }else if(world->getEntity(neighbor)->getSymbol() == symbol){
            newPos = neighbor;
            entity=world->getEntity(neighbor);
            break;
        }
    }
    if (newPos == pos)
        return;
    if(entity != nullptr){
        Animal::collision(*entity);
    }else{
        pos = newPos;
    }



}


//
// Created by julian on 3/24/24.
//

#include <iostream>
#include "Animal.h"
#include <utility>
#include <vector>


Animal::Animal(Pos pos, int priority, int damage, std::string symbol, Sim *world)
: Entity(pos, priority, damage, std::move(symbol), world) {
    alive = true;
}

void Animal::collision(Entity &entity) {
    if(symbol == entity.getSymbol()){
        reproduction(entity);
    } else {
        attack(entity);
    }
}


void Animal::action() {
    sim::Direction direction = world->getDirection();
    prevPos = pos;
    Pos newPos = world->translatePos(pos, direction);
    Entity *entity = world->getEntity(newPos);
    pos = newPos;
    if(entity != nullptr){
        Animal::collision(*entity);
    }


}
Animal::Animal(const Animal &other) : Entity(other.pos, other.priority, other.damage, other.symbol, other.world) {

}


void Animal::reproduction(Entity &entity) {
    if(!entity.isAlive() || !this->isAlive())return;
    this->pos = prevPos;
    Pos newPos = Pos(-1,-1);
    std::vector<Pos> newPosVec = pos.getNeighbors(world->getSizeW(), world->getSizeH());
    entity.getPosition().getNeighbors(newPosVec, world->getSizeW(), world->getSizeH());

    for(auto pos : newPosVec){
        if(world->getEntity(pos) == nullptr){
            newPos = pos;
            break;
        }
    }
    world->getLog().newLog(world->getTurn()) << *this << " and " << entity <<  " try reproduce" <<world->getLog().eol();

    if(newPos.getX()!=-1) {
        auto *a = new Animal(*this);
        a->updatePosition(newPos.getX(), newPos.getY());
        world->addEntity(a);
        world->getLog().newLog(world->getTurn()) << *this << " and " << entity << " created " << *a << world->getLog().eol();

    }
}

Animal::~Animal() {
    alive = false;
}

bool Animal::respondAttack(Entity &entity) {
    return false;
}



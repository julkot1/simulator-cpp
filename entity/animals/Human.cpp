//
// Created by julian on 4/9/24.
//

#include "Human.h"

Human::Human(Pos pos, Sim *world)
: Animal(pos, 4, 5, Human::SYMBOL(), world), direction(sim::UP), isUlt(false), ultCount(5), ultCooldown(5)
{}

void Human::setDirection(sim::Direction direction) {
    Human::direction = direction;
}

void Human::action() {
    if(isUlt){
        useUlt();
        if(ultCount == 0){
            isUlt = false;
            ultCooldown = 5;
            ultCount = 5;
        }else{
            ultCount--;
        }
    }
    else  ultCooldown--;
    Pos newPos = world->translatePos(pos, direction);
    Entity *entity = world->getEntity(newPos);
    if(entity != nullptr){
        Animal::collision(*entity);
    }else{
        pos = newPos;
    }
}

sim::Direction Human::getDirection() {
    return direction;
}

Human::~Human() {
    Animal::~Animal();
    world->killHuman();

}

void Human::useUlt() {
    std::vector<Entity *> neighbors = world->getNeighbors(pos);
    for(auto n : neighbors){
        if(n!= nullptr)world->removeEntity(n);
    }
}

void Human::setUlt(bool ult) {
    isUlt = ult;
}

bool Human::getUlt() const {
    return isUlt;
}

int Human::getCoolDown() const {
    return ultCooldown < 0 ? 0 : ultCooldown;
}

int Human::getUltCount() const {
    return ultCount;
}

void Human::setCoolDown(int i) {
    ultCooldown = i;
}

void Human::setUltCount(int i) {
    ultCount = i;
}


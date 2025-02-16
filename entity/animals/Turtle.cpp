//
// Created by julian on 4/15/24.
//

#include "Turtle.h"

Turtle::Turtle(Pos pos, Sim *world) : Animal(pos, 1, 2, Turtle::SYMBOL(), world) {}

void Turtle::action() {
    std::uniform_int_distribution<> dis(0, 3);
    int d = dis(world->getGen());
    if(d == 0)
        Animal::action();
}

bool Turtle::respondAttack(Entity &entity) {
    if (auto animal = dynamic_cast<Animal*>(&entity)) {
        if (animal->getDamage() >= 5)
            return false;
        animal->getPosition().setPos(animal->getPrevPos().getX(), animal->getPrevPos().getY());
        world->getLog().newLog(world->getTurn()) << *this << " defends attack from " << entity << world->getLog().eol();
        return true;
    }
    return false;
}





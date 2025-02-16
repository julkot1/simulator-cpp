//
// Created by julian on 4/17/24.
//

#include <iostream>
#include "Plant.h"

Plant::Plant(Pos pos, int damage, std::string symbol, Sim *world)
: Entity(pos, 0, damage, std::move(symbol), world) {
    alive = true;
}

Plant::Plant(const Plant &other) {
    pos = other.pos;
    priority = other.priority;
    damage = other.damage;
    symbol = other.symbol;
    world = other.world;
    alive = other.alive;
}

void Plant::collision(Entity &entity) {
    world->removeEntity(&entity);
}

void Plant::action() {
    if(trySpawn()){
        std::vector<Pos> neighbors = pos.getNeighbors(world->getSizeW(), world->getSizeH());
        for(auto pos : neighbors){
            if(world->getEntity(pos) == nullptr){
                auto *p = new Plant(pos, damage, symbol, world);
                world->addEntity(p);
                break;
            }
        }
    }
}

bool Plant::trySpawn() {
    std::uniform_int_distribution<> dis(0, SPAWN_CHANCE);
    int d = dis(world->getGen());
    if(d == 0)return true;
    return false;
}

bool Plant::respondAttack(Entity &entity) {
    return false;
}

Plant::~Plant() {
    alive = false;
}

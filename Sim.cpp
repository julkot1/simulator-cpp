//
// Created by julian on 3/24/24.
//

#include "Sim.h"
#include "view/Colors.h"
#include "view/View.h"
#include <utility>
#include <iostream>
#include "entity/animals/Human.h"
void Sim::addEntity(Entity *entity) {
    entities.push_back(entity);
    std::sort(entities.begin(), entities.end(), [](Entity *a, Entity *b) {
        return *a > *b;
    });
}

void Sim::render() {
    std::cout << std::endl;
    for (int i = 0; i < getSizeW()+2; ++i) {
        std::cout << GREEN << "*";
    }
    std::cout << std::endl;
    for (int i = 0; i < getSizeH(); ++i) {
        std::cout << GREEN << "*" << RESET;
        for (int j = 0; j < getSizeW(); ++j) {
            std::cout << " ";
        }
        std::cout << GREEN << "*" << RESET << std::endl;
    }
    for (int i = 0; i < getSizeW()+2; ++i) {
        std::cout << GREEN << "*";
    }
    std::cout << std::endl << std::endl;

    for (auto current_entity : entities) {
        current_entity->render();
    }
}

void Sim::nextTurn() {
    turn++;
    for(int i =0;i<entities.size(); i++){
        auto current_entity = entities[i];

        if(current_entity!= nullptr)if(current_entity->isAlive())current_entity->action();
    }

    auto iter = entities.begin();
    while (iter != entities.end()) {
        if (!(*iter)->isAlive()) {
            delete *iter;
            iter = entities.erase(iter);
        } else {
            ++iter;
        }
    }
}

Sim::~Sim() {
    for (auto e : entities) {
        delete e;
    }

}

Sim::Sim(int size_W, int size_H) : size_H(size_H), size_W(size_W), turn(0){
    std::random_device rd;
    gen = std::mt19937(rd());
    log = {};
}

int Sim::getSizeW() const {
    return size_W;
}

int Sim::getSizeH() const {
    return size_H;
}

int Sim::getTurn() const {
    return Sim::turn;
}

Pos Sim::translatePos(Pos pos, sim::Direction direction) {
    if (direction == sim::Direction::UP) {
        return {pos.getX(), (pos.getY() - 1)<0?(size_H-1):(pos.getY()-1)};
    } else if (direction == sim::Direction::DOWN) {
        return {pos.getX(), (pos.getY() + 1)%size_H};
    } else if (direction == sim::Direction::LEFT) {
        return {(pos.getX() - 1)<0?(size_W-1):(pos.getX()-1), pos.getY()};
    } else if (direction == sim::Direction::RIGHT) {
        return {(pos.getX() + 1)%size_W, pos.getY()};
    }
}

Entity *Sim::getEntity(Pos pos) {
    for(auto current_entity : entities){
        if(current_entity->getPosition() == pos && current_entity->isAlive()){
            return current_entity;
        }
    }
    return nullptr;
}

sim::Direction Sim::getDirection() {
    std::uniform_int_distribution<> dis(0, 2);
    int d = dis(gen);
    if (d == 0)
        return sim::UP;
    if (d == 1)
        return sim::DOWN;
    if (d == 2)
        return sim::RIGHT;
    return sim::LEFT;
}

std::vector<Entity *> Sim::getNeighbors(Pos pos) {
    std::vector<Entity *> neighbors;
    for(auto current_entity : entities){
        if(current_entity->getPosition().isNeighbor(pos) && current_entity->isAlive()){
            neighbors.push_back(current_entity);
        }
    }
    return neighbors;
}
void Sim::getNeighbors(Pos pos, std::vector<Entity *> &neighbors) {
    for(auto current_entity : entities){
        if(current_entity->getPosition().isNeighbor(pos)){
            neighbors.push_back(current_entity);
        }
    }
}
void Sim::setHumanDirection(sim::Direction direction) {
    if(human != nullptr)
        human->setDirection(direction);
}
void Sim::removeEntity(Entity *entity) {
    entity->die();
}

Human *Sim::getHuman() const {
    return human;
}

void Sim::killHuman() {
    human = nullptr;
}

std::mt19937 & Sim::getGen() {
    return gen;
}

Logger &Sim::getLog() {
    return log;
}

std::vector<Entity *> Sim::getEntities() const {
    return entities;
}

void Sim::addHuman(Human &h) {
    human = &h;
    addEntity(&h);
}

void Sim::setTurn(int i) {
    turn = i;
}


Pos Entity::getPosition() {
    return Entity::pos;
}
void Entity::updatePosition(int x, int y) {
    pos.setPos(x,y);
}


Entity::Entity(Pos pos, int priority, int damage, std::string symbol, Sim *world) : alive(true), pos(pos), priority(priority), damage(damage), symbol(std::move(symbol)), world(world){}

int Entity::getDamage() const{
    return Entity::damage;
}

int Entity::getPriority() const {
    return Entity::priority;
}

Entity::Entity(const Entity &&other) {
    pos = other.pos;
    priority = other.priority;
    damage = other.damage;
    symbol = other.symbol;
    world = other.world;
    alive = other.alive;
}

void Entity::render() {
    if(isAlive()) {
        age++;
        View::setCursorPosition(pos.getX() + 2, pos.getY() + 6);
        std::cout << symbol;
    }


}

Entity::Entity() {

}

void Entity::attack(Entity &entity) {
    if(!entity.isAlive() || !this->isAlive())return;
    world->getLog().newLog(world->getTurn()) << *this << " attack " << entity << world->getLog().eol();
    if(entity.respondAttack(*this))return;
    if(damage > entity.getDamage()){
        world->getLog().newLog(world->getTurn()) << *this << " killed " << entity << world->getLog().eol();
        pos = entity.getPosition();
        world->removeEntity(&entity);
    } else {
        world->getLog().newLog(world->getTurn()) << entity << " killed " << *this << world->getLog().eol();
        world->removeEntity(this);
    }
}

const std::string &Entity::getSymbol() const{
    return symbol;
}

bool Entity::operator==(const Entity &rhs) const {
    return pos == rhs.pos &&
           priority == rhs.priority &&
           symbol == rhs.symbol &&
           damage == rhs.damage;
}

int Entity::getAge() const {
    return age;
}

bool Entity::operator>(const Entity &rhs) const {
    if(priority == rhs.getPriority())
        return age > rhs.getAge();
    return priority > rhs.getPriority();
}

bool Entity::isAlive() const {
    return alive
    ;
}

Pos Entity::getPrevPos() const {
    return prevPos;
}

void Entity::setDamage(int d) {
    this->damage = d;
}

Logger &operator<<(Logger &log, const Entity &e) {
    log << "Entity (x: "<< e.getPos().getX() << ", y: " << e.pos.getY() << "): "<< e.getSymbol();
    return log;
}

const Pos Entity::getPos() const {
    return pos;
}

void Entity::setAge(int a) {
    age = a;
}

void Entity::die() {
    alive = false;
}




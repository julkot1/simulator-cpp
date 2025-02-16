//
// Created by julian on 3/24/24.
//
#pragma once

#ifndef SIM_WORLD_H
#define SIM_WORLD_H
#include <queue>
#include "entity/Pos.h"
#include <vector>
#include <memory>
#include <algorithm>
#include <string>
#include <random>
#include "Logger.h"

namespace sim{
    enum Direction {
        UP, DOWN, LEFT, RIGHT
    };
}
class Sim;


class Entity {
protected:

    Pos pos;
    Pos prevPos;
    int priority{}, age{};
    std::string symbol;
    int damage;
    Sim *world{};
    bool alive{};
public:
    Entity(Pos position, int priority, int damage, std::string symbol, Sim *world);
    Entity();
    Entity(const Entity&& other);

    Pos getPosition();
    void updatePosition(int x, int y);
    void setDamage(int d);
    void setAge(int a);

    Pos getPrevPos() const;
    int getDamage() const;
    int getPriority() const;
    int getAge() const;
    bool isAlive() const;
    void die();


    virtual void action() = 0;
    virtual bool respondAttack(Entity &entity) = 0;
    void render();
    virtual void collision(Entity &entity) = 0;
    virtual void attack(Entity &entity);
    const std::string &getSymbol() const;
    bool operator ==(const Entity &rhs) const;
    bool operator >(const Entity &rhs) const;
    const Pos getPos() const;
    virtual ~Entity() = default;
    friend Logger& operator<<(Logger& log, const Entity& e);

};
class Human;
class Sim {
private:
    int size_W, size_H, turn;
    std::vector<Entity *> entities;
    std::mt19937 gen;
    Human *human;
    Logger log;
public:
    Sim(int size_W, int size_H);
    void addEntity(Entity *entity);
    void nextTurn();
    void render();

    int getSizeW() const ;
    int getSizeH() const;
    int getTurn() const;
    void setTurn(int i);

    void setHumanDirection(sim::Direction direction);
    Human *getHuman() const;
    void addHuman(Human &h);

    Pos translatePos(Pos pos, sim::Direction direction);
    Entity* getEntity(Pos pos);
    sim::Direction getDirection();
    std::vector<Entity*> getNeighbors(Pos pos);

    void getNeighbors(Pos pos, std::vector<Entity *> &neighbors);

    void removeEntity(Entity *entity);
    std::vector<Entity *> getEntities() const;
    void killHuman();

    Logger &getLog();

    std::mt19937 & getGen();
    ~Sim();
};


#endif //SIM_WORLD_H

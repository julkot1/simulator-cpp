//
// Created by julian on 4/18/24.
//

#include <fstream>
#include "SimFile.h"
#include "entity/animals/Turtle.h"
#include "entity/animals/Fox.h"
#include "entity/animals/Human.h"
#include "entity/plants/Grass.h"
#include "entity/animals/Sheep.h"
#include "entity/plants/Hogweed.h"
#include "entity/plants/Dandelion.h"
#include "entity/plants/Berry.h"
#include "entity/plants/Guarana.h"
#include "entity/animals/Wolf.h"
#include "entity/animals/Antelope.h"

void SimFile::save(Sim &world, const std::string& filename) {
    std::ofstream file;
    file.open(filename);
    file << world.getSizeW() << " " << world.getSizeH() << " " << world.getTurn() <<  std::endl;
    for(auto &e : world.getEntities()){
        file << e->getSymbol() << " " << e->getPos().getX() << " " << e->getPos().getY() << " " << e->getDamage() << " " << e->getAge();
        if(e->getSymbol() == Human::SYMBOL()){
            auto *human = dynamic_cast<Human*>(e);
            file << " "<< human->getDirection() << " " << human->getCoolDown() << " " << human->getUlt() << " " << human->getUltCount();

        }
        file << std::endl;
    }
    file.close();

}

Sim *SimFile::load(const std::string &filename) {
    std::ifstream file;
    file.open(filename);
    if(file.fail()){
        return nullptr;
    }
    int w, h, turn;
    file >> w >> h >> turn;
    Sim *world = new Sim(w,h);
    world->setTurn(turn);
    std::string symbol;
    int x, y, damage, age;
    while(file >> symbol >> x >> y >> damage >> age){
        Pos pos(x,y);
        if(symbol == Human::SYMBOL()){
            auto *en = new Human(pos, world);
            en->setDamage(damage);
            en->setAge(age);
            int dir, coolDown, ult, ultCount;
            file >> dir >> coolDown >> ult >> ultCount;
            en->setDirection(static_cast<sim::Direction>(dir));
            en->setCoolDown(coolDown);
            en->setUlt(ult);
            en->setUltCount(ultCount);
            world->addHuman(*en);
        }else if(symbol == Turtle::SYMBOL()){
            auto *en = new Turtle(pos, world);
            en->setDamage(damage);
            en->setAge(age);
            world->addEntity(en);
        }else if(symbol == Fox::SYMBOL()) {
            auto *en = new Fox(pos, world);
            en->setDamage(damage);
            en->setAge(age);
            world->addEntity(en);
        }else if(symbol == Wolf::SYMBOL()){
            auto *en = new Wolf(pos, world);
            en->setDamage(damage);
            en->setAge(age);
            world->addEntity(en);
        } else if(symbol == Grass::SYMBOL()){
            auto *en = new Grass(pos, world);
            en->setDamage(damage);
            en->setAge(age);
            world->addEntity(en);
        } else if(symbol == Sheep::SYMBOL()){
            auto *en = new Sheep(pos, world);
            en->setDamage(damage);
            en->setAge(age);
            world->addEntity(en);
        } else if(symbol == Hogweed::SYMBOL()){
            auto *en = new Hogweed(pos, world);
            en->setDamage(damage);
            en->setAge(age);
            world->addEntity(en);
        } else if(symbol == Dandelion::SYMBOL()){
            auto *en = new Dandelion(pos, world);
            en->setDamage(damage);
            en->setAge(age);
            world->addEntity(en);
        } else if(symbol == Berry::SYMBOL()){
            auto *en = new Berry(pos, world);
            en->setDamage(damage);
            en->setAge(age);
            world->addEntity(en);
        } else if(symbol == Guarana::SYMBOL()) {
            auto *en = new Guarana(pos, world);
            en->setDamage(damage);
            en->setAge(age);
            world->addEntity(en);
        } else if(symbol == Antelope::SYMBOL()){
            auto *en = new Antelope(pos, world);
            en->setDamage(damage);
            en->setAge(age);
            world->addEntity(en);
        }

    }
    return world;
}

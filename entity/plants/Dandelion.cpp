//
// Created by julian on 4/17/24.
//

#include "Dandelion.h"


Dandelion::Dandelion(Pos pos, Sim *world)  : Plant(pos, 0, Dandelion::SYMBOL(), world){}

void Dandelion::action() {
    Plant::action();
    Plant::action();
    Plant::action();
}

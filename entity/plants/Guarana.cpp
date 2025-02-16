//
// Created by julian on 4/17/24.
//

#include "Guarana.h"

Guarana::Guarana(Pos pos, Sim *world) : Plant(pos, 0, Guarana::SYMBOL(), world) {

}

bool Guarana::respondAttack(Entity &entity) {
    entity.setDamage(entity.getDamage() + STRENGTH_BOOST);
    return Plant::respondAttack(entity);
}

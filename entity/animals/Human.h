//
// Created by julian on 4/9/24.
//

#ifndef SIM_CPP_HUMAN_H
#define SIM_CPP_HUMAN_H


#include "Animal.h"

class Human : public Animal {
private:
    sim::Direction direction;
    bool isUlt;
    int ultCount;
    int ultCooldown;
    void useUlt();
public:
    Human(Pos pos, Sim *world);

    static std::string SYMBOL(){return "\033[0;94mH\033[0m";};


    void setDirection(sim::Direction direction);
    sim::Direction getDirection();
    void action() override;

    void setUlt(bool ult);
    bool getUlt() const;
    int getCoolDown() const;
    int getUltCount() const;
    ~Human() override;

    void setCoolDown(int i);

    void setUltCount(int i);
};


#endif //SIM_CPP_HUMAN_H

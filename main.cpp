#include "Sim.h"
#include "entity/animals/Animal.h"
#include "view/View.h"
#include "view/Menu.h"
#include "view/NewSim.h"
#include "view/SimView.h"
#include "SimFile.h"
#include "view/LoadView.h"
#include <iostream>
#include <queue>
#include <memory>

#include "entity/animals/Wolf.h"
#include "entity/animals/Sheep.h"
#include "entity/animals/Human.h"
#include "entity/animals/Fox.h"
#include "entity/animals/Turtle.h"
#include "entity/animals/Antelope.h"
#include "entity/plants/Grass.h"
#include "entity/plants/Guarana.h"
#include "entity/plants/Berry.h"
#include "entity/plants/Dandelion.h"
#include "entity/plants/Hogweed.h"

int main() {
    SimFile simFile;
    simFile.load("foo");
    Menu view;
    int res = view.loop();
    view.exit();
    if(res == 0)
    {
        NewSim newGame;
        newGame.loop();
        auto *w = new Sim(newGame.getSizeW(), newGame.getSizeH());
        w->addEntity( new Sheep(Pos(0, 2), w));
        w->addEntity( new Sheep(Pos(1, 2), w));
        w->addEntity( new Wolf(Pos(6, 4), w));
        w->addEntity( new Wolf(Pos(2, 3), w));
        w->addEntity( new Sheep(Pos(10, 4), w));
        w->addEntity( new Antelope(Pos(8, 4), w));
        w->addEntity( new Antelope(Pos(3, 6), w));
        w->addEntity( new Fox(Pos(5, 5), w));
        w->addEntity( new Fox(Pos(7, 5), w));
        w->addEntity( new Turtle(Pos(9, 5), w));
        w->addEntity( new Turtle(Pos(4, 7), w));
        w->addEntity( new Guarana(Pos(7, 12), w));
        w->addEntity( new Berry(Pos(9, 12), w));
        w->addEntity( new Dandelion(Pos(10, 12), w));
        w->addEntity( new Grass(Pos(0, 1), w));
        auto *h = new Human({newGame.getSizeW()/2, newGame.getSizeH()/2}, w);
        w->addHuman(*h);
        SimView simView(w);
        simView.loop();
        simView.exit();
        delete w;
    }
    else if(res == 1)
    {
        LoadView loadView;
        loadView.loop();
        auto *w = loadView.getSim();
        if(w != nullptr)
        {
            SimView simView(w);
            simView.loop();
            simView.exit();
            delete w;
        }
    }
    else
        std::cout << "Exiting game" << std::endl;

    return 0;
}
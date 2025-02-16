//
// Created by julian on 3/25/24.
//

#include "SimView.h"
#include "../entity/animals/Wolf.h"
#include "../entity/animals/Sheep.h"
#include "../entity/animals/Human.h"
#include "../entity/animals/Fox.h"
#include "../entity/animals/Turtle.h"
#include "../entity/animals/Antelope.h"
#include "../entity/plants/Grass.h"
#include "../entity/plants/Guarana.h"
#include "../entity/plants/Berry.h"
#include "../entity/plants/Dandelion.h"
#include "../entity/plants/Hogweed.h"
#include "../SimFile.h"


SimView::SimView(Sim *world) : View("Sim", world->getSizeW(), world->getSizeH()), world(world) , mode(Modes::SIM), isTextSel(true){
    if(w < 50 ) w = 50;
    if(h < 50 ) h = 50;



}

menu::GameActions SimView::getInput() {
    return View::getInput();
}

int SimView::loop() {

    render();
    render();
    while(1){
        if(keyPressed())
        {
            if(mode == Modes::SIM || mode == Modes::LOG)loopSim();
            else loopExit();
            render();

        }
    }
    return 0;
}
void SimView::loopSim(){
    menu::GameActions in;
    in = getInput();
    switch (in) {
        case menu::GameActions::ARROW_UP:
            world->setHumanDirection(sim::UP);
            break;
        case menu::GameActions::ARROW_DOWN:
            world->setHumanDirection(sim::DOWN);
            break;
        case menu::GameActions::ARROW_LEFT:
            world->setHumanDirection(sim::LEFT);
            break;
        case menu::GameActions::ARROW_RIGHT:
            world->setHumanDirection(sim::RIGHT);
            break;
        case menu::GameActions::ULT:
            if(world->getHuman()->getCoolDown() == 0)world->getHuman()->setUlt(true);
            break;
        case menu::GameActions::LOGS:
            mode = Modes::LOG;
            break;
        case menu::GameActions::SAVE_STATE:
            mode = Modes::EXIT;
            break;
    }
    if(in == menu::GameActions::SELECT){
        mode = Modes::SIM;
        world->nextTurn();
    }
}
void SimView::renderHumanMove() {
    if(world->getHuman() != nullptr){
        std::cout << BLUE << "Next human move: " << world->getHuman()->getDirection() << RESET << std::endl;
        if(world->getHuman()->getUlt()){
            std::cout << BLUE << "Ultimate is active" << RESET << std::endl;
            std::cout << BLUE << "Turns left: " << world->getHuman()->getUltCount() << RESET << std::endl;
        }
        else{
            std::cout << BLUE << "Ultimate is inactive" << RESET << std::endl;
            std::cout << BLUE << "Cooldown: " << world->getHuman()->getCoolDown() << RESET << std::endl;
        }

    }
    else{
        std::cout << "Human is dead" << std::endl;
    }
}

void SimView::render() {
    View::render();
    switch (mode) {
        case Modes::SIM:
            renderSim();
            break;
        case Modes::LOG:
            renderLog();
            break;
        case Modes::EXIT:
            renderExit();
            break;

    }
    for(int i = 0; i< w; i++)std::cout << GREEN << "-";
    std::cout << RESET;
    std::cout << std::endl;
}

void SimView::renderLog() {
    std::cout << "Type Enter to exit" << std::endl;
    world->getLog().printLogs(std::cout);
}

void SimView::renderSim() {
    world->render();
    View::setCursorPosition(0,8+world->getSizeH());
    std::cout<<std::endl;

    std::cout << BLUE << world->getTurn() << " turns" << RESET;
    std::cout<<std::endl;
    renderHumanMove();
    std::cout<<std::endl;
    world->getLog().printCurrentLog(std::cout);
}

void SimView::renderExit() {
    std::cout << "Type filename and press Enter to save state" << std::endl;
    std::cout << "filename: " << BLUB << filename << RESET << std::endl;
}

void SimView::loopExit() {
    int c = getchar();
    if(c >= 32 && c <= 126)
        filename += (char)c;
    else if(c == 127){
        if(!filename.empty())filename.pop_back();
    }
    else if(c == '\n'){
        mode = Modes::SIM;
        SimFile sf = {};
        sf.save(*world, filename);
    }

}

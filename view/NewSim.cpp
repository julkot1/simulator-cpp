//
// Created by julian on 3/25/24.
//

#include "NewSim.h"

NewSim::NewSim() : View("New Game", 50, 50), size_H(1), size_W(1), sel_size(0) {}

void NewSim::render() {
    View::render();
    std::cout << "Select the " << BLUE << ((sel_size == 0) ? "width" : "height") << RESET <<" of the world" << std::endl;
    std::cout << "Width: " << ((sel_size == 0) ? BLUB : YELLOW) << size_W << RESET << std::endl;
    std::cout << "Height: " << ((sel_size == 1) ? BLUB : YELLOW) << size_H << RESET << std::endl;
    std::cout << "Press ENTER to start the game" << std::endl;
    for(int i = 0; i< w; i++)std::cout << GREEN << "-";
    std::cout << RESET;
    std::cout << std::endl;
}

int NewSim::loop() {
    render();
    while (1) {
        if(keyPressed())
        {
            auto action = static_cast<menu::GameActions>(getInput());
            switch (action) {
                case menu::ARROW_RIGHT:
                    if (sel_size == 0)
                        size_W++;
                    else
                        size_H++;
                    break;
                case menu::ARROW_LEFT:
                    if (sel_size == 0){
                        if(size_W!=0)size_W--;
                    }
                    else
                    if(size_H!=0)size_H--;
                    break;
                case menu::ARROW_UP:
                    sel_size--;
                    if(sel_size<0)sel_size = 1;
                    sel_size%=2;
                    break;
                case menu::ARROW_DOWN:
                    sel_size++;
                    sel_size%=2;
                    break;
                case menu::SELECT:
                    return menu::PLAY;
            }
            render();
        }


    }
}

int NewSim::getSizeH() const {
    return size_H;
}
int NewSim::getSizeW() const {
    return size_W;
}

//
// Created by julian on 3/25/24.
//

#include "Menu.h"


void Menu::render() {
    View::render();
    std::cout << ((selected==0)?BLUB:"") <<"1. Start" << RESET <<  std::endl;
    std::cout <<  ((selected==1)?BLUB:"") << "2. Load" << RESET << std::endl;
    std::cout <<  ((selected==2)?BLUB:"") << "3. Exit" << RESET << std::endl;
    for(int i = 0; i< w; i++)std::cout << GREEN << "-";
    std::cout << RESET;
    std::cout << std::endl;
}
Menu::Menu() : View("Menu", 50, 50), selected(0) {

}


int Menu::loop() {
    render();
    while (1) {
        if (keyPressed()) {
            int action = getInput();
            if (action == menu::SELECT) {
                return getResponse();
            }
            if (action == menu::ARROW_UP)
            {
                selected--;
                if(selected<0)selected = 2;
                selected %= 3;
            }
            if (action == menu::ARROW_DOWN)
            {
                selected++;
                selected %= 3;
            }
            render();

        }


    }

}

int Menu::getResponse() {
    switch (selected) {
        case 0:
            return menu::PLAY;
        case 1:
            return menu::LOAD;
        case 2:
            return menu::EXIT;
    };
    return -1;
}

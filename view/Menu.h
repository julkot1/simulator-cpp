//
// Created by julian on 3/25/24.
//

#ifndef SIM_CPP_MENU_H
#define SIM_CPP_MENU_H


#include "View.h"


class Menu : public View {
private:
    int selected;

public:
    Menu();
    void render() override;
    int loop() override;

    int getResponse();
};


#endif //SIM_CPP_MENU_H

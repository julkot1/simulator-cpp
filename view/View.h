//
// Created by julian on 3/25/24.
//

#ifndef SIM_CPP_VIEW_H
#define SIM_CPP_VIEW_H
#include <string>
#include "Colors.h"
#include <termios.h>
#include <iostream>
#include <utility>
#include <cstdlib>
#include <unistd.h>
namespace menu {
    enum GameActions {
        PLAY,
        LOAD,
        ARROW_UP,
        ARROW_DOWN,
        ARROW_LEFT,
        ARROW_RIGHT,
        SELECT,
        ULT,
        LOGS,
        SAVE_STATE,
        EXIT
    };
}
class View {
protected:
    std::string name;
    std::string header;
    int w,h;
    struct termios term, old_term;
    int keyPressed();

public:
    View(std::string name, int w, int h);
    virtual void render();
    virtual menu::GameActions getInput();
    virtual int loop() = 0;
    virtual void exit();
    static void setCursorPosition(int x, int y);
    virtual ~View() = default;

};


#endif //SIM_CPP_VIEW_H

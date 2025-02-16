//
// Created by julian on 3/25/24.
//

#include "View.h"

void View::render() {
    system("clear");
    for(int i = 0; i< w; i++)std::cout << GREEN << "-";
    std::cout << RESET;
    std::cout << std::endl;
    std::cout << YELLOW <<  name;
    for(int i = name.length(); i< (w-header.length()); i++)std::cout << " ";
    std::cout << BLUE << header << std::endl;
    for(int i = 0; i< w; i++)std::cout << GREEN << "-";
    std::cout << RESET;
    std::cout << std::endl;
}

View::View(std::string name, int w, int h) : name(std::move(name)), header("Julian Kotłowski s197694"), w(w), h(h) {
    tcgetattr(STDIN_FILENO, &old_term);
    term = old_term;
    term.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
    std::cout << "\033[?25l";
}

void View::exit() {
    system("clear");
    tcsetattr(STDIN_FILENO, TCSANOW, &old_term);
    std::cout << "\033[?25h";
}
int View::keyPressed() {
    fd_set set;
    timeval timeout;
    FD_ZERO(&set);
    FD_SET(STDIN_FILENO, &set);
    timeout.tv_sec = 0;
    timeout.tv_usec = 0;
    return select(STDIN_FILENO + 1, &set, NULL, NULL, &timeout) == 1;
}

menu::GameActions View::getInput() {
        int c = getchar();
        if (c == '\033') {
            getchar();
            int arrow = getchar();
            switch (arrow) {
                case 'A':
                    return menu::ARROW_UP;
                    break;
                case 'B':
                    return menu::ARROW_DOWN;
                    break;
                case 'C':
                    return menu::ARROW_RIGHT;
                    break;
                case 'D':
                    return menu::ARROW_LEFT;
                    break;
            }
        } else if (c == '\n' || c == '\r')
            return menu::SELECT;
        else if (c == 'u')
            return menu::ULT;
        else if(c == 'l')
            return menu::LOGS;
        else if(c == 's')
            return menu::SAVE_STATE;
    return menu::EXIT;
}

void View::setCursorPosition(int x, int y) {
        std::cout << "\033[" << y << ";" << x << "H";
}

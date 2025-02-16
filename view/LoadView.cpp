//
// Created by julian on 4/23/24.
//

#include "LoadView.h"

LoadView::LoadView() : View("Load Game", 50, 50),sim(nullptr) {sf = {};}

void LoadView::render() {
    View::render();
    std::cout << "Type filename and press Enter to load simulation state" << std::endl;
    std::cout << "filename: " << BLUB << filename << RESET << std::endl;
    std::cout << std::endl;
    if(!error.empty())std::cout << RED << error << RESET << std::endl;
    else  std::cout << std::endl;
    std::cout << std::endl;
    for(int i = 0; i< w; i++)std::cout << GREEN << "-";
    std::cout << RESET;
    std::cout << std::endl;
}

int LoadView::loop() {
    render();
    while (1) {
        if(keyPressed()){
            int c = getchar();
            if(c >= 32 && c <= 126)
                filename += (char)c;
            else if(c == 127){
                if(!filename.empty())filename.pop_back();
            }
            else if(c == '\n'){
                sim = sf.load(filename);
                if(sim == nullptr)error = "Error loading file";
                else return menu::PLAY;
            }
            render();
        }
    }
}

Sim *LoadView::getSim() {
    return sim;
}

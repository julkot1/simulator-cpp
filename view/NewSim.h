//
// Created by julian on 3/25/24.
//

#ifndef SIM_CPP_NEWSIM_H
#define SIM_CPP_NEWSIM_H


#include "View.h"

class NewSim : public View {
private:
    int size_W, size_H;
    int sel_size;
public:
    NewSim();
    void render() override;
    int loop() override;
public:
    int getSizeW() const;
    int getSizeH() const;

};


#endif //SIM_CPP_NEWSIM_H

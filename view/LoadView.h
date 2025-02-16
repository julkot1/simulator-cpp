//
// Created by julian on 4/23/24.
//

#ifndef SIM_CPP_LOADVIEW_H
#define SIM_CPP_LOADVIEW_H


#include "View.h"
#include "../Sim.h"
#include "../SimFile.h"

class LoadView : public View {
private:
    Sim *sim;
    std::string filename;
    std::string error;
    SimFile sf;
public:
    LoadView();
    void render() override;
    int loop() override;
public:
    Sim *getSim();

};


#endif //SIM_CPP_LOADVIEW_H

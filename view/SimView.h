//
// Created by julian on 3/25/24.
//

#ifndef SIM_CPP_SIMVIEW_H
#define SIM_CPP_SIMVIEW_H


#include "View.h"
#include "../Sim.h"

namespace Modes {
    enum Mode {
        SIM, LOG, EXIT
    };
}
class SimView : public View {
private:
    Sim *world;
    std::string filename;
    Modes::Mode mode;
    bool isTextSel;
    void renderHumanMove();
    void renderLog();
    void renderSim();
    void renderExit();
    void loopSim();
    void loopExit();
public:
    SimView(Sim *world);
    menu::GameActions getInput() override;
    void render() override;
    int loop() override;

};


#endif //SIM_CPP_SIMVIEW_H

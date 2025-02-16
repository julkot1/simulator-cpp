//
// Created by julian on 4/18/24.
//

#ifndef SIM_CPP_SIMFILE_H
#define SIM_CPP_SIMFILE_H
#include "Sim.h"

class SimFile {
public:
    void save(Sim &world, const std::string& filename);
    Sim *load(const std::string& filename);
};


#endif //SIM_CPP_SIMFILE_H

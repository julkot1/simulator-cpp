cmake_minimum_required(VERSION 3.27)
project(sim_cpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(sim_cpp main.cpp Sim.cpp entity/animals/Animal.cpp
        view/View.cpp
        view/View.h
        view/Colors.cpp
        view/Colors.h
        view/Menu.cpp
        view/Menu.h
        view/NewSim.cpp
        view/NewSim.h
        view/View.cpp
        view/SimView.cpp
        view/SimView.h
        entity/Pos.cpp
        entity/Pos.h
        entity/animals/Wolf.cpp
        entity/animals/Wolf.h
        entity/animals/Sheep.cpp
        entity/animals/Sheep.h
        entity/animals/Human.cpp
        entity/animals/Human.h
        entity/animals/Fox.cpp
        entity/animals/Fox.h
        entity/animals/Turtle.cpp
        entity/animals/Turtle.h
        entity/animals/Antelope.cpp
        entity/animals/Antelope.h
        entity/plants/Plant.cpp
        entity/plants/Plant.h
        entity/plants/Grass.cpp
        entity/plants/Grass.h
        entity/plants/Dandelion.cpp
        entity/plants/Dandelion.h
        entity/plants/Guarana.cpp
        entity/plants/Guarana.h
        entity/plants/Berry.cpp
        entity/plants/Berry.h
        entity/plants/Hogweed.cpp
        entity/plants/Hogweed.h
        Logger.cpp
        Logger.h
        SimFile.cpp
        SimFile.h
        Sim.cpp
        view/LoadView.cpp
        view/LoadView.h
        Sim.cpp
        SimFile.cpp
)

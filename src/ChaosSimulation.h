
#ifndef CHAOSGAME_CHAOSSIMULATION_H
#define CHAOSGAME_CHAOSSIMULATION_H


#include <vector>
#include <random>
#include "ChaosVertex.h"

class ChaosSimulation {

private:
    std::vector<ChaosVertex>* vertices;
    int lastIndex = 3;
    void randomPointInTriangle(int& x, int& y);

public:
    ChaosSimulation(int tri_size);
    void init();
    void tick();
    std::vector<ChaosVertex>* getVertices();

    int getHeightAtX(int width);

    int tri_size;
};


#endif //CHAOSGAME_CHAOSSIMULATION_H

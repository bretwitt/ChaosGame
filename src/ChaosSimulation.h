
#ifndef CHAOSGAME_CHAOSSIMULATION_H
#define CHAOSGAME_CHAOSSIMULATION_H


#include <vector>
#include <random>
#include "ChaosVertex.h"

class ChaosSimulation {

private:
    std::vector<ChaosVertex>* vertices;
    int width;
    int height;
    int lastIndex = 3;
    void randomPointInTriangle(int width, int& x, int& y);
    std::mt19937 mt;
    std::uniform_real_distribution<double> dist;

public:
    ChaosSimulation(int width, int height);
    void init();
    void tick();
    std::vector<ChaosVertex>* getVertices();

};


#endif //CHAOSGAME_CHAOSSIMULATION_H

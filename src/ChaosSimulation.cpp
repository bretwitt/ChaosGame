#include <vector>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include "ChaosSimulation.h"
#include <raymath.h>

ChaosSimulation::ChaosSimulation(int tri_size) {
    this->tri_size = tri_size;
}

void ChaosSimulation::init() {
    srand (time(nullptr));
    int height = getHeightAtX(tri_size / 2);

    vertices = new std::vector<ChaosVertex>();
    vertices->push_back(ChaosVertex { tri_size / 2, 0});
    vertices->push_back(ChaosVertex { tri_size, height});
    vertices->push_back(ChaosVertex { 0, height});
    int rand_x = 0;
    int rand_y = 0;
    randomPointInTriangle(rand_x,rand_y);
    vertices->push_back(ChaosVertex { rand_x, rand_y});
}

int ChaosSimulation::getHeightAtX(int width) {
    return static_cast<int>(width * (sqrt(3)));
}

void ChaosSimulation::randomPointInTriangle(int& x, int& y) {
    int tri_height = getHeightAtX(x);
    x = rand() % tri_size;
    y = tri_size - (rand() % (((int)(abs(getHeightAtX(x - (tri_size/2))))) - tri_size));
}

void ChaosSimulation::tick() {
    int size = vertices->size();
    int randIndex = rand() % 3;
    int diffx = (vertices->at(randIndex).x - vertices->at(lastIndex).x) / 2 + vertices->at(lastIndex).x;
    int diffy = (vertices->at(randIndex).y - vertices->at(lastIndex).y) / 2 + vertices->at(lastIndex).y;
    vertices->push_back(ChaosVertex{ diffx, diffy});
    lastIndex = rand() % (size - 3) + 3;
}

std::vector<ChaosVertex>* ChaosSimulation::getVertices() {
    return vertices;
}

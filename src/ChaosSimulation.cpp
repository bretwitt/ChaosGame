#include <vector>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include "ChaosSimulation.h"
#include <raymath.h>

ChaosSimulation::ChaosSimulation(int width, int height) {
    this->width = width;
    this->height = height;
}

void ChaosSimulation::init() {
    srand (time(nullptr));

    vertices = new std::vector<ChaosVertex>();
    vertices->push_back(ChaosVertex { (width / 2), 0, 2});
    vertices->push_back(ChaosVertex { (width / 4), static_cast<int>(width * (sqrt(3)/4)), 2});
    vertices->push_back(ChaosVertex { width - (width / 4), static_cast<int>(width * (sqrt(3)/4)), 2});
    int rand_x = 0;
    int rand_y = 0;
    randomPointInTriangle(width, rand_x,rand_y);
    vertices->push_back(ChaosVertex { rand_x, rand_y, 2});
}

void ChaosSimulation::randomPointInTriangle(int width, int& x, int& y) {
    height = static_cast<int>(width * (sqrt(3)/4));
    x = (rand() % ( width - (width / 2) )) + (width / 4);
    y = height - (rand() % (-height + ((int)(abs(sqrt(3) * (x - (width/2)))))));
}

void ChaosSimulation::tick() {
    int size = vertices->size();
    int randIndex = rand() % 3;
    int diffx = (vertices->at(randIndex).x - vertices->at(lastIndex).x) / 2 + vertices->at(lastIndex).x;
    int diffy = (vertices->at(randIndex).y - vertices->at(lastIndex).y) / 2 + vertices->at(lastIndex).y;
    vertices->push_back(ChaosVertex{ diffx, diffy, 2});
    lastIndex = rand() % (size - 3) + 3;
}

std::vector<ChaosVertex>* ChaosSimulation::getVertices() {
    return vertices;
}

#include <iostream>
#include <raylib.h>
#include "ChaosSimulation.h"

int main() {
    const int screenWidth = 1080;
    const int screenHeight = 1080;

    auto* sim = new ChaosSimulation(screenWidth);
    sim->init();

    InitWindow(screenWidth, screenHeight, "Chaos Game");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {


        BeginDrawing();

        ClearBackground(RAYWHITE);

        sim->tick();

        for(auto vert : *(sim->getVertices())) {
            DrawCircle(vert.x, vert.y, 2, BLACK);
        }

        EndDrawing();
    }
    CloseWindow();

    delete(sim);

    return 0;

}

#include<iostream>

#include "raylib.h"
#include "Menu.hpp"

Vector2 screen = { 1920, 1080 };

int main() {
    InitWindow(screen.x, screen.y, "Custom Button");
    ToggleFullscreen();

    Font fontRomulus = LoadFont("../font/romulus.png");
    Menu menu;

    //biologyBody(screen);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);


        menu.drawMenu(fontRomulus);

        EndDrawing();
    }
    return 0;
}

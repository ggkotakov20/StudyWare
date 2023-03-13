#include "raylib.h"
#include "Menu.h"

Vector2 screen = { 1920, 1080 };

int main() {
    InitWindow(screen.x, screen.y, "Custom Button");
    ToggleFullscreen();

    Font fontRomulus = LoadFont("../font/romulus.png");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        menu(screen, fontRomulus);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

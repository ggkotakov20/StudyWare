#include "AppManage.hpp"

AppManage* AppManage::instant = nullptr;

AppManage::AppManage() {
    InitWindow(1920, 1080, "StudyWare");
    ToggleFullscreen();

    fontRomulus = LoadFont("../font/romulus.png");
}
AppManage::~AppManage() {
    UnloadFont(fontRomulus);
    CloseWindow();
}
AppManage* AppManage::getInstant() {
    if (instant == nullptr) instant = new AppManage();

    return instant;
}
void AppManage::appManage() {
    std::shared_ptr<AppStatus> manage = AppStatus::getInstant();

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        switch (manage->status)
        {
        case AppStatus::Status::Menu:
            menu = Menu::getInstant();
            menu->drawMenu(fontRomulus);
            break;
        case AppStatus::Status::Learning:
            break;
        case AppStatus::Status::Quit:
            exit(0);
            break;
        }

        EndDrawing();
    }
}
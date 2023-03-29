#include "AppManage.hpp"

AppManage* AppManage::instance = nullptr;

AppManage::AppManage() {
    InitWindow(1920, 1080, "StudyWare");

    fontRomulus = LoadFont("../font/romulus.png");
}
AppManage::~AppManage() {
    UnloadFont(fontRomulus);
    CloseWindow();
}
AppManage* AppManage::getInstance() {
    if (instance == nullptr) instance = new AppManage();

    return instance;
}
void AppManage::appManage() {
    std::shared_ptr<AppStatus> manage = AppStatus::getInstance();

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        switch (manage->status)
        {
        case AppStatus::Status::MENU:
            /*menu = Menu::getInstance();
            menu->drawMenu(fontRomulus);*/
            body = Body::getInstance();
            body->drawBody();
            break;
        case AppStatus::Status::LEARNING:
            body = Body::getInstance();
            body->drawBody();
            break;
        case AppStatus::Status::QUIT:
            exit(0);
            break;
        }

        EndDrawing();
    }
}
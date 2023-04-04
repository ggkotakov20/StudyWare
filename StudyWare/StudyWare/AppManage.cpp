#include "AppManage.hpp"

AppManage* AppManage::instance = nullptr;

AppManage::AppManage() {
    InitWindow(GetScreenWidth(), GetScreenHeight(), "StudyWare");
    ToggleFullscreen();
}
AppManage::~AppManage() {

    CloseWindow();
}
// Method to get the instance of AppManage
AppManage* AppManage::getInstance() {
    if (instance == nullptr) instance = new AppManage();

    return instance;
}
void AppManage::appManage() {
    std::shared_ptr<AppStatus> manage = AppStatus::getInstance();
    while (!WindowShouldClose()) {
        BeginDrawing();

        switch (manage->status)
        {
        case AppStatus::Status::MENU:
            ClearBackground(MENUBACKGROUND);
            // Get the instance of Menu and draw menu
            menu = Menu::getInstance();
            menu->drawMenu();
            break;
        case AppStatus::Status::LEARNING:
            ClearBackground(BACKGROUND);
            // Get the instance of Body and draw body
            body = Body::getInstance();
            body->drawBody();
            break;
        case AppStatus::Status::QUIT:
            // Exit the application
            exit(0);
            break;
        }

        EndDrawing();
    }
}
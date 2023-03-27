#include "Menu.hpp"
std::shared_ptr<Menu> Menu::instant = nullptr;

Menu::Menu() {

	sWidth = GetScreenWidth();
	sHeight = GetScreenHeight();

	mousePosition = GetMousePosition();

	fontSize = sHeight / 11;


	// Set Learning button position
	gameMenu[0].width = 580;
	gameMenu[0].height = 100; 
	gameMenu[0].x = sWidth / 2 - gameMenu[0].width / 2;
	gameMenu[0].y = sHeight / 2 - gameMenu[0].height - gameMenu[0].height * 0.5 - 5;
	
	// Set Quit button position
	gameMenu[1].width = 200;
	gameMenu[1].height = 100;
	gameMenu[1].x = sWidth / 2 - gameMenu[1].width / 2;
	gameMenu[1].y = sHeight / 2 - (gameMenu[1].height / 2);

}
Menu::~Menu() {
	delete[] gameMenu;
}
std::shared_ptr<Menu> Menu::getInstant() {

	if (instant == nullptr) instant = std::shared_ptr<Menu>(new Menu);

	return instant;
}
void Menu::drawMenu(Font font) {
	auto manage = AppStatus::getInstant();

	for (int i = 0; i < gameMenuOptions; i++) {
		gameMenuPos = { gameMenu[i].x, gameMenu[i].y };
		switch (i)
		{
		case 0:
			DrawRectangleRec(gameMenu[i], RAYWHITE);
			DrawTextEx(font, "Start learn", gameMenuPos, fontSize, 5, BLACK);
			if (CheckCollisionPointRec(GetMousePosition(), gameMenu[i]) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				manage->status = AppStatus::Status::Learning;
			break;
		case 1:
			DrawRectangleRec(gameMenu[i], RAYWHITE);
			DrawTextEx(font, "Quit", gameMenuPos, fontSize, 5, BLACK);
			if (CheckCollisionPointRec(GetMousePosition(), gameMenu[i]) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
				manage->status = AppStatus::Status::Quit;
			}
			break;
		}
	}
}
#include "Menu.hpp"
std::shared_ptr<Menu> Menu::instance = nullptr;

Menu::Menu() {

	sWidth = GetScreenWidth();
	sHeight = GetScreenHeight();

	mousePosition = GetMousePosition();

	fontSize = sHeight / 11;


	// Set Learning button position
	gameMenu[0].width = sWidth / 3 ;
	gameMenu[0].height = 100; 
	gameMenu[0].x = sWidth / 2 - gameMenu[0].width / 2;
	gameMenu[0].y = sHeight / 2 - gameMenu[0].height - gameMenu[0].height * 0.5 - 5;
	
	// Set Quit button position
	gameMenu[1].width = sWidth / 7;
	gameMenu[1].height = 100;
	gameMenu[1].x = sWidth / 2 - gameMenu[1].width / 2;
	gameMenu[1].y = sHeight / 2 - (gameMenu[1].height / 2);

}
Menu::~Menu() {
	delete[] gameMenu;
}
std::shared_ptr<Menu> Menu::getInstance() {

	if (instance == nullptr) instance = std::shared_ptr<Menu>(new Menu);

	return instance;
}
void Menu::drawMenu() {
	auto manage = AppStatus::getInstance();

	DrawText("StudyWare", sWidth / 3.25, sHeight / 8, sHeight/ 8, MAROON);

	for (int i = 0; i < gameMenuOptions; i++) {
		float textWidth = 0;
		switch (i)
		{
		case 0:
			textWidth = MeasureText("Start learn", fontSize);
			gameMenuPos = { gameMenu[i].x + (gameMenu[i].width - textWidth -fontSize/4), gameMenu[i].y };

			DrawRectangleRec(gameMenu[i], MENUBUTTONS);
			DrawText("Start learn", gameMenuPos.x, gameMenuPos.y, fontSize, BLACK);

			if (CheckCollisionPointRec(GetMousePosition(), gameMenu[i])) {
				// Draw border
				DrawRectangleLinesEx(gameMenu[i], 1, BLACK);
				if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
					manage->status = AppStatus::Status::LEARNING;
			}
			break;
		case 1:
			textWidth = MeasureText("Quit", fontSize);
			gameMenuPos = { gameMenu[i].x + (gameMenu[i].width - textWidth - fontSize / 2), gameMenu[i].y };
			DrawRectangleRec(gameMenu[i], MENUBUTTONS);
			DrawText("Quit", gameMenuPos.x, gameMenuPos.y, fontSize, BLACK);
			if (CheckCollisionPointRec(GetMousePosition(), gameMenu[i])) {
				// Draw border
				DrawRectangleLinesEx(gameMenu[i], 1, BLACK);
				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
					manage->status = AppStatus::Status::QUIT;
			}
			break;
		}
	}
}
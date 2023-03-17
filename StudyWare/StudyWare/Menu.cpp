#include <iostream>
#include "raylib.h"

#include "Menu.h"
#include "TestMode.h"

enum Status {
	Menu,
	Learning,
	Test,
	Rules,
	Quit
};

Status gameStatus = Menu;
int gameMenuOptions = 3;
Rectangle* gameMenu = new Rectangle[gameMenuOptions];


float appNameSize = 150;
int count = 240;

void backBtn(Font font) {
	Rectangle backBtn;
	backBtn.width = 125;
	backBtn.height = 45;
	backBtn.x = 10;
	backBtn.y = 0;
	Vector2 backBtnPos = { backBtn.x, backBtn.y };

	DrawRectangleRec(backBtn, RAYWHITE);
	DrawTextEx(font, "Back", backBtnPos, 50, 5, BLACK);
	if (CheckCollisionPointRec(GetMousePosition(), backBtn) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		if (gameStatus == Test) gameStatus = Learning;
		else gameStatus = Menu;
	}

}

void testBtn(Vector2 screen, Font font) {
	Rectangle testText;
	testText.width = 400;
	testText.height = 40;
	testText.x = screen.x - testText.width;
	testText.y = screen.y - testText.height - 10;
	Vector2 testTextPos = { testText.x, testText.y };

	DrawRectangleRec(testText, RAYWHITE);
	DrawTextEx(font, "Test your self", testTextPos, 50, 5, BLACK);
	if (CheckCollisionPointRec(GetMousePosition(), testText) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		gameStatus = Test;
	}
}

void menu(Vector2 screen, Font font) {

	Vector2 gameMenuPos;
	Vector2 appNamePos = { screen.x / 3.3, screen.y / 6 - 40 };

	if (gameStatus == Menu) {
		DrawTextEx(font, "StudyWare", appNamePos, appNameSize, 5, MAROON);

		for (size_t i = 0; i < gameMenuOptions; i++) {
			gameMenuPos = { gameMenu[i].x, gameMenu[i].y };
			switch (i) {
			case 0:
				gameMenu[i].width = 580;
				gameMenu[i].height = 100;
				gameMenu[i].x = screen.x / 2 - gameMenu[i].width / 2;
				gameMenu[i].y = screen.y / 2 - gameMenu[i].height - gameMenu[i].height * 0.5 - 5;

				DrawRectangleRec(gameMenu[i], RAYWHITE);
				if (CheckCollisionPointRec(GetMousePosition(), gameMenu[i]) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
					gameStatus = Learning;
				}
				DrawTextEx(font, "Start learn", gameMenuPos, 100, 5, BLACK);

				break;

			case 1:
				gameMenu[i].width = 270;
				gameMenu[i].height = 100;
				gameMenu[i].x = screen.x / 2 - gameMenu[i].width / 2;
				gameMenu[i].y = screen.y / 2 - (gameMenu[i].height / 2);

				if (CheckCollisionPointRec(GetMousePosition(), gameMenu[i]) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
					gameStatus = Rules;
				}

				DrawRectangleRec(gameMenu[i], RAYWHITE);
				DrawTextEx(font, "Rules", gameMenuPos, 100, 5, BLACK);
				break;

			case 2:
				gameMenu[i].width = 200;
				gameMenu[i].height = 100;
				gameMenu[i].x = screen.x / 2 - gameMenu[i].width / 2;
				gameMenu[i].y = screen.y / 2 + gameMenu[i].height - gameMenu[i].height * 0.5 + 5;

				if (CheckCollisionPointRec(GetMousePosition(), gameMenu[i]) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
					gameStatus = Quit;
				}

				DrawRectangleRec(gameMenu[i], RAYWHITE);
				DrawTextEx(font, "Quit", gameMenuPos, 100, 5, BLACK);
				break;
			}

		}


	}
	else if (gameStatus == Learning) {
		backBtn(font);
		testBtn(screen,font);
	}
	else if (gameStatus == Test) {
		questions(screen, font);
	}
	else if (gameStatus == Rules) {
		backBtn(font);
	}
	else if (gameStatus == Quit) exit(0);

}
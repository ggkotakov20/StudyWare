#pragma once
#include "AppStatus.hpp"

class Menu {
private:
	static std::shared_ptr<Menu> instance;

	int gameMenuOptions = 2;
	int fontSize;

	Rectangle* gameMenu = new Rectangle[gameMenuOptions];

	Vector2 gameMenuPos;
	Vector2 mousePosition;
public:
	float sWidth;
	float sHeight;

	Menu();
	~Menu();

	void drawMenu();

	static std::shared_ptr<Menu> getInstance();
};
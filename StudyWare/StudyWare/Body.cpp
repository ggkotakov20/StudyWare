#include "Body.hpp"

std::shared_ptr<Body> Body::instance = nullptr;

Body::Body() {
	sWidth = GetScreenWidth();
	sHeight = GetScreenHeight();

	mousePosition = GetMousePosition();

	bodyOrgans = LoadTexture("../Images/bodies/organs.png");
	bodyNerves = LoadTexture("../Images/bodies/nerves.png");
	bodySkeleton = LoadTexture("../Images/bodies/skeleton.png");

	bodySize = 2.5;
	bodyOrgans.width /= bodySize;
	bodyOrgans.height /= bodySize;

	bodyNerves.width /= bodySize;
	bodyNerves.height /= bodySize;

	bodySkeleton.width /= bodySize;
	bodySkeleton.height /= bodySize;

	bodyCurrent = bodyOrgans;
}
Body::~Body() {
	UnloadTexture(bodyCurrent);
	UnloadTexture(bodyOrgans);
	UnloadTexture(bodyNerves);
	UnloadTexture(bodySkeleton);
}
std::shared_ptr<Body> Body::getInstance() {
	if (instance == nullptr)
		instance = std::shared_ptr<Body>(new Body);
	return instance;
}
void Body::switchBodyBtn() {
	switchBody.bounds = { (float)sWidth / 2 + 100, (float)sHeight / 2 + (float)bodyCurrent.height / 2 - 100, 160, 50 };
    switchBody.rounding = 1;
    switchBody.hovering = CheckCollisionPointRec(GetMousePosition(), switchBody.bounds);
    switchBody.text = "Switch body";
    switchBody.color = GRAY;

	if (switchBody.hovering) switchBody.color = DARKGRAY;
	DrawRectangleRounded(switchBody.bounds, switchBody.rounding, switchBody.rounding, switchBody.color);
	DrawText(switchBody.text, switchBody.bounds.x + switchBody.bounds.width / 2 - MeasureText(switchBody.text, 20) / 2, switchBody.bounds.y + 15, 20, BLACK);
	
	if (CheckCollisionPointRec(GetMousePosition(), switchBody.bounds) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
		if (typeBody == Type::ORGANS) {
			std::cout << 1 << std::endl;
			typeBody = Type::NERVES;
			bodyCurrent = bodyNerves;
		}
		else if (typeBody == Type::NERVES) {
			std::cout << 2 << std::endl;
			typeBody = Type::SKELETON;
			bodyCurrent = bodySkeleton;
		}
		else if (typeBody == Type::SKELETON) {
			std::cout << 3 << std::endl;
			typeBody = Type::ORGANS;
			bodyCurrent = bodyOrgans;
		}
	}
}
void Body::drawBody() {
	
	Rectangle bodyRec = { 0,0, bodyCurrent.width, bodyCurrent.height };
	Vector2 bodyCenter = { bodyCurrent.width / 2, bodyCurrent.height / 2 };
	Vector2 bodyPos = { sWidth / 2, sHeight / 2 };
	
	DrawTexturePro(bodyCurrent,
	    bodyRec,
	    Rectangle{ bodyPos.x, bodyPos.y, bodyRec.width, bodyRec.height },
	    bodyCenter,
	    0,
	    WHITE);

	switchBodyBtn();
}
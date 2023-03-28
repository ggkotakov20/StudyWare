#include "Body.hpp"

std::shared_ptr<Body> Body::instance = nullptr;

Body::Body() {
	sWidth = GetScreenWidth();
	sHeight = GetScreenHeight();

	mousePosition = GetMousePosition();

	//bodyOrgans = LoadTexture("../Images/bodies/organs.png");
	//bodyNerves = LoadTexture("../Images/bodies/nerves.png");
	//bodySkeleton = LoadTexture("../Images/bodies/skeleton.png");
	bodyCurrent = LoadTexture("../Images/bodies/skeleton.png");
	brain = LoadTexture("../Images/organs/brain.png");

	bodySize = 2.5;
	organSize = 2.5;
	//bodyOrgans.width /= bodySize;
	//bodyOrgans.height /= bodySize;

	//bodyNerves.width /= bodySize;
	//bodyNerves.height /= bodySize;

	//bodySkeleton.width /= bodySize;
	//bodySkeleton.height /= bodySize;

	bodyCurrent.width /= bodySize;
	bodyCurrent.height /= bodySize;
	brain.width /= organSize;
	brain.height /= organSize;

	bodyPos = { sWidth / 2 - bodyCurrent.width / 2, sHeight / 2 - bodyCurrent.height / 2 };
	brainPos = { sWidth / 2 - brain.width / 2 - 1, sHeight / 2 - brain.height / 2  - bodyCurrent.height / 2 + 35};
	brainRec.x = sWidth / 2 - brain.width + 140;
	brainRec.y = sHeight / 2 - brain.height / 2 - bodyCurrent.height / 3 - 40;
	brainRec.width = 77;
	brainRec.height = 55;

	brainIsActive = false;
}
Body::~Body() {
	UnloadTexture(bodyCurrent);
	UnloadTexture(brain);
	//UnloadTexture(bodyOrgans);
	//UnloadTexture(bodyNerves);
	//UnloadTexture(bodySkeleton);
}
std::shared_ptr<Body> Body::getInstance() {
	if (instance == nullptr)
		instance = std::shared_ptr<Body>(new Body);
	return instance;
}
//void Body::switchBodyBtn() {
//	switchBody.bounds = { (float)sWidth / 2 + 100, (float)sHeight / 2 + (float)bodyCurrent.height / 2 - 100, 160, 50 };
//    switchBody.rounding = 1;
//    switchBody.hovering = CheckCollisionPointRec(GetMousePosition(), switchBody.bounds);
//    switchBody.text = "Switch body";
//    switchBody.color = GRAY;
//
//	if (switchBody.hovering) switchBody.color = DARKGRAY;
//	DrawRectangleRounded(switchBody.bounds, switchBody.rounding, switchBody.rounding, switchBody.color);
//	DrawText(switchBody.text, switchBody.bounds.x + switchBody.bounds.width / 2 - MeasureText(switchBody.text, 20) / 2, switchBody.bounds.y + 15, 20, BLACK);
//	
//	if (CheckCollisionPointRec(GetMousePosition(), switchBody.bounds) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
//		if (typeBody == Type::ORGANS) {
//			std::cout << 1 << std::endl;
//			typeBody = Type::NERVES;
//			bodyCurrent = bodyNerves;
//		}
//		else if (typeBody == Type::NERVES) {
//			std::cout << 2 << std::endl;
//			typeBody = Type::SKELETON;
//			bodyCurrent = bodySkeleton;
//		}
//		else if (typeBody == Type::SKELETON) {
//			std::cout << 3 << std::endl;
//			typeBody = Type::ORGANS;
//			bodyCurrent = bodyOrgans;
//		}
//	}
//}

void Body::drawBrain() {
	DrawRectangleRec(brainRec, BLANK);
	DrawTexture(brain, brainPos.x, brainPos.y, GREEN);
	if (CheckCollisionPointRec(GetMousePosition(), brainRec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		brainIsActive = true;
	}

	if (brainIsActive) {
		DrawText("asd", 0, 0, 10, BLACK);
	}
}
void Body::drawBody() {
	DrawTexture(bodyCurrent,bodyPos.x,bodyPos.y,WHITE);

	switch (currentOrgan)
	{
	case Body::CurrentOrgan::NONE:
		break;
	case Body::CurrentOrgan::BRAIN:
		drawBrain();
		break;
	default:
		break;
	}
}
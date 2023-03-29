#include "Body.hpp"

std::shared_ptr<Body> Body::instance = nullptr;

Body::Body() {
	sWidth = GetScreenWidth();
	sHeight = GetScreenHeight();

	fontSize = sHeight / 50;

	mousePosition = GetMousePosition();

	font = LoadFont("../font/romulus.png");

	body = LoadTexture("../Images/bodies/skeleton.png");
	brain = LoadTexture("../Images/organs/brain.png");

	bodySize = 2.5;
	organSize = 2.5;

	body.width /= bodySize;
	body.height /= bodySize;
	brain.width /= organSize;
	brain.height /= organSize;

	bodyPos = { sWidth / 2 - body.width / 2, sHeight / 2 - body.height / 2 };
	brainPos = { sWidth / 2 - brain.width / 2 - 1, sHeight / 2 - brain.height / 2  - body.height / 2 + 35};
	infoPos = { 75, sHeight / 2 - body.height / 3 };

	brainRec.x = sWidth / 2 - brain.width + 140;
	brainRec.y = sHeight / 2 - brain.height / 2 - body.height / 3 - 40;
	brainRec.width = 77;
	brainRec.height = 55;

	brainIsActive = true;

	brainInfo = "BRAIN\nThe brain is the most complex and vital organ in the human body,\nresponsible for controllingand coordinating all bodily functions,\nthoughts, emotions, and sensations.It is composed of more than\n100 billion neurons and trillions of synapses, which form complex\nnetworks that allow us to think, feel, and move.\nCommon brain diseases include:\nAlzheimer's disease, Parkinson's disease, multiple sclerosis, epilepsy,\nmigraines, and traumatic brain injury. Alzheimer's disease is a\nprogressive neurodegenerative disease that affects memory, thinking,\nand behavior, while Parkinson's disease is a degenerative disorder\nthat affects movement, balance, and coordination.Multiple sclerosis\nis an autoimmune disease that affects the central nervous system,\nwhile epilepsy is a neurological disorder that causes seizures.\nMigraines are a type of headache that can be debilitatingand\nrecurring, while traumatic brain injury can result from a blow\nor jolt to the head, leading to cognitive, emotional, and physical impairment.";
}
Body::~Body() {
	UnloadTexture(body);
	UnloadTexture(brain);
	UnloadFont(font);
}
std::shared_ptr<Body> Body::getInstance() {
	if (instance == nullptr)
		instance = std::shared_ptr<Body>(new Body);
	return instance;
}
//void Body::switchBodyBtn() {
//	switchBody.bounds = { (float)sWidth / 2 + 100, (float)sHeight / 2 + (float)body.height / 2 - 100, 160, 50 };
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
//			body = bodyNerves;
//		}
//		else if (typeBody == Type::NERVES) {
//			std::cout << 2 << std::endl;
//			typeBody = Type::SKELETON;
//			body = bodySkeleton;
//		}
//		else if (typeBody == Type::SKELETON) {
//			std::cout << 3 << std::endl;
//			typeBody = Type::ORGANS;
//			body = bodyOrgans;
//		}
//	}
//}

void Body::drawBrain() {

	DrawRectangleRec(brainRec, BLANK);
	DrawTexture(brain, brainPos.x, brainPos.y, WHITE);

	if (brainIsActive) {
        //DrawText(brainInfo, 0, 0, fontSize, BLACK);
		DrawTextEx(font, brainInfo, infoPos,fontSize, 0,BLACK);
		if (CheckCollisionPointRec(GetMousePosition(), brainRec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			brainIsActive = false;
		}
	}
	else {
		if (CheckCollisionPointRec(GetMousePosition(), brainRec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) brainIsActive = true;
	}
}
void Body::drawBody() {
	DrawTexture(body,bodyPos.x,bodyPos.y,WHITE);

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
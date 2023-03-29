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
	lungs = LoadTexture("../Images/organs/lungs.png");

	bodySize = 2.5;
	organSize = 2.5;

	body.width /= bodySize;
	body.height /= bodySize;
	brain.width /= organSize;
	brain.height /= organSize;
	lungs.width /= organSize;
	lungs.height /= organSize;

	bodyPos = { sWidth / 2 - body.width / 2, sHeight / 2 - body.height / 2 };
	brainPos = { sWidth / 2 - brain.width / 2 - 1, sHeight / 2 - brain.height / 2  - body.height / 2 + 35};
	lungsPos = { sWidth / 2 - lungs.width / 2 - 1, sHeight / 2 - lungs.height / 2 - body.height / 3 + 35};
	infoPos = { 75, sHeight / 2 - body.height / 3 };

	brainRec.x = sWidth / 2 - brain.width + 140;
	brainRec.y = sHeight / 2 - brain.height / 2 - body.height / 3 - 40;
	brainRec.width = 77;
	brainRec.height = 55;
	lungsRec.x = sWidth / 2 - lungs.width + 100;
	lungsRec.y = sHeight / 2 - lungs.height / 2 - body.height / 4 - 30;
	lungsRec.width = 155;
	lungsRec.height = 250;

	brainIsActive = false;
	lungsIsActive = false;

	// With custome font
	//brainInfo = "BRAIN\nThe brain is the most complex and vital organ in the human body,\nresponsible for controllingand coordinating all bodily functions,\nthoughts, emotions, and sensations.It is composed of more than\n100 billion neurons and trillions of synapses, which form complex\nnetworks that allow us to think, feel, and move.\nCommon brain diseases include:\nAlzheimer's disease, Parkinson's disease, multiple sclerosis, epilepsy,\nmigraines, and traumatic brain injury. Alzheimer's disease is a\nprogressive neurodegenerative disease that affects memory, thinking,\nand behavior, while Parkinson's disease is a degenerative disorder\nthat affects movement, balance, and coordination. Multiple sclerosis\nis an autoimmune disease that affects the central nervous system,\nwhile epilepsy is a neurological disorder that causes seizures.\nMigraines are a type of headache that can be debilitatingand\nrecurring, while traumatic brain injury can result from a blow\nor jolt to the head, leading to cognitive, emotional, and physical impairment.";

	brainInfo = "B R A I N\nThe brain is the most complex and vital organ in the human body,\nresponsible for controllingand coordinating all bodily functions,\nthoughts, emotions, and sensations. It is composed of more than\n100 billion neurons and trillions of synapses, which form complex\nnetworks that allow us to think, feel, and move.\nCommon brain diseases include:\nAlzheimer's disease, Parkinson's disease, multiple sclerosis,\nepilepsy, migraines, and traumatic brain injury. Alzheimer's disease\nis a progressive neurodegenerative disease that affects memory,\nthinking, and behavior, while Parkinson's disease is a degenerative\ndisorder that affects movement, balance, and coordination.\nMultiple sclerosis is an autoimmune disease that affects\nthe central nervous system, while epilepsy is a neurological\ndisorder that causes seizures. Migraines are a type of headache that\ncan be debilitatingand recurring, while traumatic brin injury can result\nfrom a blow or jolt to the head, leading to cognitive, emotional,\nand physical impairment.";

	lungsInfo = "L U N G S\nThe lungs are essential organs that help us breathe by taking in\noxygen and getting rid of carbon dioxide.Here are some common lung\ndiseases : \n1. Asthma : A chronic condition that causes inflammation and narrowing\nof the airways, making it difficult to breathe.\n2. Chronic obstructive pulmonary disease(COPD) : A group of lung\ndiseases that make it hard to breathe due to damage to the airways\nand /or air Sacs in the lungs.\n3. Pneumonia : An infection that inflames the air sacs in one\nor both lungs.\n4. Tuberculosis(TB) : A bacterial infection that primarily affects\nthe lungs but can also affect other parts of the body\n5. Lung cancer : A condition where cells in the lungs grow\nabnormally and form tumors.";
}
Body::~Body() {
	UnloadTexture(body);
	UnloadTexture(brain);
	UnloadTexture(lungs);
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
		//DrawTextEx(font, brainInfo, infoPos,fontSize, 0,BLACK);
		DrawText(brainInfo, infoPos.x, infoPos.y, fontSize, BLACK);
		if (CheckCollisionPointRec(GetMousePosition(), brainRec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			brainIsActive = false;
			lungsIsActive = false;
		}
	}
	else {
		if (CheckCollisionPointRec(GetMousePosition(), brainRec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			brainIsActive = true;
			lungsIsActive = false;
		}
	}
}
void Body::drawLungs() {
	DrawRectangleRec(lungsRec, BLANK);
	DrawTexture(lungs, lungsPos.x, lungsPos.y, WHITE);

	if (lungsIsActive) {
		DrawText(lungsInfo, infoPos.x, infoPos.y, fontSize, BLACK);
		if (CheckCollisionPointRec(GetMousePosition(), lungsRec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			brainIsActive = false;
			lungsIsActive = false;
		}
	}
	else {
		if (CheckCollisionPointRec(GetMousePosition(), lungsRec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			brainIsActive = false;
			lungsIsActive = true;
		}
	}
}
void Body::drawBody() {
	DrawTexture(body,bodyPos.x,bodyPos.y,WHITE);
	drawBrain();
	drawLungs();
}
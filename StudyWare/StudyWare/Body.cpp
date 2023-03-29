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
	liver = LoadTexture("../Images/organs/liver.png");
	heart = LoadTexture("../Images/organs/heart.png");
	kidney = LoadTexture("../Images/organs/kidney.png");

	bodySize = 2.5;
	organSize = 2.5;

	body.width /= bodySize;
	body.height /= bodySize;
	brain.width /= organSize;
	brain.height /= organSize;
	lungs.width /= organSize;
	lungs.height /= organSize;
	liver.width /= organSize;
	liver.height /= organSize;
	heart.width /= organSize;
	heart.height /= organSize;
	kidney.width /= organSize;
	kidney.height /= organSize;

	bodyPos = { sWidth / 2 - body.width / 2, sHeight / 2 - body.height / 2 };
	brainPos = { sWidth / 2 - brain.width / 2 - 1, sHeight / 2 - brain.height / 2  - body.height / 2 + 35};
	lungsPos = { sWidth / 2 - lungs.width / 2 - 1, sHeight / 2 - lungs.height / 2 - body.height / 3 + 35};
	liverPos = { sWidth / 2 - lungs.width / 2 - 25, sHeight / 2 - lungs.height / 2 - body.height / 5 + 70 };
	heartPos = { sWidth / 2 - lungs.width / 2 + 7, sHeight / 2 - lungs.height / 2 - body.height / 5 + 7};
	kidneyPos = { sWidth / 2 - lungs.width / 4 + 7, sHeight / 2 - lungs.height / 2 - body.height / 7 + 20};
	infoPos = { 75, sHeight / 2 - body.height / 3 };

	brainRec.x = sWidth / 2 - brain.width + 140;
	brainRec.y = sHeight / 2 - brain.height / 2 - body.height / 3 - 40;
	brainRec.width = 77;
	brainRec.height = 55;
	lungsRec.x = sWidth / 2 - lungs.width + 100;
	lungsRec.y = sHeight / 2 - lungs.height / 2 - body.height / 4 - 30;
	lungsRec.width = 155;
	lungsRec.height = 250;
	liverRec.x = sWidth / 2 - liver.width + 110;
	liverRec.y = sHeight / 2 - liver.height / 2 - body.height / 6 + 75;
	liverRec.width = 105;
	liverRec.height = 75;
	heartRec.x = sWidth / 2 - heart.width / 2 + 75;
	heartRec.y = sHeight / 2 - heart.height / 2 - body.height / 6 + 17;
	heartRec.width = 50;
	heartRec.height = 62;
	kidneyRec.x = sWidth / 2 - kidney.width / 4 + 75;
	kidneyRec.y = sHeight / 2 - kidney.height / 2 - body.height / 9 + 25;
	kidneyRec.width = 40;
	kidneyRec.height = 60;

	brainIsActive = false;
	lungsIsActive = false;
	liverIsActive = false;
	heartIsActive = false;
	kidneyIsActive = true;

	// With custome font
	//brainInfo = "BRAIN\nThe brain is the most complex and vital organ in the human body,\nresponsible for controllingand coordinating all bodily functions,\nthoughts, emotions, and sensations.It is composed of more than\n100 billion neurons and trillions of synapses, which form complex\nnetworks that allow us to think, feel, and move.\nCommon brain diseases include:\nAlzheimer's disease, Parkinson's disease, multiple sclerosis, epilepsy,\nmigraines, and traumatic brain injury. Alzheimer's disease is a\nprogressive neurodegenerative disease that affects memory, thinking,\nand behavior, while Parkinson's disease is a degenerative disorder\nthat affects movement, balance, and coordination. Multiple sclerosis\nis an autoimmune disease that affects the central nervous system,\nwhile epilepsy is a neurological disorder that causes seizures.\nMigraines are a type of headache that can be debilitatingand\nrecurring, while traumatic brain injury can result from a blow\nor jolt to the head, leading to cognitive, emotional, and physical impairment.";

	brainInfo = "B R A I N\nThe brain is the most complex and vital organ in the human body,\nresponsible for controllingand coordinating all bodily functions,\nthoughts, emotions, and sensations. It is composed of more than\n100 billion neurons and trillions of synapses, which form complex\nnetworks that allow us to think, feel, and move.\nCommon brain diseases include:\nAlzheimer's disease, Parkinson's disease, multiple sclerosis,\nepilepsy, migraines, and traumatic brain injury. Alzheimer's disease\nis a progressive neurodegenerative disease that affects memory,\nthinking, and behavior, while Parkinson's disease is a degenerative\ndisorder that affects movement, balance, and coordination.\nMultiple sclerosis is an autoimmune disease that affects\nthe central nervous system, while epilepsy is a neurological\ndisorder that causes seizures. Migraines are a type of headache that\ncan be debilitatingand recurring, while traumatic brin injury can result\nfrom a blow or jolt to the head, leading to cognitive, emotional,\nand physical impairment.";

	lungsInfo = "L U N G S\nThe lungs are essential organs that help us breathe by taking in\noxygen and getting rid of carbon dioxide.Here are some common lung\ndiseases : \n1. Asthma : A chronic condition that causes inflammation and narrowing\nof the airways, making it difficult to breathe.\n2. Chronic obstructive pulmonary disease(COPD) : A group of lung\ndiseases that make it hard to breathe due to damage to the airways\nand /or air Sacs in the lungs.\n3. Pneumonia : An infection that inflames the air sacs in one\nor both lungs.\n4. Tuberculosis(TB) : A bacterial infection that primarily affects\nthe lungs but can also affect other parts of the body\n5. Lung cancer : A condition where cells in the lungs grow\nabnormally and form tumors.";

	liverInfo = "L I V E R\nThe liver is the largest internal organ and has many important\nfunctions, including filtering blood, producing bile, storing vitaminsand\nminerals, and breaking down toxins.Here are some common liver\ndiseases :\n1.Hepatitis : Inflammation of the liver caused by a viral infection or\nexposure to toxins.\n2.Cirrhosis : A progressive disease that occurs when liver cells are\ndamaged and replaced by scar tissue, leading to loss of liver\nfunction.\n3.Nonalcoholic fatty liver disease(NAFLD) : A condition where fat\nbuilds up in the liver, often seen in people with obesity, diabetes\nor high cholesterol levels.";

	heartInfo = "H E A R T\nThe heart is a vital organ that pumps blood throughout the body,\nsupplying the organs and tissues with oxygen and nutrients.\nHere are some common heart diseases:\n1. Coronary artery disease : A condition where the arteries that\nsupply blood to the heart become narrowed or blocked.\n2. Arrhythmia : A heart rhythm problem that can cause the heart to\nbeat too fast, too slow, or irregularly.\n3. Heart failure : A condition where the heart cannot pump enough\nblood to meet the body's needs.\n4. Atherosclerosis : A condition where plaque builds up inside the\narteries, causing them to hardenand narrow.\n5. Heart valve disease : A condition where one or more of the\nheart valves do not function properly.";

	kidneyInfo = "K I D N E Y\nThe kidneys are a pair of bean-shaped organs located on either\nside of the spine in the back of the abdominal cavity.They play a\ncrucial role in the body's urinary system and help filter waste\nproducts and excess fluids from the blood. The primary function\nof the kidneys is to produce urine, which is then transported to the\nbladder and eliminated from the body through the urethra. Chronic\nkidney disease is a condition in which the kidneys gradually lose\nfunction over time, usually over the course of months or years.\nIt can lead to a variety of complications, including high blood\npressure, anemia, and nerve damage. Kidney stones are hard,\nmineral deposits that form inside the kidneysand can cause\nintense painand discomfort when they pass through the urinary\ntract.The most common cause of kidney stones is dehydration,\nwhich can cause mineralsand salts to crystallize and form stones.\nUrinary tract infections(UTIs) are caused by bacteria that enter the\nurinary tractand can lead to symptoms such as painful urination, frequent\nurination, and lower abdominal pain. Headache is not typically a symptom of a\nUTI. Several factors can increase the risk of chronic kidney disease,\nincluding high blood pressure, diabetes, smoking, obesity, and a family\nhistory of kidney disease. The most common type of kidney stone is calcium\noxalate, which forms when there is too much calciumand oxalate in the urine.\nThe main treatment for kidney failure is dialysis, which is a process that\nfilters waste productsand excess fluids from the blood when the kidneys\ncan no longer perform this function.";
}
Body::~Body() {
	UnloadTexture(body);
	UnloadTexture(brain);
	UnloadTexture(lungs);
	UnloadTexture(liver);
	UnloadTexture(heart);
	UnloadTexture(kidney);
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
	if(lungsIsActive || liverIsActive || heartIsActive || kidneyIsActive && !brainIsActive)
		DrawTexture(brain, brainPos.x, brainPos.y, BLACK);
	else
		DrawTexture(brain, brainPos.x, brainPos.y, WHITE);

	if (brainIsActive) {
        //DrawText(brainInfo, 0, 0, fontSize, BLACK);
		//DrawTextEx(font, brainInfo, infoPos,fontSize, 0,BLACK);
		DrawText(brainInfo, infoPos.x, infoPos.y, fontSize, BLACK);
		if (CheckCollisionPointRec(GetMousePosition(), brainRec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			brainIsActive = false;
			lungsIsActive = false;
			liverIsActive = false;
			heartIsActive = false;
			kidneyIsActive = false;
		}
	}
	else {
		if (CheckCollisionPointRec(GetMousePosition(), brainRec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			brainIsActive = true;
			lungsIsActive = false;
			liverIsActive = false;
			heartIsActive = false;
			kidneyIsActive = false;
		}
	}
}
void Body::drawLungs() {
	DrawRectangleRec(lungsRec, BLANK);
	if(brainIsActive || liverIsActive || heartIsActive || kidneyIsActive && !lungsIsActive)
		DrawTexture(lungs, lungsPos.x, lungsPos.y, BLACK);
	else
		DrawTexture(lungs, lungsPos.x, lungsPos.y, WHITE);

	if (lungsIsActive) {
		DrawText(lungsInfo, infoPos.x, infoPos.y, fontSize, BLACK);
		if (CheckCollisionPointRec(GetMousePosition(), lungsRec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			brainIsActive = false;
			lungsIsActive = false;
			liverIsActive = false;
			heartIsActive = false;
			kidneyIsActive = false;
		}
	}
	else {
		if (CheckCollisionPointRec(GetMousePosition(), lungsRec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			brainIsActive = false;
			lungsIsActive = true;
			liverIsActive = false;
			heartIsActive = false;
			kidneyIsActive = false;
		}
	}
}
void Body::drawLiver() {
	DrawRectangleRec(liverRec, BLANK);
	if (brainIsActive || lungsIsActive || heartIsActive || kidneyIsActive && !liverIsActive)
		DrawTexture(liver, liverPos.x, liverPos.y, BLACK);
	else
		DrawTexture(liver, liverPos.x, liverPos.y, WHITE);

	if (liverIsActive) {
		DrawText(liverInfo, infoPos.x, infoPos.y, fontSize, BLACK);
		if (CheckCollisionPointRec(GetMousePosition(), liverRec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			brainIsActive = false;
			lungsIsActive = false;
			liverIsActive = false;
			heartIsActive = false;
			kidneyIsActive = false;
		}
	}
	else {
		if (CheckCollisionPointRec(GetMousePosition(), liverRec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			brainIsActive = false;
			lungsIsActive = false;
			liverIsActive = true;
			heartIsActive = false;
			kidneyIsActive = false;
		}
	}
}
void Body::drawHeart() {
	DrawRectangleRec(heartRec, BLANK);
	if (brainIsActive || lungsIsActive || liverIsActive || kidneyIsActive && !heartIsActive)
		DrawTexture(heart, heartPos.x, heartPos.y, BLACK);
	else
		DrawTexture(heart, heartPos.x, heartPos.y, WHITE);

	if (heartIsActive) {
		DrawText(heartInfo, infoPos.x, infoPos.y, fontSize, BLACK);
		if (CheckCollisionPointRec(GetMousePosition(), heartRec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			brainIsActive = false;
			lungsIsActive = false;
			liverIsActive = false;
			heartIsActive = false;
			kidneyIsActive = false;
		}
	}
	else {
		if (CheckCollisionPointRec(GetMousePosition(), heartRec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			brainIsActive = false;
			lungsIsActive = false;
			liverIsActive = false;
			heartIsActive = true;
			kidneyIsActive = false;
		}
	}

}
void Body::drawKidney() {
	DrawRectangleRec(kidneyRec, BLANK);
	if (brainIsActive || lungsIsActive || liverIsActive || heartIsActive && !kidneyIsActive)
		DrawTexture(kidney, kidneyPos.x, kidneyPos.y, BLACK);
	else
		DrawTexture(kidney, kidneyPos.x, kidneyPos.y, WHITE);

	if (kidneyIsActive) {
		DrawText(kidneyInfo, infoPos.x, infoPos.y, fontSize, BLACK);
		if (CheckCollisionPointRec(GetMousePosition(), kidneyRec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			brainIsActive = false;
			lungsIsActive = false;
			liverIsActive = false;
			heartIsActive = false;
			kidneyIsActive = false;
		}
	}
	else {
		if (CheckCollisionPointRec(GetMousePosition(), kidneyRec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			brainIsActive = false;
			lungsIsActive = false;
			liverIsActive = false;
			heartIsActive = false;
			kidneyIsActive = true;
		}
	}
}
void Body::drawBody() {
	DrawTexture(body,bodyPos.x,bodyPos.y,WHITE);
	if (brainIsActive) {
		drawLungs();
		drawLiver();
		drawHeart();
		drawKidney();
		drawBrain();
	}
	else if (lungsIsActive) {
		drawBrain();
		drawLiver();
		drawHeart();
		drawKidney();
		drawLungs();
	}
	else if (liverIsActive) {
		drawBrain();
		drawLungs();
		drawHeart();
		drawKidney();
		drawLiver();
	}
	else if (heartIsActive) {
		drawBrain();
		drawLungs();
		drawLiver();
		drawKidney();
		drawHeart();
	}
	else if (kidneyIsActive) {
		drawBrain();
		drawLungs();
		drawLiver();
		drawHeart();
		drawKidney();
	}
	else {
		drawBrain();
		drawLungs();
		drawLiver();
		drawHeart();
		drawKidney();
	}
	
}
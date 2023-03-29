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
	stomach = LoadTexture("../Images/organs/stomach.png");
	intestines = LoadTexture("../Images/organs/intestines.png");
	reproductiveSM = LoadTexture("../Images/organs/reproductive_system-male.png");
	nerves = LoadTexture("../Images/organs/nerves.png");
	muscle = LoadTexture("../Images/organs/muscle.png");

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
	stomach.width /= organSize;
	stomach.height /= organSize;
	intestines.width /= organSize;
	intestines.height /= organSize;
	reproductiveSM.width /= organSize;
	reproductiveSM.height /= organSize;
	nerves.width /= organSize;
	nerves.height /= organSize;
	muscle.width /= organSize;
	muscle.height /= organSize;

	bodyPos = { sWidth / 2 - body.width / 2, sHeight / 2 - body.height / 2 };
	brainPos = { sWidth / 2 - brain.width / 2 - 1, sHeight / 2 - brain.height / 2  - body.height / 2 + 35};
	lungsPos = { sWidth / 2 - lungs.width / 2 - 1, sHeight / 2 - lungs.height / 2 - body.height / 3 + 35};
	liverPos = { sWidth / 2 - lungs.width / 2 - 25, sHeight / 2 - lungs.height / 2 - body.height / 5 + 70 };
	heartPos = { sWidth / 2 - lungs.width / 2 + 7, sHeight / 2 - lungs.height / 2 - body.height / 5 + 7};
	kidneyPos = { sWidth / 2 - lungs.width / 4 + 7, sHeight / 2 - lungs.height / 2 - body.height / 7 + 20};
	stomachPos = { sWidth / 2 - stomach.width / 2 + 5, sHeight / 2 - stomach.height / 2 - body.height / 7 - 20};
	intestinesPos = { sWidth / 2 - intestines.width / 2 , sHeight / 2 - intestines.height / 2 - body.height / 23 - 20};
	reproductiveSMPos = { sWidth / 2 - reproductiveSM.width / 2  - 1, sHeight / 2 - reproductiveSM.height / 2 - body.height / 23  - 2};
	nervesPos = { sWidth / 2 - nerves.width / 2 + body.width / 4 + 15,sHeight / 2 - nerves.height / 2  - body.height / 8 + 25};
	musclePos = { sWidth / 2 - muscle.width / 2 + body.width / 4 ,sHeight / 2 - muscle.height / 2  - body.height / 4 + 15};
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
	stomachRec.x = sWidth / 2 - stomach.width / 5 + 17;
	stomachRec.y = sHeight / 2 - stomachRec.height / 2 - body.height / 5 + 15;
	stomachRec.width = 70;
	stomachRec.height = 67;
	intestinesRec.x = sWidth / 2 - intestines.width / 2 + 22;
	intestinesRec.y = sHeight / 2 - intestines.height / 2 - body.height / 23 + 27;
	intestinesRec.width = 130;
	intestinesRec.height = 120;
	reproductiveSMRec.x = sWidth / 2 - reproductiveSM.width / 2 + 22;
	reproductiveSMRec.y = sHeight / 2 - reproductiveSM.height / 2 - body.height / 23 + 5;
	reproductiveSMRec.width = 130;
	reproductiveSMRec.height = 120;
	nervesRec.x = sWidth / 2 - nerves.width / 2 + body.width / 3 + 45;
	nervesRec.y = sHeight / 2 - nerves.height / 2 - body.height / 14 + 25;
	nervesRec.width = 50;
	nervesRec.height = 110;
	muscleRec.x = sWidth / 2 - nerves.width / 2 + body.width / 3 + 30;
	muscleRec.y = sHeight / 2 - nerves.height / 2 - body.height / 5 + 10;
	muscleRec.width = 50;
	muscleRec.height = 150;

	brainIsActive = false;
	lungsIsActive = false;
	liverIsActive = false;
	heartIsActive = false;
	kidneyIsActive = false;
	stomachIsActive = false;
	intestinesIsActive = false;
	reproductiveSMIsActive = false;
	nervesIsActive = false;
	muscleIsActive = true;

	brainInfo = "B R A I N\nThe brain is the most complex and vital organ in the human body,\nresponsible for controllingand coordinating all bodily functions,\nthoughts, emotions, and sensations. It is composed of more than\n100 billion neurons and trillions of synapses, which form complex\nnetworks that allow us to think, feel, and move.\nCommon brain diseases include:\nAlzheimer's disease, Parkinson's disease, multiple sclerosis,\nepilepsy, migraines, and traumatic brain injury. Alzheimer's disease\nis a progressive neurodegenerative disease that affects memory,\nthinking, and behavior, while Parkinson's disease is a degenerative\ndisorder that affects movement, balance, and coordination.\nMultiple sclerosis is an autoimmune disease that affects\nthe central nervous system, while epilepsy is a neurological\ndisorder that causes seizures. Migraines are a type of headache that\ncan be debilitatingand recurring, while traumatic brin injury can result\nfrom a blow or jolt to the head, leading to cognitive, emotional,\nand physical impairment.";

	lungsInfo = "L U N G S\nThe lungs are essential organs that help us breathe by taking in\noxygen and getting rid of carbon dioxide.Here are some common lung\ndiseases : \n1. Asthma : A chronic condition that causes inflammation and narrowing\nof the airways, making it difficult to breathe.\n2. Chronic obstructive pulmonary disease(COPD) : A group of lung\ndiseases that make it hard to breathe due to damage to the airways\nand /or air Sacs in the lungs.\n3. Pneumonia : An infection that inflames the air sacs in one\nor both lungs.\n4. Tuberculosis(TB) : A bacterial infection that primarily affects\nthe lungs but can also affect other parts of the body\n5. Lung cancer : A condition where cells in the lungs grow\nabnormally and form tumors.";

	liverInfo = "L I V E R\nThe liver is the largest internal organ and has many important\nfunctions, including filtering blood, producing bile, storing vitaminsand\nminerals, and breaking down toxins.Here are some common liver\ndiseases :\n1.Hepatitis : Inflammation of the liver caused by a viral infection or\nexposure to toxins.\n2.Cirrhosis : A progressive disease that occurs when liver cells are\ndamaged and replaced by scar tissue, leading to loss of liver\nfunction.\n3.Nonalcoholic fatty liver disease(NAFLD) : A condition where fat\nbuilds up in the liver, often seen in people with obesity, diabetes\nor high cholesterol levels.";

	heartInfo = "H E A R T\nThe heart is a vital organ that pumps blood throughout the body,\nsupplying the organs and tissues with oxygen and nutrients.\nHere are some common heart diseases:\n1. Coronary artery disease : A condition where the arteries that\nsupply blood to the heart become narrowed or blocked.\n2. Arrhythmia : A heart rhythm problem that can cause the heart to\nbeat too fast, too slow, or irregularly.\n3. Heart failure : A condition where the heart cannot pump enough\nblood to meet the body's needs.\n4. Atherosclerosis : A condition where plaque builds up inside the\narteries, causing them to hardenand narrow.\n5. Heart valve disease : A condition where one or more of the\nheart valves do not function properly.";

	kidneyInfo = "K I D N E Y\nThe kidneys are a pair of bean-shaped organs located on either\nside of the spine in the back of the abdominal cavity.They play a\ncrucial role in the body's urinary system and help filter waste\nproducts and excess fluids from the blood. The primary function\nof the kidneys is to produce urine, which is then transported to the\nbladder and eliminated from the body through the urethra. Chronic\nkidney disease is a condition in which the kidneys gradually lose\nfunction over time, usually over the course of months or years.\nIt can lead to a variety of complications, including high blood\npressure, anemia, and nerve damage. Kidney stones are hard,\nmineral deposits that form inside the kidneysand can cause\nintense painand discomfort when they pass through the urinary\ntract.The most common cause of kidney stones is dehydration,\nwhich can cause mineralsand salts to crystallize and form stones.\nUrinary tract infections(UTIs) are caused by bacteria that enter the\nurinary tractand can lead to symptoms such as painful urination, frequent\nurination, and lower abdominal pain. Headache is not typically a symptom of a\nUTI. Several factors can increase the risk of chronic kidney disease,\nincluding high blood pressure, diabetes, smoking, obesity, and a family\nhistory of kidney disease. The most common type of kidney stone is calcium\noxalate, which forms when there is too much calciumand oxalate in the urine.\nThe main treatment for kidney failure is dialysis, which is a process that\nfilters waste productsand excess fluids from the blood when the kidneys\ncan no longer perform this function.";

	stomachInfo = "S T O M A C H\nThe stomach is a muscular sac located in the upper left abdomen,\nbetween the esophagus and the small intestine. It plays a crucial role\nin the digestive system by breaking down food into smaller particles\nand mixing it with gastric acid and enzymes. Common stomach diseases\ninclude gastroesophageal reflux disease(GERD), peptic ulcers,\ngastritis, and stomach cancer.GERD is a chronic condition in which\nthe stomach acid flows back into the esophagus, causing\nheartburnand damage to the esophageal lining. Peptic ulcers are\nopen sores that form in the lining of the stomach or small\nintestine, often caused by a bacterial infection or the long\n- term use of certain medications. Gastritis is an inflammation of\nthe stomach lining, which can be caused by infections, alcohol,\nstress, or the use of certain medications.Stomach cancer is\na type of cancer that begins in the cells lining the stomach and can\nspread to other parts of the body. Other common digestive issues\nthat can affect the stomach include irritable bowel syndrome(IBS), celiac\ndisease and food intolerances or allergies.IBS is a chronic condition that\naffects the large intestine and can cause abdominal pain, bloating\nand changes in bowel movements.Celiac disease is an autoimmune disorder\nin which the body reacts to gluten, a protein found in wheat, causing\ndamage to the small intestine.Food intolerances or allergies can cause\na range of digestive symptoms, including stomach pain, bloating, diarrhea\nor constipation.";

	intestinesInfo = "I N T E S T I O N E S\nThe human intestine, also known as the bowel, is part of the digestive\nsystem responsible for absorbing nutrients from food and eliminating\nwaste from the body. The small intestine is the longest part of the\ndigestive tract, where most nutrient absorption occurs.\nThe large intestine, or colon, absorbs water and electrolytes from\nundigested food and stores waste until elimination.\nCommon diseases of the intestines include inflammatory bowel\ndisease(IBD), irritable bowel syndrome(IBS), diverticulitis\nand colon cancer. IBD is a chronic inflammation of the digestive\ntract that includes Crohn's disease and ulcerative colitis.\nIBS is a functional disorder that causes abdominal pain, bloating\nand changes in bowel habits. Diverticulitis is the inflammation\nor infection of small pouches in the lining of the colon, while\ncolon cancer is the growth of cancerous cells in the colon or rectum.";

	reproductiveSMInfo = "R E P R O D U C T I V E  S Y S T E M  M A L E\nThe male reproductive system consists of organs that are involved\nin the production, storage, and transportation of sperm.\nThese organs include the testes, epididymis, vas deferens,\nseminal vesicles, prostate gland, and urethra. The testes produce\nsperm and testosterone,while the epididymis stores and transports\nsperm to the vas deferens, which carries sperm from the epididymis\nto the urethra. The seminal vesicles and prostate gland produce\nseminal fluid, which nourishes and transports sperm during\nejaculation. Common diseases that can affect the male reproductive\nsystem include prostate cancer, testicular cancer, erectile\ndysfunction, and infertility.Prostate cancer is a cancer that\naffects the prostate glandand can cause problems with\nurinationand sexual function.Testicular cancer is a cancer that\naffects the testiclesand can cause pain, swelling and lumps\nin the scrotum.Erectile dysfunction is a condition where a man is unable\nto achieve or maintain an erection sufficient for sexual activity.\nInfertility is a condition where a man is unable to father a child due\nto problems with sperm production or transportation.";

	nervesInfo = "N E R V E S\nThe PNS can be further divided into the somatic nervous system and\nthe autonomic nervous system. The somatic nervous system is\nresponsible for voluntary movements and is involved in sensory\nperception, while the autonomic nervous system controls involuntary\nfunctions like heart rate, breathing, and digestion.The human body\ncontains millions of individual nerve cells called neurons,\nwhich transmit electrical signals throughout the body.\nNeurons are composed of a cell body, dendrites, and an axon.\nThe dendrites receive signals from other neurons, while the axon\nsends signals to other neurons or to muscles and glands.\nDamage to nerves can result in a variety of conditions, such as\nneuropathies, which are characterized by pain, numbness \nor weakness in the affected area. Examples of neuropathies\ninclude carpal tunnel syndrome, diabetic neuropathy\nand peripheral neuropathy.";

	muscleInfo = "M U S C L E\nHuman muscles are the collection of tissues in the body responsible\nfor movement, maintaining posture, and generating heat.\nThere are three main types of muscles in the human body:\nskeletal, smooth, and cardiac muscles. Skeletal muscles are attached\nto the bones and are responsible for voluntary movement.\nThey are striated muscles and are under conscious control.\nSmooth muscles are found in the walls of internal organs such as\nthe stomach, intestines, and blood vessels, and they are\nresponsible for involuntary movements such as peristalsis.\nCardiac muscles are found only in the heart and are responsible\nfor pumping blood throughout the body. \nCommon muscle diseases include: muscular dystrophy,\nmyasthenia gravis, fibromyalgia, and polymyositis.\nMuscular dystrophy is a group of genetic disorders that cause\nprogressive muscle weakness and loss of muscle mass.\nMyasthenia gravis is a neuromuscular disorder that causes muscle\nweakness and fatigue, particularly in the eyes, face, throat, andlimbs.\nFibromyalgia is a chronic pain disorder that affects muscles, tendons\nand ligaments, causing widespread pain, fatigue and sleep disturbances.\nPolymyositis is an autoimmune disease that causes inflammation and\nweakness in the muscles, particularly in the hips, thighs, shoulders, and neck.";
}
Body::~Body() {
	UnloadTexture(body);
	UnloadTexture(brain);
	UnloadTexture(lungs);
	UnloadTexture(liver);
	UnloadTexture(heart);
	UnloadTexture(kidney);
	UnloadTexture(stomach);
	UnloadTexture(intestines);
	UnloadTexture(reproductiveSM);
	UnloadTexture(nerves);
	UnloadTexture(muscle);
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
void Body::cancelBtn(float posX, float posY) {
	cancel.bounds = { posX, posY, 125, 40};
	cancel.rounding = 1;
	cancel.hovering = CheckCollisionPointRec(GetMousePosition(), cancel.bounds);
	cancel.text = "Cancel";
	cancel.color = GRAY;

	if (cancel.hovering) cancel.color = DARKGRAY;
	DrawRectangleRounded(cancel.bounds, cancel.rounding, cancel.rounding, cancel.color);
	DrawText(cancel.text, cancel.bounds.x + cancel.bounds.width / 2 - MeasureText(cancel.text, 20) / 2, cancel.bounds.y + 11, 20, BLACK);
	if (cancel.hovering && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		brainIsActive = false;
		lungsIsActive = false;
		liverIsActive = false;
		heartIsActive = false;
		kidneyIsActive = false;
		stomachIsActive = false;
		intestinesIsActive = false;
		reproductiveSMIsActive = false;
		nervesIsActive = false;
		muscleIsActive = false;
	}
}

void Body::drawBrain() {

	DrawRectangleRec(brainRec, BLANK);
	if(lungsIsActive || liverIsActive || heartIsActive || kidneyIsActive || stomachIsActive || intestinesIsActive || reproductiveSMIsActive || nervesIsActive || muscleIsActive && !brainIsActive)
		DrawTexture(brain, brainPos.x, brainPos.y, GRAY);
	else
		DrawTexture(brain, brainPos.x, brainPos.y, WHITE);

	if (brainIsActive) {
        DrawText(brainInfo, infoPos.x, infoPos.y, fontSize, BLACK);
		cancelBtn(sWidth / 2 - body.width + 75, sHeight / 2 + body.height / 4 - 60);
		if (CheckCollisionPointRec(GetMousePosition(), brainRec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			brainIsActive = false;
			lungsIsActive = false;
			liverIsActive = false;
			heartIsActive = false;
			kidneyIsActive = false;
			stomachIsActive = false;
			intestinesIsActive = false;
			reproductiveSMIsActive = false;
			nervesIsActive = false;
			muscleIsActive = false;
		}
	}
	else {
		if (CheckCollisionPointRec(GetMousePosition(), brainRec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			brainIsActive = true;
			lungsIsActive = false;
			liverIsActive = false;
			heartIsActive = false;
			kidneyIsActive = false;
			stomachIsActive = false;
			intestinesIsActive = false;
			reproductiveSMIsActive = false;
			nervesIsActive = false;
			muscleIsActive = false;
		}
	}
}
void Body::drawLungs() {
	DrawRectangleRec(lungsRec, BLANK);
	if(brainIsActive || liverIsActive || heartIsActive || kidneyIsActive || stomachIsActive || intestinesIsActive || reproductiveSMIsActive || nervesIsActive || muscleIsActive && !lungsIsActive)
		DrawTexture(lungs, lungsPos.x, lungsPos.y, GRAY);
	else
		DrawTexture(lungs, lungsPos.x, lungsPos.y, WHITE);

	if (lungsIsActive) {
		DrawText(lungsInfo, infoPos.x, infoPos.y, fontSize, BLACK);
		cancelBtn(sWidth / 2 - body.width + 75, sHeight / 2 + body.height / 5 - 100);
		if (CheckCollisionPointRec(GetMousePosition(), lungsRec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			brainIsActive = false;
			lungsIsActive = false;
			liverIsActive = false;
			heartIsActive = false;
			kidneyIsActive = false;
			stomachIsActive = false;
			intestinesIsActive = false;
			reproductiveSMIsActive = false;
			nervesIsActive = false;
			muscleIsActive = false;
		}
	}
	else {
		if (CheckCollisionPointRec(GetMousePosition(), lungsRec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			brainIsActive = false;
			lungsIsActive = true;
			liverIsActive = false;
			heartIsActive = false;
			kidneyIsActive = false;
			stomachIsActive = false;
			intestinesIsActive = false;
			reproductiveSMIsActive = false;
			nervesIsActive = false;
			muscleIsActive = false;
		}
	}
}
void Body::drawLiver() {
	DrawRectangleRec(liverRec, BLANK);
	if (brainIsActive || lungsIsActive || heartIsActive || kidneyIsActive || stomachIsActive || intestinesIsActive || reproductiveSMIsActive || nervesIsActive || muscleIsActive && !liverIsActive)
		DrawTexture(liver, liverPos.x, liverPos.y, GRAY);
	else
		DrawTexture(liver, liverPos.x, liverPos.y, WHITE);

	if (liverIsActive) {
		DrawText(liverInfo, infoPos.x, infoPos.y, fontSize, BLACK);
		cancelBtn(sWidth / 2 - body.width + 75, sHeight / 2 + body.height / 7 - 100);
		if (CheckCollisionPointRec(GetMousePosition(), liverRec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			brainIsActive = false;
			lungsIsActive = false;
			liverIsActive = false;
			heartIsActive = false;
			kidneyIsActive = false;
			stomachIsActive = false;
			intestinesIsActive = false;
			reproductiveSMIsActive = false;
			nervesIsActive = false;
			muscleIsActive = false;
		}
	}
	else {
		if (CheckCollisionPointRec(GetMousePosition(), liverRec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			brainIsActive = false;
			lungsIsActive = false;
			liverIsActive = true;
			heartIsActive = false;
			kidneyIsActive = false;
			stomachIsActive = false;
			intestinesIsActive = false;
			reproductiveSMIsActive = false;
			nervesIsActive = false;
			muscleIsActive = false;
		}
	}
}
void Body::drawHeart() {
	DrawRectangleRec(heartRec, BLANK);
	if (brainIsActive || lungsIsActive || liverIsActive || kidneyIsActive || stomachIsActive  || intestinesIsActive || reproductiveSMIsActive || nervesIsActive || muscleIsActive && !heartIsActive)
		DrawTexture(heart, heartPos.x, heartPos.y, GRAY);
	else
		DrawTexture(heart, heartPos.x, heartPos.y, WHITE);

	if (heartIsActive) {
		DrawText(heartInfo, infoPos.x, infoPos.y, fontSize, BLACK);
		cancelBtn(sWidth / 2 - body.width + 75, sHeight / 2 + body.height / 6 - 100);
		if (CheckCollisionPointRec(GetMousePosition(), heartRec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			brainIsActive = false;
			lungsIsActive = false;
			liverIsActive = false;
			heartIsActive = false;
			kidneyIsActive = false;
			stomachIsActive = false;
			intestinesIsActive = false;
			reproductiveSMIsActive = false;
			nervesIsActive = false;
			muscleIsActive = false;
		}
	}
	else {
		if (CheckCollisionPointRec(GetMousePosition(), heartRec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			brainIsActive = false;
			lungsIsActive = false;
			liverIsActive = false;
			heartIsActive = true;
			kidneyIsActive = false;
			stomachIsActive = false;
			intestinesIsActive = false;
			reproductiveSMIsActive = false;
			nervesIsActive = false;
			muscleIsActive = false;
		}
	}

}
void Body::drawKidney() {
	DrawRectangleRec(kidneyRec, BLANK);
	if (brainIsActive || lungsIsActive || liverIsActive || heartIsActive || stomachIsActive || intestinesIsActive || reproductiveSMIsActive || nervesIsActive || muscleIsActive && !kidneyIsActive)
		DrawTexture(kidney, kidneyPos.x, kidneyPos.y, GRAY);
	else
		DrawTexture(kidney, kidneyPos.x, kidneyPos.y, WHITE);

	if (kidneyIsActive) {
		DrawText(kidneyInfo, infoPos.x, infoPos.y, fontSize, BLACK);
		cancelBtn(sWidth / 2 - body.width + 75, sHeight / 2 + body.height / 2 - 100);
		if (CheckCollisionPointRec(GetMousePosition(), kidneyRec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			brainIsActive = false;
			lungsIsActive = false;
			liverIsActive = false;
			heartIsActive = false;
			kidneyIsActive = false;
			stomachIsActive = false;
			intestinesIsActive = false;
			reproductiveSMIsActive = false;
			nervesIsActive = false;
			muscleIsActive = false;
		}
	}
	else {
		if (CheckCollisionPointRec(GetMousePosition(), kidneyRec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			brainIsActive = false;
			lungsIsActive = false;
			liverIsActive = false;
			heartIsActive = false;
			kidneyIsActive = true;
			stomachIsActive = false;
			intestinesIsActive = false;
			reproductiveSMIsActive = false;
			nervesIsActive = false;
			muscleIsActive = false;
		}
	}
}
void Body::drawStomach() {
	DrawRectangleRec(stomachRec, BLANK);
	if (brainIsActive || lungsIsActive || liverIsActive || heartIsActive || kidneyIsActive || intestinesIsActive || reproductiveSMIsActive || nervesIsActive || muscleIsActive && !stomachIsActive)
		DrawTexture(stomach, stomachPos.x, stomachPos.y, GRAY);
	else
		DrawTexture(stomach, stomachPos.x, stomachPos.y, WHITE);

	if (stomachIsActive) {
		DrawText(stomachInfo, infoPos.x, infoPos.y, fontSize, BLACK);
		cancelBtn(sWidth / 2 - body.width + 75, sHeight / 2 + body.height / 2 - 130);
		if (CheckCollisionPointRec(GetMousePosition(), stomachRec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			brainIsActive = false;
			lungsIsActive = false;
			liverIsActive = false;
			heartIsActive = false;
			kidneyIsActive = false;
			stomachIsActive = false;
			intestinesIsActive = false;
			reproductiveSMIsActive = false;
			nervesIsActive = false;
			muscleIsActive = false;
		}
	}
	else {
		if (CheckCollisionPointRec(GetMousePosition(), stomachRec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			brainIsActive = false;
			lungsIsActive = false;
			liverIsActive = false;
			heartIsActive = false;
			kidneyIsActive = false;
			stomachIsActive = true;
			intestinesIsActive = false;
			reproductiveSMIsActive = false;
			nervesIsActive = false;
			muscleIsActive = false;
		}
	}
}
void Body::drawIntestines() {
	DrawRectangleRec(intestinesRec, BLANK);
	if (brainIsActive || lungsIsActive || liverIsActive || heartIsActive || kidneyIsActive || stomachIsActive || reproductiveSMIsActive || nervesIsActive || muscleIsActive && !intestinesIsActive)
		DrawTexture(intestines, intestinesPos.x, intestinesPos.y, GRAY);
	else
		DrawTexture(intestines, intestinesPos.x, intestinesPos.y, WHITE);

	if (intestinesIsActive) {
		DrawText(intestinesInfo, infoPos.x, infoPos.y, fontSize, BLACK);
		cancelBtn(sWidth / 2 - body.width + 75, sHeight / 2 + body.height / 4 - 120);
		if (CheckCollisionPointRec(GetMousePosition(), intestinesRec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			brainIsActive = false;
			lungsIsActive = false;
			liverIsActive = false;
			heartIsActive = false;
			kidneyIsActive = false;
			stomachIsActive = false;
			intestinesIsActive = false;
			reproductiveSMIsActive = false;
			nervesIsActive = false;
			muscleIsActive = false;
		}
	}
	else {
		if (CheckCollisionPointRec(GetMousePosition(), intestinesRec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			brainIsActive = false;
			lungsIsActive = false;
			liverIsActive = false;
			heartIsActive = false;
			kidneyIsActive = false;
			stomachIsActive = false;
			intestinesIsActive = true;
			reproductiveSMIsActive = false;
			nervesIsActive = false;
			muscleIsActive = false;
		}
	}
}
void Body::drawReproductiveSM() {
	DrawRectangleRec(reproductiveSMRec, BLANK);
	if (brainIsActive || lungsIsActive || liverIsActive || heartIsActive || kidneyIsActive || stomachIsActive || intestinesIsActive || nervesIsActive || muscleIsActive && !reproductiveSMIsActive)
		DrawTexture(reproductiveSM, reproductiveSMPos.x, reproductiveSMPos.y, GRAY);
	else
		DrawTexture(reproductiveSM, reproductiveSMPos.x, reproductiveSMPos.y, WHITE);

	if (reproductiveSMIsActive) {
		DrawText(reproductiveSMInfo, infoPos.x, infoPos.y, fontSize, BLACK);
		cancelBtn(sWidth / 2 - body.width + 75, sHeight / 2 + body.height / 3 - 80);
		if (CheckCollisionPointRec(GetMousePosition(), reproductiveSMRec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			brainIsActive = false;
			lungsIsActive = false;
			liverIsActive = false;
			heartIsActive = false;
			kidneyIsActive = false;
			stomachIsActive = false;
			intestinesIsActive = false;
			reproductiveSMIsActive = false;
			nervesIsActive = false;
			muscleIsActive = false;
		}
	}
	else {
		if (CheckCollisionPointRec(GetMousePosition(), reproductiveSMRec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			brainIsActive = false;
			lungsIsActive = false;
			liverIsActive = false;
			heartIsActive = false;
			kidneyIsActive = false;
			stomachIsActive = false;
			intestinesIsActive = false;
			reproductiveSMIsActive = true;
			nervesIsActive = false;
			muscleIsActive = false;
		}
	}
}
void Body::drawNerves() {
	DrawRectangleRec(nervesRec, BLANK);
	if (brainIsActive || lungsIsActive || liverIsActive || heartIsActive || kidneyIsActive || stomachIsActive || intestinesIsActive || reproductiveSMIsActive || muscleIsActive && !nervesIsActive)
		DrawTexture(nerves, nervesPos.x, nervesPos.y, GRAY);
	else
		DrawTexture(nerves, nervesPos.x, nervesPos.y, WHITE);

	if (nervesIsActive) {
		DrawText(nervesInfo, infoPos.x, infoPos.y, fontSize, BLACK);
		cancelBtn(sWidth / 2 - body.width + 75, sHeight / 2 + body.height / 3 - 80);
		if (CheckCollisionPointRec(GetMousePosition(), nervesRec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			brainIsActive = false;
			lungsIsActive = false;
			liverIsActive = false;
			heartIsActive = false;
			kidneyIsActive = false;
			stomachIsActive = false;
			intestinesIsActive = false;
			reproductiveSMIsActive = false;
			nervesIsActive = false;
			muscleIsActive = false;
		}
	}
	else {
		if (CheckCollisionPointRec(GetMousePosition(), nervesRec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			brainIsActive = false;
			lungsIsActive = false;
			liverIsActive = false;
			heartIsActive = false;
			kidneyIsActive = false;
			stomachIsActive = false;
			intestinesIsActive = false;
			reproductiveSMIsActive = false;
			nervesIsActive = true;
			muscleIsActive = false;
		}
	}
}
void Body::drawMuscle() {
	DrawRectangleRec(muscleRec, BLANK);
	if (brainIsActive || lungsIsActive || liverIsActive || heartIsActive || kidneyIsActive || stomachIsActive || intestinesIsActive || reproductiveSMIsActive || nervesIsActive && !muscleIsActive)
		DrawTexture(muscle, musclePos.x, musclePos.y, GRAY);
	else
		DrawTexture(muscle, musclePos.x, musclePos.y, WHITE);

	if (muscleIsActive) {
		DrawText(muscleInfo, infoPos.x, infoPos.y, fontSize, BLACK);
		cancelBtn(sWidth / 2 - body.width + 75, sHeight / 2 + body.height / 3 + 10);
		if (CheckCollisionPointRec(GetMousePosition(), muscleRec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			brainIsActive = false;
			lungsIsActive = false;
			liverIsActive = false;
			heartIsActive = false;
			kidneyIsActive = false;
			stomachIsActive = false;
			intestinesIsActive = false;
			reproductiveSMIsActive = false;
			nervesIsActive = false;
			muscleIsActive = false;
		}
	}
	else {
		if (CheckCollisionPointRec(GetMousePosition(), muscleRec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			brainIsActive = false;
			lungsIsActive = false;
			liverIsActive = false;
			heartIsActive = false;
			kidneyIsActive = false;
			stomachIsActive = false;
			intestinesIsActive = false;
			reproductiveSMIsActive = false;
			nervesIsActive = false;
			muscleIsActive = true;
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
		drawStomach();
		drawIntestines();
		drawReproductiveSM();
		drawNerves();
		drawMuscle();
		drawBrain();
	}
	else if (lungsIsActive) {
		drawBrain();
		drawLiver();
		drawHeart();
		drawKidney();
		drawStomach();
		drawIntestines();
		drawReproductiveSM();
		drawNerves();
		drawMuscle();
		drawLungs();
	}
	else if (liverIsActive) {
		drawBrain();
		drawLungs();
		drawHeart();
		drawKidney();
		drawStomach();
		drawIntestines();
		drawReproductiveSM();
		drawNerves();
		drawMuscle();
		drawLiver();
	}
	else if (heartIsActive) {
		drawBrain();
		drawLungs();
		drawLiver();
		drawKidney();
		drawStomach();
		drawIntestines();
		drawReproductiveSM();
		drawNerves();
		drawMuscle();
		drawHeart();
	}
	else if (kidneyIsActive) {
		drawBrain();
		drawLungs();
		drawLiver();
		drawHeart();
		drawStomach();
		drawIntestines();
		drawReproductiveSM();
		drawNerves();
		drawMuscle();
		drawKidney();
	}
	else if (stomachIsActive) {
		drawBrain();
		drawLungs();
		drawLiver();
		drawHeart();
		drawKidney();
		drawIntestines();
		drawReproductiveSM();
		drawNerves();
		drawMuscle();
		drawStomach();
	}
	else if (intestinesIsActive) {
		drawBrain();
		drawLungs();
		drawLiver();
		drawKidney();
		drawStomach();
		drawHeart();
		drawReproductiveSM();
		drawNerves();
		drawMuscle();
		drawIntestines();
	}
	else if (reproductiveSMIsActive) {
		drawBrain();
		drawLungs();
		drawLiver();
		drawKidney();
		drawStomach();
		drawHeart();
		drawIntestines();
		drawNerves();
		drawMuscle();
		drawReproductiveSM();
	}
	else if (nervesIsActive) {
		drawBrain();
		drawLungs();
		drawLiver();
		drawKidney();
		drawStomach();
		drawHeart();
		drawIntestines();
		drawReproductiveSM();
		drawMuscle();
		drawNerves();
	}
	else if (muscleIsActive) {
		drawBrain();
		drawLungs();
		drawLiver();
		drawKidney();
		drawStomach();
		drawHeart();
		drawIntestines();
		drawReproductiveSM();
		drawNerves();
		drawMuscle();
	}
	else {
		drawBrain();
		drawLungs();
		drawLiver();
		drawKidney();
		drawStomach();
		drawHeart();
		drawIntestines();
		drawReproductiveSM();
		drawNerves();
		drawMuscle();
	}

}
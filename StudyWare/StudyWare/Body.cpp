#include "Body.hpp"

std::shared_ptr<Body> Body::instance = nullptr;

Body::Body() {
	sWidth = GetScreenWidth();
	sHeight = GetScreenHeight();

	fontSize = sHeight / 50;
	testFontSize = sHeight / 35;

	mousePosition = GetMousePosition();

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
	muscleIsActive = false;

	brainInfo = "B R A I N\nThe brain is the most complex and vital organ in the human body,\nresponsible for controllingand coordinating all bodily functions,\nthoughts, emotions, and sensations. It is composed of more than\n100 billion neurons and trillions of synapses, which form complex\nnetworks that allow us to think, feel, and move.\nCommon brain diseases include:\nAlzheimer's disease, Parkinson's disease, multiple sclerosis,\nepilepsy, migraines, and traumatic brain injury. Alzheimer's disease\nis a progressive neurodegenerative disease that affects memory,\nthinking, and behavior, while Parkinson's disease is a degenerative\ndisorder that affects movement, balance, and coordination.\nMultiple sclerosis is an autoimmune disease that affects\nthe central nervous system, while epilepsy is a neurological\ndisorder that causes seizures. Migraines are a type of headache that\ncan be debilitatingand recurring, while traumatic brin injury can result\nfrom a blow or jolt to the head, leading to cognitive, emotional,\nand physical impairment.";

	lungsInfo = "L U N G S\nThe lungs are essential organs that help us breathe by taking in\noxygen and getting rid of carbon dioxide.Here are some common lung\ndiseases : \n1. Asthma : A chronic condition that causes inflammation and narrowing\nof the airways, making it difficult to breathe.\n2. Chronic obstructive pulmonary disease(COPD) : A group of lung\ndiseases that make it hard to breathe due to damage to the airways\nand /or air Sacs in the lungs.\n3. Pneumonia : An infection that inflames the air sacs in one\nor both lungs.\n4. Tuberculosis(TB) : A bacterial infection that primarily affects\nthe lungs but can also affect other parts of the body\n5. Lung cancer : A condition where cells in the lungs grow\nabnormally and form tumors.";

	liverInfo = "L I V E R\nThe liver is the largest internal organ and has many important\nfunctions, including filtering blood, producing bile, storing vitaminsand\nminerals, and breaking down toxins.Here are some common liver\ndiseases :\n1.Hepatitis : Inflammation of the liver caused by a viral infection or\nexposure to toxins.\n2.Cirrhosis : A progressive disease that occurs when liver cells are\ndamaged and replaced by scar tissue, leading to loss of liver\nfunction.\n3.Nonalcoholic fatty liver disease(NAFLD) : A condition where fat\nbuilds up in the liver, often seen in people with obesity, diabetes\nor high cholesterol levels.";

	heartInfo = "H E A R T\nThe heart is a vital organ that pumps blood throughout the body,\nsupplying the organs and tissues with oxygen and nutrients.\nHere are some common heart diseases:\n1. Coronary artery disease : A condition where the arteries that\nsupply blood to the heart become narrowed or blocked.\n2. Arrhythmia : A heart rhythm problem that can cause the heart to\nbeat too fast, too slow, or irregularly.\n3. Heart failure : A condition where the heart cannot pump enough\nblood to meet the body's needs.\n4. Atherosclerosis : A condition where plaque builds up inside the\narteries, causing them to hardenand narrow.\n5. Heart valve disease : A condition where one or more of the\nheart valves do not function properly.";

	kidneyInfo = "K I D N E Y\nThe kidneys are a pair of bean-shaped organs located on either\nside of the spine in the back of the abdominal cavity.They play a\ncrucial role in the body's urinary system and help filter waste\nproducts and excess fluids from the blood. The primary function\nof the kidneys is to produce urine, which is then transported to the\nbladder and eliminated from the body through the urethra. Chronic\nkidney disease is a condition in which the kidneys gradually lose\nfunction over time, usually over the course of months or years.\nIt can lead to a variety of complications, including high blood\npressure, anemia, and nerve damage. Kidney stones are hard,\nmineral deposits that form inside the kidneysand can cause\nintense painand discomfort when they pass through the urinary\ntract.The most common cause of kidney stones is dehydration,\nwhich can cause mineralsand salts to crystallize and form stones.\nUrinary tract infections(UTIs) are caused by bacteria that enter the\nurinary tractand can lead to symptoms such as painful urination, frequent\nurination, and lower abdominal pain. Headache is not typically a symptom of a\nUTI. Several factors can increase the risk of chronic kidney disease,\nincluding high blood pressure, diabetes, smoking, obesity, and a family\nhistory of kidney disease. The most common type of kidney stone is calcium\noxalate, which forms when there is too much calciumand oxalate in the urine.\nThe main treatment for kidney failure is dialysis, which is a process that\nfilters waste productsand excess fluids from the blood when the kidneys\ncan no longer perform this function.";

	stomachInfo = "S T O M A C H\nThe stomach is a muscular sac located in the upper left abdomen,\nbetween the esophagus and the small intestine. It plays a crucial role\nin the digestive system by breaking down food into smaller particles\nand mixing it with gastric acid and enzymes. Common stomach diseases\ninclude gastroesophageal reflux disease(GERD), peptic ulcers,\ngastritis, and stomach cancer.GERD is a chronic condition in which\nthe stomach acid flows back into the esophagus, causing\nheartburnand damage to the esophageal lining. Peptic ulcers are\nopen sores that form in the lining of the stomach or small\nintestine, often caused by a bacterial infection or the long\n- term use of certain medications. Gastritis is an inflammation of\nthe stomach lining, which can be caused by infections, alcohol,\nstress, or the use of certain medications.Stomach cancer is\na type of cancer that begins in the cells lining the stomach and can\nspread to other parts of the body. Other common digestive issues\nthat can affect the stomach include irritable bowel syndrome(IBS), celiac\ndisease and food intolerances or allergies.IBS is a chronic condition that\naffects the large intestine and can cause abdominal pain, bloating\nand changes in bowel movements.Celiac disease is an autoimmune disorder\nin which the body reacts to gluten, a protein found in wheat, causing\ndamage to the small intestine.Food intolerances or allergies can cause\na range of digestive symptoms, including stomach pain, bloating, diarrhea\nor constipation.";

	intestinesInfo = "I N T E S T I O N E S\nThe human intestine, also known as the bowel, is part of the digestive\nsystem responsible for absorbing nutrients from food and eliminating\nwaste from the body. The small intestine is the longest part of the\ndigestive tract, where most nutrient absorption occurs.\nThe large intestine, or colon, absorbs water and electrolytes from\nundigested food and stores waste until elimination.\nCommon diseases of the intestines include inflammatory bowel\ndisease(IBD), irritable bowel syndrome(IBS), diverticulitis\nand colon cancer. IBD is a chronic inflammation of the digestive\ntract that includes Crohn's disease and ulcerative colitis.\nIBS is a functional disorder that causes abdominal pain, bloating\nand changes in bowel habits. Diverticulitis is the inflammation\nor infection of small pouches in the lining of the colon, while\ncolon cancer is the growth of cancerous cells in the colon or rectum.";

	reproductiveSMInfo = "R E P R O D U C T I V E  S Y S T E M  M A L E\nThe male reproductive system consists of organs that are involved\nin the production, storage, and transportation of sperm.\nThese organs include the testes, epididymis, vas deferens,\nseminal vesicles, prostate gland, and urethra. The testes produce\nsperm and testosterone,while the epididymis stores and transports\nsperm to the vas deferens, which carries sperm from the epididymis\nto the urethra. The seminal vesicles and prostate gland produce\nseminal fluid, which nourishes and transports sperm during\nejaculation. Common diseases that can affect the male reproductive\nsystem include prostate cancer, testicular cancer, erectile\ndysfunction, and infertility.Prostate cancer is a cancer that\naffects the prostate glandand can cause problems with\nurinationand sexual function.Testicular cancer is a cancer that\naffects the testiclesand can cause pain, swelling and lumps\nin the scrotum.Erectile dysfunction is a condition where a man is unable\nto achieve or maintain an erection sufficient for sexual activity.\nInfertility is a condition where a man is unable to father a child due\nto problems with sperm production or transportation.";

	nervesInfo = "N E R V E S\nThe PNS can be further divided into the somatic nervous system and\nthe autonomic nervous system. The somatic nervous system is\nresponsible for voluntary movements and is involved in sensory\nperception, while the autonomic nervous system controls involuntary\nfunctions like heart rate, breathing, and digestion.The human body\ncontains millions of individual nerve cells called neurons,\nwhich transmit electrical signals throughout the body.\nNeurons are composed of a cell body, dendrites, and an axon.\nThe dendrites receive signals from other neurons, while the axon\nsends signals to other neurons or to muscles and glands.\nDamage to nerves can result in a variety of conditions, such as\nneuropathies, which are characterized by pain, numbness \nor weakness in the affected area. Examples of neuropathies\ninclude carpal tunnel syndrome, diabetic neuropathy\nand peripheral neuropathy.";

	muscleInfo = "M U S C L E\nHuman muscles are the collection of tissues in the body responsible\nfor movement, maintaining posture, and generating heat.\nThere are three main types of muscles in the human body:\nskeletal, smooth, and cardiac muscles. Skeletal muscles are attached\nto the bones and are responsible for voluntary movement.\nThey are striated muscles and are under conscious control.\nSmooth muscles are found in the walls of internal organs such as\nthe stomach, intestines, and blood vessels, and they are\nresponsible for involuntary movements such as peristalsis.\nCardiac muscles are found only in the heart and are responsible\nfor pumping blood throughout the body. \nCommon muscle diseases include: muscular dystrophy,\nmyasthenia gravis, fibromyalgia, and polymyositis.\nMuscular dystrophy is a group of genetic disorders that cause\nprogressive muscle weakness and loss of muscle mass.\nMyasthenia gravis is a neuromuscular disorder that causes muscle\nweakness and fatigue, particularly in the eyes, face, throat, andlimbs.\nFibromyalgia is a chronic pain disorder that affects muscles, tendons\nand ligaments, causing widespread pain, fatigue and sleep disturbances.\nPolymyositis is an autoimmune disease that causes inflammation and\nweakness in the muscles, particularly in the hips, thighs, shoulders\nand neck.";

	field.width = sWidth / 2 + sWidth / 4;
	field.height = sHeight / 2 + sHeight / 4;
	field.x = sWidth / 20;
	field.y = sHeight / 12;
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
}
std::shared_ptr<Body> Body::getInstance() {
	if (instance == nullptr)
		instance = std::shared_ptr<Body>(new Body);
	return instance;
}

void Body::drawAlertForEnd() {
	Button yesBtn, noBtn;

	yesBtn.bounds = { (float)sWidth / 2 + 30, (float)sHeight / 2, 250, 50 };
	yesBtn.rounding = 1;
	yesBtn.hovering = CheckCollisionPointRec(GetMousePosition(), yesBtn.bounds);
	yesBtn.text = "Yes, finish attempt";
	yesBtn.color = GRAY;

	noBtn.bounds = { (float)sWidth / 2 - 280, (float)sHeight / 2, 250, 50 };
	noBtn.rounding = 1;
	noBtn.hovering = CheckCollisionPointRec(GetMousePosition(), noBtn.bounds);
	noBtn.text = "No, back to attempt";
	noBtn.color = GRAY;

	Vector2 textPos = { sWidth / 2 - 475, sHeight / 2 - 100 };
	DrawText("Are you sure you want to finish attempt", textPos.x, textPos.y, 50, BLACK);

	Vector2 yesBtnPos = { yesBtn.bounds.x + yesBtn.bounds.width / 2 - MeasureText(yesBtn.text, 20) / 2, yesBtn.bounds.y + 15 };
	if (yesBtn.hovering) yesBtn.color = DARKGRAY;
	DrawRectangleRounded(yesBtn.bounds, yesBtn.rounding, yesBtn.rounding, yesBtn.color);
	DrawText(yesBtn.text, yesBtnPos.x, yesBtnPos.y, 20, BLACK);

	if (yesBtn.hovering && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		inTest = false;
		showAlert = false;
		questionTurn[0] = true;
		questionTurn[1] = false;
		questionTurn[2] = false;
		questionTurn[3] = false;
		questionTurn[4] = false;
		questionTurn[5] = false;
		questionTurn[6] = false;
		questionTurn[7] = false;
		questionTurn[8] = false;
		questionTurn[9] = false;
	}

	Vector2 noBtnPos = { noBtn.bounds.x + noBtn.bounds.width / 2 - MeasureText(noBtn.text, 20) / 2, noBtn.bounds.y + 15 };
	if (noBtn.hovering) noBtn.color = DARKGRAY;
	DrawRectangleRounded(noBtn.bounds, noBtn.rounding, noBtn.rounding, noBtn.color);
	DrawText(noBtn.text, noBtnPos.x, noBtnPos.y, 20, BLACK);

	if (noBtn.hovering && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		showAlert = false;
	}
}
void Body::drawTestButtons() {
	if (!questionTurn[0]) {
		Button previousBtn;

		previousBtn.bounds = { (float)sWidth / 20, (float)sHeight / 2 + sHeight / 3 + 10, 150, 50 };

		previousBtn.rounding = 1;
		previousBtn.hovering = CheckCollisionPointRec(GetMousePosition(), previousBtn.bounds);
		previousBtn.text = "Previous";
		previousBtn.color = GRAY;

		if (previousBtn.hovering) previousBtn.color = DARKGRAY;
		DrawRectangleRounded(previousBtn.bounds, previousBtn.rounding, previousBtn.rounding, previousBtn.color);
		DrawText(previousBtn.text, previousBtn.bounds.x + previousBtn.bounds.width / 2 - MeasureText(previousBtn.text, 20) / 2, previousBtn.bounds.y + 15, 20, BLACK);

		if (CheckCollisionPointRec(GetMousePosition(), previousBtn.bounds) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			if (questionTurn[1]) {
				questionTurn[0] = true;
				questionTurn[1] = false;
				questionTurn[2] = false;
				questionTurn[3] = false;
				questionTurn[4] = false;
				questionTurn[5] = false;
				questionTurn[6] = false;
				questionTurn[7] = false;
				questionTurn[8] = false;
				questionTurn[9] = false;
			}
			else if (questionTurn[2]) {
				questionTurn[0] = false;
				questionTurn[1] = true;
				questionTurn[2] = false;
				questionTurn[3] = false;
				questionTurn[4] = false;
				questionTurn[5] = false;
				questionTurn[6] = false;
				questionTurn[7] = false;
				questionTurn[8] = false;
				questionTurn[9] = false;
			}
			else if (questionTurn[3]) {
				questionTurn[0] = false;
				questionTurn[1] = false;
				questionTurn[2] = true;
				questionTurn[3] = false;
				questionTurn[4] = false;
				questionTurn[5] = false;
				questionTurn[6] = false;
				questionTurn[7] = false;
				questionTurn[8] = false;
				questionTurn[9] = false;
			}
			else if (questionTurn[4]) {
				questionTurn[0] = false;
				questionTurn[1] = false;
				questionTurn[2] = false;
				questionTurn[3] = true;
				questionTurn[4] = false;
				questionTurn[5] = false;
				questionTurn[6] = false;
				questionTurn[7] = false;
				questionTurn[8] = false;
				questionTurn[9] = false;
			}
			else if (questionTurn[5]) {
				questionTurn[0] = false;
				questionTurn[1] = false;
				questionTurn[2] = false;
				questionTurn[3] = false;
				questionTurn[4] = true;
				questionTurn[5] = false;
				questionTurn[6] = false;
				questionTurn[7] = false;
				questionTurn[8] = false;
				questionTurn[9] = false;
			}
			else if (questionTurn[6]) {
				questionTurn[0] = false;
				questionTurn[1] = false;
				questionTurn[2] = false;
				questionTurn[3] = false;
				questionTurn[4] = false;
				questionTurn[5] = true;
				questionTurn[6] = false;
				questionTurn[7] = false;
				questionTurn[8] = false;
				questionTurn[9] = false;
			}
			else if (questionTurn[7]) {
				questionTurn[0] = false;
				questionTurn[1] = false;
				questionTurn[2] = false;
				questionTurn[3] = false;
				questionTurn[4] = false;
				questionTurn[5] = false;
				questionTurn[6] = true;
				questionTurn[7] = false;
				questionTurn[8] = false;
				questionTurn[9] = false;
			}
			else if (questionTurn[8]) {
				questionTurn[0] = false;
				questionTurn[1] = false;
				questionTurn[2] = false;
				questionTurn[3] = false;
				questionTurn[4] = false;
				questionTurn[5] = false;
				questionTurn[6] = false;
				questionTurn[7] = true;
				questionTurn[8] = false;
				questionTurn[9] = false;
			}
			else if (questionTurn[9]) {
				questionTurn[0] = false;
				questionTurn[1] = false;
				questionTurn[2] = false;
				questionTurn[3] = false;
				questionTurn[4] = false;
				questionTurn[5] = false;
				questionTurn[6] = false;
				questionTurn[7] = false;
				questionTurn[8] = true;
				questionTurn[9] = false;
			}
		}
	}

	if (!questionTurn[9]) {
		Button nextBtn;

		nextBtn.bounds = { (float)sWidth / 2 + sWidth / 5 + 40, (float)sHeight / 2 + sHeight / 3 + 10, 150, 50 };

		nextBtn.rounding = 1;
		nextBtn.hovering = CheckCollisionPointRec(GetMousePosition(), nextBtn.bounds);
		nextBtn.text = "Next";
		nextBtn.color = GRAY;

		if (nextBtn.hovering) nextBtn.color = DARKGRAY;
		DrawRectangleRounded(nextBtn.bounds, nextBtn.rounding, nextBtn.rounding, nextBtn.color);
		DrawText(nextBtn.text, nextBtn.bounds.x + nextBtn.bounds.width / 2 - MeasureText(nextBtn.text, 20) / 2, nextBtn.bounds.y + 15, 20, BLACK);

		if (CheckCollisionPointRec(GetMousePosition(), nextBtn.bounds) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			if (questionTurn[0]) {
				questionTurn[0] = false;
				questionTurn[1] = true;
				questionTurn[2] = false;
				questionTurn[3] = false;
				questionTurn[4] = false;
				questionTurn[5] = false;
				questionTurn[6] = false;
				questionTurn[7] = false;
				questionTurn[8] = false;
				questionTurn[9] = false;
			}
			else if (questionTurn[1]) {
				questionTurn[0] = false;
				questionTurn[1] = false;
				questionTurn[2] = true;
				questionTurn[3] = false;
				questionTurn[4] = false;
				questionTurn[5] = false;
				questionTurn[6] = false;
				questionTurn[7] = false;
				questionTurn[8] = false;
				questionTurn[9] = false;
			}
			else if (questionTurn[2]) {
				questionTurn[0] = false;
				questionTurn[1] = false;
				questionTurn[2] = false;
				questionTurn[3] = true;
				questionTurn[4] = false;
				questionTurn[5] = false;
				questionTurn[6] = false;
				questionTurn[7] = false;
				questionTurn[8] = false;
				questionTurn[9] = false;
			}
			else if (questionTurn[3]) {
				questionTurn[0] = false;
				questionTurn[1] = false;
				questionTurn[2] = false;
				questionTurn[3] = false;
				questionTurn[4] = true;
				questionTurn[5] = false;
				questionTurn[6] = false;
				questionTurn[7] = false;
				questionTurn[8] = false;
				questionTurn[9] = false;
			}
			else if (questionTurn[4]) {
				questionTurn[0] = false;
				questionTurn[1] = false;
				questionTurn[2] = false;
				questionTurn[3] = false;
				questionTurn[4] = false;
				questionTurn[5] = true;
				questionTurn[6] = false;
				questionTurn[7] = false;
				questionTurn[8] = false;
				questionTurn[9] = false;
			}
			else if (questionTurn[5]) {
				questionTurn[0] = false;
				questionTurn[1] = false;
				questionTurn[2] = false;
				questionTurn[3] = false;
				questionTurn[4] = false;
				questionTurn[5] = false;
				questionTurn[6] = true;
				questionTurn[7] = false;
				questionTurn[8] = false;
				questionTurn[9] = false;
			}
			else if (questionTurn[6]) {
				questionTurn[0] = false;
				questionTurn[1] = false;
				questionTurn[2] = false;
				questionTurn[3] = false;
				questionTurn[4] = false;
				questionTurn[5] = false;
				questionTurn[6] = false;
				questionTurn[7] = true;
				questionTurn[8] = false;
				questionTurn[9] = false;
			}
			else if (questionTurn[7]) {
				questionTurn[0] = false;
				questionTurn[1] = false;
				questionTurn[2] = false;
				questionTurn[3] = false;
				questionTurn[4] = false;
				questionTurn[5] = false;
				questionTurn[6] = false;
				questionTurn[7] = false;
				questionTurn[8] = true;
				questionTurn[9] = false;
			}
			else if (questionTurn[8]) {
				questionTurn[0] = false;
				questionTurn[1] = false;
				questionTurn[2] = false;
				questionTurn[3] = false;
				questionTurn[4] = false;
				questionTurn[5] = false;
				questionTurn[6] = false;
				questionTurn[7] = false;
				questionTurn[8] = false;
				questionTurn[9] = true;
			}
		}
	}


	Button finishBtn;

	finishBtn.bounds = { (float)sWidth / 2 + sWidth / 5 + 40, (float)sHeight - 75, 150, 50 };

	finishBtn.rounding = 1;
	finishBtn.hovering = CheckCollisionPointRec(GetMousePosition(), finishBtn.bounds);
	finishBtn.text = "Finish";
	finishBtn.color = GRAY;

	if (finishBtn.hovering) finishBtn.color = DARKGRAY;

	DrawRectangleRounded(finishBtn.bounds, finishBtn.rounding, finishBtn.rounding, finishBtn.color);
	DrawText(finishBtn.text, finishBtn.bounds.x + finishBtn.bounds.width / 2 - MeasureText(finishBtn.text, 20) / 2, finishBtn.bounds.y + 15, 20, BLACK);

	if (CheckCollisionPointRec(GetMousePosition(), finishBtn.bounds) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		if (inTest) {
			showAlert = true;
		}

	}


}
void Body::drawQuestionNum(float posX, float posY, Questions question[]) {
	Color secondRec = WHITE;
	for (int i = 0; i < 10; i++) {
		if (questionTurn[i])
			secondRec = BLUE;
		else if (question[i].ans[0].checked || question[i].ans[1].checked || question[i].ans[2].checked || question[i].ans[3].checked)
			secondRec = GRAY;
		else secondRec = WHITE;
		DrawRectangleRounded(Rectangle{ posX + i * 55, posY, sWidth / 45, sHeight / 25 }, 0.5f, 30, DARKGRAY);
		DrawRectangleRounded(Rectangle{ posX + i * 55 + 2, posY + 3, sWidth / 50, sHeight / 30 }, 0.5f, 30, secondRec);
		const char* text = TextFormat("%d", i + 1);
		float textWidth = MeasureText(text, 20);
		DrawText(text, posX + i * 55 + sWidth / 90 - textWidth / 2, posY + sHeight / 60 - 8, 20, BLACK);
		if (CheckCollisionPointRec(GetMousePosition(), Rectangle{ posX + i * 55, posY, sWidth / 45, sHeight / 25 }) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			switch (i)
			{
			case 0:
				questionTurn[0] = true;
				questionTurn[1] = false;
				questionTurn[2] = false;
				questionTurn[3] = false;
				questionTurn[4] = false;
				questionTurn[5] = false;
				questionTurn[6] = false;
				questionTurn[7] = false;
				questionTurn[8] = false;
				questionTurn[9] = false;
				break;
			case 1:
				questionTurn[0] = false;
				questionTurn[1] = true;
				questionTurn[2] = false;
				questionTurn[3] = false;
				questionTurn[4] = false;
				questionTurn[5] = false;
				questionTurn[6] = false;
				questionTurn[7] = false;
				questionTurn[8] = false;
				questionTurn[9] = false;
				break;
			case 2:
				questionTurn[0] = false;
				questionTurn[1] = false;
				questionTurn[2] = true;
				questionTurn[3] = false;
				questionTurn[4] = false;
				questionTurn[5] = false;
				questionTurn[6] = false;
				questionTurn[7] = false;
				questionTurn[8] = false;
				questionTurn[9] = false;
				break;
			case 3:
				questionTurn[0] = false;
				questionTurn[1] = false;
				questionTurn[2] = false;
				questionTurn[3] = true;
				questionTurn[4] = false;
				questionTurn[5] = false;
				questionTurn[6] = false;
				questionTurn[7] = false;
				questionTurn[8] = false;
				questionTurn[9] = false;
				break;
			case 4:
				questionTurn[0] = false;
				questionTurn[1] = false;
				questionTurn[2] = false;
				questionTurn[3] = false;
				questionTurn[4] = true;
				questionTurn[5] = false;
				questionTurn[6] = false;
				questionTurn[7] = false;
				questionTurn[8] = false;
				questionTurn[9] = false;
				break;
			case 5:
				questionTurn[0] = false;
				questionTurn[1] = false;
				questionTurn[2] = false;
				questionTurn[3] = false;
				questionTurn[4] = false;
				questionTurn[5] = true;
				questionTurn[6] = false;
				questionTurn[7] = false;
				questionTurn[8] = false;
				questionTurn[9] = false;
				break;
			case 6:
				questionTurn[0] = false;
				questionTurn[1] = false;
				questionTurn[2] = false;
				questionTurn[3] = false;
				questionTurn[4] = false;
				questionTurn[5] = false;
				questionTurn[6] = true;
				questionTurn[7] = false;
				questionTurn[8] = false;
				questionTurn[9] = false;
				break;
			case 7:
				questionTurn[0] = false;
				questionTurn[1] = false;
				questionTurn[2] = false;
				questionTurn[3] = false;
				questionTurn[4] = false;
				questionTurn[5] = false;
				questionTurn[6] = false;
				questionTurn[7] = true;
				questionTurn[8] = false;
				questionTurn[9] = false;
				break;
			case 8:
				questionTurn[0] = false;
				questionTurn[1] = false;
				questionTurn[2] = false;
				questionTurn[3] = false;
				questionTurn[4] = false;
				questionTurn[5] = false;
				questionTurn[6] = false;
				questionTurn[7] = false;
				questionTurn[8] = true;
				questionTurn[9] = false;
				break;
			case 9:
				questionTurn[0] = false;
				questionTurn[1] = false;
				questionTurn[2] = false;
				questionTurn[3] = false;
				questionTurn[4] = false;
				questionTurn[5] = false;
				questionTurn[6] = false;
				questionTurn[7] = false;
				questionTurn[8] = false;
				questionTurn[9] = true;
				break;
			}
		}
	}
}
void Body::drawQuestions(Questions question1[]) {
	if (!showAlert) {

		float currectAnswers = 0;
		float score = 0;

		int questionNum = 10; // Number of questions
		DrawRectangleRec(field, GRAY);
		for (int i = 0; i < questionNum; i++) {
			question1[i].pos.x = field.x + 30;
			question1[i].pos.y = field.y + 15;
			if (i == 0 && questionTurn[i]) {
				DrawText(question1[i].question, question1[i].pos.x, question1[i].pos.y, testFontSize, BLACK);
				for (int j = 0; j < 4; j++) {
					switch (j) {
					case 0:
						if ((questionTurn[3] && testfor == TestFor::BRAIN) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[3] || questionTurn[4]) && testfor == TestFor::LUNGS) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[2] || questionTurn[3] || questionTurn[4] || questionTurn[6]) && testfor == TestFor::HEART) ||
							((questionTurn[5] || questionTurn[7]) && testfor == TestFor::REPRODUCTIVE) ||
							((questionTurn[1] || questionTurn[5] || questionTurn[9]) && testfor == TestFor::NERVES) ||
							((questionTurn[6] || questionTurn[8]) && testfor == TestFor::MUSCLE))
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 120 };
						else
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 70 };

						checkBoxPos = { question1[i].pos.x + 10, question1[i].ans[j].pos.y + 15 };
						clickRecPos.x = question1[i].pos.x;
						clickRecPos.y = question1[i].ans[j].pos.y;
						clickRecPos.width = sWidth / 2 + sWidth / 5 + 50;
						if (questionTurn[5] && testfor == TestFor::LIVER)
							clickRecPos.height = 70;
						else
							clickRecPos.height = 30;
						/*DrawRectangleRec(clickRecPos, BLACK);*/
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question1[i].ans[0].checked = true;
							question1[i].ans[1].checked = false;
							question1[i].ans[2].checked = false;
							question1[i].ans[3].checked = false;
						}

						if (question1[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawText(question1[i].ans[j].text, question1[i].ans[j].pos.x, question1[i].ans[j].pos.y, 30, BLACK);
						break;
					case 1:
						if ((questionTurn[3] && testfor == TestFor::BRAIN) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[3] || questionTurn[4]) && testfor == TestFor::LUNGS) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[2] || questionTurn[3] || questionTurn[4] || questionTurn[6]) && testfor == TestFor::HEART) ||
							((questionTurn[5] || questionTurn[7]) && testfor == TestFor::REPRODUCTIVE) ||
							((questionTurn[1] || questionTurn[5] || questionTurn[9]) && testfor == TestFor::NERVES) ||
							((questionTurn[6] || questionTurn[8]) && testfor == TestFor::MUSCLE))
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 170 };
						else if (questionTurn[5] && testfor == TestFor::LIVER)
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 170 };
						else
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 120 };

						checkBoxPos = { question1[i].pos.x + 10, question1[i].ans[j].pos.y + 15 };
						clickRecPos.x = question1[i].pos.x;
						clickRecPos.y = question1[i].ans[j].pos.y;
						clickRecPos.width = sWidth / 2 + sWidth / 5 + 50;
						if (questionTurn[5] && testfor == TestFor::LIVER)
							clickRecPos.height = 70;
						else
							clickRecPos.height = 30;
						/*DrawRectangleRec(clickRecPos, BLACK);*/
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question1[i].ans[0].checked = false;
							question1[i].ans[1].checked = true;
							question1[i].ans[2].checked = false;
							question1[i].ans[3].checked = false;
						}

						if (question1[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawText(question1[i].ans[j].text, question1[i].ans[j].pos.x, question1[i].ans[j].pos.y, 30, BLACK);
						break;
					case 2:
						if ((questionTurn[3] && testfor == TestFor::BRAIN) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[3] || questionTurn[4]) && testfor == TestFor::LUNGS) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[2] || questionTurn[3] || questionTurn[4] || questionTurn[6]) && testfor == TestFor::HEART) ||
							((questionTurn[5] || questionTurn[7]) && testfor == TestFor::REPRODUCTIVE) ||
							((questionTurn[1] || questionTurn[5] || questionTurn[9]) && testfor == TestFor::NERVES) ||
							((questionTurn[6] || questionTurn[8]) && testfor == TestFor::MUSCLE))
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 220 };
						else if (questionTurn[5] && testfor == TestFor::LIVER)
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 270 };
						else
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 170 };

						checkBoxPos = { question1[i].pos.x + 10, question1[i].ans[j].pos.y + 15 };
						clickRecPos.x = question1[i].pos.x;
						clickRecPos.y = question1[i].ans[j].pos.y;
						clickRecPos.width = sWidth / 2 + sWidth / 5 + 50;
						if ((questionTurn[5] && testfor == TestFor::LIVER) || ((questionTurn[4] || questionTurn[5] || questionTurn[6] || questionTurn[7]) && testfor == TestFor::INTESTINES))
							clickRecPos.height = 70;
						else
							clickRecPos.height = 30;
						/*DrawRectangleRec(clickRecPos, BLACK);*/
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question1[i].ans[0].checked = false;
							question1[i].ans[1].checked = false;
							question1[i].ans[2].checked = true;
							question1[i].ans[3].checked = false;
						}

						if (question1[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawText(question1[i].ans[j].text, question1[i].ans[j].pos.x, question1[i].ans[j].pos.y, 30, BLACK);
						break;
					case 3:
						if ((questionTurn[3] && testfor == TestFor::BRAIN) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[3] || questionTurn[4]) && testfor == TestFor::LUNGS) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[2] || questionTurn[3] || questionTurn[4] || questionTurn[6]) && testfor == TestFor::HEART) ||
							((questionTurn[4] || questionTurn[5] || questionTurn[6] || questionTurn[7]) && testfor == TestFor::INTESTINES) ||
							((questionTurn[5] || questionTurn[7]) && testfor == TestFor::REPRODUCTIVE) ||
							((questionTurn[1] || questionTurn[5] || questionTurn[9]) && testfor == TestFor::NERVES) ||
							((questionTurn[6] || questionTurn[8]) && testfor == TestFor::MUSCLE))
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 270 };
						else if (questionTurn[5] && testfor == TestFor::LIVER)
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 370 };
						else
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 220 };

						checkBoxPos = { question1[i].pos.x + 10, question1[i].ans[j].pos.y + 15 };
						clickRecPos.x = question1[i].pos.x;
						clickRecPos.y = question1[i].ans[j].pos.y;
						clickRecPos.width = sWidth / 2 + sWidth / 5 + 50;
						if (questionTurn[5] && testfor == TestFor::LIVER)
							clickRecPos.height = 70;
						else
							clickRecPos.height = 30;
						/*DrawRectangleRec(clickRecPos, BLACK);*/
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question1[i].ans[0].checked = false;
							question1[i].ans[1].checked = false;
							question1[i].ans[2].checked = false;
							question1[i].ans[3].checked = true;
						}

						if (question1[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawText(question1[i].ans[j].text, question1[i].ans[j].pos.x, question1[i].ans[j].pos.y, 30, BLACK);
						break;
					}
				}
			}
			if (i == 1 && questionTurn[i]) {
				DrawText(question1[i].question, question1[i].pos.x, question1[i].pos.y, testFontSize, BLACK);
				for (int j = 0; j < 4; j++) {
					switch (j) {
					case 0:
						if ((questionTurn[3] && testfor == TestFor::BRAIN) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[3] || questionTurn[4]) && testfor == TestFor::LUNGS) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[2] || questionTurn[3] || questionTurn[4] || questionTurn[6]) && testfor == TestFor::HEART) ||
							((questionTurn[5] || questionTurn[7]) && testfor == TestFor::REPRODUCTIVE) ||
							((questionTurn[1] || questionTurn[5] || questionTurn[9]) && testfor == TestFor::NERVES) ||
							((questionTurn[6] || questionTurn[8]) && testfor == TestFor::MUSCLE))
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 120 };
						else
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 70 };

						checkBoxPos = { question1[i].pos.x + 10, question1[i].ans[j].pos.y + 15 };
						clickRecPos.x = question1[i].pos.x;
						clickRecPos.y = question1[i].ans[j].pos.y;
						clickRecPos.width = sWidth / 2 + sWidth / 5 + 50;
						if (questionTurn[5] && testfor == TestFor::LIVER)
							clickRecPos.height = 70;
						else
							clickRecPos.height = 30;
						/*DrawRectangleRec(clickRecPos, BLACK);*/
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question1[i].ans[0].checked = true;
							question1[i].ans[1].checked = false;
							question1[i].ans[2].checked = false;
							question1[i].ans[3].checked = false;
						}

						if (question1[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawText(question1[i].ans[j].text, question1[i].ans[j].pos.x, question1[i].ans[j].pos.y, 30, BLACK);
						break;
					case 1:
						if ((questionTurn[3] && testfor == TestFor::BRAIN) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[3] || questionTurn[4]) && testfor == TestFor::LUNGS) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[2] || questionTurn[3] || questionTurn[4] || questionTurn[6]) && testfor == TestFor::HEART) ||
							((questionTurn[5] || questionTurn[7]) && testfor == TestFor::REPRODUCTIVE) ||
							((questionTurn[1] || questionTurn[5] || questionTurn[9]) && testfor == TestFor::NERVES) ||
							((questionTurn[6] || questionTurn[8]) && testfor == TestFor::MUSCLE))
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 170 };
						else if (questionTurn[5] && testfor == TestFor::LIVER)
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 170 };
						else
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 120 };

						checkBoxPos = { question1[i].pos.x + 10, question1[i].ans[j].pos.y + 15 };
						clickRecPos.x = question1[i].pos.x;
						clickRecPos.y = question1[i].ans[j].pos.y;
						clickRecPos.width = sWidth / 2 + sWidth / 5 + 50;
						if (questionTurn[5] && testfor == TestFor::LIVER)
							clickRecPos.height = 70;
						else
							clickRecPos.height = 30;
						/*DrawRectangleRec(clickRecPos, BLACK);*/
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question1[i].ans[0].checked = false;
							question1[i].ans[1].checked = true;
							question1[i].ans[2].checked = false;
							question1[i].ans[3].checked = false;
						}

						if (question1[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawText(question1[i].ans[j].text, question1[i].ans[j].pos.x, question1[i].ans[j].pos.y, 30, BLACK);
						break;
					case 2:
						if ((questionTurn[3] && testfor == TestFor::BRAIN) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[3] || questionTurn[4]) && testfor == TestFor::LUNGS) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[2] || questionTurn[3] || questionTurn[4] || questionTurn[6]) && testfor == TestFor::HEART) ||
							((questionTurn[5] || questionTurn[7]) && testfor == TestFor::REPRODUCTIVE) ||
							((questionTurn[1] || questionTurn[5] || questionTurn[9]) && testfor == TestFor::NERVES) ||
							((questionTurn[6] || questionTurn[8]) && testfor == TestFor::MUSCLE))
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 220 };
						else if (questionTurn[5] && testfor == TestFor::LIVER)
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 270 };
						else
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 170 };

						checkBoxPos = { question1[i].pos.x + 10, question1[i].ans[j].pos.y + 15 };
						clickRecPos.x = question1[i].pos.x;
						clickRecPos.y = question1[i].ans[j].pos.y;
						clickRecPos.width = sWidth / 2 + sWidth / 5 + 50;
						if ((questionTurn[5] && testfor == TestFor::LIVER) || ((questionTurn[4] || questionTurn[5] || questionTurn[6] || questionTurn[7]) && testfor == TestFor::INTESTINES))
							clickRecPos.height = 70;
						else
							clickRecPos.height = 30;
						/*DrawRectangleRec(clickRecPos, BLACK);*/
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question1[i].ans[0].checked = false;
							question1[i].ans[1].checked = false;
							question1[i].ans[2].checked = true;
							question1[i].ans[3].checked = false;
						}

						if (question1[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawText(question1[i].ans[j].text, question1[i].ans[j].pos.x, question1[i].ans[j].pos.y, 30, BLACK);
						break;
					case 3:
						if ((questionTurn[3] && testfor == TestFor::BRAIN) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[3] || questionTurn[4]) && testfor == TestFor::LUNGS) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[2] || questionTurn[3] || questionTurn[4] || questionTurn[6]) && testfor == TestFor::HEART) ||
							((questionTurn[4] || questionTurn[5] || questionTurn[6] || questionTurn[7]) && testfor == TestFor::INTESTINES) ||
							((questionTurn[5] || questionTurn[7]) && testfor == TestFor::REPRODUCTIVE) ||
							((questionTurn[1] || questionTurn[5] || questionTurn[9]) && testfor == TestFor::NERVES) ||
							((questionTurn[6] || questionTurn[8]) && testfor == TestFor::MUSCLE))
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 270 };
						else if (questionTurn[5] && testfor == TestFor::LIVER)
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 370 };
						else
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 220 };

						checkBoxPos = { question1[i].pos.x + 10, question1[i].ans[j].pos.y + 15 };
						clickRecPos.x = question1[i].pos.x;
						clickRecPos.y = question1[i].ans[j].pos.y;
						clickRecPos.width = sWidth / 2 + sWidth / 5 + 50;
						if (questionTurn[5] && testfor == TestFor::LIVER)
							clickRecPos.height = 70;
						else
							clickRecPos.height = 30;
						/*DrawRectangleRec(clickRecPos, BLACK);*/
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question1[i].ans[0].checked = false;
							question1[i].ans[1].checked = false;
							question1[i].ans[2].checked = false;
							question1[i].ans[3].checked = true;
						}

						if (question1[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawText(question1[i].ans[j].text, question1[i].ans[j].pos.x, question1[i].ans[j].pos.y, 30, BLACK);
						break;
					}
				}
			}
			if (i == 2 && questionTurn[i]) {
				DrawText(question1[i].question, question1[i].pos.x, question1[i].pos.y, testFontSize, BLACK);
				for (int j = 0; j < 4; j++) {
					switch (j) {
					case 0:
						if ((questionTurn[3] && testfor == TestFor::BRAIN) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[3] || questionTurn[4]) && testfor == TestFor::LUNGS) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[2] || questionTurn[3] || questionTurn[4] || questionTurn[6]) && testfor == TestFor::HEART) ||
							((questionTurn[5] || questionTurn[7]) && testfor == TestFor::REPRODUCTIVE) ||
							((questionTurn[1] || questionTurn[5] || questionTurn[9]) && testfor == TestFor::NERVES) ||
							((questionTurn[6] || questionTurn[8]) && testfor == TestFor::MUSCLE))
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 120 };
						else
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 70 };

						checkBoxPos = { question1[i].pos.x + 10, question1[i].ans[j].pos.y + 15 };
						clickRecPos.x = question1[i].pos.x;
						clickRecPos.y = question1[i].ans[j].pos.y;
						clickRecPos.width = sWidth / 2 + sWidth / 5 + 50;
						if (questionTurn[5] && testfor == TestFor::LIVER)
							clickRecPos.height = 70;
						else
							clickRecPos.height = 30;
						/*DrawRectangleRec(clickRecPos, BLACK);*/
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question1[i].ans[0].checked = true;
							question1[i].ans[1].checked = false;
							question1[i].ans[2].checked = false;
							question1[i].ans[3].checked = false;
						}

						if (question1[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawText(question1[i].ans[j].text, question1[i].ans[j].pos.x, question1[i].ans[j].pos.y, 30, BLACK);
						break;
					case 1:
						if ((questionTurn[3] && testfor == TestFor::BRAIN) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[3] || questionTurn[4]) && testfor == TestFor::LUNGS) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[2] || questionTurn[3] || questionTurn[4] || questionTurn[6]) && testfor == TestFor::HEART) ||
							((questionTurn[5] || questionTurn[7]) && testfor == TestFor::REPRODUCTIVE) ||
							((questionTurn[1] || questionTurn[5] || questionTurn[9]) && testfor == TestFor::NERVES) ||
							((questionTurn[6] || questionTurn[8]) && testfor == TestFor::MUSCLE))
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 170 };
						else if (questionTurn[5] && testfor == TestFor::LIVER)
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 170 };
						else
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 120 };

						checkBoxPos = { question1[i].pos.x + 10, question1[i].ans[j].pos.y + 15 };
						clickRecPos.x = question1[i].pos.x;
						clickRecPos.y = question1[i].ans[j].pos.y;
						clickRecPos.width = sWidth / 2 + sWidth / 5 + 50;
						if (questionTurn[5] && testfor == TestFor::LIVER)
							clickRecPos.height = 70;
						else
							clickRecPos.height = 30;
						/*DrawRectangleRec(clickRecPos, BLACK);*/
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question1[i].ans[0].checked = false;
							question1[i].ans[1].checked = true;
							question1[i].ans[2].checked = false;
							question1[i].ans[3].checked = false;
						}

						if (question1[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawText(question1[i].ans[j].text, question1[i].ans[j].pos.x, question1[i].ans[j].pos.y, 30, BLACK);
						break;
					case 2:
						if ((questionTurn[3] && testfor == TestFor::BRAIN) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[3] || questionTurn[4]) && testfor == TestFor::LUNGS) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[2] || questionTurn[3] || questionTurn[4] || questionTurn[6]) && testfor == TestFor::HEART) ||
							((questionTurn[5] || questionTurn[7]) && testfor == TestFor::REPRODUCTIVE) ||
							((questionTurn[1] || questionTurn[5] || questionTurn[9]) && testfor == TestFor::NERVES) ||
							((questionTurn[6] || questionTurn[8]) && testfor == TestFor::MUSCLE))
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 220 };
						else if (questionTurn[5] && testfor == TestFor::LIVER)
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 270 };
						else
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 170 };

						checkBoxPos = { question1[i].pos.x + 10, question1[i].ans[j].pos.y + 15 };
						clickRecPos.x = question1[i].pos.x;
						clickRecPos.y = question1[i].ans[j].pos.y;
						clickRecPos.width = sWidth / 2 + sWidth / 5 + 50;
						if ((questionTurn[5] && testfor == TestFor::LIVER) || ((questionTurn[4] || questionTurn[5] || questionTurn[6] || questionTurn[7]) && testfor == TestFor::INTESTINES))
							clickRecPos.height = 70;
						else
							clickRecPos.height = 30;
						/*DrawRectangleRec(clickRecPos, BLACK);*/
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question1[i].ans[0].checked = false;
							question1[i].ans[1].checked = false;
							question1[i].ans[2].checked = true;
							question1[i].ans[3].checked = false;
						}

						if (question1[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawText(question1[i].ans[j].text, question1[i].ans[j].pos.x, question1[i].ans[j].pos.y, 30, BLACK);
						break;
					case 3:
						if ((questionTurn[3] && testfor == TestFor::BRAIN) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[3] || questionTurn[4]) && testfor == TestFor::LUNGS) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[2] || questionTurn[3] || questionTurn[4] || questionTurn[6]) && testfor == TestFor::HEART) ||
							((questionTurn[4] || questionTurn[5] || questionTurn[6] || questionTurn[7]) && testfor == TestFor::INTESTINES) ||
							((questionTurn[5] || questionTurn[7]) && testfor == TestFor::REPRODUCTIVE) ||
							((questionTurn[1] || questionTurn[5] || questionTurn[9]) && testfor == TestFor::NERVES) ||
							((questionTurn[6] || questionTurn[8]) && testfor == TestFor::MUSCLE))
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 270 };
						else if (questionTurn[5] && testfor == TestFor::LIVER)
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 370 };
						else
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 220 };

						checkBoxPos = { question1[i].pos.x + 10, question1[i].ans[j].pos.y + 15 };
						clickRecPos.x = question1[i].pos.x;
						clickRecPos.y = question1[i].ans[j].pos.y;
						clickRecPos.width = sWidth / 2 + sWidth / 5 + 50;
						if (questionTurn[5] && testfor == TestFor::LIVER)
							clickRecPos.height = 70;
						else
							clickRecPos.height = 30;
						/*DrawRectangleRec(clickRecPos, BLACK);*/
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question1[i].ans[0].checked = false;
							question1[i].ans[1].checked = false;
							question1[i].ans[2].checked = false;
							question1[i].ans[3].checked = true;
						}

						if (question1[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawText(question1[i].ans[j].text, question1[i].ans[j].pos.x, question1[i].ans[j].pos.y, 30, BLACK);
						break;
					}
				}
			}
			if (i == 3 && questionTurn[i]) {
				DrawText(question1[i].question, question1[i].pos.x, question1[i].pos.y, testFontSize, BLACK);
				for (int j = 0; j < 4; j++) {
					switch (j) {
					case 0:
						if ((questionTurn[3] && testfor == TestFor::BRAIN) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[3] || questionTurn[4]) && testfor == TestFor::LUNGS) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[2] || questionTurn[3] || questionTurn[4] || questionTurn[6]) && testfor == TestFor::HEART) ||
							((questionTurn[5] || questionTurn[7]) && testfor == TestFor::REPRODUCTIVE) ||
							((questionTurn[1] || questionTurn[5] || questionTurn[9]) && testfor == TestFor::NERVES) ||
							((questionTurn[6] || questionTurn[8]) && testfor == TestFor::MUSCLE))
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 120 };
						else
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 70 };

						checkBoxPos = { question1[i].pos.x + 10, question1[i].ans[j].pos.y + 15 };
						clickRecPos.x = question1[i].pos.x;
						clickRecPos.y = question1[i].ans[j].pos.y;
						clickRecPos.width = sWidth / 2 + sWidth / 5 + 50;
						if (questionTurn[5] && testfor == TestFor::LIVER)
							clickRecPos.height = 70;
						else
							clickRecPos.height = 30;
						/*DrawRectangleRec(clickRecPos, BLACK);*/
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question1[i].ans[0].checked = true;
							question1[i].ans[1].checked = false;
							question1[i].ans[2].checked = false;
							question1[i].ans[3].checked = false;
						}

						if (question1[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawText(question1[i].ans[j].text, question1[i].ans[j].pos.x, question1[i].ans[j].pos.y, 30, BLACK);
						break;
					case 1:
						if ((questionTurn[3] && testfor == TestFor::BRAIN) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[3] || questionTurn[4]) && testfor == TestFor::LUNGS) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[2] || questionTurn[3] || questionTurn[4] || questionTurn[6]) && testfor == TestFor::HEART) ||
							((questionTurn[5] || questionTurn[7]) && testfor == TestFor::REPRODUCTIVE) ||
							((questionTurn[1] || questionTurn[5] || questionTurn[9]) && testfor == TestFor::NERVES) ||
							((questionTurn[6] || questionTurn[8]) && testfor == TestFor::MUSCLE))
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 170 };
						else if (questionTurn[5] && testfor == TestFor::LIVER)
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 170 };
						else
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 120 };

						checkBoxPos = { question1[i].pos.x + 10, question1[i].ans[j].pos.y + 15 };
						clickRecPos.x = question1[i].pos.x;
						clickRecPos.y = question1[i].ans[j].pos.y;
						clickRecPos.width = sWidth / 2 + sWidth / 5 + 50;
						if (questionTurn[5] && testfor == TestFor::LIVER)
							clickRecPos.height = 70;
						else
							clickRecPos.height = 30;
						/*DrawRectangleRec(clickRecPos, BLACK);*/
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question1[i].ans[0].checked = false;
							question1[i].ans[1].checked = true;
							question1[i].ans[2].checked = false;
							question1[i].ans[3].checked = false;
						}

						if (question1[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawText(question1[i].ans[j].text, question1[i].ans[j].pos.x, question1[i].ans[j].pos.y, 30, BLACK);
						break;
					case 2:
						if ((questionTurn[3] && testfor == TestFor::BRAIN) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[3] || questionTurn[4]) && testfor == TestFor::LUNGS) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[2] || questionTurn[3] || questionTurn[4] || questionTurn[6]) && testfor == TestFor::HEART) ||
							((questionTurn[5] || questionTurn[7]) && testfor == TestFor::REPRODUCTIVE) ||
							((questionTurn[1] || questionTurn[5] || questionTurn[9]) && testfor == TestFor::NERVES) ||
							((questionTurn[6] || questionTurn[8]) && testfor == TestFor::MUSCLE))
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 220 };
						else if (questionTurn[5] && testfor == TestFor::LIVER)
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 270 };
						else
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 170 };

						checkBoxPos = { question1[i].pos.x + 10, question1[i].ans[j].pos.y + 15 };
						clickRecPos.x = question1[i].pos.x;
						clickRecPos.y = question1[i].ans[j].pos.y;
						clickRecPos.width = sWidth / 2 + sWidth / 5 + 50;
						if ((questionTurn[5] && testfor == TestFor::LIVER) || ((questionTurn[4] || questionTurn[5] || questionTurn[6] || questionTurn[7]) && testfor == TestFor::INTESTINES))
							clickRecPos.height = 70;
						else
							clickRecPos.height = 30;
						/*DrawRectangleRec(clickRecPos, BLACK);*/
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question1[i].ans[0].checked = false;
							question1[i].ans[1].checked = false;
							question1[i].ans[2].checked = true;
							question1[i].ans[3].checked = false;
						}

						if (question1[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawText(question1[i].ans[j].text, question1[i].ans[j].pos.x, question1[i].ans[j].pos.y, 30, BLACK);
						break;
					case 3:
						if ((questionTurn[3] && testfor == TestFor::BRAIN) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[3] || questionTurn[4]) && testfor == TestFor::LUNGS) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[2] || questionTurn[3] || questionTurn[4] || questionTurn[6]) && testfor == TestFor::HEART) ||
							((questionTurn[4] || questionTurn[5] || questionTurn[6] || questionTurn[7]) && testfor == TestFor::INTESTINES) ||
							((questionTurn[5] || questionTurn[7]) && testfor == TestFor::REPRODUCTIVE) ||
							((questionTurn[1] || questionTurn[5] || questionTurn[9]) && testfor == TestFor::NERVES) ||
							((questionTurn[6] || questionTurn[8]) && testfor == TestFor::MUSCLE))
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 270 };
						else if (questionTurn[5] && testfor == TestFor::LIVER)
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 370 };
						else
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 220 };

						checkBoxPos = { question1[i].pos.x + 10, question1[i].ans[j].pos.y + 15 };
						clickRecPos.x = question1[i].pos.x;
						clickRecPos.y = question1[i].ans[j].pos.y;
						clickRecPos.width = sWidth / 2 + sWidth / 5 + 50;
						if (questionTurn[5] && testfor == TestFor::LIVER)
							clickRecPos.height = 70;
						else
							clickRecPos.height = 30;
						/*DrawRectangleRec(clickRecPos, BLACK);*/
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question1[i].ans[0].checked = false;
							question1[i].ans[1].checked = false;
							question1[i].ans[2].checked = false;
							question1[i].ans[3].checked = true;
						}

						if (question1[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawText(question1[i].ans[j].text, question1[i].ans[j].pos.x, question1[i].ans[j].pos.y, 30, BLACK);
						break;
					}
				}
			}
			if (i == 4 && questionTurn[i]) {
				DrawText(question1[i].question, question1[i].pos.x, question1[i].pos.y, testFontSize, BLACK);
				for (int j = 0; j < 4; j++) {
					switch (j) {
					case 0:
						if ((questionTurn[3] && testfor == TestFor::BRAIN) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[3] || questionTurn[4]) && testfor == TestFor::LUNGS) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[2] || questionTurn[3] || questionTurn[4] || questionTurn[6]) && testfor == TestFor::HEART) ||
							((questionTurn[5] || questionTurn[7]) && testfor == TestFor::REPRODUCTIVE) ||
							((questionTurn[1] || questionTurn[5] || questionTurn[9]) && testfor == TestFor::NERVES) ||
							((questionTurn[6] || questionTurn[8]) && testfor == TestFor::MUSCLE))
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 120 };
						else
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 70 };

						checkBoxPos = { question1[i].pos.x + 10, question1[i].ans[j].pos.y + 15 };
						clickRecPos.x = question1[i].pos.x;
						clickRecPos.y = question1[i].ans[j].pos.y;
						clickRecPos.width = sWidth / 2 + sWidth / 5 + 50;
						if (questionTurn[5] && testfor == TestFor::LIVER)
							clickRecPos.height = 70;
						else
							clickRecPos.height = 30;
						/*DrawRectangleRec(clickRecPos, BLACK);*/
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question1[i].ans[0].checked = true;
							question1[i].ans[1].checked = false;
							question1[i].ans[2].checked = false;
							question1[i].ans[3].checked = false;
						}

						if (question1[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawText(question1[i].ans[j].text, question1[i].ans[j].pos.x, question1[i].ans[j].pos.y, 30, BLACK);
						break;
					case 1:
						if ((questionTurn[3] && testfor == TestFor::BRAIN) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[3] || questionTurn[4]) && testfor == TestFor::LUNGS) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[2] || questionTurn[3] || questionTurn[4] || questionTurn[6]) && testfor == TestFor::HEART) ||
							((questionTurn[5] || questionTurn[7]) && testfor == TestFor::REPRODUCTIVE) ||
							((questionTurn[1] || questionTurn[5] || questionTurn[9]) && testfor == TestFor::NERVES) ||
							((questionTurn[6] || questionTurn[8]) && testfor == TestFor::MUSCLE))
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 170 };
						else if (questionTurn[5] && testfor == TestFor::LIVER)
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 170 };
						else
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 120 };

						checkBoxPos = { question1[i].pos.x + 10, question1[i].ans[j].pos.y + 15 };
						clickRecPos.x = question1[i].pos.x;
						clickRecPos.y = question1[i].ans[j].pos.y;
						clickRecPos.width = sWidth / 2 + sWidth / 5 + 50;
						if (questionTurn[5] && testfor == TestFor::LIVER)
							clickRecPos.height = 70;
						else
							clickRecPos.height = 30;
						/*DrawRectangleRec(clickRecPos, BLACK);*/
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question1[i].ans[0].checked = false;
							question1[i].ans[1].checked = true;
							question1[i].ans[2].checked = false;
							question1[i].ans[3].checked = false;
						}

						if (question1[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawText(question1[i].ans[j].text, question1[i].ans[j].pos.x, question1[i].ans[j].pos.y, 30, BLACK);
						break;
					case 2:
						if ((questionTurn[3] && testfor == TestFor::BRAIN) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[3] || questionTurn[4]) && testfor == TestFor::LUNGS) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[2] || questionTurn[3] || questionTurn[4] || questionTurn[6]) && testfor == TestFor::HEART) ||
							((questionTurn[5] || questionTurn[7]) && testfor == TestFor::REPRODUCTIVE) ||
							((questionTurn[1] || questionTurn[5] || questionTurn[9]) && testfor == TestFor::NERVES) ||
							((questionTurn[6] || questionTurn[8]) && testfor == TestFor::MUSCLE))
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 220 };
						else if (questionTurn[5] && testfor == TestFor::LIVER)
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 270 };
						else
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 170 };

						checkBoxPos = { question1[i].pos.x + 10, question1[i].ans[j].pos.y + 15 };
						clickRecPos.x = question1[i].pos.x;
						clickRecPos.y = question1[i].ans[j].pos.y;
						clickRecPos.width = sWidth / 2 + sWidth / 5 + 50;
						if ((questionTurn[5] && testfor == TestFor::LIVER) || ((questionTurn[4] || questionTurn[5] || questionTurn[6] || questionTurn[7]) && testfor == TestFor::INTESTINES))
							clickRecPos.height = 70;
						else
							clickRecPos.height = 30;
						/*DrawRectangleRec(clickRecPos, BLACK);*/
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question1[i].ans[0].checked = false;
							question1[i].ans[1].checked = false;
							question1[i].ans[2].checked = true;
							question1[i].ans[3].checked = false;
						}

						if (question1[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawText(question1[i].ans[j].text, question1[i].ans[j].pos.x, question1[i].ans[j].pos.y, 30, BLACK);
						break;
					case 3:
						if ((questionTurn[3] && testfor == TestFor::BRAIN) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[3] || questionTurn[4]) && testfor == TestFor::LUNGS) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[2] || questionTurn[3] || questionTurn[4] || questionTurn[6]) && testfor == TestFor::HEART) ||
							((questionTurn[4] || questionTurn[5] || questionTurn[6] || questionTurn[7]) && testfor == TestFor::INTESTINES) ||
							((questionTurn[5] || questionTurn[7]) && testfor == TestFor::REPRODUCTIVE) ||
							((questionTurn[1] || questionTurn[5] || questionTurn[9]) && testfor == TestFor::NERVES) ||
							((questionTurn[6] || questionTurn[8]) && testfor == TestFor::MUSCLE))
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 270 };
						else if (questionTurn[5] && testfor == TestFor::LIVER)
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 370 };
						else
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 220 };

						checkBoxPos = { question1[i].pos.x + 10, question1[i].ans[j].pos.y + 15 };
						clickRecPos.x = question1[i].pos.x;
						clickRecPos.y = question1[i].ans[j].pos.y;
						clickRecPos.width = sWidth / 2 + sWidth / 5 + 50;
						if (questionTurn[5] && testfor == TestFor::LIVER)
							clickRecPos.height = 70;
						else
							clickRecPos.height = 30;
						/*DrawRectangleRec(clickRecPos, BLACK);*/
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question1[i].ans[0].checked = false;
							question1[i].ans[1].checked = false;
							question1[i].ans[2].checked = false;
							question1[i].ans[3].checked = true;
						}

						if (question1[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawText(question1[i].ans[j].text, question1[i].ans[j].pos.x, question1[i].ans[j].pos.y, 30, BLACK);
						break;
					}
				}
			}
			if (i == 5 && questionTurn[i]) {
				DrawText(question1[i].question, question1[i].pos.x, question1[i].pos.y, testFontSize, BLACK);
				for (int j = 0; j < 4; j++) {
					switch (j) {
					case 0:
						if ((questionTurn[3] && testfor == TestFor::BRAIN) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[3] || questionTurn[4]) && testfor == TestFor::LUNGS) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[2] || questionTurn[3] || questionTurn[4] || questionTurn[6]) && testfor == TestFor::HEART) ||
							((questionTurn[5] || questionTurn[7]) && testfor == TestFor::REPRODUCTIVE) ||
							((questionTurn[1] || questionTurn[5] || questionTurn[9]) && testfor == TestFor::NERVES) ||
							((questionTurn[6] || questionTurn[8]) && testfor == TestFor::MUSCLE))
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 120 };
						else
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 70 };

						checkBoxPos = { question1[i].pos.x + 10, question1[i].ans[j].pos.y + 15 };
						clickRecPos.x = question1[i].pos.x;
						clickRecPos.y = question1[i].ans[j].pos.y;
						clickRecPos.width = sWidth / 2 + sWidth / 5 + 50;
						if (questionTurn[5] && testfor == TestFor::LIVER)
							clickRecPos.height = 70;
						else
							clickRecPos.height = 30;
						/*DrawRectangleRec(clickRecPos, BLACK);*/
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question1[i].ans[0].checked = true;
							question1[i].ans[1].checked = false;
							question1[i].ans[2].checked = false;
							question1[i].ans[3].checked = false;
						}

						if (question1[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawText(question1[i].ans[j].text, question1[i].ans[j].pos.x, question1[i].ans[j].pos.y, 30, BLACK);
						break;
					case 1:
						if ((questionTurn[3] && testfor == TestFor::BRAIN) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[3] || questionTurn[4]) && testfor == TestFor::LUNGS) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[2] || questionTurn[3] || questionTurn[4] || questionTurn[6]) && testfor == TestFor::HEART) ||
							((questionTurn[5] || questionTurn[7]) && testfor == TestFor::REPRODUCTIVE) ||
							((questionTurn[1] || questionTurn[5] || questionTurn[9]) && testfor == TestFor::NERVES) ||
							((questionTurn[6] || questionTurn[8]) && testfor == TestFor::MUSCLE))
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 170 };
						else if (questionTurn[5] && testfor == TestFor::LIVER)
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 170 };
						else
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 120 };

						checkBoxPos = { question1[i].pos.x + 10, question1[i].ans[j].pos.y + 15 };
						clickRecPos.x = question1[i].pos.x;
						clickRecPos.y = question1[i].ans[j].pos.y;
						clickRecPos.width = sWidth / 2 + sWidth / 5 + 50;
						if (questionTurn[5] && testfor == TestFor::LIVER)
							clickRecPos.height = 70;
						else
							clickRecPos.height = 30;
						/*DrawRectangleRec(clickRecPos, BLACK);*/
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question1[i].ans[0].checked = false;
							question1[i].ans[1].checked = true;
							question1[i].ans[2].checked = false;
							question1[i].ans[3].checked = false;
						}

						if (question1[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawText(question1[i].ans[j].text, question1[i].ans[j].pos.x, question1[i].ans[j].pos.y, 30, BLACK);
						break;
					case 2:
						if ((questionTurn[3] && testfor == TestFor::BRAIN) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[3] || questionTurn[4]) && testfor == TestFor::LUNGS) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[2] || questionTurn[3] || questionTurn[4] || questionTurn[6]) && testfor == TestFor::HEART) ||
							((questionTurn[5] || questionTurn[7]) && testfor == TestFor::REPRODUCTIVE) ||
							((questionTurn[1] || questionTurn[5] || questionTurn[9]) && testfor == TestFor::NERVES) ||
							((questionTurn[6] || questionTurn[8]) && testfor == TestFor::MUSCLE))
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 220 };
						else if (questionTurn[5] && testfor == TestFor::LIVER)
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 270 };
						else
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 170 };

						checkBoxPos = { question1[i].pos.x + 10, question1[i].ans[j].pos.y + 15 };
						clickRecPos.x = question1[i].pos.x;
						clickRecPos.y = question1[i].ans[j].pos.y;
						clickRecPos.width = sWidth / 2 + sWidth / 5 + 50;
						if ((questionTurn[5] && testfor == TestFor::LIVER) || ((questionTurn[4] || questionTurn[5] || questionTurn[6] || questionTurn[7]) && testfor == TestFor::INTESTINES))
							clickRecPos.height = 70;
						else
							clickRecPos.height = 30;
						/*DrawRectangleRec(clickRecPos, BLACK);*/
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question1[i].ans[0].checked = false;
							question1[i].ans[1].checked = false;
							question1[i].ans[2].checked = true;
							question1[i].ans[3].checked = false;
						}

						if (question1[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawText(question1[i].ans[j].text, question1[i].ans[j].pos.x, question1[i].ans[j].pos.y, 30, BLACK);
						break;
					case 3:
						if ((questionTurn[3] && testfor == TestFor::BRAIN) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[3] || questionTurn[4]) && testfor == TestFor::LUNGS) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[2] || questionTurn[3] || questionTurn[4] || questionTurn[6]) && testfor == TestFor::HEART) ||
							((questionTurn[4] || questionTurn[5] || questionTurn[6] || questionTurn[7]) && testfor == TestFor::INTESTINES) ||
							((questionTurn[5] || questionTurn[7]) && testfor == TestFor::REPRODUCTIVE) ||
							((questionTurn[1] || questionTurn[5] || questionTurn[9]) && testfor == TestFor::NERVES) ||
							((questionTurn[6] || questionTurn[8]) && testfor == TestFor::MUSCLE))
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 270 };
						else if (questionTurn[5] && testfor == TestFor::LIVER)
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 370 };
						else
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 220 };

						checkBoxPos = { question1[i].pos.x + 10, question1[i].ans[j].pos.y + 15 };
						clickRecPos.x = question1[i].pos.x;
						clickRecPos.y = question1[i].ans[j].pos.y;
						clickRecPos.width = sWidth / 2 + sWidth / 5 + 50;
						if (questionTurn[5] && testfor == TestFor::LIVER)
							clickRecPos.height = 70;
						else
							clickRecPos.height = 30;
						/*DrawRectangleRec(clickRecPos, BLACK);*/
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question1[i].ans[0].checked = false;
							question1[i].ans[1].checked = false;
							question1[i].ans[2].checked = false;
							question1[i].ans[3].checked = true;
						}

						if (question1[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawText(question1[i].ans[j].text, question1[i].ans[j].pos.x, question1[i].ans[j].pos.y, 30, BLACK);
						break;
					}
				}
			}
			if (i == 6 && questionTurn[i]) {
				DrawText(question1[i].question, question1[i].pos.x, question1[i].pos.y, testFontSize, BLACK);
				for (int j = 0; j < 4; j++) {
					switch (j) {
					case 0:
						if ((questionTurn[3] && testfor == TestFor::BRAIN) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[3] || questionTurn[4]) && testfor == TestFor::LUNGS) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[2] || questionTurn[3] || questionTurn[4] || questionTurn[6]) && testfor == TestFor::HEART) ||
							((questionTurn[5] || questionTurn[7]) && testfor == TestFor::REPRODUCTIVE) ||
							((questionTurn[1] || questionTurn[5] || questionTurn[9]) && testfor == TestFor::NERVES) ||
							((questionTurn[6] || questionTurn[8]) && testfor == TestFor::MUSCLE))
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 120 };
						else
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 70 };

						checkBoxPos = { question1[i].pos.x + 10, question1[i].ans[j].pos.y + 15 };
						clickRecPos.x = question1[i].pos.x;
						clickRecPos.y = question1[i].ans[j].pos.y;
						clickRecPos.width = sWidth / 2 + sWidth / 5 + 50;
						if (questionTurn[5] && testfor == TestFor::LIVER)
							clickRecPos.height = 70;
						else
							clickRecPos.height = 30;
						/*DrawRectangleRec(clickRecPos, BLACK);*/
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question1[i].ans[0].checked = true;
							question1[i].ans[1].checked = false;
							question1[i].ans[2].checked = false;
							question1[i].ans[3].checked = false;
						}

						if (question1[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawText(question1[i].ans[j].text, question1[i].ans[j].pos.x, question1[i].ans[j].pos.y, 30, BLACK);
						break;
					case 1:
						if ((questionTurn[3] && testfor == TestFor::BRAIN) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[3] || questionTurn[4]) && testfor == TestFor::LUNGS) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[2] || questionTurn[3] || questionTurn[4] || questionTurn[6]) && testfor == TestFor::HEART) ||
							((questionTurn[5] || questionTurn[7]) && testfor == TestFor::REPRODUCTIVE) ||
							((questionTurn[1] || questionTurn[5] || questionTurn[9]) && testfor == TestFor::NERVES) ||
							((questionTurn[6] || questionTurn[8]) && testfor == TestFor::MUSCLE))
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 170 };
						else if (questionTurn[5] && testfor == TestFor::LIVER)
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 170 };
						else
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 120 };

						checkBoxPos = { question1[i].pos.x + 10, question1[i].ans[j].pos.y + 15 };
						clickRecPos.x = question1[i].pos.x;
						clickRecPos.y = question1[i].ans[j].pos.y;
						clickRecPos.width = sWidth / 2 + sWidth / 5 + 50;
						if (questionTurn[5] && testfor == TestFor::LIVER)
							clickRecPos.height = 70;
						else
							clickRecPos.height = 30;
						/*DrawRectangleRec(clickRecPos, BLACK);*/
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question1[i].ans[0].checked = false;
							question1[i].ans[1].checked = true;
							question1[i].ans[2].checked = false;
							question1[i].ans[3].checked = false;
						}

						if (question1[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawText(question1[i].ans[j].text, question1[i].ans[j].pos.x, question1[i].ans[j].pos.y, 30, BLACK);
						break;
					case 2:
						if ((questionTurn[3] && testfor == TestFor::BRAIN) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[3] || questionTurn[4]) && testfor == TestFor::LUNGS) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[2] || questionTurn[3] || questionTurn[4] || questionTurn[6]) && testfor == TestFor::HEART) ||
							((questionTurn[5] || questionTurn[7]) && testfor == TestFor::REPRODUCTIVE) ||
							((questionTurn[1] || questionTurn[5] || questionTurn[9]) && testfor == TestFor::NERVES) ||
							((questionTurn[6] || questionTurn[8]) && testfor == TestFor::MUSCLE))
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 220 };
						else if (questionTurn[5] && testfor == TestFor::LIVER)
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 270 };
						else
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 170 };

						checkBoxPos = { question1[i].pos.x + 10, question1[i].ans[j].pos.y + 15 };
						clickRecPos.x = question1[i].pos.x;
						clickRecPos.y = question1[i].ans[j].pos.y;
						clickRecPos.width = sWidth / 2 + sWidth / 5 + 50;
						if ((questionTurn[5] && testfor == TestFor::LIVER) || ((questionTurn[4] || questionTurn[5] || questionTurn[6] || questionTurn[7]) && testfor == TestFor::INTESTINES))
							clickRecPos.height = 70;
						else
							clickRecPos.height = 30;
						/*DrawRectangleRec(clickRecPos, BLACK);*/
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question1[i].ans[0].checked = false;
							question1[i].ans[1].checked = false;
							question1[i].ans[2].checked = true;
							question1[i].ans[3].checked = false;
						}

						if (question1[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawText(question1[i].ans[j].text, question1[i].ans[j].pos.x, question1[i].ans[j].pos.y, 30, BLACK);
						break;
					case 3:
						if ((questionTurn[3] && testfor == TestFor::BRAIN) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[3] || questionTurn[4]) && testfor == TestFor::LUNGS) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[2] || questionTurn[3] || questionTurn[4] || questionTurn[6]) && testfor == TestFor::HEART) ||
							((questionTurn[4] || questionTurn[5] || questionTurn[6] || questionTurn[7]) && testfor == TestFor::INTESTINES) ||
							((questionTurn[5] || questionTurn[7]) && testfor == TestFor::REPRODUCTIVE) ||
							((questionTurn[1] || questionTurn[5] || questionTurn[9]) && testfor == TestFor::NERVES) ||
							((questionTurn[6] || questionTurn[8]) && testfor == TestFor::MUSCLE))
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 270 };
						else if (questionTurn[5] && testfor == TestFor::LIVER)
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 370 };
						else
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 220 };

						checkBoxPos = { question1[i].pos.x + 10, question1[i].ans[j].pos.y + 15 };
						clickRecPos.x = question1[i].pos.x;
						clickRecPos.y = question1[i].ans[j].pos.y;
						clickRecPos.width = sWidth / 2 + sWidth / 5 + 50;
						if (questionTurn[5] && testfor == TestFor::LIVER)
							clickRecPos.height = 70;
						else
							clickRecPos.height = 30;
						/*DrawRectangleRec(clickRecPos, BLACK);*/
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question1[i].ans[0].checked = false;
							question1[i].ans[1].checked = false;
							question1[i].ans[2].checked = false;
							question1[i].ans[3].checked = true;
						}

						if (question1[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawText(question1[i].ans[j].text, question1[i].ans[j].pos.x, question1[i].ans[j].pos.y, 30, BLACK);
						break;
					}
				}
			}
			if (i == 7 && questionTurn[i]) {
				DrawText(question1[i].question, question1[i].pos.x, question1[i].pos.y, testFontSize, BLACK);
				for (int j = 0; j < 4; j++) {
					switch (j) {
					case 0:
						if ((questionTurn[3] && testfor == TestFor::BRAIN) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[3] || questionTurn[4]) && testfor == TestFor::LUNGS) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[2] || questionTurn[3] || questionTurn[4] || questionTurn[6]) && testfor == TestFor::HEART) ||
							((questionTurn[5] || questionTurn[7]) && testfor == TestFor::REPRODUCTIVE) ||
							((questionTurn[1] || questionTurn[5] || questionTurn[9]) && testfor == TestFor::NERVES) ||
							((questionTurn[6] || questionTurn[8]) && testfor == TestFor::MUSCLE))
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 120 };
						else
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 70 };

						checkBoxPos = { question1[i].pos.x + 10, question1[i].ans[j].pos.y + 15 };
						clickRecPos.x = question1[i].pos.x;
						clickRecPos.y = question1[i].ans[j].pos.y;
						clickRecPos.width = sWidth / 2 + sWidth / 5 + 50;
						if (questionTurn[5] && testfor == TestFor::LIVER)
							clickRecPos.height = 70;
						else
							clickRecPos.height = 30;
						/*DrawRectangleRec(clickRecPos, BLACK);*/
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question1[i].ans[0].checked = true;
							question1[i].ans[1].checked = false;
							question1[i].ans[2].checked = false;
							question1[i].ans[3].checked = false;
						}

						if (question1[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawText(question1[i].ans[j].text, question1[i].ans[j].pos.x, question1[i].ans[j].pos.y, 30, BLACK);
						break;
					case 1:
						if ((questionTurn[3] && testfor == TestFor::BRAIN) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[3] || questionTurn[4]) && testfor == TestFor::LUNGS) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[2] || questionTurn[3] || questionTurn[4] || questionTurn[6]) && testfor == TestFor::HEART) ||
							((questionTurn[5] || questionTurn[7]) && testfor == TestFor::REPRODUCTIVE) ||
							((questionTurn[1] || questionTurn[5] || questionTurn[9]) && testfor == TestFor::NERVES) ||
							((questionTurn[6] || questionTurn[8]) && testfor == TestFor::MUSCLE))
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 170 };
						else if (questionTurn[5] && testfor == TestFor::LIVER)
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 170 };
						else
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 120 };

						checkBoxPos = { question1[i].pos.x + 10, question1[i].ans[j].pos.y + 15 };
						clickRecPos.x = question1[i].pos.x;
						clickRecPos.y = question1[i].ans[j].pos.y;
						clickRecPos.width = sWidth / 2 + sWidth / 5 + 50;
						if (questionTurn[5] && testfor == TestFor::LIVER)
							clickRecPos.height = 70;
						else
							clickRecPos.height = 30;
						/*DrawRectangleRec(clickRecPos, BLACK);*/
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question1[i].ans[0].checked = false;
							question1[i].ans[1].checked = true;
							question1[i].ans[2].checked = false;
							question1[i].ans[3].checked = false;
						}

						if (question1[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawText(question1[i].ans[j].text, question1[i].ans[j].pos.x, question1[i].ans[j].pos.y, 30, BLACK);
						break;
					case 2:
						if ((questionTurn[3] && testfor == TestFor::BRAIN) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[3] || questionTurn[4]) && testfor == TestFor::LUNGS) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[2] || questionTurn[3] || questionTurn[4] || questionTurn[6]) && testfor == TestFor::HEART) ||
							((questionTurn[5] || questionTurn[7]) && testfor == TestFor::REPRODUCTIVE) ||
							((questionTurn[1] || questionTurn[5] || questionTurn[9]) && testfor == TestFor::NERVES) ||
							((questionTurn[6] || questionTurn[8]) && testfor == TestFor::MUSCLE))
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 220 };
						else if (questionTurn[5] && testfor == TestFor::LIVER)
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 270 };
						else
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 170 };

						checkBoxPos = { question1[i].pos.x + 10, question1[i].ans[j].pos.y + 15 };
						clickRecPos.x = question1[i].pos.x;
						clickRecPos.y = question1[i].ans[j].pos.y;
						clickRecPos.width = sWidth / 2 + sWidth / 5 + 50;
						if ((questionTurn[5] && testfor == TestFor::LIVER) || ((questionTurn[4] || questionTurn[5] || questionTurn[6] || questionTurn[7]) && testfor == TestFor::INTESTINES))
							clickRecPos.height = 70;
						else
							clickRecPos.height = 30;
						/*DrawRectangleRec(clickRecPos, BLACK);*/
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question1[i].ans[0].checked = false;
							question1[i].ans[1].checked = false;
							question1[i].ans[2].checked = true;
							question1[i].ans[3].checked = false;
						}

						if (question1[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawText(question1[i].ans[j].text, question1[i].ans[j].pos.x, question1[i].ans[j].pos.y, 30, BLACK);
						break;
					case 3:
						if ((questionTurn[3] && testfor == TestFor::BRAIN) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[3] || questionTurn[4]) && testfor == TestFor::LUNGS) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[2] || questionTurn[3] || questionTurn[4] || questionTurn[6]) && testfor == TestFor::HEART) ||
							((questionTurn[4] || questionTurn[5] || questionTurn[6] || questionTurn[7]) && testfor == TestFor::INTESTINES) ||
							((questionTurn[5] || questionTurn[7]) && testfor == TestFor::REPRODUCTIVE) ||
							((questionTurn[1] || questionTurn[5] || questionTurn[9]) && testfor == TestFor::NERVES) ||
							((questionTurn[6] || questionTurn[8]) && testfor == TestFor::MUSCLE))
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 270 };
						else if (questionTurn[5] && testfor == TestFor::LIVER)
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 370 };
						else
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 220 };

						checkBoxPos = { question1[i].pos.x + 10, question1[i].ans[j].pos.y + 15 };
						clickRecPos.x = question1[i].pos.x;
						clickRecPos.y = question1[i].ans[j].pos.y;
						clickRecPos.width = sWidth / 2 + sWidth / 5 + 50;
						if (questionTurn[5] && testfor == TestFor::LIVER)
							clickRecPos.height = 70;
						else
							clickRecPos.height = 30;
						/*DrawRectangleRec(clickRecPos, BLACK);*/
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question1[i].ans[0].checked = false;
							question1[i].ans[1].checked = false;
							question1[i].ans[2].checked = false;
							question1[i].ans[3].checked = true;
						}

						if (question1[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawText(question1[i].ans[j].text, question1[i].ans[j].pos.x, question1[i].ans[j].pos.y, 30, BLACK);
						break;
					}
				}
			}
			if (i == 8 && questionTurn[i]) {
				DrawText(question1[i].question, question1[i].pos.x, question1[i].pos.y, testFontSize, BLACK);
				for (int j = 0; j < 4; j++) {
					switch (j) {
					case 0:
						if ((questionTurn[3] && testfor == TestFor::BRAIN) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[3] || questionTurn[4]) && testfor == TestFor::LUNGS) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[2] || questionTurn[3] || questionTurn[4] || questionTurn[6]) && testfor == TestFor::HEART) ||
							((questionTurn[5] || questionTurn[7]) && testfor == TestFor::REPRODUCTIVE) ||
							((questionTurn[1] || questionTurn[5] || questionTurn[9]) && testfor == TestFor::NERVES) ||
							((questionTurn[6] || questionTurn[8]) && testfor == TestFor::MUSCLE))
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 120 };
						else
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 70 };

						checkBoxPos = { question1[i].pos.x + 10, question1[i].ans[j].pos.y + 15 };
						clickRecPos.x = question1[i].pos.x;
						clickRecPos.y = question1[i].ans[j].pos.y;
						clickRecPos.width = sWidth / 2 + sWidth / 5 + 50;
						if (questionTurn[5] && testfor == TestFor::LIVER)
							clickRecPos.height = 70;
						else
							clickRecPos.height = 30;
						/*DrawRectangleRec(clickRecPos, BLACK);*/
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question1[i].ans[0].checked = true;
							question1[i].ans[1].checked = false;
							question1[i].ans[2].checked = false;
							question1[i].ans[3].checked = false;
						}

						if (question1[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawText(question1[i].ans[j].text, question1[i].ans[j].pos.x, question1[i].ans[j].pos.y, 30, BLACK);
						break;
					case 1:
						if ((questionTurn[3] && testfor == TestFor::BRAIN) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[3] || questionTurn[4]) && testfor == TestFor::LUNGS) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[2] || questionTurn[3] || questionTurn[4] || questionTurn[6]) && testfor == TestFor::HEART) ||
							((questionTurn[5] || questionTurn[7]) && testfor == TestFor::REPRODUCTIVE) ||
							((questionTurn[1] || questionTurn[5] || questionTurn[9]) && testfor == TestFor::NERVES) ||
							((questionTurn[6] || questionTurn[8]) && testfor == TestFor::MUSCLE))
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 170 };
						else if (questionTurn[5] && testfor == TestFor::LIVER)
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 170 };
						else
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 120 };

						checkBoxPos = { question1[i].pos.x + 10, question1[i].ans[j].pos.y + 15 };
						clickRecPos.x = question1[i].pos.x;
						clickRecPos.y = question1[i].ans[j].pos.y;
						clickRecPos.width = sWidth / 2 + sWidth / 5 + 50;
						if (questionTurn[5] && testfor == TestFor::LIVER)
							clickRecPos.height = 70;
						else
							clickRecPos.height = 30;
						/*DrawRectangleRec(clickRecPos, BLACK);*/
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question1[i].ans[0].checked = false;
							question1[i].ans[1].checked = true;
							question1[i].ans[2].checked = false;
							question1[i].ans[3].checked = false;
						}

						if (question1[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawText(question1[i].ans[j].text, question1[i].ans[j].pos.x, question1[i].ans[j].pos.y, 30, BLACK);
						break;
					case 2:
						if ((questionTurn[3] && testfor == TestFor::BRAIN) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[3] || questionTurn[4]) && testfor == TestFor::LUNGS) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[2] || questionTurn[3] || questionTurn[4] || questionTurn[6]) && testfor == TestFor::HEART) ||
							((questionTurn[5] || questionTurn[7]) && testfor == TestFor::REPRODUCTIVE) ||
							((questionTurn[1] || questionTurn[5] || questionTurn[9]) && testfor == TestFor::NERVES) ||
							((questionTurn[6] || questionTurn[8]) && testfor == TestFor::MUSCLE))
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 220 };
						else if (questionTurn[5] && testfor == TestFor::LIVER)
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 270 };
						else
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 170 };

						checkBoxPos = { question1[i].pos.x + 10, question1[i].ans[j].pos.y + 15 };
						clickRecPos.x = question1[i].pos.x;
						clickRecPos.y = question1[i].ans[j].pos.y;
						clickRecPos.width = sWidth / 2 + sWidth / 5 + 50;
						if ((questionTurn[5] && testfor == TestFor::LIVER) || ((questionTurn[4] || questionTurn[5] || questionTurn[6] || questionTurn[7]) && testfor == TestFor::INTESTINES))
							clickRecPos.height = 70;
						else
							clickRecPos.height = 30;
						/*DrawRectangleRec(clickRecPos, BLACK);*/
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question1[i].ans[0].checked = false;
							question1[i].ans[1].checked = false;
							question1[i].ans[2].checked = true;
							question1[i].ans[3].checked = false;
						}

						if (question1[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawText(question1[i].ans[j].text, question1[i].ans[j].pos.x, question1[i].ans[j].pos.y, 30, BLACK);
						break;
					case 3:
						if ((questionTurn[3] && testfor == TestFor::BRAIN) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[3] || questionTurn[4]) && testfor == TestFor::LUNGS) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[2] || questionTurn[3] || questionTurn[4] || questionTurn[6]) && testfor == TestFor::HEART) ||
							((questionTurn[4] || questionTurn[5] || questionTurn[6] || questionTurn[7]) && testfor == TestFor::INTESTINES) ||
							((questionTurn[5] || questionTurn[7]) && testfor == TestFor::REPRODUCTIVE) ||
							((questionTurn[1] || questionTurn[5] || questionTurn[9]) && testfor == TestFor::NERVES) ||
							((questionTurn[6] || questionTurn[8]) && testfor == TestFor::MUSCLE))
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 270 };
						else if (questionTurn[5] && testfor == TestFor::LIVER)
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 370 };
						else
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 220 };

						checkBoxPos = { question1[i].pos.x + 10, question1[i].ans[j].pos.y + 15 };
						clickRecPos.x = question1[i].pos.x;
						clickRecPos.y = question1[i].ans[j].pos.y;
						clickRecPos.width = sWidth / 2 + sWidth / 5 + 50;
						if (questionTurn[5] && testfor == TestFor::LIVER)
							clickRecPos.height = 70;
						else
							clickRecPos.height = 30;
						/*DrawRectangleRec(clickRecPos, BLACK);*/
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question1[i].ans[0].checked = false;
							question1[i].ans[1].checked = false;
							question1[i].ans[2].checked = false;
							question1[i].ans[3].checked = true;
						}

						if (question1[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawText(question1[i].ans[j].text, question1[i].ans[j].pos.x, question1[i].ans[j].pos.y, 30, BLACK);
						break;
					}
				}
			}
			if (i == 9 && questionTurn[i]) {
				DrawText(question1[i].question, question1[i].pos.x, question1[i].pos.y, testFontSize, BLACK);
				for (int j = 0; j < 4; j++) {
					switch (j) {
					case 0:
						if ((questionTurn[3] && testfor == TestFor::BRAIN) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[3] || questionTurn[4]) && testfor == TestFor::LUNGS) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[2] || questionTurn[3] || questionTurn[4] || questionTurn[6]) && testfor == TestFor::HEART) ||
							((questionTurn[5] || questionTurn[7]) && testfor == TestFor::REPRODUCTIVE) ||
							((questionTurn[1] || questionTurn[5] || questionTurn[9]) && testfor == TestFor::NERVES) ||
							((questionTurn[6] || questionTurn[8]) && testfor == TestFor::MUSCLE))
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 120 };
						else
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 70 };

						checkBoxPos = { question1[i].pos.x + 10, question1[i].ans[j].pos.y + 15 };
						clickRecPos.x = question1[i].pos.x;
						clickRecPos.y = question1[i].ans[j].pos.y;
						clickRecPos.width = sWidth / 2 + sWidth / 5 + 50;
						if (questionTurn[5] && testfor == TestFor::LIVER)
							clickRecPos.height = 70;
						else
							clickRecPos.height = 30;
						/*DrawRectangleRec(clickRecPos, BLACK);*/
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question1[i].ans[0].checked = true;
							question1[i].ans[1].checked = false;
							question1[i].ans[2].checked = false;
							question1[i].ans[3].checked = false;
						}

						if (question1[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawText(question1[i].ans[j].text, question1[i].ans[j].pos.x, question1[i].ans[j].pos.y, 30, BLACK);
						break;
					case 1:
						if ((questionTurn[3] && testfor == TestFor::BRAIN) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[3] || questionTurn[4]) && testfor == TestFor::LUNGS) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[2] || questionTurn[3] || questionTurn[4] || questionTurn[6]) && testfor == TestFor::HEART) ||
							((questionTurn[5] || questionTurn[7]) && testfor == TestFor::REPRODUCTIVE) ||
							((questionTurn[1] || questionTurn[5] || questionTurn[9]) && testfor == TestFor::NERVES) ||
							((questionTurn[6] || questionTurn[8]) && testfor == TestFor::MUSCLE))
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 170 };
						else if (questionTurn[5] && testfor == TestFor::LIVER)
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 170 };
						else
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 120 };

						checkBoxPos = { question1[i].pos.x + 10, question1[i].ans[j].pos.y + 15 };
						clickRecPos.x = question1[i].pos.x;
						clickRecPos.y = question1[i].ans[j].pos.y;
						clickRecPos.width = sWidth / 2 + sWidth / 5 + 50;
						if (questionTurn[5] && testfor == TestFor::LIVER)
							clickRecPos.height = 70;
						else
							clickRecPos.height = 30;
						/*DrawRectangleRec(clickRecPos, BLACK);*/
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question1[i].ans[0].checked = false;
							question1[i].ans[1].checked = true;
							question1[i].ans[2].checked = false;
							question1[i].ans[3].checked = false;
						}

						if (question1[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawText(question1[i].ans[j].text, question1[i].ans[j].pos.x, question1[i].ans[j].pos.y, 30, BLACK);
						break;
					case 2:
						if ((questionTurn[3] && testfor == TestFor::BRAIN) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[3] || questionTurn[4]) && testfor == TestFor::LUNGS) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[2] || questionTurn[3] || questionTurn[4] || questionTurn[6]) && testfor == TestFor::HEART) ||
							((questionTurn[5] || questionTurn[7]) && testfor == TestFor::REPRODUCTIVE) ||
							((questionTurn[1] || questionTurn[5] || questionTurn[9]) && testfor == TestFor::NERVES) ||
							((questionTurn[6] || questionTurn[8]) && testfor == TestFor::MUSCLE))
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 220 };
						else if (questionTurn[5] && testfor == TestFor::LIVER)
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 270 };
						else
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 170 };

						checkBoxPos = { question1[i].pos.x + 10, question1[i].ans[j].pos.y + 15 };
						clickRecPos.x = question1[i].pos.x;
						clickRecPos.y = question1[i].ans[j].pos.y;
						clickRecPos.width = sWidth / 2 + sWidth / 5 + 50;
						if ((questionTurn[5] && testfor == TestFor::LIVER) || ((questionTurn[4] || questionTurn[5] || questionTurn[6] || questionTurn[7]) && testfor == TestFor::INTESTINES))
							clickRecPos.height = 70;
						else
							clickRecPos.height = 30;
						/*DrawRectangleRec(clickRecPos, BLACK);*/
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question1[i].ans[0].checked = false;
							question1[i].ans[1].checked = false;
							question1[i].ans[2].checked = true;
							question1[i].ans[3].checked = false;
						}

						if (question1[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawText(question1[i].ans[j].text, question1[i].ans[j].pos.x, question1[i].ans[j].pos.y, 30, BLACK);
						break;
					case 3:
						if ((questionTurn[3] && testfor == TestFor::BRAIN) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[3] || questionTurn[4]) && testfor == TestFor::LUNGS) ||
							((questionTurn[0] || questionTurn[1] || questionTurn[2] || questionTurn[3] || questionTurn[4] || questionTurn[6]) && testfor == TestFor::HEART) ||
							((questionTurn[4] || questionTurn[5] || questionTurn[6] || questionTurn[7]) && testfor == TestFor::INTESTINES) ||
							((questionTurn[5] || questionTurn[7]) && testfor == TestFor::REPRODUCTIVE) ||
							((questionTurn[1] || questionTurn[5] || questionTurn[9]) && testfor == TestFor::NERVES) ||
							((questionTurn[6] || questionTurn[8]) && testfor == TestFor::MUSCLE))
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 270 };
						else if (questionTurn[5] && testfor == TestFor::LIVER)
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 370 };
						else
							question1[i].ans[j].pos = { question1[i].pos.x + 30, question1[i].pos.y + 220 };

						checkBoxPos = { question1[i].pos.x + 10, question1[i].ans[j].pos.y + 15 };
						clickRecPos.x = question1[i].pos.x;
						clickRecPos.y = question1[i].ans[j].pos.y;
						clickRecPos.width = sWidth / 2 + sWidth / 5 + 50;
						if (questionTurn[5] && testfor == TestFor::LIVER)
							clickRecPos.height = 70;
						else
							clickRecPos.height = 30;
						/*DrawRectangleRec(clickRecPos, BLACK);*/
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question1[i].ans[0].checked = false;
							question1[i].ans[1].checked = false;
							question1[i].ans[2].checked = false;
							question1[i].ans[3].checked = true;
						}

						if (question1[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawText(question1[i].ans[j].text, question1[i].ans[j].pos.x, question1[i].ans[j].pos.y, 30, BLACK);
						break;
					}
				}
			}
		}
	
		drawTestButtons();
		drawQuestionNum(sWidth / 2 - sWidth / 45 * 7, sHeight - 75, question1);
	}
	else drawAlertForEnd();
}

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
void Body::testBtn(float posX, float posY, TestFor test) {
	testBTN.bounds = { posX, posY, 125, 40 };
	testBTN.rounding = 1;
	testBTN.hovering = CheckCollisionPointRec(GetMousePosition(), testBTN.bounds);
	testBTN.text = "Test";
	testBTN.color = GRAY;

	if (testBTN.hovering) testBTN.color = DARKGRAY;
	DrawRectangleRounded(testBTN.bounds, testBTN.rounding, testBTN.rounding, testBTN.color);
	DrawText(testBTN.text, testBTN.bounds.x + testBTN.bounds.width / 2 - MeasureText(testBTN.text, 20) / 2, testBTN.bounds.y + 11, 20, BLACK);
	if (testBTN.hovering && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		inTest = true;
		testfor = test;
	}
}
void Body::organsBtn() {
	brainBTN.bounds = { sWidth / 2 - body.width / 4 + 350,  sHeight / 2 - 300, 175, 45 };
	brainBTN.rounding = 1;
	brainBTN.hovering = CheckCollisionPointRec(GetMousePosition(), brainBTN.bounds);
	brainBTN.text = "Brain";
	brainBTN.color = GRAY;

	if (brainBTN.hovering) brainBTN.color = DARKGRAY;
	DrawRectangleRounded(brainBTN.bounds, brainBTN.rounding, brainBTN.rounding, brainBTN.color);
	DrawText(brainBTN.text, brainBTN.bounds.x + brainBTN.bounds.width / 2 - MeasureText(brainBTN.text, 20) / 2, brainBTN.bounds.y + 11, 22, BLACK);

	lungsBTN.bounds = { sWidth / 2 - body.width / 4 + 350,  sHeight / 2 - 250, 175, 45 };
	lungsBTN.rounding = 1;
	lungsBTN.hovering = CheckCollisionPointRec(GetMousePosition(), lungsBTN.bounds);
	lungsBTN.text = "Lungs";
	lungsBTN.color = GRAY;

	if (lungsBTN.hovering) lungsBTN.color = DARKGRAY;
	DrawRectangleRounded(lungsBTN.bounds, lungsBTN.rounding, lungsBTN.rounding, lungsBTN.color);
	DrawText(lungsBTN.text, lungsBTN.bounds.x + lungsBTN.bounds.width / 2 - MeasureText(lungsBTN.text, 20) / 2, lungsBTN.bounds.y + 11, 22, BLACK);

	heartBTN.bounds = { sWidth / 2 - body.width / 4 + 350,  sHeight / 2 - 200, 175, 45 };
	heartBTN.rounding = 1;
	heartBTN.hovering = CheckCollisionPointRec(GetMousePosition(), heartBTN.bounds);
	heartBTN.text = "Heart";
	heartBTN.color = GRAY;

	if (heartBTN.hovering) heartBTN.color = DARKGRAY;
	DrawRectangleRounded(heartBTN.bounds, heartBTN.rounding, heartBTN.rounding, heartBTN.color);
	DrawText(heartBTN.text, heartBTN.bounds.x + heartBTN.bounds.width / 2 - MeasureText(heartBTN.text, 20) / 2, heartBTN.bounds.y + 11, 22, BLACK);

	liverBTN.bounds = { sWidth / 2 - body.width / 4 + 350,  sHeight / 2 - 150, 175, 45 };
	liverBTN.rounding = 1;
	liverBTN.hovering = CheckCollisionPointRec(GetMousePosition(), liverBTN.bounds);
	liverBTN.text = "Liver";
	liverBTN.color = GRAY;

	if (liverBTN.hovering) liverBTN.color = DARKGRAY;
	DrawRectangleRounded(liverBTN.bounds, liverBTN.rounding, liverBTN.rounding, liverBTN.color);
	DrawText(liverBTN.text, liverBTN.bounds.x + liverBTN.bounds.width / 2 - MeasureText(liverBTN.text, 20) / 2, liverBTN.bounds.y + 11, 22, BLACK);

	kidneyBTN.bounds = { sWidth / 2 - body.width / 4 + 350,  sHeight / 2 - 100, 175, 45 };
	kidneyBTN.rounding = 1;
	kidneyBTN.hovering = CheckCollisionPointRec(GetMousePosition(), kidneyBTN.bounds);
	kidneyBTN.text = "Kidney";
	kidneyBTN.color = GRAY;

	if (kidneyBTN.hovering) kidneyBTN.color = DARKGRAY;
	DrawRectangleRounded(kidneyBTN.bounds, kidneyBTN.rounding, kidneyBTN.rounding, kidneyBTN.color);
	DrawText(kidneyBTN.text, kidneyBTN.bounds.x + kidneyBTN.bounds.width / 2 - MeasureText(kidneyBTN.text, 20) / 2, kidneyBTN.bounds.y + 11, 22, BLACK);

	stomachBTN.bounds = { sWidth / 2 - body.width / 4 + 350,  sHeight / 2 - 50, 175, 45 };
	stomachBTN.rounding = 1;
	stomachBTN.hovering = CheckCollisionPointRec(GetMousePosition(), stomachBTN.bounds);
	stomachBTN.text = "Stomach";
	stomachBTN.color = GRAY;

	if (stomachBTN.hovering) stomachBTN.color = DARKGRAY;
	DrawRectangleRounded(stomachBTN.bounds, stomachBTN.rounding, stomachBTN.rounding, stomachBTN.color);
	DrawText(stomachBTN.text, stomachBTN.bounds.x + stomachBTN.bounds.width / 2 - MeasureText(stomachBTN.text, 20) / 2, stomachBTN.bounds.y + 11, 22, BLACK);

	intestinesBTN.bounds = { sWidth / 2 - body.width / 4 + 350,  sHeight / 2 , 175, 45 };
	intestinesBTN.rounding = 1;
	intestinesBTN.hovering = CheckCollisionPointRec(GetMousePosition(), intestinesBTN.bounds);
	intestinesBTN.text = "Intestines";
	intestinesBTN.color = GRAY;

	if (intestinesBTN.hovering) intestinesBTN.color = DARKGRAY;
	DrawRectangleRounded(intestinesBTN.bounds, intestinesBTN.rounding, intestinesBTN.rounding, intestinesBTN.color);
	DrawText(intestinesBTN.text, intestinesBTN.bounds.x + intestinesBTN.bounds.width / 2 - MeasureText(intestinesBTN.text, 20) / 2, intestinesBTN.bounds.y + 11, 22, BLACK);

	reproductiveSMBTN.bounds = { sWidth / 2 - body.width / 4 + 300,  sHeight / 2 + 50, 290, 45 };
	reproductiveSMBTN.rounding = 1;
	reproductiveSMBTN.hovering = CheckCollisionPointRec(GetMousePosition(), reproductiveSMBTN.bounds);
	reproductiveSMBTN.text = "Reproductive system";
	reproductiveSMBTN.color = GRAY;

	if (reproductiveSMBTN.hovering) reproductiveSMBTN.color = DARKGRAY;
	DrawRectangleRounded(reproductiveSMBTN.bounds, reproductiveSMBTN.rounding, reproductiveSMBTN.rounding, reproductiveSMBTN.color);
	DrawText(reproductiveSMBTN.text, reproductiveSMBTN.bounds.x + reproductiveSMBTN.bounds.width / 2 - MeasureText(reproductiveSMBTN.text, 20) / 2 - 5, reproductiveSMBTN.bounds.y + 11, 22, BLACK);

	nervesBTN.bounds = { sWidth / 2 - body.width / 4 + 350,  sHeight / 2 + 100, 175, 45 };
	nervesBTN.rounding = 1;
	nervesBTN.hovering = CheckCollisionPointRec(GetMousePosition(), nervesBTN.bounds);
	nervesBTN.text = "Nerves";
	nervesBTN.color = GRAY;

	if (nervesBTN.hovering) nervesBTN.color = DARKGRAY;
	DrawRectangleRounded(nervesBTN.bounds, nervesBTN.rounding, nervesBTN.rounding, nervesBTN.color);
	DrawText(nervesBTN.text, nervesBTN.bounds.x + nervesBTN.bounds.width / 2 - MeasureText(nervesBTN.text, 20) / 2, nervesBTN.bounds.y + 11, 22, BLACK);

	muscleBTN.bounds = { sWidth / 2 - body.width / 4 + 350,  sHeight / 2 + 150, 175, 45 };
	muscleBTN.rounding = 1;
	muscleBTN.hovering = CheckCollisionPointRec(GetMousePosition(), muscleBTN.bounds);
	muscleBTN.text = "Muscles";
	muscleBTN.color = GRAY;

	if (muscleBTN.hovering) muscleBTN.color = DARKGRAY;
	DrawRectangleRounded(muscleBTN.bounds, muscleBTN.rounding, muscleBTN.rounding, muscleBTN.color);
	DrawText(muscleBTN.text, muscleBTN.bounds.x + muscleBTN.bounds.width / 2 - MeasureText(muscleBTN.text, 20) / 2, muscleBTN.bounds.y + 11, 22, BLACK);

	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		if (brainBTN.hovering) {
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
		else if (lungsBTN.hovering) {
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
		else if (heartBTN.hovering) {
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
		else if (liverBTN.hovering) {
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
		else if (kidneyBTN.hovering) {
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
		else if (stomachBTN.hovering) {
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
		else if (intestinesBTN.hovering) {
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
		else if (reproductiveSMBTN.hovering) {
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
		else if (nervesBTN.hovering) {
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
		else if (muscleBTN.hovering) {
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

void Body::drawBrain() {

	DrawRectangleRec(brainRec, BLANK);
	if(lungsIsActive || liverIsActive || heartIsActive || kidneyIsActive || stomachIsActive || intestinesIsActive || reproductiveSMIsActive || nervesIsActive || muscleIsActive && !brainIsActive)
		DrawTexture(brain, brainPos.x, brainPos.y, GRAY);
	else
		DrawTexture(brain, brainPos.x, brainPos.y, WHITE);

	if (brainIsActive) {
        DrawText(brainInfo, infoPos.x, infoPos.y, fontSize, BLACK);
		cancelBtn(sWidth / 2 - body.width - 55, sHeight / 2 + body.height / 4 - 60);
		testBtn(sWidth / 2 - body.width + 75, sHeight / 2 + body.height / 4 - 60, TestFor::BRAIN);
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
		cancelBtn(sWidth / 2 - body.width - 55, sHeight / 2 + body.height / 5 - 100);
		testBtn(sWidth / 2 - body.width + 75, sHeight / 2 + body.height / 5 - 100, TestFor::LUNGS);
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
		cancelBtn(sWidth / 2 - body.width - 55, sHeight / 2 + body.height / 7 - 100);
		testBtn(sWidth / 2 - body.width + 75, sHeight / 2 + body.height / 7 - 100, TestFor::LIVER);
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
		cancelBtn(sWidth / 2 - body.width - 55, sHeight / 2 + body.height / 6 - 100);
		testBtn(sWidth / 2 - body.width + 75, sHeight / 2 + body.height / 6 - 100, TestFor::HEART);
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
		cancelBtn(sWidth / 2 - body.width - 10, sHeight / 2 + body.height / 2 - 100);
		testBtn(sWidth / 2 - body.width + 120, sHeight / 2 + body.height / 2 - 100, TestFor::KIDNEY);
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
		cancelBtn(sWidth / 2 - body.width - 55, sHeight / 2 + body.height / 2 - 130);
		testBtn(sWidth / 2 - body.width + 75, sHeight / 2 + body.height / 2 - 130, TestFor::STOMACH);
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
		cancelBtn(sWidth / 2 - body.width - 55, sHeight / 2 + body.height / 4 - 120);
		testBtn(sWidth / 2 - body.width + 75, sHeight / 2 + body.height / 4 - 120, TestFor::INTESTINES);
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
		cancelBtn(sWidth / 2 - body.width - 55, sHeight / 2 + body.height / 3 - 80);
		testBtn(sWidth / 2 - body.width + 75, sHeight / 2 + body.height / 3 - 80, TestFor::REPRODUCTIVE);
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
		cancelBtn(sWidth / 2 - body.width - 55, sHeight / 2 + body.height / 5 - 70);
		testBtn(sWidth / 2 - body.width + 75, sHeight / 2 + body.height / 5 - 70, TestFor::NERVES);
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
		cancelBtn(sWidth / 2 - body.width - 55, sHeight / 2 + body.height / 3 + 10);
		testBtn(sWidth / 2 - body.width + 75, sHeight / 2 + body.height / 3 + 10, TestFor::MUSCLE);
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
	if (!inTest) {
		DrawTexture(body, bodyPos.x, bodyPos.y, WHITE);

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

		organsBtn();
	}
	else {
		switch (Body::testfor)
		{
		case Body::TestFor::BRAIN:
			questions[0].Questions::question = "What is the primary function of the brain?";
			questions[0].Questions::currectAns = 0;
			questions[0].Questions::ans[0].text = "To control bodily functions";
			questions[0].Questions::ans[1].text = "To pump blood";
			questions[0].Questions::ans[2].text = "To digest food";
			questions[0].Questions::ans[3].text = "To regulate body temperature";
			questions[1].Questions::question = "How many neurons are in the brain?";
			questions[1].Questions::currectAns = 2;
			questions[1].Questions::ans[0].text = "1 billion";
			questions[1].Questions::ans[1].text = "10 billion";
			questions[1].Questions::ans[2].text = "100 billion";
			questions[1].Questions::ans[3].text = "1 000 billion";
			questions[2].Questions::question = "What is the function of synapses in the brain?";
			questions[2].Questions::currectAns = 1;
			questions[2].Questions::ans[0].text = "To control bodily functions";
			questions[2].Questions::ans[1].text = "To form complex networks";
			questions[2].Questions::ans[2].text = "To digest food";
			questions[2].Questions::ans[3].text = "To regulate body temperature";
			questions[3].Questions::question = "Which of the following is a degenerative disorder that affects movement, balance\nand coordination?";
			questions[3].Questions::currectAns = 1;
			questions[3].Questions::ans[0].text = "Alzheimer's disease";
			questions[3].Questions::ans[1].text = "Parkinson's disease";
			questions[3].Questions::ans[2].text = "Multiple sclerosis";
			questions[3].Questions::ans[3].text = "Epilepsy";
			questions[4].Questions::question = "Which of the following is a type of headache that can be debilitating and recurring";
			questions[4].Questions::currectAns = 3;
			questions[4].Questions::ans[0].text = "Alzheimer's disease";
			questions[4].Questions::ans[1].text = "Parkinson's disease";
			questions[4].Questions::ans[2].text = "Multiple sclerosis";
			questions[4].Questions::ans[3].text = "Migraines";
			questions[5].Questions::question = "What is traumatic brain injury?";
			questions[5].Questions::currectAns = 3;
			questions[5].Questions::ans[0].text = "A progressive neurodegenerative disease";
			questions[5].Questions::ans[1].text = "A degenerative disorder that affects movement, balance, and coordination";
			questions[5].Questions::ans[2].text = "An autoimmune disease that affects the central nervous system";
			questions[5].Questions::ans[3].text = "An injury resulting from a blow or jolt to the head";
			questions[6].Questions::question = "What is the most common brain disease?";
			questions[6].Questions::currectAns = 0;
			questions[6].Questions::ans[0].text = "Alzheimer's disease";
			questions[6].Questions::ans[1].text = "Parkinson's disease";
			questions[6].Questions::ans[2].text = "Multiple sclerosis";
			questions[6].Questions::ans[3].text = "Epilepsy";
			questions[7].Questions::question = "Which of the following is an autoimmune disease that affects the central nervous system?";
			questions[7].Questions::currectAns = 2;
			questions[7].Questions::ans[0].text = "Alzheimer's disease";
			questions[7].Questions::ans[1].text = "Parkinson's disease";
			questions[7].Questions::ans[2].text = "Multiple sclerosis";
			questions[7].Questions::ans[3].text = "Epilepsy";
			questions[8].Questions::question = "Which of the following is a neurological disorder that causes seizures?";
			questions[8].Questions::currectAns = 3;
			questions[8].Questions::ans[0].text = "Alzheimer's disease";
			questions[8].Questions::ans[1].text = "Parkinson's disease";
			questions[8].Questions::ans[2].text = "Multiple sclerosis";
			questions[8].Questions::ans[3].text = "Epilepsy";
			questions[9].Questions::question = "What are synapses made of?";
			questions[9].Questions::currectAns = 0;
			questions[9].Questions::ans[0].text = "Neurons";
			questions[9].Questions::ans[1].text = "Glial cells";
			questions[9].Questions::ans[2].text = "Dendrites";
			questions[9].Questions::ans[3].text = "Axons";
			break;

		case Body::TestFor::LUNGS:
			questions[0].Questions::question = "What is the name of the chronic lung condition that causes inflammation and narrowing\nof the airways, making it difficult to breathe ? ";
			questions[0].Questions::currectAns = 2;
			questions[0].Questions::ans[0].text = "Pneumonia";
			questions[0].Questions::ans[1].text = "Lung cancer";
			questions[0].Questions::ans[2].text = "Asthma";
			questions[0].Questions::ans[3].text = "Tuberculosis";

			questions[1].Questions::question = "What is the name of the group of lung diseases that make it hard to breathe due to\ndamage to the airways and/or air sacs in the lungs?";
			questions[1].Questions::currectAns = 2;
			questions[1].Questions::ans[0].text = "Asthma";
			questions[1].Questions::ans[1].text = "Lung cancer";
			questions[1].Questions::ans[2].text = "Chronic obstructive pulmonary disease (COPD)";
			questions[1].Questions::ans[3].text = "Tuberculosis";

			questions[2].Questions::question = "What is the name of the lung infection that inflames the air sacs in one or both lungs?";
			questions[2].Questions::currectAns = 2;
			questions[2].Questions::ans[0].text = "Tuberculosis";
			questions[2].Questions::ans[1].text = "Lung cancer";
			questions[2].Questions::ans[2].text = "Pneumonia";
			questions[2].Questions::ans[3].text = "Asthma";

			questions[3].Questions::question = "What is the name of the bacterial infection that primarily affects the lungs but\ncan also affect other parts of the body?";
			questions[3].Questions::currectAns = 2;
			questions[3].Questions::ans[0].text = "Pneumonia";
			questions[3].Questions::ans[1].text = "Asthma";
			questions[3].Questions::ans[2].text = "Tuberculosis";
			questions[3].Questions::ans[3].text = "Lung cancer";

			questions[4].Questions::question = "What is the name of the condition where cells in the lungs grow abnormally and form\ntumors?";
			questions[4].Questions::currectAns = 3;
			questions[4].Questions::ans[0].text = "Asthma";
			questions[4].Questions::ans[1].text = "Tuberculosis";
			questions[4].Questions::ans[2].text = "Pneumonia";
			questions[4].Questions::ans[3].text = "Lung cancer";

			questions[5].Questions::question = "Which of the following is a common symptom of asthma?";
			questions[5].Questions::currectAns = 3;
			questions[5].Questions::ans[0].text = "Coughing";
			questions[5].Questions::ans[1].text = "Wheezing";
			questions[5].Questions::ans[2].text = "Shortness of breath";
			questions[5].Questions::ans[3].text = "All of the above";

			questions[6].Questions::question = "Which of the following is NOT a cause of chronic obstructive pulmonary disease (COPD)?";
			questions[6].Questions::currectAns = 2;
			questions[6].Questions::ans[0].text = "Smoking";
			questions[6].Questions::ans[1].text = "Air pollution";
			questions[6].Questions::ans[2].text = "Allergies";
			questions[6].Questions::ans[3].text = "Occupational exposure to dust and chemicals";

			questions[7].Questions::question = "Which of the following is a common symptom of pneumonia?";
			questions[7].Questions::currectAns = 3;
			questions[7].Questions::ans[0].text = "Chest pain";
			questions[7].Questions::ans[1].text = "Fever";
			questions[7].Questions::ans[2].text = "Fatigue";
			questions[7].Questions::ans[3].text = "All of the above";

			questions[8].Questions::question = "Which of the following is a way to prevent tuberculosis (TB)?";
			questions[8].Questions::currectAns = 3;
			questions[8].Questions::ans[0].text = "Getting vaccinated";
			questions[8].Questions::ans[1].text = "Practicing good hygiene";
			questions[8].Questions::ans[2].text = "Avoiding close contact with people who have TB";
			questions[8].Questions::ans[3].text = "All of the above";

			questions[9].Questions::question = "What is the most common cause of lung cancer?";
			questions[9].Questions::currectAns = 1;
			questions[9].Questions::ans[0].text = "Exposure to asbestos";
			questions[9].Questions::ans[1].text = "Smoking";
			questions[9].Questions::ans[2].text = "Air pollution";
			questions[9].Questions::ans[3].text = "Occupational exposure to chemicals";
			break;

		case Body::TestFor::LIVER:
			questions[0].Questions::question = "What is the function of the liver?";
			questions[0].Questions::currectAns = 1;
			questions[0].Questions::ans[0].text = "Producing insulin";
			questions[0].Questions::ans[1].text = "Filtering blood";
			questions[0].Questions::ans[2].text = "Pumping blood to the heart";
			questions[0].Questions::ans[3].text = "Digesting food";
			questions[1].Questions::question = "What is hepatitis?";
			questions[1].Questions::currectAns = 1;
			questions[1].Questions::ans[0].text = "Inflammation of the kidneys";
			questions[1].Questions::ans[1].text = "Inflammation of the liver";
			questions[1].Questions::ans[2].text = "Inflammation of the lungs";
			questions[1].Questions::ans[3].text = "Inflammation of the brain";
			questions[2].Questions::question = "Which of the following is a common cause of cirrhosis?";
			questions[2].Questions::currectAns = 3;
			questions[2].Questions::ans[0].text = "Viral infection";
			questions[2].Questions::ans[1].text = "Exposure to toxins";
			questions[2].Questions::ans[2].text = "Excessive alcohol consumption";
			questions[2].Questions::ans[3].text = "All of the above";
			questions[3].Questions::question = "What is the main feature of cirrhosis?";
			questions[3].Questions::currectAns = 2;
			questions[3].Questions::ans[0].text = "Fat accumulation in the liver";
			questions[3].Questions::ans[1].text = "Inflammation of the liver";
			questions[3].Questions::ans[2].text = "Formation of scar tissue in the liver";
			questions[3].Questions::ans[3].text = "Destruction of liver cells";
			questions[4].Questions::question = "Which of the following is a risk factor for developing NAFLD?";
			questions[4].Questions::currectAns = 2;
			questions[4].Questions::ans[0].text = "High levels of physical activity";
			questions[4].Questions::ans[1].text = "Low-carbohydrate diet";
			questions[4].Questions::ans[2].text = "Obesity";
			questions[4].Questions::ans[3].text = "All of the above";
			questions[5].Questions::question = "What is the difference between alcoholic and nonalcoholic liver disease?";
			questions[5].Questions::currectAns = 2;
			questions[5].Questions::ans[0].text = "Alcoholic liver disease is caused by drinking too much alcohol, while nonalcoholic liver\ndisease is caused by exposure to toxins.";
			questions[5].Questions::ans[1].text = "Alcoholic liver disease is caused by a virus, while nonalcoholic liver disease is causedny\na genetic mutation.";
			questions[5].Questions::ans[2].text = "Alcoholic liver disease is caused by drinking too much alcohol, while nonalcoholic liver\ndisease is not related to alcohol consumption.";
			questions[5].Questions::ans[3].text = "Alcoholic liver disease is caused by a genetic mutation, while nonalcoholic liver diseasen\nis caused by exposure to toxins.";
			questions[6].Questions::question = "What are the symptoms of liver disease?";
			questions[6].Questions::currectAns = 3;
			questions[6].Questions::ans[0].text = "Nausea and vomiting";
			questions[6].Questions::ans[1].text = "Abdominal pain and swelling";
			questions[6].Questions::ans[2].text = "Fatigue and weakness";
			questions[6].Questions::ans[3].text = "All of the above";
			questions[7].Questions::question = "Which of the following is a preventive measure for liver disease?";
			questions[7].Questions::currectAns = 3;
			questions[7].Questions::ans[0].text = "Limiting alcohol consumption";
			questions[7].Questions::ans[1].text = "Getting vaccinated against hepatitis B and C";
			questions[7].Questions::ans[2].text = "Maintaining a healthy weight";
			questions[7].Questions::ans[3].text = "All of the above";
			questions[8].Questions::question = "What is the treatment for liver disease?";
			questions[8].Questions::currectAns = 3;
			questions[8].Questions::ans[0].text = "Surgery";
			questions[8].Questions::ans[1].text = "Medications";
			questions[8].Questions::ans[2].text = "Lifestyle changes";
			questions[8].Questions::ans[3].text = "All of the above";
			questions[9].Questions::question = "What is the most common cause of liver cancer?";
			questions[9].Questions::currectAns = 0;
			questions[9].Questions::ans[0].text = "Hepatitis B and C";
			questions[9].Questions::ans[1].text = "Smoking";
			questions[9].Questions::ans[2].text = "Obesity";
			questions[9].Questions::ans[3].text = "Genetic mutation";
			break;

		case Body::TestFor::HEART:
			questions[0].Questions::question = "What is the name of the condition where the arteries that supply blood to the heart\nbecome narrowed or blocked?";
			questions[0].Questions::currectAns = 2;
			questions[0].Questions::ans[0].text = "Atherosclerosis";
			questions[0].Questions::ans[1].text = "Arrhythmia";
			questions[0].Questions::ans[2].text = "Coronary artery disease";
			questions[0].Questions::ans[3].text = "Heart valve disease";
			questions[1].Questions::question = "What is the name of the heart rhythm problem that can cause the heart to beat too fast,\ntoo slow, or irregularly?";
			questions[1].Questions::currectAns = 2;
			questions[1].Questions::ans[0].text = "Heart valve disease";
			questions[1].Questions::ans[1].text = "Coronary artery disease";
			questions[1].Questions::ans[2].text = "Arrhythmia";
			questions[1].Questions::ans[3].text = "Atherosclerosis";
			questions[2].Questions::question = "What is the name of the condition where the heart cannot pump enough blood to meet\nthe body's needs?";
			questions[2].Questions::currectAns = 2;
			questions[2].Questions::ans[0].text = "Atherosclerosis";
			questions[2].Questions::ans[1].text = "Heart valve disease";
			questions[2].Questions::ans[2].text = "Heart failure";
			questions[2].Questions::ans[3].text = "Coronary artery disease";
			questions[3].Questions::question = "What is the name of the condition where plaque builds up inside the arteries, causing\nthem to harden and narrow?";
			questions[3].Questions::currectAns = 2;
			questions[3].Questions::ans[0].text = "Heart valve disease";
			questions[3].Questions::ans[1].text = "Coronary artery disease";
			questions[3].Questions::ans[2].text = "Atherosclerosis";
			questions[3].Questions::ans[3].text = "Arrhythmia";
			questions[4].Questions::question = "What is the name of the condition where one or more of the heart valves do not function\nproperly?";
			questions[4].Questions::currectAns = 0;
			questions[4].Questions::ans[0].text = "Heart valve disease";
			questions[4].Questions::ans[1].text = "Coronary artery disease";
			questions[4].Questions::ans[2].text = "Atherosclerosis";
			questions[4].Questions::ans[3].text = "Arrhythmia";
			questions[5].Questions::question = "What is the most common cause of coronary artery disease?";
			questions[5].Questions::currectAns = 3;
			questions[5].Questions::ans[0].text = "Smoking";
			questions[5].Questions::ans[1].text = "High blood pressure";
			questions[5].Questions::ans[2].text = "Lack of exercise";
			questions[5].Questions::ans[3].text = "High cholesterol";
			questions[6].Questions::question = "What is the name of the medical procedure used to treat coronary artery disease by\nopening up narrowed or blocked arteries?";
			questions[6].Questions::currectAns = 2;
			questions[6].Questions::ans[0].text = "Coronary artery bypass graft surgery";
			questions[6].Questions::ans[1].text = "Cardiac catheterization";
			questions[6].Questions::ans[2].text = "Angioplasty";
			questions[6].Questions::ans[3].text = "Stent placement";
			questions[7].Questions::question = "What is the name of the condition where the heart beats too slowly?";
			questions[7].Questions::currectAns = 1;
			questions[7].Questions::ans[0].text = "Tachycardia";
			questions[7].Questions::ans[1].text = "Bradycardia";
			questions[7].Questions::ans[2].text = "Arrhythmia";
			questions[7].Questions::ans[3].text = "Atrial fibrillation";
			questions[8].Questions::question = "Which of the following is a common symptom of heart failure?";
			questions[8].Questions::currectAns = 1;
			questions[8].Questions::ans[0].text = "Chest pain";
			questions[8].Questions::ans[1].text = "Shortness of breath";
			questions[8].Questions::ans[2].text = "Dizziness";
			questions[8].Questions::ans[3].text = "All of the above";
			questions[9].Questions::question = "What is the name of the condition where the heart beats irregularly?";
			questions[9].Questions::currectAns = 1;
			questions[9].Questions::ans[0].text = "Atherosclerosis";
			questions[9].Questions::ans[1].text = "Arrhythmia";
			questions[9].Questions::ans[2].text = "Coronary artery disease";
			questions[9].Questions::ans[3].text = "Heart valve disease";
			break;

		case Body::TestFor::KIDNEY:
			questions[0].Questions::question = "What is the primary function of the kidneys?";
			questions[0].Questions::currectAns = 0;
			questions[0].Questions::ans[0].text = "Produce urine";
			questions[0].Questions::ans[1].text = "Pump blood";
			questions[0].Questions::ans[2].text = "Digest food";
			questions[0].Questions::ans[3].text = "Regulate body temperature";
			questions[1].Questions::question = "What is chronic kidney disease?";
			questions[1].Questions::currectAns = 1;
			questions[1].Questions::ans[0].text = "A condition where the kidneys fail suddenly";
			questions[1].Questions::ans[1].text = "A condition where the kidneys gradually lose function over time";
			questions[1].Questions::ans[2].text = "A condition where the kidneys become enlarged";
			questions[1].Questions::ans[3].text = "A condition where the kidneys produce too much urine";
			questions[2].Questions::question = "What is the most common cause of kidney stones?";
			questions[2].Questions::currectAns = 0;
			questions[2].Questions::ans[0].text = "Dehydration";
			questions[2].Questions::ans[1].text = "Consuming too much calcium";
			questions[2].Questions::ans[2].text = "Consuming too much sodium";
			questions[2].Questions::ans[3].text = "Eating too much sugar";
			questions[3].Questions::question = "Which of the following is NOT a symptom of a urinary tract infection?";
			questions[3].Questions::currectAns = 3;
			questions[3].Questions::ans[0].text = "Painful urination";
			questions[3].Questions::ans[1].text = "Back pain";
			questions[3].Questions::ans[2].text = "Fever";
			questions[3].Questions::ans[3].text = "Headache";
			questions[4].Questions::question = "Which of the following is a risk factor for chronic kidney disease?";
			questions[4].Questions::currectAns = 1;
			questions[4].Questions::ans[0].text = "Drinking plenty of water";
			questions[4].Questions::ans[1].text = "High blood pressure";
			questions[4].Questions::ans[2].text = "Regular exercise";
			questions[4].Questions::ans[3].text = "A diet low in protein";
			questions[5].Questions::question = "What is the most common type of kidney stone?";
			questions[5].Questions::currectAns = 0;
			questions[5].Questions::ans[0].text = "Calcium oxalate";
			questions[5].Questions::ans[1].text = "Uric acid";
			questions[5].Questions::ans[2].text = "Struvite";
			questions[5].Questions::ans[3].text = "Cystine";
			questions[6].Questions::question = "What is the main treatment for kidney failure?";
			questions[6].Questions::currectAns = 0;
			questions[6].Questions::ans[0].text = "Dialysis";
			questions[6].Questions::ans[1].text = "Surgery";
			questions[6].Questions::ans[2].text = "Antibiotics";
			questions[6].Questions::ans[3].text = "Physical therapy";
			questions[7].Questions::question = "What is the function of the nephrons in the kidneys?";
			questions[7].Questions::currectAns = 2;
			questions[7].Questions::ans[0].text = "To produce urine";
			questions[7].Questions::ans[1].text = "To regulate blood pressure";
			questions[7].Questions::ans[2].text = "To filter waste and excess fluids from the blood";
			questions[7].Questions::ans[3].text = "To secrete hormones that regulate metabolism";
			questions[8].Questions::question = "Which of the following is a symptom of chronic kidney disease?";
			questions[8].Questions::currectAns = 1;
			questions[8].Questions::ans[0].text = "High blood pressure";
			questions[8].Questions::ans[1].text = "Swelling of the legs and feet";
			questions[8].Questions::ans[2].text = "Urinary incontinence";
			questions[8].Questions::ans[3].text = "Blurred vision";
			questions[9].Questions::question = "How can kidney disease be prevented?";
			questions[9].Questions::currectAns = 3;
			questions[9].Questions::ans[0].text = "Drinking plenty of water";
			questions[9].Questions::ans[1].text = "Eating a diet high in protein";
			questions[9].Questions::ans[2].text = "Avoiding regular exercise";
			questions[9].Questions::ans[3].text = "Monitoring blood pressure and blood sugar levels regularly.";
			break;

		case Body::TestFor::STOMACH:
			questions[0].Questions::question = "What is the primary function of the human stomach?";
			questions[0].Questions::currectAns = 0;
			questions[0].Questions::ans[0].text = "Absorption of nutrients";
			questions[0].Questions::ans[1].text = "Digestion of food";
			questions[0].Questions::ans[2].text = "Storage of food";
			questions[0].Questions::ans[3].text = "Production of hormones";
			questions[1].Questions::question = "Which of the following is NOT a common disease of the human stomach?";
			questions[1].Questions::currectAns = 0;
			questions[1].Questions::ans[0].text = "Gastritis";
			questions[1].Questions::ans[1].text = "Ulcers";
			questions[1].Questions::ans[2].text = "Celiac disease";
			questions[1].Questions::ans[3].text = "Parkinson's disease";
			questions[2].Questions::question = "Which of the following is a symptom of gastroesophageal reflux disease (GERD)?";
			questions[2].Questions::currectAns = 0;
			questions[2].Questions::ans[0].text = "Chest pain";
			questions[2].Questions::ans[1].text = "Joint pain";
			questions[2].Questions::ans[2].text = "Visual disturbances";
			questions[2].Questions::ans[3].text = "Hair loss";
			questions[3].Questions::question = "What is the name of the bacterium that causes most stomach ulcers?";
			questions[3].Questions::currectAns = 0;
			questions[3].Questions::ans[0].text = "Streptococcus";
			questions[3].Questions::ans[1].text = "E. coli";
			questions[3].Questions::ans[2].text = "Salmonella";
			questions[3].Questions::ans[3].text = "Helicobacter pylori";
			questions[4].Questions::question = "What is the name of the condition in which the stomach lining becomes inflamed and irritated?";
			questions[4].Questions::currectAns = 0;
			questions[4].Questions::ans[0].text = "Ulcerative colitis";
			questions[4].Questions::ans[1].text = "Crohn's disease";
			questions[4].Questions::ans[2].text = "Gastritis";
			questions[4].Questions::ans[3].text = "Irritable bowel syndrome";
			questions[5].Questions::question = "Which of the following foods should be avoided if someone has gastritis?";
			questions[5].Questions::currectAns = 0;
			questions[5].Questions::ans[0].text = "Spicy foods";
			questions[5].Questions::ans[1].text = "Lean proteins";
			questions[5].Questions::ans[2].text = "Whole grains";
			questions[5].Questions::ans[3].text = "Fruits and vegetables";
			questions[6].Questions::question = "Which of the following is a potential complication of a peptic ulcer?";
			questions[6].Questions::currectAns = 0;
			questions[6].Questions::ans[0].text = "Hypertension";
			questions[6].Questions::ans[1].text = "Blood clots";
			questions[6].Questions::ans[2].text = "Internal bleeding";
			questions[6].Questions::ans[3].text = "Vision loss";
			questions[7].Questions::question = "What is the name of the procedure in which a small camera is inserted into the stomach to examine the lining?";
			questions[7].Questions::currectAns = 0;
			questions[7].Questions::ans[0].text = "MRI";
			questions[7].Questions::ans[1].text = "Endoscopy";
			questions[7].Questions::ans[2].text = "X-ray";
			questions[7].Questions::ans[3].text = "Ultrasound";
			questions[8].Questions::question = "Which of the following medications is commonly used to treat acid reflux?";
			questions[8].Questions::currectAns = 0;
			questions[8].Questions::ans[0].text = "Antibiotics";
			questions[8].Questions::ans[1].text = "Antihistamines";
			questions[8].Questions::ans[2].text = "Antacids";
			questions[8].Questions::ans[3].text = "Pain relievers";
			questions[9].Questions::question = "What is the medical term for vomiting?";
			questions[9].Questions::currectAns = 0;
			questions[9].Questions::ans[0].text = "Diarrhea";
			questions[9].Questions::ans[1].text = "Hematemesis";
			questions[9].Questions::ans[2].text = "Dysphagia";
			questions[9].Questions::ans[3].text = "Pyrosis";

		case Body::TestFor::INTESTINES:
			questions[0].Questions::question = "What is the function of the human intestine?";
			questions[0].Questions::currectAns = 0;
			questions[0].Questions::ans[0].text = "Absorbing nutrients and eliminating waste";
			questions[0].Questions::ans[1].text = "Pumping blood";
			questions[0].Questions::ans[2].text = "Regulating breathing";
			questions[0].Questions::ans[3].text = "Producing hormones";
			questions[1].Questions::question = "Which part of the digestive tract is responsible for most nutrient absorption?";
			questions[1].Questions::currectAns = 1;
			questions[1].Questions::ans[0].text = "Stomach";
			questions[1].Questions::ans[1].text = "Small intestine";
			questions[1].Questions::ans[2].text = "Large intestine";
			questions[1].Questions::ans[3].text = "Esophagus";
			questions[2].Questions::question = "What is the function of the large intestine or colon?";
			questions[2].Questions::currectAns = 1;
			questions[2].Questions::ans[0].text = "Nutrient absorption";
			questions[2].Questions::ans[1].text = "Eliminating waste";
			questions[2].Questions::ans[2].text = "Pumping blood";
			questions[2].Questions::ans[3].text = "Producing enzymes";
			questions[3].Questions::question = "What are some common diseases of the intestines?";
			questions[3].Questions::currectAns = 2;
			questions[3].Questions::ans[0].text = "Asthma and pneumonia";
			questions[3].Questions::ans[1].text = "Malaria and dengue fever";
			questions[3].Questions::ans[2].text = "Inflammatory bowel disease, irritable bowel syndrome, diverticulitis, and colon cancer";
			questions[3].Questions::ans[3].text = "All of the above";
			questions[4].Questions::question = "What is inflammatory bowel disease (IBD)?";
			questions[4].Questions::currectAns = 2;
			questions[4].Questions::ans[0].text = "A functional disorder that causes abdominal pain and bloating";
			questions[4].Questions::ans[1].text = "The inflammation or infection of small pouches in the lining of the colon";
			questions[4].Questions::ans[2].text = "A chronic inflammation of the digestive tract that includes Crohn's disease and\nulcerative colitis";
			questions[4].Questions::ans[3].text = "The growth of cancerous cells in the colon or rectum";
			questions[5].Questions::question = "What is irritable bowel syndrome (IBS)?";
			questions[5].Questions::currectAns = 0;
			questions[5].Questions::ans[0].text = "A functional disorder that causes abdominal pain and bloating";
			questions[5].Questions::ans[1].text = "The inflammation or infection of small pouches in the lining of the colon";
			questions[5].Questions::ans[2].text = "A chronic inflammation of the digestive tract that includes Crohn's disease and\nulcerative colitis";
			questions[5].Questions::ans[3].text = "The growth of cancerous cells in the colon or rectum";
			questions[6].Questions::question = "What is diverticulitis?";
			questions[6].Questions::currectAns = 1;
			questions[6].Questions::ans[0].text = "A functional disorder that causes abdominal pain and bloating";
			questions[6].Questions::ans[1].text = "The inflammation or infection of small pouches in the lining of the colon";
			questions[6].Questions::ans[2].text = "A chronic inflammation of the digestive tract that includes Crohn's disease and\nulcerative colitis";
			questions[6].Questions::ans[3].text = "The growth of cancerous cells in the colon or rectum";
			questions[7].Questions::question = "What is colon cancer?";
			questions[7].Questions::currectAns = 3;
			questions[7].Questions::ans[0].text = "A functional disorder that causes abdominal pain and bloating";
			questions[7].Questions::ans[1].text = "The inflammation or infection of small pouches in the lining of the colon";
			questions[7].Questions::ans[2].text = "A chronic inflammation of the digestive tract that includes Crohn's disease and\nulcerative colitis";
			questions[7].Questions::ans[3].text = "The growth of cancerous cells in the colon or rectum";
			questions[8].Questions::question = "What is the small intestine?";
			questions[8].Questions::currectAns = 2;
			questions[8].Questions::ans[0].text = "The shortest part of the digestive tract";
			questions[8].Questions::ans[1].text = "Responsible for absorbing water and electrolytes";
			questions[8].Questions::ans[2].text = "Responsible for most nutrient absorption";
			questions[8].Questions::ans[3].text = "None of the above";
			questions[9].Questions::question = "What is the large intestine or colon?";
			questions[9].Questions::currectAns = 3;
			questions[9].Questions::ans[0].text = "The shortest part of the digestive tract";
			questions[9].Questions::ans[1].text = "Responsible for absorbing water and electrolytes";
			questions[9].Questions::ans[2].text = "Responsible for most nutrient absorption";
			questions[9].Questions::ans[3].text = "Stores waste until elimination";
			break;
		case Body::TestFor::REPRODUCTIVE:
			questions[0].Questions::question = "What is the primary function of the male reproductive system?";
			questions[0].Questions::currectAns = 0;
			questions[0].Questions::ans[0].text = "To produce and deliver sperm";
			questions[0].Questions::ans[1].text = "To produce and deliver eggs";
			questions[0].Questions::ans[2].text = "To nourish and protect the fetus";
			questions[0].Questions::ans[3].text = "To facilitate menstruation";
			questions[1].Questions::question = "What is the name of the male sex hormone?";
			questions[1].Questions::currectAns = 1;
			questions[1].Questions::ans[0].text = "Estrogen";
			questions[1].Questions::ans[1].text = "Testosterone";
			questions[1].Questions::ans[2].text = "Progesterone";
			questions[1].Questions::ans[3].text = "Follicle-stimulating hormone";
			questions[2].Questions::question = "Where are the testes located in the male body?";
			questions[2].Questions::currectAns = 2;
			questions[2].Questions::ans[0].text = "In the penis";
			questions[2].Questions::ans[1].text = "In the prostate gland";
			questions[2].Questions::ans[2].text = "In the scrotum";
			questions[2].Questions::ans[3].text = "In the bladder";
			questions[3].Questions::question = "What is the name of the tube that carries sperm from the testes to the urethra?";
			questions[3].Questions::currectAns = 0;
			questions[3].Questions::ans[0].text = "Vas deferens";
			questions[3].Questions::ans[1].text = "Ureter";
			questions[3].Questions::ans[2].text = "Fallopian tube";
			questions[3].Questions::ans[3].text = "Epididymis";
			questions[4].Questions::question = "Which of the following is a common disease of the male reproductive system?";
			questions[4].Questions::currectAns = 2;
			questions[4].Questions::ans[0].text = "Breast cancer";
			questions[4].Questions::ans[1].text = "Ovarian cancer";
			questions[4].Questions::ans[2].text = "Prostate cancer";
			questions[4].Questions::ans[3].text = "Cervical cancer";
			questions[5].Questions::question = "What is the name of the gland that produces the fluid that mixes with sperm to form\nsemen?";
			questions[5].Questions::currectAns = 0;
			questions[5].Questions::ans[0].text = "Prostate gland";
			questions[5].Questions::ans[1].text = "Cowper's gland";
			questions[5].Questions::ans[2].text = "Bartholin's gland";
			questions[5].Questions::ans[3].text = "Skene's gland";
			questions[6].Questions::question = "What is the medical term for the surgical removal of the testes?";
			questions[6].Questions::currectAns = 1;
			questions[6].Questions::ans[0].text = "Vasectomy";
			questions[6].Questions::ans[1].text = "Orchiectomy";
			questions[6].Questions::ans[2].text = "Prostatectomy";
			questions[6].Questions::ans[3].text = "Hysterectomy";
			questions[7].Questions::question = "Which of the following is a common sexually transmitted infection that can affect\nthe male reproductive system?";
			questions[7].Questions::currectAns = 1;
			questions[7].Questions::ans[0].text = "Hepatitis C";
			questions[7].Questions::ans[1].text = "Human papillomavirus (HPV)";
			questions[7].Questions::ans[2].text = "Influenza";
			questions[7].Questions::ans[3].text = "Tuberculosis";
			questions[8].Questions::question = "What is the name of the condition where the foreskin of the penis cannot be retracted?";
			questions[8].Questions::currectAns = 3;
			questions[8].Questions::ans[0].text = "Erectile dysfunction";
			questions[8].Questions::ans[1].text = "Testicular torsion";
			questions[8].Questions::ans[2].text = "Peyronie's disease";
			questions[8].Questions::ans[3].text = "Phimosis";
			questions[9].Questions::question = "Which of the following is a common symptom of testicular cancer?";
			questions[9].Questions::currectAns = 2;
			questions[9].Questions::ans[0].text = "Nausea and vomiting";
			questions[9].Questions::ans[1].text = "Abnormal discharge from the penis";
			questions[9].Questions::ans[2].text = "Pain or discomfort in the testicles";
			questions[9].Questions::ans[3].text = "Urinary incontinence";
			break;

		case Body::TestFor::NERVES:
			questions[0].Questions::question = "What is the primary function of human nerves?";
			questions[0].Questions::currectAns = 0;
			questions[0].Questions::ans[0].text = "To control and coordinate bodily functions";
			questions[0].Questions::ans[1].text = "To produce hormones";
			questions[0].Questions::ans[2].text = "To digest food";
			questions[0].Questions::ans[3].text = "To pump blood";
			questions[1].Questions::question = "Which type of nerves carry signals from the brain and spinal cord to the muscles\nand organs?";
			questions[1].Questions::currectAns = 1;
			questions[1].Questions::ans[0].text = "Sensory nerves";
			questions[1].Questions::ans[1].text = "Motor nerves";
			questions[1].Questions::ans[2].text = "Autonomic nerves";
			questions[1].Questions::ans[3].text = "Cranial nerves";
			questions[2].Questions::question = "What is a myelin sheath?";
			questions[2].Questions::currectAns = 2;
			questions[2].Questions::ans[0].text = "A type of nerve cell";
			questions[2].Questions::ans[1].text = "A type of neurotransmitter";
			questions[2].Questions::ans[2].text = "A protective coating around nerves";
			questions[2].Questions::ans[3].text = "A type of nerve impulse";
			questions[3].Questions::question = "Which type of nerve fibers transmit signals faster?";
			questions[3].Questions::currectAns = 3;
			questions[3].Questions::ans[0].text = "Unmyelinated fibers";
			questions[3].Questions::ans[1].text = "Sensory fibers";
			questions[3].Questions::ans[2].text = "Motor fibers";
			questions[3].Questions::ans[3].text = "Myelinated fibers";
			questions[4].Questions::question = "Which part of a neuron receives signals from other neurons?";
			questions[4].Questions::currectAns = 0;
			questions[4].Questions::ans[0].text = "Dendrites";
			questions[4].Questions::ans[1].text = "Axons";
			questions[4].Questions::ans[2].text = "Soma";
			questions[4].Questions::ans[3].text = "Synapses";
			questions[5].Questions::question = "Which division of the autonomic nervous system is responsible for the fight or\nflight response?";
			questions[5].Questions::currectAns = 0;
			questions[5].Questions::ans[0].text = "Sympathetic division";
			questions[5].Questions::ans[1].text = "Parasympathetic division";
			questions[5].Questions::ans[2].text = "Somatic division";
			questions[5].Questions::ans[3].text = "Sensory division";
			questions[6].Questions::question = "Which of the following is a disorder that affects the peripheral nervous system?";
			questions[6].Questions::currectAns = 3;
			questions[6].Questions::ans[0].text = "Multiple sclerosis";
			questions[6].Questions::ans[1].text = "Parkinson's disease";
			questions[6].Questions::ans[2].text = "Alzheimer's disease";
			questions[6].Questions::ans[3].text = "Guillain-Barre syndrome";
			questions[7].Questions::question = "Which of the following is a type of nerve cell that helps to support and nourish neurons?";
			questions[7].Questions::currectAns = 1;
			questions[7].Questions::ans[0].text = "Schwann cells";
			questions[7].Questions::ans[1].text = "Astrocytes";
			questions[7].Questions::ans[2].text = "Microglia";
			questions[7].Questions::ans[3].text = "Oligodendrocytes";
			questions[8].Questions::question = "Which of the following is a common symptom of nerve damage?";
			questions[8].Questions::currectAns = 0;
			questions[8].Questions::ans[0].text = "Muscle weakness";
			questions[8].Questions::ans[1].text = "High blood pressure";
			questions[8].Questions::ans[2].text = "Hearing loss";
			questions[8].Questions::ans[3].text = "Skin rash";
			questions[9].Questions::question = "Which of the following is a type of nerve that carries signals from the body to the spinal\ncord and brain?";
			questions[9].Questions::currectAns = 0;
			questions[9].Questions::ans[0].text = "Sensory nerves";
			questions[9].Questions::ans[1].text = "Motor nerves";
			questions[9].Questions::ans[2].text = "Autonomic nerves";
			questions[9].Questions::ans[3].text = "Cranial nerves";
			break;

		case Body::TestFor::MUSCLE:
			questions[0].Questions::question = "Which type of muscle is responsible for involuntary movements?";
			questions[0].Questions::currectAns = 2;
			questions[0].Questions::ans[0].text = "Skeletal muscle";
			questions[0].Questions::ans[1].text = "Cardiac muscle";
			questions[0].Questions::ans[2].text = "Smooth muscle";
			questions[0].Questions::ans[3].text = "Striated muscle";
			questions[1].Questions::question = "Which disease causes progressive muscle weakness and loss of muscle mass?";
			questions[1].Questions::currectAns = 2;
			questions[1].Questions::ans[0].text = "Multiple sclerosis";
			questions[1].Questions::ans[1].text = "Parkinson's disease";
			questions[1].Questions::ans[2].text = "Muscular dystrophy";
			questions[1].Questions::ans[3].text = "Fibromyalgia";
			questions[2].Questions::question = "Which muscle group is responsible for extension of the elbow joint?";
			questions[2].Questions::currectAns = 1;
			questions[2].Questions::ans[0].text = "Biceps brachii";
			questions[2].Questions::ans[1].text = "Triceps brachii";
			questions[2].Questions::ans[2].text = "Deltoid";
			questions[2].Questions::ans[3].text = "Pectoralis major";
			questions[3].Questions::question = "Which muscle is commonly referred to as the 'six - pack' muscle ? ";
			questions[3].Questions::currectAns = 2;
			questions[3].Questions::ans[0].text = "Rectus femoris";
			questions[3].Questions::ans[1].text = "Pectoralis major";
			questions[3].Questions::ans[2].text = "Rectus abdominis";
			questions[3].Questions::ans[3].text = "Deltoid";
			questions[4].Questions::question = "Which disease is characterized by chronic widespread muscle pain and tenderness?";
			questions[4].Questions::currectAns = 0;
			questions[4].Questions::ans[0].text = "Fibromyalgia";
			questions[4].Questions::ans[1].text = "Rheumatoid arthritis";
			questions[4].Questions::ans[2].text = "Osteoarthritis";
			questions[4].Questions::ans[3].text = "Scoliosis";
			questions[5].Questions::question = "Which muscle is responsible for abducting the arm at the shoulder joint?";
			questions[5].Questions::currectAns = 2;
			questions[5].Questions::ans[0].text = "Pectoralis major";
			questions[5].Questions::ans[1].text = "Latissimus dorsi";
			questions[5].Questions::ans[2].text = "Deltoid";
			questions[5].Questions::ans[3].text = "Trapezius";
			questions[6].Questions::question = "Which disease is caused by the degeneration of motor neurons, resulting in progressive\nmuscle weakness and atrophy?";
			questions[6].Questions::currectAns = 1;
			questions[6].Questions::ans[0].text = "Muscular dystrophy";
			questions[6].Questions::ans[1].text = "ALS (Amyotrophic lateral sclerosis";
			questions[6].Questions::ans[2].text = "Multiple sclerosis";
			questions[6].Questions::ans[3].text = "Fibromyalgia";
			questions[7].Questions::question = "Which muscle group is responsible for plantarflexion of the foot?";
			questions[7].Questions::currectAns = 0;
			questions[7].Questions::ans[0].text = "Gastrocnemius and soleus";
			questions[7].Questions::ans[1].text = "Quadriceps femoris";
			questions[7].Questions::ans[2].text = "Hamstrings";
			questions[7].Questions::ans[3].text = "Gluteus maximus";
			questions[8].Questions::question = "Which disease is characterized by inflammation and weakness of the muscles, particularly\nin the shoulders and hips?";
			questions[8].Questions::currectAns = 1;
			questions[8].Questions::ans[0].text = "Fibromyalgia";
			questions[8].Questions::ans[1].text = "Polymyositis";
			questions[8].Questions::ans[2].text = "Myasthenia gravis";
			questions[8].Questions::ans[3].text = "Muscular dystrophy";
			questions[9].Questions::question = "Which muscle group is responsible for flexion of the knee joint?";
			questions[9].Questions::currectAns = 1;
			questions[9].Questions::ans[0].text = "Quadriceps femoris";
			questions[9].Questions::ans[1].text = "Hamstrings";
			questions[9].Questions::ans[2].text = "Gastrocnemius and soleus";
			questions[9].Questions::ans[3].text = "Gluteus maximus";
			break;
		}
		drawQuestions(questions);
	}
}
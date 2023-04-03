#pragma once
#include "AppStatus.hpp"

class Body {
public:
	enum class TestFor {
		BRAIN,
		LUNGS,
		LIVER,
		HEART,
		KIDNEY,
		STOMACH,
		INTESTINES,
		REPRODUCTIVE,
		NERVES,
		MUSCLE
	};
	TestFor testfor;

	struct Button {
		Rectangle bounds;
		int rounding;
		bool hovering;
		const char* text;
		Color color;
	};
	Button cancel;
	Button testBTN;
	Button brainBTN;
	Button lungsBTN;
	Button liverBTN;
	Button heartBTN;
	Button kidneyBTN;
	Button stomachBTN;
	Button intestinesBTN;
	Button reproductiveSMBTN;
	Button nervesBTN;
	Button muscleBTN;

	Body();
	~Body();
	void cancelBtn(float posX, float posY);
	void testBtn(float posX, float posY,TestFor test);
	void organsBtn();

	void drawBrain();
	void drawLungs();
	void drawLiver();
	void drawHeart();
	void drawKidney();
	void drawStomach();
	void drawIntestines();
	void drawReproductiveSM();
	void drawNerves();
	void drawMuscle();
	void drawBody();

	struct Answers {
		const char* text;
		Vector2 pos;
		bool checked = false;
	};
	struct Questions {
		const char* question;
		Vector2 pos;
		Answers ans[4];
		int currectAns;
	};

	bool questionTurn[10] = { true, false, false , false , false , false , false , false , false , false };
	Questions questions[10];
	Vector2 checkBoxPos;
	Rectangle clickRecPos;

	void drawScore(int score);
	void drawTestButtons();
	void drawAlertForEnd();
	void drawQuestionNum(float posX, float posY, Questions question[]);
	void drawAnswer(Questions question);
	void drawQuestions(Questions question1[]);

	Rectangle field;


	bool inTest = false;
	bool showAlert = false;
	bool showResult = false;


	static std::shared_ptr<Body> getInstance();
private:
	static std::shared_ptr<Body> instance;
	//std::shared_ptr<TestMode> test;

	float sWidth;
	float sHeight;
	float bodySize;
	float organSize;

	int fontSize;
	int testFontSize;

	bool brainIsActive;
	bool lungsIsActive;
	bool liverIsActive;
	bool heartIsActive;
	bool kidneyIsActive;
	bool stomachIsActive;
	bool intestinesIsActive;
	bool reproductiveSMIsActive;
	bool nervesIsActive;
	bool muscleIsActive;

	const char* brainInfo;
	const char* lungsInfo;
	const char* liverInfo;
	const char* heartInfo;
	const char* kidneyInfo;
	const char* stomachInfo;
	const char* intestinesInfo;
	const char* reproductiveSMInfo;
	const char* nervesInfo;
	const char* muscleInfo;

	Vector2 mousePosition;
	Vector2 bodyPos;
	Vector2 brainPos;
	Vector2 lungsPos;
	Vector2 liverPos;
	Vector2 heartPos;
	Vector2 kidneyPos;
	Vector2 stomachPos;
	Vector2 intestinesPos;
	Vector2 reproductiveSMPos;
	Vector2 nervesPos;
	Vector2 musclePos;
	Vector2 infoPos;

	Rectangle brainRec;
	Rectangle lungsRec;
	Rectangle liverRec;
	Rectangle heartRec;
	Rectangle kidneyRec;
	Rectangle stomachRec;
	Rectangle intestinesRec;
	Rectangle reproductiveSMRec;
	Rectangle nervesRec;
	Rectangle muscleRec;

	Texture2D body;
	Texture2D brain;
	Texture2D lungs;
	Texture2D liver;
	Texture2D heart;
	Texture2D kidney;
	Texture2D stomach;
	Texture2D intestines;
	Texture2D reproductiveSM;
	Texture2D nerves;
	Texture2D muscle;
};
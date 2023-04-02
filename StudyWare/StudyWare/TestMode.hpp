#pragma once
#include "AppStatus.hpp"

class TestMode {
public:
	struct Button {
		Rectangle bounds;
		int rounding;
		bool hovering;
		const char* text;
		Color color;
	};
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
		Color color;
	};

	int questionNum = 10;
	//Questions* question = new Questions[questionNum];
	bool* questionTurn = new bool[questionNum];
	Questions question;

	TestMode();
	~TestMode();

	void drawAnswers();
	void drawQuestion(Questions question);
	void drawTest(Questions question1[]);

	static std::shared_ptr<TestMode> getInstance();
private:
	static std::shared_ptr<TestMode> instance;

	float sWidth;
	float sHeight;

	int fontSize;

	Vector2 mousePosition;

	Rectangle field;
};
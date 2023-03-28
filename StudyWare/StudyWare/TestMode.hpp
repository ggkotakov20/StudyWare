#pragma once

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
void popAlertForEnd(Vector2 screen, Font font);
void testButtons(Vector2 screen, Font font);
void resultOfTest(Vector2 screen, Font font, float score);
void questions(Vector2 screen, Font font);
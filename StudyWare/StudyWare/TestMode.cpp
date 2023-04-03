#include "TestMode.hpp"

std::shared_ptr<TestMode> TestMode::instance = nullptr;

TestMode::TestMode() {
	sWidth = GetScreenWidth();
	sHeight = GetScreenHeight();

	fontSize = sHeight / 50;

	mousePosition = GetMousePosition();

	field.width = 1400;
	field.height = 820;
	field.x = 100;
	field.y = 100;
}
TestMode::~TestMode(){
	//delete[] question;
	delete[] questionTurn;
}
std::shared_ptr<TestMode> TestMode::getInstance() {
	if (instance == nullptr)
		instance = std::shared_ptr<TestMode>(new TestMode);
	return instance;
}
void TestMode::drawQuestion(Questions question) {
	DrawText(question.question, question.pos.x, question.pos.y, 30, question.color);
	for (int i = 0; i < 4; i++) {
		Vector2 checkBoxPos;
		Rectangle clickRecPos;
		switch (i) {
		case 0:
			question.ans[i].pos = { question.pos.x + 30, question.pos.y + 70 };


			checkBoxPos = { question.pos.x + 10, question.ans[i].pos.y + 15 };
			clickRecPos.x = question.pos.x;
			clickRecPos.y = question.ans[i].pos.y;
			clickRecPos.width = 200;
			clickRecPos.height = 30;
			if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
				question.ans[0].checked = true;
				question.ans[1].checked = false;
				question.ans[2].checked = false;
				question.ans[3].checked = false;
			}

			if (question.ans[i].checked) {
				DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
				DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
			}
			else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

			DrawText(question.ans[i].text, question.ans[i].pos.x, question.ans[i].pos.y, 30, question.color);
			break;
		case 1:
			question.ans[i].pos = { question.pos.x + 30, question.pos.y + 120 };

			checkBoxPos = { question.pos.x + 10, question.ans[i].pos.y + 15 };
			clickRecPos.x = question.pos.x;
			clickRecPos.y = question.ans[i].pos.y;
			clickRecPos.width = 200;
			clickRecPos.height = 30;
			if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
				question.ans[0].checked = false;
				question.ans[1].checked = true;
				question.ans[2].checked = false;
				question.ans[3].checked = false;
			}

			if (question.ans[i].checked) {
				DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
				DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
			}
			else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

			DrawText(question.ans[i].text, question.ans[i].pos.x, question.ans[i].pos.y, 30, question.color);
			break;
		case 2:
			question.ans[i].pos = { question.pos.x + 30, question.pos.y + 170 };

			checkBoxPos = { question.pos.x + 10, question.ans[i].pos.y + 15 };
			clickRecPos.x = question.pos.x;
			clickRecPos.y = question.ans[i].pos.y;
			clickRecPos.width = 200;
			clickRecPos.height = 30;
			if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
				question.ans[0].checked = false;
				question.ans[1].checked = false;
				question.ans[2].checked = true;
				question.ans[3].checked = false;
			}

			if (question.ans[i].checked) {
				DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
				DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
			}
			else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

			DrawText(question.ans[i].text, question.ans[i].pos.x, question.ans[i].pos.y, 30, question.color);
			break;
		case 3:
			question.ans[i].pos = { question.pos.x + 30, question.pos.y + 220 };

			checkBoxPos = { question.pos.x + 10, question.ans[i].pos.y + 15 };
			clickRecPos.x = question.pos.x;
			clickRecPos.y = question.ans[i].pos.y;
			clickRecPos.width = 200;
			clickRecPos.height = 30;
			if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
				question.ans[0].checked = false;
				question.ans[1].checked = false;
				question.ans[2].checked = false;
				question.ans[3].checked = true;
			}

			if (question.ans[i].checked) {
				DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
				DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
			}
			else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

			DrawText(question.ans[i].text, question.ans[i].pos.x, question.ans[i].pos.y, 30, question.color);
			break;
		}
	}
}
void TestMode::drawTest(Questions question1[]) {

	DrawRectangleRec(field, GRAY);
	question.question = question1[0].question;
	question.pos.x = field.x + 30;
	question.pos.y = field.y + 15;
	question.color = BLACK;
	question.ans[0].text = question1[0].ans[0].text;
	question.ans[1].text = question1[0].ans[1].text;
	question.ans[2].text = question1[0].ans[2].text;
	question.ans[3].text = question1[0].ans[3].text;
	drawQuestion(question);
}
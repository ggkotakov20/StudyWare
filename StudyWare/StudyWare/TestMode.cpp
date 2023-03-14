#include <iostream>
#include <string>
#include <sstream>

#include "raylib.h"
#include "TestMode.h"

Questions question[5];
Rectangle field;


bool questionTurn[5] = { true, false, false, false, false };
bool isTesting = true;
bool showAlert = false;

void popAlertForEnd(Vector2 screen, Font font) {
	Button yesBtn, noBtn;

	yesBtn.bounds = { (float)screen.x / 2 + 30, (float)screen.y / 2, 250, 50 };
	yesBtn.rounding = 1;
	yesBtn.hovering = CheckCollisionPointRec(GetMousePosition(), yesBtn.bounds);
	yesBtn.text = "Yes, finish attempt";
	yesBtn.color = GRAY;

	noBtn.bounds = { (float)screen.x / 2 - 280, (float)screen.y / 2, 250, 50 };
	noBtn.rounding = 1;
	noBtn.hovering = CheckCollisionPointRec(GetMousePosition(), noBtn.bounds);
	noBtn.text = "No, back to attempt";
	noBtn.color = GRAY;

	Vector2 textPos = { screen.x / 2 - 475, screen.y / 2 - 100 };
	DrawTextEx(font, "Are you sure you want to finish attempt", textPos, 50, 1, BLACK);

	Vector2 yesBtnPos = { yesBtn.bounds.x + yesBtn.bounds.width / 2 - MeasureText(yesBtn.text, 20) / 2, yesBtn.bounds.y + 15 };
	if (yesBtn.hovering) yesBtn.color = DARKGRAY;
	DrawRectangleRounded(yesBtn.bounds, yesBtn.rounding, yesBtn.rounding, yesBtn.color);
	DrawTextEx(font, yesBtn.text, yesBtnPos, 20, 1, BLACK);

	if (yesBtn.hovering && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		isTesting = false;
		showAlert = false;
	}

	Vector2 noBtnPos = { noBtn.bounds.x + noBtn.bounds.width / 2 - MeasureText(noBtn.text, 20) / 2, noBtn.bounds.y + 15 };
	if (noBtn.hovering) noBtn.color = DARKGRAY;
	DrawRectangleRounded(noBtn.bounds, noBtn.rounding, noBtn.rounding, noBtn.color);
	DrawTextEx(font, noBtn.text, noBtnPos, 20, 1, BLACK);

	if (noBtn.hovering && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		showAlert = false;

}

void resultOfTest(Vector2 screen, Font font, float score) {
	if (!isTesting) {
		char scoreText[10];
		sprintf_s(scoreText, "Score : ", score, "%");

		DrawText(scoreText, 0, 0, 20, BLACK);
	}
}

void buttons(Vector2 screen, Font font) {
	if (isTesting) {
		if (!questionTurn[0]) {
			Button previousBtn;

			if (questionTurn[4])
				previousBtn.bounds = { (float)screen.x / 2 - 155, (float)screen.y - 75, 150, 50 };
			else
				previousBtn.bounds = { (float)screen.x / 2 - 75 - 4 * 40, (float)screen.y - 75, 150, 50 };

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
				}
				else if (questionTurn[2]) {
					questionTurn[0] = false;
					questionTurn[1] = true;
					questionTurn[2] = false;
					questionTurn[3] = false;
					questionTurn[4] = false;
				}
				else if (questionTurn[3]) {
					questionTurn[0] = false;
					questionTurn[1] = false;
					questionTurn[2] = true;
					questionTurn[3] = false;
					questionTurn[4] = false;
				}
				else if (questionTurn[4]) {
					questionTurn[0] = false;
					questionTurn[1] = false;
					questionTurn[2] = false;
					questionTurn[3] = true;
					questionTurn[4] = false;
				}
			}
		}

		if (!questionTurn[4]) {
			Button nextBtn;

			if (questionTurn[0])
				nextBtn.bounds = { (float)screen.x / 2 - 155, (float)screen.y - 75, 150, 50 };
			else
				nextBtn.bounds = { (float)screen.x / 2 - 75, (float)screen.y - 75, 150, 50 };

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
				}
				else if (questionTurn[1]) {
					questionTurn[0] = false;
					questionTurn[1] = false;
					questionTurn[2] = true;
					questionTurn[3] = false;
					questionTurn[4] = false;
				}
				else if (questionTurn[2]) {
					questionTurn[0] = false;
					questionTurn[1] = false;
					questionTurn[2] = false;
					questionTurn[3] = true;
					questionTurn[4] = false;
				}
				else if (questionTurn[3]) {
					questionTurn[0] = false;
					questionTurn[1] = false;
					questionTurn[2] = false;
					questionTurn[3] = false;
					questionTurn[4] = true;
				}
			}
		}


		Button finishBtn;

		if (questionTurn[0] || questionTurn[4])
			finishBtn.bounds = { (float)screen.x / 2 + 5, (float)screen.y - 75, 150, 50 };
		else
			finishBtn.bounds = { (float)screen.x / 2 - 75 + 4 * 40, (float)screen.y - 75, 150, 50 };

		finishBtn.rounding = 1;
		finishBtn.hovering = CheckCollisionPointRec(GetMousePosition(), finishBtn.bounds);
		finishBtn.text = "Finish";
		finishBtn.color = GRAY;

		if (finishBtn.hovering) finishBtn.color = DARKGRAY;

		DrawRectangleRounded(finishBtn.bounds, finishBtn.rounding, finishBtn.rounding, finishBtn.color);
		DrawText(finishBtn.text, finishBtn.bounds.x + finishBtn.bounds.width / 2 - MeasureText(finishBtn.text, 20) / 2, finishBtn.bounds.y + 15, 20, BLACK);

		if (CheckCollisionPointRec(GetMousePosition(), finishBtn.bounds) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			showAlert = true;
	}
}

void questions(Vector2 screen, Font font) {
	field.width = 1400;
	field.height = 820;
	field.x = 100;
	field.y = 100;

	float currectAnswers = 0;
	float score = 0;

	int questionNum = 5; // Number of questions
	if (!showAlert && isTesting) {
		DrawRectangleRec(field, GRAY);
		for (int i = 0; i < questionNum; i++) {
			if (i == 0 && questionTurn[i]) {
				question[i].question = "Question 1";
				question[i].pos.x = field.x + 30;
				question[i].pos.y = field.y + 15;
				question[i].currectAns = 1;
				question[i].color = BLACK;

				for (int j = 0; j < 4; j++) {
					Vector2 checkBoxPos;
					Rectangle clickRecPos;
					switch (j) {
					case 0:
						question[i].ans[j].text = "Answer 1";
						question[i].ans[j].pos = { question[i].pos.x + 30, question[i].pos.y + 70 };


						checkBoxPos = { question[i].pos.x + 10, question[i].ans[j].pos.y + 15 };
						clickRecPos.x = question[i].pos.x;
						clickRecPos.y = question[i].ans[j].pos.y;
						clickRecPos.width = 200;
						clickRecPos.height = 30;
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question[i].ans[0].checked = true;
							question[i].ans[1].checked = false;
							question[i].ans[2].checked = false;
							question[i].ans[3].checked = false;
						}

						if (question[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawTextEx(font, question[i].ans[j].text, question[i].ans[j].pos, 30, 1, question[i].color);
						break;
					case 1:
						question[i].ans[j].text = "Answer 2";
						question[i].ans[j].pos = { question[i].pos.x + 30, question[i].pos.y + 120 };

						checkBoxPos = { question[i].pos.x + 10, question[i].ans[j].pos.y + 15 };
						clickRecPos.x = question[i].pos.x;
						clickRecPos.y = question[i].ans[j].pos.y;
						clickRecPos.width = 200;
						clickRecPos.height = 30;
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question[i].ans[0].checked = false;
							question[i].ans[1].checked = true;
							question[i].ans[2].checked = false;
							question[i].ans[3].checked = false;
						}

						if (question[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawTextEx(font, question[i].ans[j].text, question[i].ans[j].pos, 30, 1, question[i].color);
						break;
					case 2:
						question[i].ans[j].text = "Answer 3";
						question[i].ans[j].pos = { question[i].pos.x + 30, question[i].pos.y + 170 };

						checkBoxPos = { question[i].pos.x + 10, question[i].ans[j].pos.y + 15 };
						clickRecPos.x = question[i].pos.x;
						clickRecPos.y = question[i].ans[j].pos.y;
						clickRecPos.width = 200;
						clickRecPos.height = 30;
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question[i].ans[0].checked = false;
							question[i].ans[1].checked = false;
							question[i].ans[2].checked = true;
							question[i].ans[3].checked = false;
						}

						if (question[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawTextEx(font, question[i].ans[j].text, question[i].ans[j].pos, 30, 1, question[i].color);
						break;
					case 3:
						question[i].ans[j].text = "Answer 4";
						question[i].ans[j].pos = { question[i].pos.x + 30, question[i].pos.y + 220 };

						checkBoxPos = { question[i].pos.x + 10, question[i].ans[j].pos.y + 15 };
						clickRecPos.x = question[i].pos.x;
						clickRecPos.y = question[i].ans[j].pos.y;
						clickRecPos.width = 200;
						clickRecPos.height = 30;
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question[i].ans[0].checked = false;
							question[i].ans[1].checked = false;
							question[i].ans[2].checked = false;
							question[i].ans[3].checked = true;
						}

						if (question[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawTextEx(font, question[i].ans[j].text, question[i].ans[j].pos, 30, 1, question[i].color);
						break;
					}
				}

				DrawTextEx(font, question[i].question, question[i].pos, 30, 1, question[i].color);
			}
			else if (i == 1 && questionTurn[i]) {
				question[i].question = "Question 2";
				question[i].pos.x = field.x + 30;
				question[i].pos.y = field.y + 15;
				question[i].currectAns = 2;
				question[i].color = BLACK;

				for (int j = 0; j < 4; j++) {
					Vector2 checkBoxPos;
					Rectangle clickRecPos;
					switch (j) {
					case 0:
						question[i].ans[j].text = "Answer 1";
						question[i].ans[j].pos = { question[i].pos.x + 30, question[i].pos.y + 70 };


						checkBoxPos = { question[i].pos.x + 10, question[i].ans[j].pos.y + 15 };
						clickRecPos.x = question[i].pos.x;
						clickRecPos.y = question[i].ans[j].pos.y;
						clickRecPos.width = 200;
						clickRecPos.height = 30;
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question[i].ans[0].checked = true;
							question[i].ans[1].checked = false;
							question[i].ans[2].checked = false;
							question[i].ans[3].checked = false;
						}

						if (question[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawTextEx(font, question[i].ans[j].text, question[i].ans[j].pos, 30, 1, question[i].color);
						break;
					case 1:
						question[i].ans[j].text = "Answer 2";
						question[i].ans[j].pos = { question[i].pos.x + 30, question[i].pos.y + 120 };

						checkBoxPos = { question[i].pos.x + 10, question[i].ans[j].pos.y + 15 };
						clickRecPos.x = question[i].pos.x;
						clickRecPos.y = question[i].ans[j].pos.y;
						clickRecPos.width = 200;
						clickRecPos.height = 30;
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question[i].ans[0].checked = false;
							question[i].ans[1].checked = true;
							question[i].ans[2].checked = false;
							question[i].ans[3].checked = false;
						}

						if (question[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawTextEx(font, question[i].ans[j].text, question[i].ans[j].pos, 30, 1, question[i].color);
						break;
					case 2:
						question[i].ans[j].text = "Answer 3";
						question[i].ans[j].pos = { question[i].pos.x + 30, question[i].pos.y + 170 };

						checkBoxPos = { question[i].pos.x + 10, question[i].ans[j].pos.y + 15 };
						clickRecPos.x = question[i].pos.x;
						clickRecPos.y = question[i].ans[j].pos.y;
						clickRecPos.width = 200;
						clickRecPos.height = 30;
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question[i].ans[0].checked = false;
							question[i].ans[1].checked = false;
							question[i].ans[2].checked = true;
							question[i].ans[3].checked = false;
						}

						if (question[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawTextEx(font, question[i].ans[j].text, question[i].ans[j].pos, 30, 1, question[i].color);
						break;
					case 3:
						question[i].ans[j].text = "Answer 4";
						question[i].ans[j].pos = { question[i].pos.x + 30, question[i].pos.y + 220 };

						checkBoxPos = { question[i].pos.x + 10, question[i].ans[j].pos.y + 15 };
						clickRecPos.x = question[i].pos.x;
						clickRecPos.y = question[i].ans[j].pos.y;
						clickRecPos.width = 200;
						clickRecPos.height = 30;
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question[i].ans[0].checked = false;
							question[i].ans[1].checked = false;
							question[i].ans[2].checked = false;
							question[i].ans[3].checked = true;
						}

						if (question[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawTextEx(font, question[i].ans[j].text, question[i].ans[j].pos, 30, 1, question[i].color);
						break;
					}
				}

				DrawTextEx(font, question[i].question, question[i].pos, 30, 1, question[i].color);
			}
			else if (i == 2 && questionTurn[i]) {
				question[i].question = "Question 3";
				question[i].pos.x = field.x + 30;
				question[i].pos.y = field.y + 15;
				question[i].currectAns = 3;
				question[i].color = BLACK;

				for (int j = 0; j < 4; j++) {
					Vector2 checkBoxPos;
					Rectangle clickRecPos;
					switch (j) {
					case 0:
						question[i].ans[j].text = "Answer 1";
						question[i].ans[j].pos = { question[i].pos.x + 30, question[i].pos.y + 70 };


						checkBoxPos = { question[i].pos.x + 10, question[i].ans[j].pos.y + 15 };
						clickRecPos.x = question[i].pos.x;
						clickRecPos.y = question[i].ans[j].pos.y;
						clickRecPos.width = 200;
						clickRecPos.height = 30;
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question[i].ans[0].checked = true;
							question[i].ans[1].checked = false;
							question[i].ans[2].checked = false;
							question[i].ans[3].checked = false;
						}

						if (question[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawTextEx(font, question[i].ans[j].text, question[i].ans[j].pos, 30, 1, question[i].color);
						break;
					case 1:
						question[i].ans[j].text = "Answer 2";
						question[i].ans[j].pos = { question[i].pos.x + 30, question[i].pos.y + 120 };

						checkBoxPos = { question[i].pos.x + 10, question[i].ans[j].pos.y + 15 };
						clickRecPos.x = question[i].pos.x;
						clickRecPos.y = question[i].ans[j].pos.y;
						clickRecPos.width = 200;
						clickRecPos.height = 30;
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question[i].ans[0].checked = false;
							question[i].ans[1].checked = true;
							question[i].ans[2].checked = false;
							question[i].ans[3].checked = false;
						}

						if (question[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawTextEx(font, question[i].ans[j].text, question[i].ans[j].pos, 30, 1, question[i].color);
						break;
					case 2:
						question[i].ans[j].text = "Answer 3";
						question[i].ans[j].pos = { question[i].pos.x + 30, question[i].pos.y + 170 };

						checkBoxPos = { question[i].pos.x + 10, question[i].ans[j].pos.y + 15 };
						clickRecPos.x = question[i].pos.x;
						clickRecPos.y = question[i].ans[j].pos.y;
						clickRecPos.width = 200;
						clickRecPos.height = 30;
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question[i].ans[0].checked = false;
							question[i].ans[1].checked = false;
							question[i].ans[2].checked = true;
							question[i].ans[3].checked = false;
						}

						if (question[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawTextEx(font, question[i].ans[j].text, question[i].ans[j].pos, 30, 1, question[i].color);
						break;
					case 3:
						question[i].ans[j].text = "Answer 4";
						question[i].ans[j].pos = { question[i].pos.x + 30, question[i].pos.y + 220 };

						checkBoxPos = { question[i].pos.x + 10, question[i].ans[j].pos.y + 15 };
						clickRecPos.x = question[i].pos.x;
						clickRecPos.y = question[i].ans[j].pos.y;
						clickRecPos.width = 200;
						clickRecPos.height = 30;
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question[i].ans[0].checked = false;
							question[i].ans[1].checked = false;
							question[i].ans[2].checked = false;
							question[i].ans[3].checked = true;
						}

						if (question[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawTextEx(font, question[i].ans[j].text, question[i].ans[j].pos, 30, 1, question[i].color);
						break;
					}
				}

				DrawTextEx(font, question[i].question, question[i].pos, 30, 1, question[i].color);
			}
			else if (i == 3 && questionTurn[i]) {
				question[i].question = "Question 4";
				question[i].pos.x = field.x + 30;
				question[i].pos.y = field.y + 15;
				question[i].currectAns = 4;
				question[i].color = BLACK;

				for (int j = 0; j < 4; j++) {
					Vector2 checkBoxPos;
					Rectangle clickRecPos;
					switch (j) {
					case 0:
						question[i].ans[j].text = "Answer 1";
						question[i].ans[j].pos = { question[i].pos.x + 30, question[i].pos.y + 70 };


						checkBoxPos = { question[i].pos.x + 10, question[i].ans[j].pos.y + 15 };
						clickRecPos.x = question[i].pos.x;
						clickRecPos.y = question[i].ans[j].pos.y;
						clickRecPos.width = 200;
						clickRecPos.height = 30;
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question[i].ans[0].checked = true;
							question[i].ans[1].checked = false;
							question[i].ans[2].checked = false;
							question[i].ans[3].checked = false;
						}

						if (question[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawTextEx(font, question[i].ans[j].text, question[i].ans[j].pos, 30, 1, question[i].color);
						break;
					case 1:
						question[i].ans[j].text = "Answer 2";
						question[i].ans[j].pos = { question[i].pos.x + 30, question[i].pos.y + 120 };

						checkBoxPos = { question[i].pos.x + 10, question[i].ans[j].pos.y + 15 };
						clickRecPos.x = question[i].pos.x;
						clickRecPos.y = question[i].ans[j].pos.y;
						clickRecPos.width = 200;
						clickRecPos.height = 30;
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question[i].ans[0].checked = false;
							question[i].ans[1].checked = true;
							question[i].ans[2].checked = false;
							question[i].ans[3].checked = false;
						}

						if (question[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawTextEx(font, question[i].ans[j].text, question[i].ans[j].pos, 30, 1, question[i].color);
						break;
					case 2:
						question[i].ans[j].text = "Answer 3";
						question[i].ans[j].pos = { question[i].pos.x + 30, question[i].pos.y + 170 };

						checkBoxPos = { question[i].pos.x + 10, question[i].ans[j].pos.y + 15 };
						clickRecPos.x = question[i].pos.x;
						clickRecPos.y = question[i].ans[j].pos.y;
						clickRecPos.width = 200;
						clickRecPos.height = 30;
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question[i].ans[0].checked = false;
							question[i].ans[1].checked = false;
							question[i].ans[2].checked = true;
							question[i].ans[3].checked = false;
						}

						if (question[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawTextEx(font, question[i].ans[j].text, question[i].ans[j].pos, 30, 1, question[i].color);
						break;
					case 3:
						question[i].ans[j].text = "Answer 4";
						question[i].ans[j].pos = { question[i].pos.x + 30, question[i].pos.y + 220 };

						checkBoxPos = { question[i].pos.x + 10, question[i].ans[j].pos.y + 15 };
						clickRecPos.x = question[i].pos.x;
						clickRecPos.y = question[i].ans[j].pos.y;
						clickRecPos.width = 200;
						clickRecPos.height = 30;
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question[i].ans[0].checked = false;
							question[i].ans[1].checked = false;
							question[i].ans[2].checked = false;
							question[i].ans[3].checked = true;
						}

						if (question[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawTextEx(font, question[i].ans[j].text, question[i].ans[j].pos, 30, 1, question[i].color);
						break;
					}
				}

				DrawTextEx(font, question[i].question, question[i].pos, 30, 1, question[i].color);
			}
			else if (i == 4 && questionTurn[i]) {
				question[i].question = "Question 5";
				question[i].pos.x = field.x + 30;
				question[i].pos.y = field.y + 15;
				question[i].currectAns = 4;
				question[i].color = BLACK;

				for (int j = 0; j < 4; j++) {
					Vector2 checkBoxPos;
					Rectangle clickRecPos;
					switch (j) {
					case 0:
						question[i].ans[j].text = "Answer 1";
						question[i].ans[j].pos = { question[i].pos.x + 30, question[i].pos.y + 70 };


						checkBoxPos = { question[i].pos.x + 10, question[i].ans[j].pos.y + 15 };
						clickRecPos.x = question[i].pos.x;
						clickRecPos.y = question[i].ans[j].pos.y;
						clickRecPos.width = 200;
						clickRecPos.height = 30;
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question[i].ans[0].checked = true;
							question[i].ans[1].checked = false;
							question[i].ans[2].checked = false;
							question[i].ans[3].checked = false;
						}

						if (question[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawTextEx(font, question[i].ans[j].text, question[i].ans[j].pos, 30, 1, question[i].color);
						break;
					case 1:
						question[i].ans[j].text = "Answer 2";
						question[i].ans[j].pos = { question[i].pos.x + 30, question[i].pos.y + 120 };

						checkBoxPos = { question[i].pos.x + 10, question[i].ans[j].pos.y + 15 };
						clickRecPos.x = question[i].pos.x;
						clickRecPos.y = question[i].ans[j].pos.y;
						clickRecPos.width = 200;
						clickRecPos.height = 30;
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question[i].ans[0].checked = false;
							question[i].ans[1].checked = true;
							question[i].ans[2].checked = false;
							question[i].ans[3].checked = false;
						}

						if (question[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawTextEx(font, question[i].ans[j].text, question[i].ans[j].pos, 30, 1, question[i].color);
						break;
					case 2:
						question[i].ans[j].text = "Answer 3";
						question[i].ans[j].pos = { question[i].pos.x + 30, question[i].pos.y + 170 };

						checkBoxPos = { question[i].pos.x + 10, question[i].ans[j].pos.y + 15 };
						clickRecPos.x = question[i].pos.x;
						clickRecPos.y = question[i].ans[j].pos.y;
						clickRecPos.width = 200;
						clickRecPos.height = 30;
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question[i].ans[0].checked = false;
							question[i].ans[1].checked = false;
							question[i].ans[2].checked = true;
							question[i].ans[3].checked = false;
						}

						if (question[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawTextEx(font, question[i].ans[j].text, question[i].ans[j].pos, 30, 1, question[i].color);
						break;
					case 3:
						question[i].ans[j].text = "Answer 4";
						question[i].ans[j].pos = { question[i].pos.x + 30, question[i].pos.y + 220 };

						checkBoxPos = { question[i].pos.x + 10, question[i].ans[j].pos.y + 15 };
						clickRecPos.x = question[i].pos.x;
						clickRecPos.y = question[i].ans[j].pos.y;
						clickRecPos.width = 200;
						clickRecPos.height = 30;
						if (CheckCollisionPointRec(GetMousePosition(), clickRecPos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
							question[i].ans[0].checked = false;
							question[i].ans[1].checked = false;
							question[i].ans[2].checked = false;
							question[i].ans[3].checked = true;
						}

						if (question[i].ans[j].checked) {
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);
							DrawCircle(checkBoxPos.x, checkBoxPos.y, 7, BLUE);
						}
						else DrawCircle(checkBoxPos.x, checkBoxPos.y, 10, DARKGRAY);

						DrawTextEx(font, question[i].ans[j].text, question[i].ans[j].pos, 30, 1, question[i].color);
						break;
					}
				}

				DrawTextEx(font, question[i].question, question[i].pos, 30, 1, question[i].color);
			}

			if (question[i].ans[question[i].currectAns - 1].checked) currectAnswers++;
		}
		buttons(screen, font);

		score = (currectAnswers / questionNum) * 100;
	}
	else if (showAlert) popAlertForEnd(screen, font);
	else if (!isTesting) {
		resultOfTest(screen, font, score);
	}
}
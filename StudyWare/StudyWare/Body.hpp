#pragma once
#include "AppStatus.hpp"

class Body {
public:
	enum class TypeBody {
		ORGANS,
		NERVES,
		SKELETON
	};
	TypeBody typeBody = TypeBody::SKELETON;

	struct Button {
		Rectangle bounds;
		int rounding;
		bool hovering;
		const char* text;
		Color color;
	};
	Button switchBody;

	Body();
	~Body();

	void drawBrain();
	void drawLungs();
	void drawLiver();
	void drawHeart();
	void drawKidney();
	void drawStomach();
	void drawIntestines();
	void drawBody();

	static std::shared_ptr<Body> getInstance();
private:
	static std::shared_ptr<Body> instance;

	Font font;

	float sWidth;
	float sHeight;
	float bodySize;
	float organSize;

	int fontSize;

	bool brainIsActive;
	bool lungsIsActive;
	bool liverIsActive;
	bool heartIsActive;
	bool kidneyIsActive;
	bool stomachIsActive;
	bool intestinesIsActive;

	const char* brainInfo;
	const char* lungsInfo;
	const char* liverInfo;
	const char* heartInfo;
	const char* kidneyInfo;
	const char* stomachInfo;
	const char* intestinesInfo;

	Vector2 mousePosition;
	Vector2 bodyPos;
	Vector2 brainPos;
	Vector2 lungsPos;
	Vector2 liverPos;
	Vector2 heartPos;
	Vector2 kidneyPos;
	Vector2 stomachPos;
	Vector2 intestinesPos;
	Vector2 infoPos;

	Rectangle brainRec;
	Rectangle lungsRec;
	Rectangle liverRec;
	Rectangle heartRec;
	Rectangle kidneyRec;
	Rectangle stomachRec;
	Rectangle intestinesRec;

	Texture2D body;
	Texture2D brain;
	Texture2D lungs;
	Texture2D liver;
	Texture2D heart;
	Texture2D kidney;
	Texture2D stomach;
	Texture2D intestines;
};
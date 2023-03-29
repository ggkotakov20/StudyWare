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

	const char* brainInfo;
	const char* lungsInfo;

	Vector2 mousePosition;
	Vector2 bodyPos;
	Vector2 brainPos;
	Vector2 lungsPos;
	Vector2 infoPos;

	Rectangle brainRec;
	Rectangle lungsRec;

	Texture2D body;
	Texture2D brain;
	Texture2D lungs;
};
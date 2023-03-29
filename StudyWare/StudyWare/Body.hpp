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

	enum class CurrentOrgan {
		NONE,
		BRAIN,
	};
	CurrentOrgan currentOrgan = CurrentOrgan::BRAIN;

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

	const char* brainInfo;

	Vector2 mousePosition;
	Vector2 bodyPos;
	Vector2 brainPos;
	Vector2 infoPos;

	Rectangle brainRec;

	Texture2D body;
	Texture2D brain;
};
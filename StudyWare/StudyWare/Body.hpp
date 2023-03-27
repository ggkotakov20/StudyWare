#pragma once
#include "AppStatus.hpp"

class Body {
public:
	enum class Type {
		ORGANS,
		NERVES,
		SKELETON
	};
	Type typeBody = Type::ORGANS;
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
	void drawBody();
	void switchBodyBtn();

	static std::shared_ptr<Body> getInstance();
private:
	static std::shared_ptr<Body> instance;

	float sWidth;
	float sHeight;
	float bodySize;

	Vector2 mousePosition;


	Texture2D bodyCurrent;
	Texture2D bodyOrgans;
	Texture2D bodyNerves;
	Texture2D bodySkeleton;
};
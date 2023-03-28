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
	//void switchBodyBtn();

	static std::shared_ptr<Body> getInstance();
private:
	static std::shared_ptr<Body> instance;


	float sWidth;
	float sHeight;
	float bodySize;
	float organSize;

	bool brainIsActive;

	Vector2 mousePosition;
	Vector2 bodyPos;
	Vector2 brainPos;

	Rectangle brainRec;

	Texture2D bodyCurrent;
	Texture2D brain;
	//Texture2D bodyOrgans;
	//Texture2D bodyNerves;
	//Texture2D bodySkeleton;
};
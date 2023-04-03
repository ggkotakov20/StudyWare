#pragma once
#include<iostream>
#include<raylib.h>
#include<vector>
#include "Colors.hpp"

class AppStatus {
public:
	enum class Status {
		MENU,
		LEARNING,
		TEST,
		QUIT
	};

	Status status = Status::MENU;

	static std::shared_ptr<AppStatus> getInstance();
private:
	static std::shared_ptr<AppStatus> instance;
};
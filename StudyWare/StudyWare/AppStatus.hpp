#pragma once
#include<iostream>
#include<raylib.h>
#include<vector>

class AppStatus {
public:
	enum class Status {
		Menu,
		Learning,
		Test,
		Quit
	};

	Status status = Status::Menu;

	static std::shared_ptr<AppStatus> getInstant();
private:
	static std::shared_ptr<AppStatus> instant;
};
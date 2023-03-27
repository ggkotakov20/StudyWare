#include "AppStatus.hpp"

std::shared_ptr<AppStatus> AppStatus::instance = nullptr;

std::shared_ptr<AppStatus> AppStatus::getInstance(){
	if (instance == nullptr) instance = std::shared_ptr<AppStatus>(new AppStatus);
	return instance;
}

#include "AppStatus.hpp"

std::shared_ptr<AppStatus> AppStatus::instant = nullptr;

std::shared_ptr<AppStatus> AppStatus::getInstant(){
	if (instant == nullptr) instant = std::shared_ptr<AppStatus>(new AppStatus);
	return instant;
}

#include "AppStatus.hpp"
#include "Menu.hpp"

class AppManage {
private:
	static AppManage* instant;
	std::shared_ptr<Menu> menu;
	
public:
	float sWidth;
	float sHeight;

	AppManage();
	~AppManage();
	void appManage();

	Font fontRomulus;

	static AppManage* getInstant();
};
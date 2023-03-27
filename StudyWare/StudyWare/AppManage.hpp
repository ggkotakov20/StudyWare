#include "AppStatus.hpp"
#include "Menu.hpp"
#include "Body.hpp"

class AppManage {
private:
	float sWidth;
	float sHeight;

	static AppManage* instance;
	std::shared_ptr<Menu> menu;
	std::shared_ptr<Body> app;
	
public:
	AppManage();
	~AppManage();
	void appManage();

	Font fontRomulus;

	static AppManage* getInstance();
};
#include "AppStatus.hpp"
#include "Menu.hpp"
#include "Body.hpp"
#include "TestMode.hpp"

class AppManage {
private:
	float sWidth;
	float sHeight;

	static AppManage* instance;
	std::shared_ptr<Menu> menu;
	std::shared_ptr<Body> body;
	std::shared_ptr<TestMode> test;
	
public:
	AppManage();
	~AppManage();
	void appManage();

	Font fontRomulus;

	static AppManage* getInstance();
};
#include"AppStatus.hpp"
#include"AppManage.hpp"

int main() {

    AppManage* manage = AppManage::getInstance();
    manage->appManage();
    delete manage;
}

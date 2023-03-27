#include"AppStatus.hpp"
#include"AppManage.hpp"

int main() {

    AppManage* manage = AppManage::getInstant();
    manage->appManage();
    delete manage;
}

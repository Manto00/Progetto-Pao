#include "homecontroller.h"

homeController::homeController(HomeView*v, Controller*parent): Controller(v, nullptr, parent)
{
    connectSlots();
}

HomeView* homeController::getView() const {
    return static_cast<HomeView*>(vista);
}

void homeController::connectSlots() const{

}


#include "homecontroller.h"

homeController::homeController(HomeView*v, Controller*parent): Controller(v, nullptr, parent)
{
    connectViewCtrlSignalsSlots();
}

void homeController::connectViewCtrlSignalsSlots() const{

}


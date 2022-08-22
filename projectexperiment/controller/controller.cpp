#include "controller.h"

Controller::Controller(View*v, usermodel*m, Controller*parent): QObject(parent), vista(v), modello(m)
{
    connectSlots();
}

void Controller::connectSlots()const{
    connect(vista,SIGNAL(viewClosed()),this,SLOT(onViewClosed()));
}

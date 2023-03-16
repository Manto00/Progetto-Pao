#include "controller.h"

Controller::Controller(View*v, usermodel*m, Controller*parent): QObject(parent), vista(v), modello(m)
{
    connectSlots();
}

Controller::~Controller() {
    setParent(nullptr);
    for(auto child : children())
        delete child;
    delete vista;
    delete modello;
}

void Controller::connectSlots()const{
    connect(vista,SIGNAL(viewClosed()),this,SLOT(onViewClosed()));
}

void Controller::showView() const{
    vista->show();
}

void Controller::hideView() const{
    vista->hide();
}

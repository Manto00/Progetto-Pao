#include "corsopbutton.h"
#include <controller/controller.h>
#include "iostream"

corsoPButton::corsoPButton(QString title, int numero, View*parent)
{
    mainLayout=new QHBoxLayout(parent);
    mainLayout->setSpacing(70);
    deleteButton=new QPushButton("ELIMINA", parent);
    modButton= new QPushButton("MODIFICA", parent);
    corsoButton=new QPushButton(title, parent);
    mainLayout->addWidget(corsoButton);
    mainLayout->addWidget(deleteButton);
    mainLayout->addWidget(modButton);

    numeroCorso=numero;
}

corsoPButton::~corsoPButton(){
    corsoButton->hide();
    deleteButton->hide();
    modButton->hide();
    delete corsoButton;
    delete deleteButton;
    delete modButton;
    delete mainLayout;
}

int corsoPButton::decreseCorso(){
    return numeroCorso--;
}

int corsoPButton::getNumeroCorso() const{
    return numeroCorso;
}

QHBoxLayout* corsoPButton::getLayout() const{return mainLayout;}
QPushButton* corsoPButton::getDeleteButton()const{return deleteButton;}
QPushButton* corsoPButton::getModificaButton()const{return modButton;}
QPushButton* corsoPButton::getCorsoButton()const{return corsoButton;}



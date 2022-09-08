#include "rowesamiview.h"
#include "controller/controller.h"
#include "iostream"

rowEsamiView::rowEsamiView(const QSize& s,View* parent): View(s, parent)
{
    mainLayout=new QHBoxLayout(this);

    eliminaButton=new QPushButton("Elimina", this);
    salvaButton=new QPushButton("Salva", this);
    mainLayout->addWidget(eliminaButton);
    mainLayout->addWidget(salvaButton);
}

void rowEsamiView::createRow(int esame, int mat, int vot, int app, QDate date, int chi, int ape, int ese, int dur){

    numeroEsame=esame;

    matricola=new QSpinBox(this);
    mainLayout->addWidget(matricola);
    matricola->setMaximum(9999999);
    matricola->setValue(mat);

    voto=new QSpinBox(this);
    mainLayout->addWidget(voto);
    voto->setMaximum(30);
    voto->setValue(vot);

    appello=new QSpinBox(this);
    mainLayout->addWidget(appello);
    appello->setMaximum(5);
    appello->setMinimum(1);
    appello->setValue(app);

    dateBox=new QDateEdit(this);
    mainLayout->addWidget(dateBox);
    dateBox->setMaximumDate(QDate::currentDate());
    dateBox->setDate(date);

    if(chi!=0 || ape!=0 || ese!=0){
        chiuse=new QSpinBox(this);
        mainLayout->addWidget(chiuse);
        chiuse->setValue(chi);

        aperte=new QSpinBox(this);
        mainLayout->addWidget(aperte);
        aperte->setValue(ape);

        esercizi=new QSpinBox(this);
        mainLayout->addWidget(esercizi);
        esercizi->setValue(ese);
    }
    if(dur!=0){
        durata=new QSpinBox(this);
        mainLayout->addWidget(durata);
        durata->setValue(dur);
    }
    if(chiuse->value()==0 && aperte->value()==0 && esercizi->value()==0){
        chiuse->setDisabled(true);
        aperte->setDisabled(true);
        esercizi->setDisabled(true);
    }
    if(durata->value()==0){
        durata->setDisabled(true);
    }
    //ESPERIMENTI!!!!:

}

void rowEsamiView::setController(Controller *c){
    ctrl=c;
    connectViewSignals();
}

QHBoxLayout* rowEsamiView::getLayout() const{return mainLayout;}

QPushButton* rowEsamiView::getSaveButton() const{return salvaButton;}

QPushButton* rowEsamiView::getDeleteButton() const{return eliminaButton;}

int rowEsamiView::getNumeroEsame() const{return numeroEsame;}

int rowEsamiView::getMatricola() const{return matricola->value();}

int rowEsamiView::getVoto() const{return voto->value();}

int rowEsamiView::getAppello() const{return appello->value();}

QDate rowEsamiView::getDate() const{return dateBox->date();}

int rowEsamiView::getChiuse() const{
    if(chiuse->isEnabled())
        return chiuse->value();
    else
        return -1;
}

int rowEsamiView::getDurata() const{
    if(durata->isEnabled())
        return durata->value();
    else
        return -1;
}

int rowEsamiView::getAperte() const{
    if(aperte->isEnabled())
        return aperte->value();
    else
        return -1;
}

int rowEsamiView::getEsercizi() const{
    if(aperte->isEnabled())
        return aperte->value();
    else
        return -1;
}

void rowEsamiView::connectViewSignals() const{
    //connect(eliminaButton, SIGNAL(clicked()), ctrl, SLOT(deleteEsame(numeroEsame)));
    //connect(salvaButton, SIGNAL(clicked()), ctrl, SLOT(modEsame(matricola->value(), voto->value(), appello->value(), dateBox->date(),
                                                                //chiuse->value(), aperte->value(), esercizi->value(), durata->value(),
                                                                //numeroEsame)));
    connect(eliminaButton, &QPushButton::clicked,this,[this](){emit removeRow(numeroEsame);});
    /*connect(salvaButton, &QPushButton::clicked,this,[this](){emit modifyRow(matricola->value(), voto->value(), appello->value(), dateBox->date(),
                chiuse->value(), aperte->value(), esercizi->value(), durata->value(),
                numeroEsame);});*/
    //modEsame
}

int rowEsamiView::decreseEsame(){
    numeroEsame--;
    disconnect(eliminaButton, 0, 0, 0);
    disconnect(salvaButton, 0, 0, 0);
    connect(eliminaButton, &QPushButton::clicked,this,[this](){emit removeRow(numeroEsame);});
    /*connect(salvaButton, &QPushButton::clicked,this,[this](){emit modifyRow(matricola->value(), voto->value(), appello->value(), dateBox->date(),
                chiuse->value(), aperte->value(), esercizi->value(), durata->value(),
                numeroEsame);});*/
    return numeroEsame;
}

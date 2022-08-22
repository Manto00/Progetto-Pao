#include "userview.h"
#include "controller/controller.h"

userView::userView(const QSize& s,View* parent, std::vector<QString> corsi) :
    View(s,parent)
{
    mainLayout=new QVBoxLayout();
    mainLayout->setSpacing(10);
    mainLayout->setMargin(10);

    introLayout=new QHBoxLayout();
    activeLayout=new QHBoxLayout();
    mainLayout->addLayout(introLayout);
    mainLayout->addLayout(activeLayout);

    corsiLayout=new QVBoxLayout();
    chartLayout=new QVBoxLayout();
    activeLayout->addLayout(corsiLayout);
    activeLayout->addLayout(chartLayout);

    newModelButton=new QPushButton("Inizia un nuovo modello", this);
    introLayout->addWidget(newModelButton, Qt::AlignCenter);

    changeModelButton=new QPushButton("Cambia modello", this);
    introLayout->addWidget(changeModelButton, Qt::AlignCenter);

    addButton = new QPushButton("+",this);
    corsiLayout->addWidget(addButton, Qt::AlignJustify);

    newEsame=new QPushButton("Aggiungi un esito", this);
    chartLayout->addWidget(newEsame, Qt::AlignCenter);

    if(corsiButton.size()>0)
    {
        insertCorsi(corsi);
    }

    //implementazione
    setLayout(mainLayout);

    //Connessione dei SIGNAL dei Widget al Signal della AdminView
    connectViewSignals();
}

void userView::setController(Controller *c){
    ctrl=c;
}

//usando il filepiker crea una lista di pushbutton per ogni corso
void userView::insertCorsi(std::vector<QString> listaCorsi){
    unsigned int i=0;
    for(auto it=listaCorsi.begin(); it!=listaCorsi.end(); it++){
        QPushButton*corsoButton=new QPushButton(*it);
        corsiLayout->addWidget(corsoButton);
        connect(corsoButton, SIGNAL(clicked()), ctrl, SLOT(showChart(i)));
        i++;
    }
}

//in base al corso selezionato crea i suoi grafici
//come parametri ha i singoli dati del corso, non il corso stesso
void userView::createCharts(){}

void userView::connectViewSignals() const{}

void userView::closeEvent(QCloseEvent* event){}

//fare una funzione che inserisca i button nel corsiLayout
/*
void userView::insertCorsi(std::vector<Corsi*> input){
    std::vector<Corsi*>::iterator it;
    for(it=input.begin; it!=input.end; it++){
        QPushButton*bottone=new QPushButton(input->getnome(), this);
        corsiButton.pushback(Button);
        }
}

*/

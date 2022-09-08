#include "userview.h"
#include "controller/controller.h"
#include "iostream"

userView::userView(const QSize& s,View* parent) :
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
    fieldLayout=new QVBoxLayout();
    chartBaseLayout=new QHBoxLayout();
    chartSpecificiLayout=new QHBoxLayout();
    activeLayout->addLayout(corsiLayout, 1);
    activeLayout->addLayout(chartLayout,90);
    activeLayout->addLayout(fieldLayout, 5);
    chartLayout->setSizeConstraint(QLayout::SetMaximumSize);
    chartLayout->addLayout(chartBaseLayout,50);
    chartLayout->addLayout(chartSpecificiLayout,50);



    salvaModello=new QPushButton("Salva", this);
    introLayout->addWidget(salvaModello, Qt::AlignCenter);

    salvaCome=new QPushButton("Salva come", this);
    introLayout->addWidget(salvaCome, Qt::AlignCenter);

    addCorsoButton= new QPushButton("Aggiungi un corso",this);
    corsiLayout->addWidget(addCorsoButton);

    noChart=new QLabel("Nessun corso selezionato, per osservare le statistiche seleziona un corso \n"
                       "(se non è presente nessun corso puoi crearne uno premendo su Aggiungi un corso)");
    chartBaseLayout->addWidget(noChart, Qt::AlignHCenter);

    //aggiornaButton=new QPushButton("Aggiorna grafici", this);
    //chartLayout->addWidget(aggiornaButton, Qt::AlignCenter);

    createInsertField();
    //implementazione
    setLayout(mainLayout);

}

void userView::setController(Controller *c){
    ctrl=c;
    //Connessione dei SIGNAL dei Widget al Signal della UserView
    connectViewSignals();
}

//usando il filepiker crea una lista di pushbutton per ogni corso
void userView::insertCorsi(std::vector<QString> listaCorsi){
    for(unsigned int i=0; listaCorsi.size()>i; i++){
        corsoPButton*corsoButton=new corsoPButton(listaCorsi[i], i, this);
        //corsoButton->setController(ctrl);
        corsiLayout->addLayout(corsoButton->getLayout());
        corsiVec.push_back(corsoButton);
    }
}

void userView::createPassChart(unsigned int primo, unsigned int secondo, unsigned int terzo, unsigned int quarto, unsigned int quinto){
    QPieSeries *series = new QPieSeries();
    series->append("Primo", primo);
    series->append("Secondo", secondo);
    series->append("Terzo", terzo);
    series->append("Quarto", quarto);
    series->append("Quinto", quinto);

    //impostazioni
    QPieSlice *slice = series->slices().at(1);
    slice->setExploded(true);
    slice->setLabelVisible(true);
    slice->setPen(QPen(Qt::darkGreen, 2));
    slice->setBrush(Qt::green);


    passChart = new QChart();
    passChart->addSeries(series);
    passChart->setTitle("Esami superati ad ogni appello");


    passChartView = new QChartView(passChart);
    //passChartView->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    chartSpecificiLayout->addWidget(passChartView, 1);

    /*QScrollArea*area=new QScrollArea();
    area->setWidget(passChartView);
    area->setLayout(chartLayout);
    area->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    area->resize(300,300);
    activeLayout->addWidget(area);*/

}

void userView::createPromossiperYearChart(std::vector<unsigned int> promossi, std::vector<unsigned int> bocciati){
    QBarSet *set0 = new QBarSet("Promossi");
    QBarSet *set1 = new QBarSet("Bocciati");
    int max=100;
    if(promossi.size()>=bocciati.size())
        max=promossi.size();
    else
        max=bocciati.size();

    //inserimento dati
    *set0 << promossi[4] << promossi[3] << promossi[2] << promossi[1] << promossi[0];
    *set1 << bocciati[4] << bocciati[3] << bocciati[2] << bocciati[1] << bocciati[0];

    QBarSeries *barSeries = new QBarSeries();
    barSeries->append(set0);
    barSeries->append(set1);

    //impostazioni e altre categorie
    barChart = new QChart();
    barChart->addSeries(barSeries);
    barChart->setTitle("Esiti positivi e negativi degli ultimi 5 anni");
    barChart->setAnimationOptions(QChart::SeriesAnimations);
    QStringList categories;
    categories << QString::number((QDate::currentDate().year()-4)) << QString::number((QDate::currentDate().year()-3)) <<
                  QString::number((QDate::currentDate().year()-2)) << QString::number((QDate::currentDate().year()-1)) <<
                  QString::number((QDate::currentDate().year()));
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    barChart->addAxis(axisX, Qt::AlignBottom);
    barSeries->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, max);
    barChart->addAxis(axisY, Qt::AlignLeft);
    barSeries->attachAxis(axisY);

    barChart->legend()->setVisible(true);
    barChart->legend()->setAlignment(Qt::AlignBottom);
    barChartView = new QChartView(barChart);
    barChartView->setRenderHint(QPainter::Antialiasing);

    chartBaseLayout->addWidget(barChartView,1);

}

void userView::createVotiChart(std::vector<unsigned int> voti){
    //LINE CHART
    //inseriemento dati
    QLineSeries *lineSeries = new QLineSeries();
    for(int i=0; i!=30; i++){
        lineSeries->append(i, voti[i]);
    }

    //impostazioni
    QChart *votiChart = new QChart();
    votiChart->legend()->hide();
    votiChart->addSeries(lineSeries);
    votiChart->createDefaultAxes();
    votiChart->setTitle("Distribuzione dei voti");

    votiChartView = new QChartView(votiChart);
    votiChartView->setRenderHint(QPainter::Antialiasing);

    chartBaseLayout->addWidget(votiChartView,1);
}

void userView::createDurataChart(std::list<unsigned int> durata){
        QLineSeries *series = new QLineSeries();
        unsigned int i=0;
        unsigned int cnt;
        unsigned int max=0;
        while(i<=50){
            cnt = std::count(durata.begin(), durata.end(), i);
            series->append(i, cnt);
            if(cnt>max)
                max=cnt;
            i++;
        }
        series->setName("Durata");
        QPen pen(0x059605);
        pen.setWidth(3);
        series->setPen(pen);

        QLinearGradient gradient(QPointF(0, 0), QPointF(0, 1));
        gradient.setColorAt(0.0, 0x3cc63c);
        gradient.setColorAt(1.0, 0x26f626);
        gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
        series->setBrush(gradient);

        QChart *durataChart = new QChart();
        durataChart->addSeries(series);
        durataChart->setTitle("Durata prove orali");
        durataChart->createDefaultAxes();
        durataChart->axes(Qt::Horizontal).first()->setRange(0, 50);
        durataChart->axes(Qt::Vertical).first()->setRange(0, max);

        durChartView = new QChartView(durataChart);
         chartBaseLayout->addWidget(durChartView,1);
}

void userView::createEsChart(float aperte, float chiuse, float esercizi){
    QPieSeries *series = new QPieSeries();
    series->append("Aperte", aperte);
    series->append("Chiuse", chiuse);
    series->append("Esercizi", esercizi);

    //impostazioni
    QPieSlice *slice = series->slices().at(1);
    slice->setExploded(true);
    slice->setLabelVisible(true);
    slice->setPen(QPen(Qt::darkGreen, 2));
    slice->setBrush(Qt::green);


    esChart = new QChart();
    esChart->addSeries(series);
    esChart->setTitle("Distribuzione quesiti prova scritta");


    esChartView = new QChartView(esChart);
    chartSpecificiLayout->addWidget(esChartView,1);
}

void userView::destroyChartsBase(){
    /*barChart->hide();
    esChart->hide();
    passChart->hide();
    votiChart->hide();
    durataChart->hide();*/
    chartLayout->removeWidget(passChartView);
    delete passChartView;
    chartLayout->removeWidget(votiChartView);
    delete votiChartView;
    chartLayout->removeWidget(barChartView);
    delete barChartView;
}

void userView::destroyChartsOrali(){
    chartLayout->removeWidget(durChartView);
    delete durChartView;
}

void userView::destroyChartsScritti(){
    chartLayout->removeWidget(esChartView);
    delete esChartView;

}

void userView::createInsertField(){
    addEsameButton=new QPushButton("Aggiungi un esito", this);
    organizzaEsamiButton=new QPushButton("Elimina/Modifica esami", this);
    QLabel*matricolaLabel=new QLabel("inserisci matricola:", this);
    QLabel*votoLabel=new QLabel("inserisci il voto:", this);
    QLabel*appelloLabel=new QLabel("inserisci l'appello:", this);
    QLabel*dateLabel=new QLabel("inserisci la data dell'esame:", this);
    QLabel*chiuseLabel=new QLabel("inserisci il numero di domande chiuse:", this);
    QLabel*aperteLabel=new QLabel("inserisci il numero di domande aperte:", this);
    QLabel*eserciziLabel=new QLabel("inserisci il numero di esercizi:", this);
    QLabel*durataLabel=new QLabel("inserisci la durata(se è un esame orale):", this);

    matricolaField=new QSpinBox;
    matricolaField->setMaximum(9999999);
    votoField=new QSpinBox(this);
    votoField->setMaximum(30);
    appelloField=new QSpinBox(this);
    appelloField->setMaximum(5);
    appelloField->setMinimum(1);
    dateField=new QDateEdit(this);
    dateField->setMaximumDate(QDate::currentDate());
    chiuseField=new QSpinBox(this);
    aperteField=new QSpinBox(this);
    eserciziField=new QSpinBox(this);
    durataField=new QSpinBox(this);

    fieldLayout->addWidget(addEsameButton, Qt::AlignCenter);
    fieldLayout->addWidget(organizzaEsamiButton, Qt::AlignCenter);
    fieldLayout->addWidget(matricolaLabel);
    fieldLayout->addWidget(matricolaField);
    fieldLayout->addWidget(votoLabel);
    fieldLayout->addWidget(votoField);
    fieldLayout->addWidget(appelloLabel);
    fieldLayout->addWidget(appelloField);
    fieldLayout->addWidget(dateLabel);
    fieldLayout->addWidget(dateField);
    fieldLayout->addWidget(chiuseLabel);
    fieldLayout->addWidget(chiuseField);
    fieldLayout->addWidget(aperteLabel);
    fieldLayout->addWidget(aperteField);
    fieldLayout->addWidget(eserciziLabel);
    fieldLayout->addWidget(eserciziField);
    fieldLayout->addWidget(durataLabel);
    fieldLayout->addWidget(durataField);

}

void userView::addCorso(QString title){
    corsoPButton*nuovo=new corsoPButton(title, corsiVec.size());
    corsiVec.push_back(nuovo);
    corsiLayout->addLayout(nuovo->getLayout());
    unsigned int i=corsiVec.size()-1;
    connect(corsiVec[i]->getCorsoButton(),
            &QPushButton::clicked,
            ctrl,
            [=]() { emit selectCorso(i); });

    connect(corsiVec[i]->getModificaButton(),
            &QPushButton::clicked,
            ctrl,
            [=]() { emit modCorso(corsiVec[corsiVec.size()-1]->getNumeroCorso()); });

    connect(corsiVec[i]->getDeleteButton(),
            &QPushButton::clicked,
            ctrl,
            [=]() { emit deleteCorso(i);});
}

void userView::removeCorso(int posizione){
    delete corsiVec[posizione];
    corsiVec.erase(corsiVec.begin()+posizione);

    for(unsigned int i=0; corsiVec.size()>i; i++){

        disconnect(corsiVec[i]->getCorsoButton(),0,0,0);
        disconnect(corsiVec[i]->getDeleteButton(),0,0,0);
        disconnect(corsiVec[i]->getModificaButton(),0,0,0);

        connect(corsiVec[i]->getCorsoButton(),
                &QPushButton::clicked,
                ctrl,
                [=]() { emit selectCorso(corsiVec[i]->getNumeroCorso()); });

        connect(corsiVec[i]->getModificaButton(),
                &QPushButton::clicked,
                ctrl,
                [=]() { emit modCorso(corsiVec[i]->getNumeroCorso()); });

        connect(corsiVec[i]->getDeleteButton(),
                &QPushButton::clicked,
                ctrl,
                [=]() { emit deleteCorso(corsiVec[i]->getNumeroCorso()); std::cout<<"nuova connect: "<<i ;});
    }
}

void userView::resetFields(){
    matricolaField->setValue(0);
    votoField->setValue(0);
    appelloField->setValue(0);
    dateField->setDate(QDate::currentDate());
    chiuseField->setValue(0);
    aperteField->setValue(0);
    eserciziField->setValue(0);
    durataField->setValue(0);
}

std::vector<corsoPButton*> userView::getCorsoVector(){
    return corsiVec;
}

void userView::connectViewSignals() const{
    //connect(addEsameButton, SIGNAL(clicked()), ctrl, SLOT(insertEsame(int matricolaField->value(), int votoField->value(),
            //int appelloField->value(), QDate dateField->value(), int chiuseField->value(), int aperteField->value(),
            //int eserciziField->value(), int durataField->value())));
    connect(salvaModello, SIGNAL(clicked()), ctrl, SLOT(onSave()));
    connect(salvaCome, SIGNAL(clicked()), ctrl, SLOT(onSaveAs()));
    connect(addCorsoButton, SIGNAL(clicked()), ctrl, SLOT(onInsertCorso()));
    //connect(aggiornaButton, SIGNAL(clicked()), ctrl, SLOT(onShowChart()));
    connect(organizzaEsamiButton, SIGNAL(clicked()), ctrl, SLOT(onOrganizzaEsami())); //CONNETTERE organizzaEsamiButton
    connect(addEsameButton, &QPushButton::clicked,ctrl,[this](){emit insertEsame(matricolaField->value(), votoField->value(), appelloField->value(),
                                                                                 dateField->date(), chiuseField->value(), aperteField->value(),
                                                                                 eserciziField->value(), durataField->value());});
    for(unsigned int i=0; corsiVec.size()>i; i++){

        connect(corsiVec[i]->getCorsoButton(),
                &QPushButton::clicked,
                ctrl,
                [=]() { emit selectCorso(corsiVec[i]->getNumeroCorso()); });

        connect(corsiVec[i]->getModificaButton(),
                &QPushButton::clicked,
                ctrl,
                [=]() { emit modCorso(corsiVec[i]->getNumeroCorso()); });

        connect(corsiVec[i]->getDeleteButton(),
                &QPushButton::clicked,
                ctrl,
                [=]() { emit deleteCorso(corsiVec[i]->getNumeroCorso()); });
    }
}

void userView::hideDefaultLabel() const{
    noChart->hide();
}

void userView::showDefaultLabel() const{
    noChart->show();
}

void userView::closeEvent(QCloseEvent* event){
    if(!event->spontaneous()) return;
    if(!showQuestionDialog(2,"Exit","Chiudere l'applicazione?\n")){
        event->ignore();
    } else {
        event->accept();
        emit viewClosed();
    }
}



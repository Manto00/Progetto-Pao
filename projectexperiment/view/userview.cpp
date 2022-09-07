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
    activeLayout->addLayout(corsiLayout);
    activeLayout->addLayout(chartLayout);
    activeLayout->addLayout(fieldLayout);

    newModelButton=new QPushButton("Inizia un nuovo modello", this);
    introLayout->addWidget(newModelButton, Qt::AlignCenter);

    changeModelButton=new QPushButton("Cambia modello", this);
    introLayout->addWidget(changeModelButton, Qt::AlignCenter);

    addCorsoButton= new QPushButton("+",this);
    corsiLayout->addWidget(addCorsoButton, Qt::AlignJustify);

    aggiornaButton=new QPushButton("Aggiorna grafici", this);
    chartLayout->addWidget(aggiornaButton, Qt::AlignCenter);

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
    series->append("Primo appello", primo);
    series->append("Secondo appello", secondo);
    series->append("Terzo appello", terzo);
    series->append("Quarto appello", quarto);
    series->append("Quinto appello", quinto);

    //impostazioni
    QPieSlice *slice = series->slices().at(1);
    slice->setExploded(true);
    slice->setLabelVisible(true);
    slice->setPen(QPen(Qt::darkGreen, 2));
    slice->setBrush(Qt::green);


    passChart = new QChart();
    passChart->addSeries(series);
    passChart->setTitle("Qt5 Pie Chart Example");


    QChartView *chartview = new QChartView(passChart);
    chartLayout->addWidget(chartview);
}

void userView::createPromossiperYearChart(std::vector<unsigned int> promossi, std::vector<unsigned int> bocciati){
    QBarSet *set0 = new QBarSet("Promossi");
    QBarSet *set1 = new QBarSet("Bocciati");

    //inserimento dati
    int p=promossi.front();
    int b=bocciati.front();
    *set0 << p+4 << p+3 << p+2 << p+1 << p;
    *set1 << b+4 << b+3 << b+2 << b+1 << b;

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
    axisY->setRange(0, 200);
    barChart->addAxis(axisY, Qt::AlignLeft);
    barSeries->attachAxis(axisY);

    barChart->legend()->setVisible(true);
    barChart->legend()->setAlignment(Qt::AlignBottom);
    QChartView *barChartView = new QChartView(barChart);
    barChartView->setRenderHint(QPainter::Antialiasing);

    chartLayout->addWidget(barChartView);

}

void userView::createVotiChart(std::vector<unsigned int> voti){
    //LINE CHART
    //inseriemento dati
    QLineSeries *lineSeries = new QLineSeries();
    for(int i=0; i!=31; i++){
        lineSeries->append(i, voti[i]);
    }

    //impostazioni
    QChart *votiChart = new QChart();
    votiChart->legend()->hide();
    votiChart->addSeries(lineSeries);
    votiChart->createDefaultAxes();
    votiChart->setTitle("Distribuzione dei voti");

    QChartView *lineChartView = new QChartView(votiChart);
    lineChartView->setRenderHint(QPainter::Antialiasing);

    chartLayout->addWidget(lineChartView);
}

void userView::createDurataChart(std::list<unsigned int> durata){
        QLineSeries *series = new QLineSeries();
        unsigned int i=0;
        unsigned int cnt;
        //QUESTO CICLO FA CRASHARE IL PROGRAMMA
        while(i<=50){
            cnt = std::count(durata.begin(), durata.end(), i);
            series->append(i, cnt);
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
        durataChart->axes(Qt::Horizontal).first()->setRange(0, 20);
        durataChart->axes(Qt::Vertical).first()->setRange(0, 10);

        QChartView *chartView = new QChartView(durataChart);
         chartLayout->addWidget(chartView);
}

void userView::createEsChart(unsigned int aperte, unsigned int chiuse, unsigned int esercizi){
    QPieSeries *series = new QPieSeries();
    series->append("Primo appello", aperte);
    series->append("Secondo appello", chiuse);
    series->append("Terzo appello", esercizi);

    //impostazioni
    QPieSlice *slice = series->slices().at(1);
    slice->setExploded(true);
    slice->setLabelVisible(true);
    slice->setPen(QPen(Qt::darkGreen, 2));
    slice->setBrush(Qt::green);


    esChart = new QChart();
    esChart->addSeries(series);
    esChart->setTitle("Distribuzione quesiti prova scritta");


    QChartView *chartview = new QChartView(esChart);
    chartLayout->addWidget(chartview);
}

void userView::destroyCharts(){
    barChart->hide();
    esChart->hide();
    passChart->hide();
    votiChart->hide();
    durataChart->hide();

    delete barChart;
    delete esChart;
    delete passChart;
    delete votiChart;
    delete durataChart;
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
            [=]() { emit insertCorso(corsiVec[corsiVec.size()-1]->getNumeroCorso()); });

    connect(corsiVec[i]->getDeleteButton(),
            &QPushButton::clicked,
            ctrl,
            [=]() { emit deleteCorso(i); std::cout<<"       elimina questa cella"<<corsiVec.size()-1;});
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
                [=]() { emit insertCorso(corsiVec[i]->getNumeroCorso()); });

        connect(corsiVec[i]->getDeleteButton(),
                &QPushButton::clicked,
                ctrl,
                [=]() { emit deleteCorso(corsiVec[i]->getNumeroCorso()); std::cout<<"nuova connect: "<<i ;});
    }
}


std::vector<corsoPButton*> userView::getCorsoVector(){
    return corsiVec;
}

void userView::connectViewSignals() const{
    //connect(addEsameButton, SIGNAL(clicked()), ctrl, SLOT(insertEsame(int matricolaField->value(), int votoField->value(),
            //int appelloField->value(), QDate dateField->value(), int chiuseField->value(), int aperteField->value(),
            //int eserciziField->value(), int durataField->value())));
    connect(addCorsoButton, SIGNAL(clicked()), ctrl, SLOT(onInsertCorso()));
    connect(aggiornaButton, SIGNAL(clicked()), ctrl, SLOT(onShowChart()));
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
                [=]() { emit insertCorso(corsiVec[i]->getNumeroCorso()); });

        connect(corsiVec[i]->getDeleteButton(),
                &QPushButton::clicked,
                ctrl,
                [=]() { emit deleteCorso(corsiVec[i]->getNumeroCorso()); });
    }
}

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

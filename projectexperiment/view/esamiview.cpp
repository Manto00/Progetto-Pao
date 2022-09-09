#include "esamiview.h"
#include "controller/controller.h"

esamiView::esamiView(const QSize& s,View* parent): View(s, parent)
{   
    home=new QPushButton("torna alla Home", this);
    QLabel*space=new QLabel("  ", this);
    QLabel*mat=new QLabel("Matricola",this);
    QLabel*vot=new QLabel("Voto", this);
    QLabel*app=new QLabel("Appello", this);
    QLabel*dat=new QLabel("Data", this);
    QLabel*chi=new QLabel("Domande Chiuse", this);
    QLabel*ape=new QLabel("Domande aperte", this);
    QLabel*ese=new QLabel("Esercizi", this);
    QLabel*dur=new QLabel("Durata", this);

    labelLayout=new QHBoxLayout();
    labelLayout->setMargin(10);
    labelLayout->setSpacing(25);
    labelLayout->setContentsMargins(12, 50, 25, 50);
    mainLayout=new QVBoxLayout();
    esamiLayout=new QVBoxLayout();

    QWidget* scrollAreaContent = new QWidget;
    scrollAreaContent->setLayout( esamiLayout );
    QScrollArea* scrollArea = new QScrollArea;
    scrollArea->setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
    scrollArea->setVerticalScrollBarPolicy( Qt::ScrollBarAsNeeded );
    scrollArea->setWidgetResizable( true );
    scrollArea->setWidget( scrollAreaContent );

    labelLayout->addWidget(home, Qt::AlignJustify);
    labelLayout->addWidget(space, 10, Qt::AlignJustify);
    labelLayout->addWidget(mat, Qt::AlignJustify);
    labelLayout->addWidget(vot, Qt::AlignJustify);
    labelLayout->addWidget(app, Qt::AlignJustify);
    labelLayout->addWidget(dat, Qt::AlignJustify);
    labelLayout->addWidget(chi, Qt::AlignJustify);
    labelLayout->addWidget(ape, Qt::AlignJustify);
    labelLayout->addWidget(ese, Qt::AlignJustify);
    labelLayout->addWidget(dur, Qt::AlignJustify);

    mainLayout->addLayout(labelLayout, 5);
    mainLayout->addWidget(scrollArea, 95);
    setLayout(mainLayout);

    connectViewSignals();
}


std::vector<rowEsamiView*> esamiView::getRows() const{
    return rowVector;
}

void esamiView::connectViewSignals() const{}


void esamiView::createEsamiTable(int esami[][7], std::vector<QDate> date, int dim){
    connect(home, SIGNAL(clicked()), ctrl, SLOT(onHome()));
    int i=0;
    while(i<dim){
        rowEsamiView* riga=new rowEsamiView();
        riga->createRow(i, esami[i][0],  esami[i][1],  esami[i][2], date[i],  esami[i][3],  esami[i][4],  esami[i][5],  esami[i][6]);
        riga->setController(ctrl);


        connect(riga->getSaveButton(), &QPushButton::clicked, ctrl, [=](){emit modifyRow(i);});

        connect(riga->getDeleteButton(), &QPushButton::clicked, ctrl, [=](){emit eliminaRiga(i);});
        rowVector.push_back(riga);
        esamiLayout->addWidget(riga);
        i++;
    }
}

void esamiView::deleteRiga(int i){
    delete rowVector[i];
    rowVector.erase(rowVector.begin()+i);
    int d;
    while(i<rowVector.size()){
    disconnect(rowVector[i], 0, 0, 0);
    d=rowVector[i]->decreseEsame();
    connect(rowVector[i]->getSaveButton(), &QPushButton::clicked, ctrl, [=](){emit modifyRow(d);});
    connect(rowVector[i]->getDeleteButton(), &QPushButton::clicked, ctrl, [=](){emit eliminaRiga(d);});
        i++;
    }
}

void esamiView::closeEvent(QCloseEvent* event){
    if(!event->spontaneous()) return;
    if(!showQuestionDialog(2,"Exit","Chiudere l'applicazione?\n")){
        event->ignore();
    } else {
        event->accept();
        emit viewClosed();
    }
}

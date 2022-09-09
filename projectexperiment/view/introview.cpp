#include "introview.h"
#include "controller/controller.h"

introView::introView(const QSize& s, View* parent): View(s, parent)
{
    mainLayout=new QVBoxLayout();
    mainLayout->setSpacing(10);
    mainLayout->setMargin(10);

    QLabel*presentazione=new QLabel("Benvenuto/a, quest'applicazione ti permetterà di prepararti meglio ai tuoi prossimi esami \n"
                                    "Bene iniziamo, scegli se creare un nuovo set di dati o usarne uno già esistente");
    mainLayout->addWidget(presentazione, Qt::AlignJustify);

    newModel=new QPushButton("Inizia un nuovo modello", this);
    mainLayout->addWidget(newModel, Qt::AlignCenter);

    openModel=new QPushButton("Apri un modello esistente", this);
    mainLayout->addWidget(openModel, Qt::AlignCenter);

    setLayout(mainLayout);
}

void introView::setController(Controller *c){
    ctrl=c;
    connectViewSignals();
}

void introView::connectViewSignals() const{
    connect(newModel, SIGNAL(clicked()), ctrl, SLOT(onNewModel()));
    connect(openModel, SIGNAL(clicked()), ctrl, SLOT(onOpenView()));
}

void introView::closeEvent(QCloseEvent* event){
    if(!event->spontaneous()) return;

    if(!showQuestionDialog(2,"Exit","Chiudere l'applicazione?\n")){
        event->ignore();
    } else {
        event->accept();
        emit viewClosed();
    }
}

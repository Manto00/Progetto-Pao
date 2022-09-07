#include "introview.h"
#include "controller/controller.h"

introView::introView(const QSize& s, View* parent): View(s, parent)
{
    mainLayout=new QVBoxLayout();
    mainLayout->setSpacing(10);
    mainLayout->setMargin(10);

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
    //Elaboro chiusura solo se intenzionata da evento esterno
    if(!event->spontaneous()) return;

    if(!showQuestionDialog(2,"Exit","Chiudere l'applicazione?\n")){
        //Ignoro l'evento di chiusura
        event->ignore();
    } else {
        //Accetto l'evento di chiusura della Window
        event->accept();
        //Emetto segnale di chiusura della View
        emit viewClosed();
    }
}

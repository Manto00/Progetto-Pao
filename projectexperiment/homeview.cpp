#include "homeview.h"

/*NOTES
 * maye avrebbe più senso fare 5 layout verticali per ogni grafico, contenente: grafico, pulsante e descrizione.
 * Probabilmente ridimensionerebbe meglio
*/

HomeView::HomeView(const QSize& s,View* parent) : View(s,parent)
{
    QVBoxLayout* mainLayout = new QVBoxLayout;
    QVBoxLayout* contentLayout = new QVBoxLayout;
    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);

    //creazione del title layout
    mainLayout->addLayout(createTitleLayout(tr("Exam manager ti permette di fare un sacco di cose ganze"), "D:/Pictures/Saved Pictures/geroglifici.jpg"));

    //creazione button layout
    mainLayout->addLayout(createButtonsLayout());

    //creazione del content layout
    mainLayout->addLayout(contentLayout);
    /*
     * contentLayout->addLayout(createExamLayout());
     */
    contentLayout->addLayout(createChartLayout());


    //Imposto il Layout alla View per essere visualizzata
    setLayout(mainLayout);

    //Connessione dei SIGNAL dei Widget al Signal della HomeView
    connectViewSignals();
}

QLayout* HomeView::createTitleLayout(const QString& description, const QString& imgPath){
    //Parte destra immagine e descrizione
    QVBoxLayout* descrLayout = new QVBoxLayout;
    //Immagine stampante descrizione
    QLabel* img = new QLabel(this);
    QPixmap pic = QPixmap(imgPath);
    pic = pic.scaledToHeight(250);
    img->setPixmap(pic);
    img->setFixedSize(250,250);
    descrLayout->addWidget(img,Qt::AlignHCenter);

    //Descrizione
    QLabel* title = new QLabel("Exam Manager",this);
    QFont font("Calibri", 20);
    title->setFont(font);
    title->setAlignment(Qt::AlignHCenter);
    descrLayout->addWidget(title);

    QLabel* desc = new QLabel(description,this);
    QFont f("Calibri", 9);
    desc->setFont(f);
    desc->setAlignment(Qt::AlignHCenter);
    descrLayout->addWidget(desc);

    return descrLayout;
}

QLayout* HomeView::createButtonsLayout(){
    QHBoxLayout* buttonsLayout = new QHBoxLayout;

    buttonsLayout->setMargin(10);
    buttonsLayout->setSpacing(120);
    buttonsLayout->setContentsMargins(25,50,12,50);
    buttonsLayout->setAlignment(Qt::AlignCenter);

    modifyButton = new QPushButton("Aggiungi o elimina i tuoi esami",this);
    newButton = new QPushButton("Aggiungi o elimina una recensione",this);
    modifyButton->setFixedSize(250,50);
    newButton->setFixedSize(250,50);
    buttonsLayout->addWidget(modifyButton);
    buttonsLayout->addWidget(newButton);

    return buttonsLayout;
}

QLayout* HomeView::createChartLayout(){

    QVBoxLayout* descrLayout = new QVBoxLayout;
    descrLayout->setContentsMargins(3, 7, 5, 7);

    QHBoxLayout* groupLayout = new QHBoxLayout;
    groupLayout->setMargin(2);
    groupLayout->setSpacing(2);
    groupLayout->setContentsMargins(0, 0, 0, 0);

    QGroupBox* gruppo = new QGroupBox("Grafico 1",this);
    gruppo->setLayout(descrLayout);
    groupLayout->addWidget(gruppo);

    return groupLayout;
}

void HomeView::connectViewSignals() const{
    connect(modifyButton,SIGNAL(clicked()),this,SIGNAL(newProject()));
    connect(newButton,SIGNAL(clicked()),this,SIGNAL(openProject()));
}


void HomeView::closeEvent(QCloseEvent* event){
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




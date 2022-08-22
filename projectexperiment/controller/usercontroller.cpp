#include "usercontroller.h"

userController::userController(userView* v, usermodel* m, Controller* parent): Controller(v, m, parent)
{
    connectSlots();

    //è essenziale che si crei prima la materialTable e solo poi la record table
    //Questo perchè in caso contrario si verificano dei problemi sulle QComboBox della
    //view che vengono registrati doppiamente.

    //Creo la Material Table
    std::vector<QString> stringVec;
    std::vector<Corso*> corsoVec=getModel()->getCorsi();
    unsigned int i=0;
    while(corsoVec[i]){
        stringVec.push_back(corsoVec[i]->getnome());
    }
    getView()->insertCorsi(stringVec);
}

userView* userController::getView() const {
    return static_cast<userView*>(vista);
}

usermodel* userController::getModel() const {
    return static_cast<usermodel*>(modello);
}

void userController::connectSlots()const{

    connect(vista, SIGNAL(showChart(i)), this, SLOT(onShowChart(i)));
    //connessioni per la RecordTable
/*    connect(view,SIGNAL(recordTableRemoved(uint)),this,SLOT(onRecordTableRemoved(uint)));
    connect(view,SIGNAL(recordTableAdded(QString,uint,uint,QDate)),this,SLOT(onRecordTableAdded(QString,uint,uint,QDate)));
    connect(view,SIGNAL(recordTableMaterialeMod(uint,QString)),this,SLOT(onRecordTableMaterialeMod(uint,QString)));
    connect(view,SIGNAL(recordTableDurataMod(uint,uint)),this,SLOT(onRecordTableDurataMod(uint,uint)));
    connect(view,SIGNAL(recordTableMatUsatoMod(uint,uint)),this,SLOT(onRecordTableMatUsatoMod(uint,uint)));
    connect(view,SIGNAL(recordTableDataMod(uint,QDate)),this,SLOT(onRecordTableDataMod(uint,QDate)));

    //connessioni per la ModelTable
    connect(view,SIGNAL(materialTableAdded(QString)),this,SLOT(onMaterialTableAdded(QString)));
    connect(view,SIGNAL(materialTableRemoved(uint)),this,SLOT(onMaterialTableRemoved(uint)));
    connect(view,SIGNAL(materialTableMaterialeMod(uint,QString)),this,SLOT(onMaterialTableMaterialeMod(uint,QString)));

    //connessioni per i pulsanti di interrazione
    connect(view,SIGNAL(newBPressed()),this,SLOT(onNewBPressed()));
    connect(view,SIGNAL(saveBPressed()),this,SLOT(onSaveBPressed()));
    connect(view,SIGNAL(saveAsBPressed()),this,SLOT(onSaveAsBPressed()));
    connect(view,SIGNAL(homeBPressed()),this,SLOT(onHomeBPressed()));

    connect(view,SIGNAL(pieChartBPressed(bool)),this,SLOT(onPieChartBPressed(bool)));
    connect(view,SIGNAL(lineChartBPressed()),this,SLOT(onLineChartBPressed()));
    connect(view,SIGNAL(barChartBPressed(bool)),this,SLOT(onBarChartBPressed(bool)));*/
}

void userController::onShowChart(int i) const{
    //recuperare i dati dal model
    Corso*cor=getModel()->getCorso(i);
    std::vector<Esame*>es=cor->getEsami();

    //creare struttura base per esame
    std::list<unsigned int> listaVoto;
    std::list<unsigned int> listaAppello;
    //std::list<unsigned int> listaMatricola;   (aggiungere se serve)
    std::list<QDate> listaData;

    //creare struttura esame scritto
    std::list<unsigned int> listaAperte;
    std::list<unsigned int> listaChiuse;
    std::list<unsigned int> listaEsercizi;

    //creare struttura dati per un esame orale
    std::list<unsigned int> listaDurata;

    bool isScritto=false;
    bool isOrale=false;

    for(auto it=es.begin(); it!=es.end(); it++){
        //inserire dati esame base
        listaVoto.push_back((*it)->getvoto());
        listaAppello.push_back((*it)->getappello());
        listaData.push_back((*it)->getdata());
        EsameScritto*sCasted=dynamic_cast<EsameScritto*>(*it);
        EsameOrale*oCasted=dynamic_cast<EsameOrale*>(*it);
        if(sCasted){
            //inserire i dati dell'esame scritto
            listaAperte.push_back((sCasted)->getaperte());
            listaChiuse.push_back((sCasted)->getchiuse());
            listaEsercizi.push_back((sCasted)->getesercizi());
            isScritto=true;
        }
        else if(oCasted){
            //inserire i dati dell'esame orale
            listaDurata.push_back((oCasted)->getdurata());
            isOrale=true;
        }
        else{
            //errore
        }
    }
    //sfruttare overloading della funzione createCharts
    if(isScritto){
        if(isOrale)
            getView()->createCharts(listaVoto, listaAppello, listaData, listaAperte, listaChiuse, listaEsercizi, listaDurata);
        getView()->createCharts(listaVoto, listaAppello, listaData, listaAperte, listaChiuse, listaEsercizi);
    }
    else
        getView()->createCharts(listaVoto, listaAppello, listaData, listaDurata);
}


void userController::onViewClosed() const {
    delete this;
}

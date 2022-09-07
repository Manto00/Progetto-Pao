#include "usercontroller.h"
#include "iostream"

userController::userController(userView* v, usermodel* m, Controller* parent): Controller(v, m, parent), currentCorso(-1)
{
    connectSlots();

    std::vector<QString> stringVec;
    std::vector<Corso*> corsoVec=getModel()->getCorsi();
    unsigned int i=0;
    while(corsoVec.size()>i){
        stringVec.push_back(corsoVec[i]->getnome());
        //std::cout<<stringVec[i].toStdString();
        i++;
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

    connect(vista, SIGNAL(showChart()), this, SLOT(onShowChart()));
    connect(vista, SIGNAL(selectCorso(int)), this, SLOT(onShowChart(int)));
    connect(vista, SIGNAL(deleteCorso(int)), this, SLOT(onDeleteCorso(int)));
    connect(vista, SIGNAL(insertEsame(int, int, int, QDate, int, int, int, int)), this,
            SLOT(onInsertEsame(int, int, int, QDate, int, int, int, int)));
}

void userController::onShowChart(int i){
    if(i>=0){
        currentCorso=i;
    }
    //recuperare i dati dal model
    Corso*cor=getModel()->getCorso(currentCorso);
    std::vector<Esame*>es=cor->getEsami();

    //creare struttura base per esame
    unsigned int uno=0;
    unsigned int due=0;
    unsigned int tre=0;
    unsigned int quattro=0;
    unsigned int cinque=0;
    std::vector<unsigned int> vecVoti(30, 0);
    std::vector<unsigned int> vecPromossi(5, 0);
    std::vector<unsigned int> vecBocciati(5, 0);
    //std::list<unsigned int> listaMatricola;   (aggiungere se serve)
    std::list<QDate> listaData;

    //creare struttura esame scritto
    float aperte=0;
    float chiuse=0;
    float esercizi=0;
    int scrittiCounter=0;

    //creare struttura dati per un esame orale
    std::list<unsigned int> listaDurata;

    bool isScritto=false;
    bool isOrale=false;
    for(auto it=es.begin(); it!=es.end(); it++){
        //inserire dati esame base
        if((*it)->getvoto()>17){
            switch((*it)->getappello()){
            case 1:
                uno++;
                break;
            case 2:
                due++;
                break;
            case 3:
                tre++;
                break;
            case 4:
                quattro++;
                break;
            case 5:
                cinque++;
                break;
            }
            if(QDate::currentDate().year()-(*it)->getdata().year()<5){}
            vecPromossi[QDate::currentDate().year()-(*it)->getdata().year()]++;
        }

        else{
            if(QDate::currentDate().year()-(*it)->getdata().year()<5){}
            vecBocciati[QDate::currentDate().year()-(*it)->getdata().year()]++;
        }

        vecVoti[(*it)->getvoto()]++;

        listaData.push_back((*it)->getdata());
        EsameScritto*sCasted=dynamic_cast<EsameScritto*>(*it);
        EsameOrale*oCasted=dynamic_cast<EsameOrale*>(*it);
        if(sCasted){
            //inserire i dati dell'esame scritto
            aperte=+(sCasted)->getaperte();
            chiuse=+(sCasted)->getchiuse();
            esercizi=+(sCasted)->getesercizi();
            scrittiCounter++;
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

    getView()->createPassChart(uno, due, tre, quattro, cinque);
    getView()->createPromossiperYearChart(vecPromossi, vecBocciati);
    getView()->createVotiChart(vecVoti);
    if(isScritto){
        getView()->createEsChart(aperte/scrittiCounter, chiuse/scrittiCounter, esercizi/scrittiCounter);
    }
    if(isOrale){
        getView()->createDurataChart(listaDurata);
    }
    /*getView()->createInsertField();*/
}

void userController::removeCharts() const{
    getView()->destroyCharts();
}

void userController::onInsertEsame(int matricola, int voto, int appello, QDate date, int chiuse, int aperte,
                                   int esercizi, int durata) const{
    //un botto di controlli
    if(currentCorso<0){
        vista->showWarningDialog("Errore", "Devi prima selezionare un corso");
    }
    else{
        if(matricola==NULL || voto==NULL || appello==NULL){
            //errore mancano dei valori fondamentali
        }
        else{
            if((chiuse!=0 || aperte!=0 || esercizi!=0) && (chiuse!=NULL || aperte!=NULL || esercizi!=NULL)){
                if(durata!=0){
                    //errore, esame o scritto o orale, non entrambi
                }
                //modifico il moddello (esame scritto)
                //getModel()->addEsame(currentCorso, new EsameScritto(voto, appello, matricola, date, aperte, chiuse, esercizi));
            }
            else if(durata!=0){
                //getModel()->addEsame(currentCorso, new EsameOrale(voto, appello, matricola, date, durata));
            }
            else{
                getModel()->addEsame(currentCorso, new Esame(voto, appello, matricola, date));
                std::cout<<"Hai aggiunto un esame BASE vez";
            }
            //salvare sul foglio json

        }
    }
}

void userController::onInsertCorso() const{
    bool ok;
    QString text=QInputDialog::getText(getView(),"Aggiungi nuovo corso", "Nome del corso:", QLineEdit::Normal, "", &ok);
    if(ok && !text.isEmpty()){
        getModel()->addCorso(new Corso(text));
        getView()->addCorso(text);
    }
}


void userController::onDeleteCorso(int posizione){
    /*for(it+1;it!=getView()->getCorsoVector().end();it++){
            (*it)->decreseCorso();
        }*/
    unsigned int i=posizione;
    while(i<getView()->getCorsoVector().size()){
        getView()->getCorsoVector()[i]->decreseCorso();
        i++;
    }
    getModel()->removeCorso(posizione);
    getView()->removeCorso(posizione);
    if(currentCorso==posizione){
        std::cout<<"ERA IL CORSO CORRENTE";
        currentCorso=-1;
        removeCharts();
    }
    else if(currentCorso>posizione){
        std::cout<<"E ENTRATO QUI!!!!!                      ";
        currentCorso--;
        }
}

void userController::onSave() const{
    // Se il file non esiste, magari perchè è un nuovo progetto, salvo con nome
    if(getModel()->getFilePath().isEmpty() || getModel()->getFilePath().isNull()){
        onSaveAs();
        return;
    }

    //Imposto il titolo alla schermata
    QStringList pieces = getModel()->getFilePath().split( "/" );
    QString last = pieces.value( pieces.length() - 1 );
    vista->setViewTitle(last);

    //effettuo il salvataggio ed in base all'esito mostro un messaggio
    bool esito = JSonReader::saveUserModel(getModel()->toQJSonDocument(),getModel()->getFilePath());
    if(!esito)
        vista->showCriticalDialog("Errore Salvataggio grave","Salvataggio NON riuscito");
    else
        vista->showInformationDialog("Perfetto !","Salvataggio Riuscito");
}

void userController::onSaveAs() const{
    //Faccio la richiesta per il nume del file
    QString jsonFilter = "JSON Files (*.json)";
    QString titolo = QString::fromStdString("Salva file con nome");
    QString fname = QFileDialog::getSaveFileName(vista,titolo,QDir::homePath(),jsonFilter);

    //Verifico che il nume sia valido
    if(fname.isEmpty() || fname.isNull()){
        vista->showCriticalDialog("Errore Salvataggio","Salvataggio NON riuscito\nInserire un nome file valido");
        return;
    }

    if (!fname.endsWith(".json"))
        fname+= tr(".json");

    //Setto il nume del file al modello di dati
    getModel()->setFilePath(fname);

    //ora faccio il salvataggio automatico
    onSave();
}

void userController::onOrganizzaEsami() const{
    esamiView* eView = new esamiView(vista->size(),vista);

    //Imposto il titolo alla schermata
    eView->setViewTitle("Visualizza esami");

    esamiModController* esamiCtrl = new esamiModController(eView, modello, const_cast<userController*>(this), currentCorso);
    eView->setController(esamiCtrl);
    esamiCtrl->completeView();
    esamiCtrl->showView();

    vista->hide();
}

void userController::onViewClosed() const {
    delete this;
}

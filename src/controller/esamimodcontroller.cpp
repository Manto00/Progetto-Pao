#include "esamimodcontroller.h"

esamiModController::esamiModController(esamiView*v, usermodel* m, Controller* c, int i):Controller(v, m, c), currentCorso(i)
{
    connectSlots();
}



void esamiModController::completeView() const{
    std::vector<QDate> dateVec;
    std::vector<Esame*> esamiVec=getModel()->getCorso(currentCorso)->getEsami();
    int infoVec[esamiVec.size()][7];
    int j=0;
    for(auto it=esamiVec.begin(); it!=esamiVec.end(); it++){
        infoVec[j][0]=(*it)->getmatricola();
        infoVec[j][1]=(*it)->getvoto();
        infoVec[j][2]=(*it)->getappello();
        dateVec.push_back((*it)->getdata());
        EsameScritto* sCasted=dynamic_cast<EsameScritto*>(*it);
        EsameOrale* oCasted=dynamic_cast<EsameOrale*>(*it);
        if(sCasted){
            infoVec[j][3]=sCasted->getchiuse();
            infoVec[j][4]=sCasted->getaperte();
            infoVec[j][5]=sCasted->getesercizi();
            infoVec[j][6]=-1;
        }
        else if(oCasted){
            infoVec[j][3]=-1;
            infoVec[j][4]=-1;
            infoVec[j][5]=-1;
            infoVec[j][6]=oCasted->getdurata();
        }
        else{
            infoVec[j][3]=-1;
            infoVec[j][4]=-1;
            infoVec[j][5]=-1;
            infoVec[j][6]=-1;
        }
        j++;
    }
    getView()->createEsamiTable(infoVec, dateVec, esamiVec.size());
}

esamiView* esamiModController::getView() const {
    return static_cast<esamiView*>(vista);
}

usermodel* esamiModController::getModel() const {
    return static_cast<usermodel*>(modello);
}

void esamiModController::onSaveEsame(int esame) const{
    int mat, vot, ape, chi, app, ese, dur;
    QDate date=getView()->getRows()[esame]->getDate();
    mat=getView()->getRows()[esame]->getMatricola();
    vot=getView()->getRows()[esame]->getVoto();
    app=getView()->getRows()[esame]->getAppello();
    chi=getView()->getRows()[esame]->getChiuse();
    ape=getView()->getRows()[esame]->getAperte();
    ese=getView()->getRows()[esame]->getEsercizi();
    dur=getView()->getRows()[esame]->getDurata();
    if(!(chi==-1 || ape==-1 || ese==-1)){
        getModel()->getCorso(currentCorso)->modificaEsame(new EsameScritto(mat, vot, app, date, chi, ape, ese), esame);
    }
    else if(!(dur==-1)){
        getModel()->getCorso(currentCorso)->modificaEsame(new EsameOrale(mat, vot, app, date, dur), esame);
    }
    else{
        getModel()->getCorso(currentCorso)->modificaEsame(new Esame(mat, vot, app, date), esame);
    }
    vista->showInformationDialog("Successo", "Modifica effettuata");
}

void esamiModController::onDeleteEsame(int i) const{
    getModel()->getCorso(currentCorso)->removeEsame(i);
    getView()->deleteRiga(i);
}

void esamiModController::connectSlots()const{

    connect(vista, SIGNAL(modifyRow(int)), this, SLOT(onSaveEsame(int)));
    connect(vista, SIGNAL(eliminaRiga(int)), this, SLOT(onDeleteEsame(int)));
}

void esamiModController::onHome(){
    if(!vista->showQuestionDialog(3,"Torna alla home","Vuoi tornare alla schermata precedente?"))return;
    if(vista->parent()){
        static_cast<View*>(vista->parent())->showMaximized();
    }
    vista->hide();

    setParent(nullptr);
    for(auto child :children())
        delete child;
    delete vista;

}

void esamiModController::onViewClosed() const{

}





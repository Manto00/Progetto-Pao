#include "esamimodcontroller.h"
#include "iostream"

esamiModController::esamiModController(esamiView*v, usermodel* m, Controller* c, int i):Controller(v, m, c), currentCorso(i)
{
    currentCorso=i;
    connectSlots(); //NON FUNZIONA
    /*std::vector<QDate> dateVec;
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
    getView()->createEsamiTable(infoVec, dateVec, esamiVec.size());*/
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

//LA FUNZIONE SAVE NON VA BENE, CAMBIA L'ORDINE DEL VETTORE ---------> in teoria non  più
void esamiModController::onSaveEsame(int esame, int mat, int vot, int app, QDate date, int chi, int ape, int ese, int dur) const{
    if(chi!=0 || ape!=0 || ese!=0){
        getModel()->getCorso(currentCorso)->modificaEsame(new EsameScritto(mat, vot, app, date, chi, ape, ese), esame);
    }
    else if(dur!=0){
        getModel()->getCorso(currentCorso)->modificaEsame(new EsameOrale(mat, vot, app, date, dur), esame);
    }
    else{
        getModel()->getCorso(currentCorso)->modificaEsame(new Esame(mat, vot, app, date), esame);
    }
}

void esamiModController::onDeleteEsame(int i) const{
    std::cout<<"passa per il controller";
    getModel()->getCorso(currentCorso)->removeEsame(i);
    getView()->deleteRiga(i);
}

void esamiModController::connectSlots()const{

    connect(vista, SIGNAL(modifyRow(int, int, int, QDate, int, int, int, int, int)), this,
            SLOT(onSaveEsame(int, int, int, QDate, int, int, int, int, int)));
    //connect(vista, SIGNAL(deleteRiga(int)), this, SLOT(onDeleteEsame(int)));
}

void esamiModController::onViewClosed() const{

}





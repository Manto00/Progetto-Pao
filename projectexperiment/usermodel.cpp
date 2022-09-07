#include "usermodel.h"
#include "iostream"

usermodel::usermodel(QJsonDocument *data, QString* path){
    corsiVector = JSonReader::getCorsi(data);
    filePath = path;
    /*for(unsigned int i=0; corsiVector.size()>i; i++){
        std::cout<<corsiVector[i]->getnome().toStdString()<< "  ";
        for(unsigned int j=0; corsiVector[i]->getEsami().size()>j; j++){
            std::cout<<corsiVector[i]->getEsami()[j]->getappello()<<"    ";
            std::cout<<corsiVector[i]->getEsami()[j]->getdata().toString().toStdString()<<"    ";
            std::cout<<corsiVector[i]->getEsami()[j]->getmatricola()<<"    ";
            std::cout<<corsiVector[i]->getEsami()[j]->getvoto()<<"    ";
        }
    }*/
}
/*recordList = JSONFilePicker::getRecords(data);*/

usermodel::usermodel(){
    corsiVector=std::vector<Corso*>();
    filePath=new QString();
}

Corso* usermodel::getCorso(unsigned int i) const{
    return corsiVector[i];
}

std::vector<Corso*> usermodel::getCorsi()const{
    return corsiVector;
}


void usermodel::addCorso(Corso *nuovo){
    for(auto it=corsiVector.begin(); it!=corsiVector.end(); it++){
        if(nuovo->getnome()==(*it)->getnome()){
            //TO DO:mostra errorre
        }
    }
    corsiVector.push_back(nuovo);
}

void usermodel::removeCorso(int posizione){
    corsiVector.erase(corsiVector.begin()+posizione);
}

void usermodel::addEsame(int posizione, Esame *nuovo){
    corsiVector[posizione]->addEsame(nuovo);
}

void usermodel::removeEsame(int posCorso, int posizione){
    corsiVector[posCorso]->removeEsame(posizione);
}

const QJsonDocument & usermodel::saveModel() const{
    QJsonDocument* nuovoJson = new QJsonDocument();
    QJsonObject mainObj;

    for(Corso* c : corsiVector){
        QJsonObject corsoVal;
        corsoVal.insert(QString::fromStdString("nome"), c->getnome());
        unsigned int i=0;
        while(corsiVector.size()>i){
            corsoVal.insert(QString::fromStdString("appello"), QJsonValue((int) c->getEsami()[i]->getappello()));
            corsoVal.insert(QString::fromStdString("data"),  c->getEsami()[i]->getdata().toString("dd/mm/yyyy"));
            corsoVal.insert(QString::fromStdString("appello"), QJsonValue((int) c->getEsami()[i]->getmatricola()));
            corsoVal.insert(QString::fromStdString("appello"), QJsonValue((int) c->getEsami()[i]->getvoto()));
            i++;
        }
    }
    nuovoJson->setObject(mainObj);

    return *nuovoJson;
}


const QJsonDocument& usermodel::toQJSonDocument() const{
    QJsonDocument* modelJson = new QJsonDocument();
    QJsonObject mainObj;

    QJsonArray corsiArray;
    for(Corso* r : corsiVector){
        QJsonObject corObj;
        corObj.insert(QString::fromStdString("nome"),r->getnome());
        unsigned int i=0;
        EsameScritto*sCasted;
        EsameOrale*oCasted;
        QJsonArray esamiArray;
        QJsonArray esamiScrittiArray;
        QJsonArray esamiOraliArray;
        while(r->getEsami().size()>i){
            sCasted=dynamic_cast<EsameScritto*>(r->getEsami()[i]);
            oCasted=dynamic_cast<EsameOrale*>(r->getEsami()[i]);
            if(!(sCasted || oCasted)){
                QJsonObject esaObj;
                esaObj.insert(QString::fromStdString("matricola"),QJsonValue((int)(r->getEsami()[i]->getmatricola())));
                esaObj.insert(QString::fromStdString("voto"),QJsonValue((int)(r->getEsami()[i]->getvoto())));
                esaObj.insert(QString::fromStdString("appello"),QJsonValue((int)r->getEsami()[i]->getappello()));
                esaObj.insert(QString::fromStdString("data"),r->getEsami()[i]->getdata().toString("dd/MM/yyyy"));
                esamiArray.push_back(esaObj);
            }
            if(sCasted){
                QJsonObject esaSObj;
                esaSObj.insert(QString::fromStdString("matricola"),QJsonValue((int)(r->getEsami()[i]->getmatricola())));
                esaSObj.insert(QString::fromStdString("voto"),QJsonValue((int)(r->getEsami()[i]->getvoto())));
                esaSObj.insert(QString::fromStdString("appello"),QJsonValue((int)r->getEsami()[i]->getappello()));
                esaSObj.insert(QString::fromStdString("data"),r->getEsami()[i]->getdata().toString("dd/MM/yyyy"));
                esaSObj.insert(QString::fromStdString("chiuse"),QJsonValue((int)(sCasted->getchiuse())));
                esaSObj.insert(QString::fromStdString("aperte"),QJsonValue((int)(sCasted->getaperte())));
                esaSObj.insert(QString::fromStdString("esercizi"),QJsonValue((int)(sCasted->getesercizi())));
                esamiScrittiArray.push_back(esaSObj);
            }
            else if(oCasted){
                QJsonObject esaOObj;
                esaOObj.insert(QString::fromStdString("matricola"),QJsonValue((int)(r->getEsami()[i]->getmatricola())));
                esaOObj.insert(QString::fromStdString("voto"),QJsonValue((int)(r->getEsami()[i]->getvoto())));
                esaOObj.insert(QString::fromStdString("appello"),QJsonValue((int)r->getEsami()[i]->getappello()));
                esaOObj.insert(QString::fromStdString("data"),r->getEsami()[i]->getdata().toString("dd/MM/yyyy"));
                esaOObj.insert(QString::fromStdString("durata"),QJsonValue((int)(oCasted->getdurata())));
                esamiOraliArray.push_back(esaOObj);
            }
        }
        corObj.insert(QString::fromStdString("esami"), esamiArray);
        corObj.insert(QString::fromStdString("esami scritti"), esamiScrittiArray);
        corObj.insert(QString::fromStdString("esami orali"), esamiOraliArray);
        corsiArray.push_back(corObj);
    }
    mainObj.insert(QString::fromStdString("corsi"),corsiArray);
    modelJson->setObject(mainObj);

    return *modelJson;
}

const QString& usermodel::getFilePath() const{
    return *filePath;
}

void usermodel::setFilePath(const QString &path){
    *filePath=path;
}

#include "usermodel.h"

usermodel::usermodel(QJsonDocument *data, QString* path){
    std::vector<Esame*> temp;
    while(true)
    {
        corsiVector = JSonReader::getCorsi(data);

    }
    filepath = path;
}
/*recordList = JSONFilePicker::getRecords(data);*/

usermodel::usermodel(){
    corsiVector=std::vector<Corso*>();
    filepath=new QString();
}

Corso* usermodel::getCorso(unsigned int i) const{
    return corsiVector[i];
}

std::vector<Corso*> usermodel::getCorsi()const{
    return corsiVector;
}


void usermodel::addCorso(Corso *nuovo){
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

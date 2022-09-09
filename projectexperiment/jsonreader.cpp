#include "jsonreader.h"

QJsonDocument* JSonReader::getJSONFileData(const QString& path){
    if(path.isNull()) return new QJsonDocument();
    QString fileData;
    QFile file;

    file.setFileName(path);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    fileData = file.readAll();
    file.close();

    //Controllo validità documento
    QJsonDocument* doc = new QJsonDocument(QJsonDocument::fromJson(fileData.toLocal8Bit()));
    QJsonObject dataObj = doc->object();

    QStringList keywords=dataObj.keys();
    for(int i=0; keywords.size()>i; i++){
    }

    if(!dataObj.contains("corsi")){
        delete doc;
        return new QJsonDocument();
    }
    return doc;
}

QString JSonReader::selectJSONFileDialog(){
    QFileDialog dialog;
    dialog.setFileMode(QFileDialog::ExistingFile);
    dialog.setNameFilter("JSON File (*.json)");
    QString fileName;
    if (dialog.exec())
        fileName = dialog.selectedFiles().at(0);
    return fileName;
}


std::vector<Corso*> JSonReader::getCorsi(QJsonDocument* data){
    std::vector<Corso*> corsiVec;
    QJsonObject dataObj = data->object();
    QJsonArray corsi = dataObj["corsi"].toArray();
    for(const QJsonValue& corso : corsi){
        std::vector<Esame*> esamiVec;
        QJsonObject objectEsami=corso.toObject();
        QJsonArray arrayEsami= objectEsami["esami"].toArray();
        QJsonArray arrayEsamiScritti= objectEsami["esami scritti"].toArray();
        QJsonArray arrayEsamiOrali= objectEsami["esami orali"].toArray();
        int i=0;
        for(const QJsonValue& esame: arrayEsami){
            QJsonObject objectBase=esame.toObject();
            Esame* nuovoEsame=new Esame(
                objectBase.value("matricola").toInt(),
                objectBase.value("voto").toInt(),
                objectBase.value("appello").toInt(),
                QDate::fromString(objectBase.value("data").toString(),"dd/MM/yyyy"));
                esamiVec.push_back(nuovoEsame);
                i++;
        }
        for(const QJsonValue& esame: arrayEsamiScritti){
            QJsonObject objectScritti=esame.toObject();
            Esame* nuovoEsame=new EsameScritto(
                objectScritti.value("matricola").toInt(),
                objectScritti.value("voto").toInt(),
                objectScritti.value("appello").toInt(),
                QDate::fromString(objectScritti.value("data").toString(),"dd/MM/yyyy"),
                objectScritti.value("chiuse").toInt(),
                objectScritti.value("aperte").toInt(),
                objectScritti.value("esercizi").toInt());
            esamiVec.push_back(nuovoEsame);
            i++;
        }
        for(const QJsonValue& esame: arrayEsamiOrali){
            QJsonObject objectOrali=esame.toObject();
            Esame* nuovoEsame=new EsameOrale(
                objectOrali.value("matricola").toInt(),
                objectOrali.value("voto").toInt(),
                objectOrali.value("appello").toInt(),
                QDate::fromString(objectOrali.value("data").toString(),"dd/MM/yyyy"),
                objectOrali.value("durata").toInt());
            esamiVec.push_back(nuovoEsame);
            i++;

        }

        Corso* r = new Corso(
                corso.toObject().value("nome").toString(), esamiVec);
        corsiVec.push_back(r);
    }
    return corsiVec;
}

std::vector<Esame*> JSonReader::getEsami(QJsonDocument* data){
    std::vector<Esame*> esamiVec;
    QJsonObject dataObj = data->object();
    QJsonArray esami = dataObj["Esami"].toArray();
    esami.push_back(dataObj["Esami Scritti"].toArray());
    int i=0;
    for(const QJsonValue& esame : esami){
        i++;
        Esame* r = new Esame(
                esame.toObject().value("matricola").toInt(),
                esame.toObject().value("voto").toInt(),
                esame.toObject().value("appello").toInt(),
                QDate::fromString(esame.toObject().value("data").toString(),"dd/MM/yyyy"));
        esamiVec.push_back(r);
    }
    for(const QJsonValue& esame : esami+i){
        Esame* r = new EsameScritto(
                esame.toObject().value("matricola").toInt(),
                esame.toObject().value("voto").toInt(),
                esame.toObject().value("appello").toInt(),
                QDate::fromString(esame.toObject().value("data").toString(),"dd/MM/yyyy"),
                esame.toObject().value("aperte").toInt(),
                esame.toObject().value("chiuse").toInt(),
                esame.toObject().value("esercizi").toInt());
        esamiVec.push_back(r);
    }
    return esamiVec;
}

bool JSonReader::saveUserModel(const QJsonDocument& doc, const QString& path){
    if(path.isNull() || path.isEmpty()) return false;
    QFile file(path);
    if(file.open(QFile::WriteOnly | QFile::Text | QFile::Truncate)){
        file.write(doc.toJson());
        file.close();
        return true;
    }
    return false;
}

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
    if(!dataObj.contains("records") || !dataObj.contains("materiali")){
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
    std::vector<Corso*> ret;
    QJsonObject dataObj = data->object();
    QJsonArray corsi = dataObj["Corsi"].toArray();
    for(const QJsonValue& corso : corsi){
        Corso* r = new Corso(
                corso.toObject().value("nome").toString(),
                getEsami(data));
        ret.push_back(r);
    }
    return ret;
}

std::vector<Esame*> JSonReader::getEsami(QJsonDocument* data){
    std::vector<Esame*> ret;
    QJsonObject dataObj = data->object();
    QJsonArray esami = dataObj["Esami"].toArray();
    esami.push_back(dataObj["Esamiscritti"].toArray());
    int i=0;
    for(const QJsonValue& esame : esami){
        i++;
        Esame* r = new Esame(
                esame.toObject().value("voto").toInt(),
                esame.toObject().value("appello").toInt(),
                esame.toObject().value("matricola").toInt(),
                QDate::fromString(esame.toObject().value("data").toString(),"dd/MM/yyyy"));
        ret.push_back(r);
    }
    for(const QJsonValue& esame : esami+i){
        Esame* r = new EsameScritto(
                esame.toObject().value("voto").toInt(),
                esame.toObject().value("appello").toInt(),
                esame.toObject().value("matricola").toInt(),
                QDate::fromString(esame.toObject().value("data").toString(),"dd/MM/yyyy"),
                esame.toObject().value("aperte").toInt(),
                esame.toObject().value("chiuse").toInt(),
                esame.toObject().value("esercizi").toInt());
        ret.push_back(r);
    }
    return ret;
}

bool JSonReader::saveAdminModel(const QJsonDocument& doc, const QString& path){
    if(path.isNull() || path.isEmpty()) return false;
    QFile file(path);
    if(file.open(QFile::WriteOnly | QFile::Text | QFile::Truncate)){
        file.write(doc.toJson());
        file.close();
        return true;
    }
    return false;
}

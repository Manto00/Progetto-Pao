#ifndef JSONREADER_H
#define JSONREADER_H

#include <QFile>
#include <QFileDialog>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>

#include <esame.h>
#include <usermodel.h>

class JSonReader
{
public:
    static QString selectJSONFileDialog();

    static QJsonDocument* getJSONFileData(const QString& path);

    static std::vector<Corso*> getCorsi(QJsonDocument* data);

    static std::vector<Esame*> getEsami(QJsonDocument*data);

    static bool saveAdminModel(const QJsonDocument& doc, const QString& path);
};

#endif // JSONREADER_H

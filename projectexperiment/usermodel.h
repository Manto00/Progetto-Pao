#ifndef USERMODEL_H
#define USERMODEL_H

#include <corso.h>
#include <QJsonDocument>
#include <QString>

#include <jsonreader.h>

class usermodel
{
private:
    std::vector<Corso*> corsiVector;

    QString* filepath;

public:
    Corso* getCorso(unsigned int i)const;

    std::vector<Corso*> getCorsi()const;

    usermodel(QJsonDocument*data, QString* path);

    usermodel();

    void addCorso(Corso* nuovo);

    void removeCorso(int posizione);

    void addEsame(int posizione, Esame*nuovo);

    void removeEsame(int posCorso, int posizione);

    const QJsonDocument & saveModel() const;
};

#endif // USERMODEL_H

#ifndef ESAME_H
#define ESAME_H

#include <QString>
#include <QDate>

class Esame
{
private:
    unsigned int voto;
    unsigned int appello;
    unsigned int matricola;
    QDate data;
public:
    Esame( unsigned int studente=999999, unsigned int punteggio=30, unsigned int app=0, QDate date=QDate::currentDate());
    Esame();
    virtual ~Esame()=default;
    //metodi getter
    virtual unsigned int getvoto() const;
    virtual unsigned int getappello() const;
    virtual unsigned int getmatricola() const;
    virtual QDate getdata() const;

    //metodi setter
    void setvoto(unsigned int punteggio);
    void setappello(unsigned int app);
    void setmatricola(unsigned int m);
    void setdata(QDate d);
};

class EsameScritto: public Esame{
private:
    unsigned int aperte;
    unsigned int chiuse;
    unsigned int esercizi;
    bool inserted;
public:
    EsameScritto(unsigned int punteggio, unsigned int app, unsigned int studente, QDate date, unsigned int a=0, unsigned int c=0, unsigned int e=0);
    unsigned int getaperte() const;
    unsigned int getchiuse() const;
    unsigned int getesercizi() const;
    bool isInserted() const;

};

class EsameOrale: public Esame{
private:
    unsigned int minuti;
public:
    EsameOrale(unsigned int punteggio, unsigned int app, unsigned int studente, QDate date, unsigned int durata=0);
    virtual unsigned int getdurata() const;

};

#endif // ESAME_H

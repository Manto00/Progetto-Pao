#include "esame.h"

Esame::Esame(unsigned int punteggio, unsigned int app, unsigned int studente, QDate date) : voto(punteggio), appello(app), matricola(studente), data(date){}

Esame::Esame(): voto(0), appello(0), matricola(0), data(QDate::currentDate()){}

unsigned int Esame::getvoto() const{return voto;}

unsigned int Esame::getappello() const{return appello;}

unsigned int Esame::getmatricola() const{return matricola;}

QDate Esame::getdata() const{return data;}



EsameScritto::EsameScritto(unsigned int punteggio, unsigned int app, unsigned int studente, QDate date, unsigned int a, unsigned int c, unsigned int e)
    : Esame(punteggio, app, studente, date), aperte(a), chiuse(c), esercizi(e){}

unsigned int EsameScritto::getaperte() const{return aperte;}

unsigned int EsameScritto::getchiuse() const{return chiuse;}

unsigned int EsameScritto::getesercizi() const{return esercizi;}

bool EsameScritto::isInserted() const{return (aperte || chiuse || esercizi);}



EsameOrale::EsameOrale(unsigned int punteggio, unsigned int app, unsigned int studente, QDate date, unsigned int d): Esame(punteggio, app, studente, date), minuti(d){}

unsigned int EsameOrale::getdurata() const{return minuti;}

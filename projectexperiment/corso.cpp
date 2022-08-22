#include "corso.h"

Corso::Corso(QString n, std::vector<Esame*> esami): nome(n), esameVector(esami)
{

}

QString Corso::getnome() const {return nome;}

std::vector<Esame*> Corso::getEsami() const {return esameVector;}

void Corso::addEsame(Esame *nuovo){
    esameVector.push_back(nuovo);
}

void Corso::removeEsame(int posizione){
    esameVector.erase(esameVector.begin()+posizione);
}

#include "corso.h"

Corso::Corso(QString n, std::vector<Esame*> esami): nome(n), esameVector(esami)
{

}

QString Corso::getnome() const {return nome;}

void Corso::setNome(QString nuovo){
    nome=nuovo;
}

std::vector<Esame*> Corso::getEsami() const {return esameVector;}

void Corso::addEsame(Esame* nuovo){
    esameVector.push_back(nuovo);
}


void Corso::modificaEsame(Esame* modificato, int posizione){
    delete esameVector[posizione];
    esameVector[posizione]=modificato;
}

void Corso::removeEsame(int posizione){
    esameVector.erase(esameVector.begin()+posizione);
}

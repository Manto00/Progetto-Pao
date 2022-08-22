#ifndef CORSO_H
#define CORSO_H

#include <esame.h>

class Corso
{
private:
    QString nome;
    std::vector<Esame*> esameVector;
    //Aggiungere dei bool per capire che esami ammette???
public:
    Corso(QString name, std::vector<Esame*> lista);

    QString getnome() const;

    std::vector<Esame*> getEsami() const;

    void addEsame(Esame* nuovo);

    void removeEsame(int posizione);
};

#endif // CORSO_H

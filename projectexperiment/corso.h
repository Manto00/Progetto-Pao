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
    Corso(QString name, std::vector<Esame*> lista=std::vector<Esame*>());

    QString getnome() const;

    std::vector<Esame*> getEsami() const;

    void modificaEsame(Esame* modificato, int posizione);

    void addEsame(Esame* nuovo);

    void removeEsame(int posizione);
};

#endif // CORSO_H

#ifndef CORSO_H
#define CORSO_H

#include <esame.h>
#include <vector>

class Corso
{
private:
    QString nome;
    std::vector<Esame*> esameVector;
public:
    Corso(QString name, std::vector<Esame*> lista=std::vector<Esame*>());

    QString getnome() const;

    void setNome(QString nuovo);

    std::vector<Esame*> getEsami() const;

    void modificaEsame(Esame* modificato, int posizione);

    void addEsame(Esame* nuovo);

    void removeEsame(int posizione);
};

#endif // CORSO_H

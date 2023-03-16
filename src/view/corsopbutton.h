#ifndef CORSOPBUTTON_H
#define CORSOPBUTTON_H

#include <view/view.h>
#include <QPushButton>
#include <QHBoxLayout>



class corsoPButton: public QPushButton
{
    Q_OBJECT
private:
    int numeroCorso;

    QHBoxLayout*mainLayout;
    QPushButton*deleteButton;
    QPushButton*modButton;
    QPushButton*corsoButton;

public:
    corsoPButton(QString title, int numero, View*parent=nullptr);
    ~corsoPButton();

    QPushButton*getDeleteButton() const;
    QPushButton*getModificaButton() const;
    QPushButton*getCorsoButton() const;
    int getNumeroCorso() const;
    QHBoxLayout*getLayout() const;

    int decreseCorso();
    void modificaCorso(QString);

signals:
    void selectCorso(int) const;
    void deleteCorso(int) const;

};

#endif // CORSOPBUTTON_H

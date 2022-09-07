#ifndef ROWESAMIVIEW_H
#define ROWESAMIVIEW_H

#include <view/view.h>
#include <QSpinBox>
#include <QDateEdit>
#include <QBoxLayout>
#include <QPushButton>

class rowEsamiView: public View
{
    Q_OBJECT
private:
    QHBoxLayout* mainLayout;
    QPushButton* eliminaButton;
    QPushButton* salvaButton;
    QSpinBox* matricola;
    QSpinBox* voto;
    QSpinBox* appello;
    QDateEdit* dateBox;
    QSpinBox* chiuse;
    QSpinBox* aperte;
    QSpinBox* esercizi;
    QSpinBox* durata;
    int numeroEsame;

    void connectViewSignals() const override;

public:
    rowEsamiView(const QSize& s = QSize(),View* parent = nullptr);

    void createRow(int esame, int mat, int vot, int app, QDate date, int chi=0, int ape=0, int ese=0, int dur=0);

    virtual void setController(Controller*c) override;

    int decreseEsame();

signals:
    void removeRow(int) const;
    void modifyRow(int, int, int, QDate, int, int, int, int, int) const;
};

#endif // ROWESAMIVIEW_H

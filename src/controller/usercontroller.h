#ifndef USERCONTROLLER_H
#define USERCONTROLLER_H

#include <controller/controller.h>
#include <view/userview.h>
#include <usermodel.h>
#include <controller/esamimodcontroller.h>
#include <view/esamiview.h>

class userController: public Controller
{
    Q_OBJECT
private:
    int currentCorso;
    bool chartBaseVisibili;
    bool chartScrittiVisibili;
    bool chartOraliVisibili;

    void connectSlots() const;

public:

    userController(userView* v, usermodel* m = new usermodel(), Controller* parent = nullptr);

    userView* getView() const override;

    usermodel* getModel() const override;

    void removeCharts();

signals:

public slots:

    void onShowChart(int i=-1);

    void onInsertEsame(int matricola, int voto, int appello, QDate date, int chiuse, int aperte, int esercizi, int durata=0);

    void onInsertCorso() const;

    void onDeleteCorso(int posizione);

    void onSaveAs() const;

    void onSave() const;

    void onOrganizzaEsami() const;

    void onViewClosed() const override;

    void onModCorso(int posizione);

};

#endif // USERCONTROLLER_H

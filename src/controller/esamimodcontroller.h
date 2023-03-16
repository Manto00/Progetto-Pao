#ifndef ESAMIMODCONTROLLER_H
#define ESAMIMODCONTROLLER_H

#include <controller/controller.h>
#include <view/esamiview.h>
#include <usermodel.h>

class esamiModController: public Controller
{
    Q_OBJECT
private:
    int currentCorso;

    void connectSlots()const;

public:
    esamiModController();

    esamiModController(esamiView* v, usermodel* m, Controller* parent, int currentCorso);

    void completeView() const;

    esamiView* getView() const override;

    usermodel* getModel() const override;

signals:

public slots:

    void onViewClosed() const override;

    void onSaveEsame(int esame) const;

    void onDeleteEsame(int i) const;

    void onHome();

};

#endif // ESAMIMODCONTROLLER_H

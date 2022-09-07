#ifndef ESAMIMODCONTROLLER_H
#define ESAMIMODCONTROLLER_H

#include <controller/controller.h>
#include <view/esamiview.h>
#include <usermodel.h>

class esamiModController: public Controller
{
private:
    int currentCorso;
public:
    esamiModController(esamiView* v, usermodel* m, Controller* parent, int currentCorso);

    void completeView() const;

    void connectSlots()const;

    esamiView* getView() const override;

    usermodel* getModel() const override;

signals:

public slots:

    void onViewClosed() const override;

    void onSaveEsame(int esame,int mat, int vot, int app, QDate date, int chi, int ape, int ese, int dur) const;

    void onDeleteEsame(int i) const;

};

#endif // ESAMIMODCONTROLLER_H

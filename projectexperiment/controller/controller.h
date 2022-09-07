#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "view/view.h"
#include "usermodel.h"

class Controller: public QObject
{
    Q_OBJECT
protected:
    View* vista;
    usermodel* modello;

private:
    void connectSlots() const;

public:
    Controller(View* v, usermodel* m, Controller* parent=nullptr);

    virtual ~Controller();

    virtual View* getView() const=0;

    virtual usermodel* getModel() const=0;

    virtual void showView()const;

    virtual void hideView() const;

public slots:

    virtual void onViewClosed() const = 0;
};

#endif // CONTROLLER_H

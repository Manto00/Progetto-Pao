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

    void connectSlots() const;
public:
    Controller(View* v, usermodel* m, Controller* parent=nullptr);

    virtual void onViewClosed() const = 0;
};

#endif // CONTROLLER_H

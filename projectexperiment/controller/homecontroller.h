#ifndef HOMECONTROLLER_H
#define HOMECONTROLLER_H


#include <QFileDialog>
#include <QStringList>
#include <QJsonDocument>

#include "homeview.h"
#include "view/userview.h"
#include "usermodel.h"
#include "jsonreader.h"
#include "controller.h"

class homeController: public Controller
{
    Q_OBJECT
 private:
     void connectSlots() const;

public:
    homeController(HomeView* v, Controller* parent = nullptr);

    HomeView* getView() const;

    //Model* getModel() const;
};

#endif // HOMECONTROLLER_H

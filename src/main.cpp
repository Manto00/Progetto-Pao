#include "mainwindow.h"
#include <view/introview.h>
#include <view/userview.h>
#include <controller/introcontroller.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    introView* iView = new introView();
    introController* iController = new introController(iView);
    iView->setController(iController);
    iController->showView();

    return a.exec();
}

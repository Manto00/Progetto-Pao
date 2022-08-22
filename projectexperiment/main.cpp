#include "mainwindow.h"
#include "homeview.h"
#include <view/introview.h>
#include <view/userview.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    userView w;
    w.show();
    return a.exec();
}

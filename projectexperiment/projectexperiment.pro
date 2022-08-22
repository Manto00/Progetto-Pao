QT       += core charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    barchartview.cpp \
    controller/controller.cpp \
    controller/usercontroller.cpp \
    corso.cpp \
    esame.cpp \
    homeview.cpp \
    jsonreader.cpp \
    main.cpp \
    mainwindow.cpp \
    usermodel.cpp \
    controller/homecontroller.cpp \
    view/introview.cpp \
    view/pieview.cpp \
    view/userview.cpp \
    view/view.cpp \
    votilinechart.cpp

HEADERS += \
    barchartview.h \
    controller/controller.h \
    controller/usercontroller.h \
    corso.h \
    esame.h \
    homeview.h \
    jsonreader.h \
    mainwindow.h \
    usermodel.h \
    controller/homecontroller.h \
    view/introview.h \
    view/pieview.h \
    view/userview.h \
    view/view.h \
    votilinechart.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

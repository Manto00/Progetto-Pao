QT       += core charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    controller/controller.cpp \
    controller/esamimodcontroller.cpp \
    controller/introcontroller.cpp \
    controller/usercontroller.cpp \
    corso.cpp \
    esame.cpp \
    jsonreader.cpp \
    main.cpp \
    mainwindow.cpp \
    usermodel.cpp \
    view/corsopbutton.cpp \
    view/esamiview.cpp \
    view/introview.cpp \
    view/rowesamiview.cpp \
    view/userview.cpp \
    view/view.cpp

HEADERS += \
    controller/controller.h \
    controller/esamimodcontroller.h \
    controller/introcontroller.h \
    controller/usercontroller.h \
    corso.h \
    esame.h \
    jsonreader.h \
    mainwindow.h \
    usermodel.h \
    view/corsopbutton.h \
    view/esamiview.h \
    view/introview.h \
    view/rowesamiview.h \
    view/userview.h \
    view/view.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

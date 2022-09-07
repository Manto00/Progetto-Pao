#ifndef INTROCONTROLLER_H
#define INTROCONTROLLER_H

#include <controller/controller.h>
#include <view/introview.h>
#include <view/userview.h>
#include <controller/usercontroller.h>
#include <jsonreader.h>

class introController: public Controller
{
    Q_OBJECT
private:
    void connectSlots()const;

public:
    introController(introView* v, Controller* parent=nullptr);

    introView* getView() const override;

    usermodel* getModel() const override;

signals:

public slots:

    void onNewModel() const;

    void onOpenView() const;

    void onViewClosed() const override;
};

#endif // INTROCONTROLLER_H

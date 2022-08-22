#ifndef INTROVIEW_H
#define INTROVIEW_H

#include <QObject>
#include <view/view.h>
#include <QLayout>
#include <QPushButton>


class introView: public View
{
    Q_OBJECT
private:
    QPushButton* newModel;
    QPushButton* openModel;
    QVBoxLayout*mainLayout;

    virtual void connectViewSignals() const override;
public:
    introView(const QSize& s= QSize(), View* parent=nullptr);
};

#endif // INTROVIEW_H

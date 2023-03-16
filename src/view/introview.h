#ifndef INTROVIEW_H
#define INTROVIEW_H

#include <QObject>
#include <view/view.h>
#include <QLayout>
#include <QPushButton>
#include <QLabel>


class introView: public View
{
    Q_OBJECT
private:
    QPushButton* newModel;
    QPushButton* openModel;
    QVBoxLayout*mainLayout;

    virtual void connectViewSignals() const override;

protected:
    void closeEvent(QCloseEvent *event) override;

public:
    void setController(Controller* c) override;

    introView(const QSize& s= QSize(), View* parent=nullptr);

signals:
    void createNewModel();

    void openUserView();
};

#endif // INTROVIEW_H

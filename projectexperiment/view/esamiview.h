#ifndef ESAMIVIEW_H
#define ESAMIVIEW_H

#include <view/view.h>
#include <QBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QDateEdit>
#include <QSpinBox>
#include <view/rowesamiview.h>


class esamiView: public View
{
    Q_OBJECT
private:
    QVBoxLayout*mainLayout;
    QHBoxLayout* labelLayout;
    std::vector<rowEsamiView*> rowVector;

    void connectViewSignals() const override;

public:
    esamiView(const QSize& s = QSize(), View* parent = nullptr);

    void createEsamiTable(int esami[][7], std::vector<QDate> date, int dim);

    void deleteRiga(int i);

    void closeEvent(QCloseEvent* event);
};

#endif // ESAMIVIEW_H

#ifndef ESAMIVIEW_H
#define ESAMIVIEW_H

#include <view/view.h>
#include <QBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QDateEdit>
#include <QSpinBox>
#include <view/rowesamiview.h>
#include <qscrollarea.h>


class esamiView: public View
{
    Q_OBJECT
private:
    QVBoxLayout*mainLayout;
    QVBoxLayout*esamiLayout;
    QHBoxLayout* labelLayout;
    std::vector<rowEsamiView*> rowVector;
    QPushButton*home;

    void connectViewSignals() const override;

public:
    esamiView(const QSize& s = QSize(), View* parent = nullptr);

    ~esamiView();

    std::vector<rowEsamiView*> getRows() const;

    void createEsamiTable(int esami[][7], std::vector<QDate> date, int dim);

    void deleteRiga(int i);

protected:
    void closeEvent(QCloseEvent* event) override;

signals:
    void eliminaRiga(int riga) const;

    void modifyRow(int esame);
};

#endif // ESAMIVIEW_H

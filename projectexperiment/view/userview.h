#ifndef USERVIEW_H
#define USERVIEW_H

#include <view/view.h>
#include <vector>
#include <QBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QSpinBox>
#include <QInputDialog>
#include <view/corsopbutton.h>
#include <QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>


class userView: public View
{
    Q_OBJECT
private:
    QPushButton* newModelButton;
    QPushButton* changeModelButton;
    QPushButton* addCorsoButton;
    QPushButton* addEsameButton;
    QPushButton* aggiornaButton;
    QPushButton* organizzaEsamiButton;
    QSpinBox* matricolaField;
    QSpinBox* votoField;
    QSpinBox* appelloField;
    QDateEdit* dateField;
    QSpinBox* aperteField;
    QSpinBox* chiuseField;
    QSpinBox* eserciziField;
    QSpinBox* durataField;
    std::vector<corsoPButton*> corsiVec;
    QVBoxLayout* mainLayout;
    QHBoxLayout* introLayout;
    QHBoxLayout* activeLayout;
    QVBoxLayout* corsiLayout;
    QVBoxLayout* chartLayout;
    QVBoxLayout* fieldLayout;
    QChart* passChart;
    QChart* barChart;
    QChart* votiChart;
    QChart* durataChart;
    QChart* esChart;


    QLayout* createDescriptionLayout(const QString& description, const QString& imgPath);

    void connectViewSignals() const override;

protected:

    void closeEvent(QCloseEvent *event) override;

public:

    explicit userView(const QSize& s = QSize(),View* parent = nullptr);

    virtual void setController(Controller*c) override;

    void insertCorsi(std::vector<QString> listaCorsi);

    void createPassChart(unsigned int primo, unsigned int secondo, unsigned int terzo, unsigned int quarto, unsigned int quinto);

    void createPromossiperYearChart(std::vector<unsigned int> promossi, std::vector<unsigned int> bocciati);

    void createVotiChart(std::vector<unsigned int> voti);

    void createDurataChart(std::list<unsigned int> durata);

    void createEsChart(unsigned int aperte, unsigned int chiuse, unsigned int esercizi);

    void createInsertField();

    std::vector<corsoPButton*> getCorsoVector();

    void destroyCharts();

    void addCorso(QString title);

    void removeCorso(int posizione);

signals:

    void insertEsame(int, int, int, QDate, int, int, int, int) const;

    void showChart() const;

    void insertCorso(int) const;

    void selectCorso(int) const;

    void deleteCorso(int) const;

public slots:
};

#endif // USERVIEW_H

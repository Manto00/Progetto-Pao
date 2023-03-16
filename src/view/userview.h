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
#include <QScrollArea>
#include <QScrollBar>


class userView: public View
{
    Q_OBJECT
private:
    QPushButton* salvaModello;
    QPushButton* salvaCome;
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
    QHBoxLayout* chartBaseLayout;
    QHBoxLayout* chartSpecificiLayout;
    QVBoxLayout* fieldLayout;
    QChart* passChart;
    QChart* barChart;
    QChart* votiChart;
    QChart* durataChart;
    QChart* esChart;
    QChartView *esChartView;
    QChartView *passChartView;
    QChartView *barChartView;
    QChartView *durChartView;
    QChartView *votiChartView;
    QLabel*noChart;


    QLayout* createDescriptionLayout(const QString& description, const QString& imgPath);

    void connectViewSignals() const override;

protected:

    void closeEvent(QCloseEvent *event) override;

public:

    explicit userView(const QSize& s = QSize(),View* parent = nullptr);

    virtual void setController(Controller*c) override;

    void insertCorsi(std::vector<QString> listaCorsi);

    void createPassChart(unsigned int primo, unsigned int secondo, unsigned int terzo, unsigned int quarto, unsigned int quinto, QString title);

    void createPromossiperYearChart(std::vector<unsigned int> promossi, std::vector<unsigned int> bocciati, QString title);

    void createVotiChart(std::vector<unsigned int> voti, QString title);

    void createDurataChart(std::list<unsigned int> durata, QString title);

    void createEsChart(float aperte, float chiuse, float esercizi, QString title);

    void createInsertField();

    std::vector<corsoPButton*> getCorsoVector();

    void destroyChartsBase();

    void destroyChartsScritti();

    void destroyChartsOrali();

    void addCorso(QString title);

    void removeCorso(int posizione);

    void resetFields();

    void hideDefaultLabel() const;

    void showDefaultLabel() const;

signals:

    void insertEsame(int, int, int, QDate, int, int, int, int) const;

    void showChart() const;

    void modCorso(int) const;

    void selectCorso(int) const;

    void deleteCorso(int) const;

public slots:
};

#endif // USERVIEW_H

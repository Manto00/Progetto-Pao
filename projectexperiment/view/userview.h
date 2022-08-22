#ifndef USERVIEW_H
#define USERVIEW_H

#include <view/view.h>
#include <usermodel.h>
#include <vector>
#include <QBoxLayout>
#include <QPushButton>

class userView: public View
{
    Q_OBJECT
private:
    QPushButton* newModelButton;
    QPushButton* changeModelButton;
    QPushButton* addButton;
    QPushButton* newEsame;
    std::vector<QPushButton> corsiButton;
    QVBoxLayout* mainLayout;
    QHBoxLayout* introLayout;
    QHBoxLayout* activeLayout;
    QVBoxLayout* corsiLayout;
    QVBoxLayout* chartLayout;


    QLayout* createDescriptionLayout(const QString& description, const QString& imgPath);

    void connectViewSignals() const override;

protected:

    void closeEvent(QCloseEvent *event) override;

public:

    explicit userView(const QSize& s = QSize(),View* parent = nullptr, std::vector<QString> listaCorsi=std::vector<QString>());

    virtual void setController(Controller*c) override;

    void insertCorsi(std::vector<QString> listaCorsi);

    void createCharts(std::list<unsigned int>listaVoto, std::list<unsigned int>listaAppello, std::list<unsigned int>listaData,
                      std::list<unsigned int>listaAperte, std::list<unsigned int>listaChiuse, std::list<unsigned int>listaEsercizi, std::list<unsigned int>listaDurata);

    void createCharts(std::list<unsigned int>listaVoto, std::list<unsigned int>listaAppello, std::list<unsigned int>listaData,
                      std::list<unsigned int>listaAperte, std::list<unsigned int>listaChiuse, std::list<unsigned int>listaEsercizi);

    void createCharts(std::list<unsigned int>listaVoto, std::list<unsigned int>listaAppello, std::list<unsigned int>listaData,
                      std::list<unsigned int>listaDurata);

signals:

    void newProject() const;

    void openProject() const;

public slots:
};

#endif // USERVIEW_H

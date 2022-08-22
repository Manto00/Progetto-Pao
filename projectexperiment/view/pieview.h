#ifndef PIEVIEW_H
#define PIEVIEW_H
#include <view/view.h>
#include <QtCharts/QChartView>
#include <QtCharts/qpieseries.h>
#include <QBoxLayout>

    QT_CHARTS_USE_NAMESPACE

class pieView: public View
{
protected:
    QPieSeries* series;
    QChart* chart;

public:
    explicit pieView(const QSize& s = QSize(800,500),View* parent = nullptr);

    /**
     * @brief insertMaterial Metodo che serve ad inserire un nuovo materiale nel grafico
     * a torta
     * @param materiale materiale da aggiungere
     * @param occurences occorenze del materiale
     */
    virtual void parametrize(unsigned int aperte, unsigned int chiuse, unsigned int esercizi);

    /**
     * @brief applyGraphics Metodo che serve ad impostare le caratteristiche grafiche
     * del grafioc a torta
     * In particolare imposta i label visibili, mostra un contorno per ogni fetta
     * e modifica il label aggiungendo la percentuale accanto.
     */
    virtual void applyGraphics();
};

#endif // PIEVIEW_H

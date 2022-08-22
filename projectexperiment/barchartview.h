#ifndef BARCHARTVIEW_H
#define BARCHARTVIEW_H

#include <view/view.h>

#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>

#include <QScrollBar>
#include <QHBoxLayout>
#include <map>
#include <list>

QT_CHARTS_USE_NAMESPACE

class BarChartView : public View
{
    Q_OBJECT
protected:
    QChart* chart;
    QBarSeries *series;
    std::list<QBarSet*>listaSetsItem;
    QStringList listaOrdini;
    QScrollBar* chartScroll;
    //Parametro che indica quanti mesi alla volta mostrare nel grafico
    int maxItems = 6;

    /**
     * @brief connectViewSignals Metodo virtuale che serve a collegare i segnali dei singoli
     * Widget ai segnali della View
     */
    void connectViewSignals() const override;

public:
    /**
     * @brief BarChartView Costruttore della View
     * @param size size della window
     * @param parent view parente invocante
     */
    explicit BarChartView(const QSize& size = QSize(300,300), View* parent = nullptr, const QString title="");

    /**
     * @brief insertSetMateriale Metodo che serve ad inserire un SET di dati
     * Un set di dati in questo caso rappresenta una barra e per ciascuna meseA
     * cioè ciascuna data.
     * @param materiale materiale titolo del set
     * @param consumiMesi consumi per ogni meseA del set, per ogni barra
     */
    void insertSetItem(const QString& items, std::list<uint> serieOrdini);

    /**
     * @brief applySetsOnChart Metodo che aggiunge i sets allla series
     * successivemente applica la series al chart.
     * in pratica mostra i dati al chart.
     */
    void applySetsOnChart();

    /**
     * @brief applyAxis Metodo che imposta i dettagli degli Assi
     * impostandone la grandezza e la descrizione
     * @param mesi lista dei meseA con la descrizione per l'asse X
     * @param maxY massimo intero dei dati da rapresentare, appunto con la
     * granzza massima del asse y
     */
    void applyAxis(const QStringList& mesi, const uint maxY);

};

#endif // BARCHARTVIEW_H

#include "barchartview.h"

void BarChartView::connectViewSignals() const{
    //niente da dichiarare
}

BarChartView::BarChartView(const QSize &size, View *parent, const QString title) :
    View(size,parent),
    chart(new QChart()),
    series(new QBarSeries()),
    chartScroll(new QScrollBar(Qt::Horizontal,this))
{
    //Connetto i segnali della View ai widget
    connectViewSignals();

    //Chart
    chart->setTheme(QChart::ChartThemeDark);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->setAnimationDuration(1500);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setTitle(title);
    QChartView* chartView = new QChartView(chart,this);
    chartView->setRenderHint(QPainter::Antialiasing);

    //Main Layout
    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addWidget(chartView);
    mainLayout->addWidget(chartScroll);
    setLayout(mainLayout);
    setMinimumSize(300,300);
    resize(size);
}

void BarChartView::insertSetItem(const QString &quantita, std::list<uint> serieItems){
    QBarSet* set = new QBarSet(quantita);
    for(auto item : serieItems)
        *set << item;
    listaSetsItem.push_back(set);
}

void BarChartView::applySetsOnChart(){
    for(auto s : listaSetsItem)
        series->append(s);
    chart->addSeries(series);
}

void BarChartView::applyAxis(const QStringList &items, const uint maxY){
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(items);
    //Set range per il grafico, massimo 6 mesi PER volta da mostrare
    //Se il numero di mesi disponibili è più grande di 6 imposto un range dal primo al 6 mese
    //Se il numero di mesi disponibile è più piccolo di 6 imposto un range dal primo al ultimo
    axisX->setRange(items.at(0),items.length() > maxItems  ? items.at(maxItems-1) : items.last());
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0,maxY);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    //Imposto titolo degli assi
    if(chart->axisX() && chart->axisY()){
       chart->axisX()->setTitleText("Pietanza");
       chart->axisY()->setTitleText("Ordini giornialieri");
    }

    //Scrlling
    //Imposto il range della scrllbar da 0 al mesiA.lenght - mesiVisibili
    //il range finisce a mesiA.lenght - mesiVisibili perchè così
    //posso mostrare da v a v+mesivisibili
    chartScroll->setRange(0,items.length()-(maxItems));
    //Creo una connessione per la scrllbar in maniera che al variare del suo valore
    //mostro sul cahrt a partire da valore selezionato a valore selezionato + mesi visibili
    int max = maxItems;
    connect(chartScroll,&QAbstractSlider::valueChanged,this,[max,items,this](int v){
        chart->axisX()->setRange(items.at(v),items.at(v+(max-1)));
    });
}



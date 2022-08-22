#include "pieview.h"

pieView::pieView(const QSize& size, View*parent): View(size,parent), series(new QPieSeries()), chart(new QChart())
{
    QHBoxLayout* mainLayout = new QHBoxLayout;
    chart->addSeries(series);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setTheme(QChart::ChartThemeDark);
    chart->setAnimationOptions(QChart::AllAnimations);
    chart->setAnimationDuration(500);
    QChartView *chartView = new QChartView(chart,this);
    chartView->setRenderHint(QPainter::Antialiasing);
    mainLayout->addWidget(chartView);
    setLayout(mainLayout);
    setMinimumSize(800,500);
    resize(size);
}

void pieView::parametrize(unsigned int aperte, unsigned int chiuse, unsigned int esercizi){
    series->append("domande aperte", aperte);
    series->append("domande chiuse", chiuse);
    series->append("esercizi", esercizi);
}

void pieView::applyGraphics(){
    for(QPieSlice* slice : series->slices()){
        //slice->setExploded();
        slice->setPen(QPen(Qt::white, 2));
        slice->setLabelColor(Qt::black);
        slice->setLabelVisible();
    }
    chart->setTitle("Distribuzione quesiti");
    series->setLabelsPosition(QPieSlice::LabelInsideTangential);
}

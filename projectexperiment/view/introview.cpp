#include "introview.h"

introView::introView(const QSize& s, View* parent): View(s, parent)
{
    mainLayout=new QVBoxLayout();
    mainLayout->setSpacing(10);
    mainLayout->setMargin(10);

    newModel=new QPushButton("Inizia un nuovo modello", this);
    mainLayout->addWidget(newModel, Qt::AlignCenter);

    openModel=new QPushButton("Apri un modello esistente", this);
    mainLayout->addWidget(openModel, Qt::AlignCenter);

    setLayout(mainLayout);
}

void introView::connectViewSignals() const{}

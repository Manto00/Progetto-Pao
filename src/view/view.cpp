#include "view.h"

void View::closeEvent(QCloseEvent *event){
    event->accept();
    hide();
    emit viewClosed();
}

View::View(const QSize& s,View* parent) : QWidget(parent,Qt::Window){
    //Resizing della windows
    if(!s.isEmpty() && !s.isNull())
        setWindowSize(s);
}

void View::setController(Controller *c){
    ctrl=c;
}

void View::setWindowSize(const QSize& s){
    resize(s);
}

void View::showInformationDialog(const QString& title, const QString& mesInfo){
    QMessageBox::information(this,title,mesInfo,QMessageBox::Ok);
}

void View::showCriticalDialog(const QString& title, const QString& mesInfo){
    QMessageBox::critical(this,title,mesInfo,QMessageBox::Ok);
}

void View::showWarningDialog(const QString& title, const QString& mesInfo){
    QMessageBox::warning(this,title,mesInfo,QMessageBox::Ok);
}

bool View::showQuestionDialog(unsigned int paramNum, const QString& title,const QString& info){
    QMessageBox::StandardButton resBtn = QMessageBox::Yes;
    switch (paramNum)
    {
        case 2:
            resBtn = QMessageBox::question( this,title,info,QMessageBox::No | QMessageBox::Yes | QMessageBox::Yes);
        break;
        default:
            resBtn = QMessageBox::question( this,title,info,QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes | QMessageBox::Yes);
        break;
    }
    return (resBtn == QMessageBox::Yes);
}

void View::setViewTitle(const QString &title){
    setWindowTitle(title);
}

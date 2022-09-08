#ifndef VIEW_H
#define VIEW_H

#include <QWidget>
#include <QSize>
#include <QMessageBox>
#include <QCloseEvent>
#include <iostream>


class Controller;
/**
 * @brief The View class
 * Classe che serve a rappresentare una View,
 */
class View : public QWidget
{
    Q_OBJECT
private:

    virtual void connectViewSignals() const = 0;

protected:

    Controller* ctrl;

    void closeEvent(QCloseEvent *event) override;

public:

    explicit View(const QSize& s = QSize(),View* parent = nullptr);


    virtual ~View() {
        /*setParent(nullptr);*/
    }

    virtual void setController(Controller* c);

    void setWindowSize(const QSize&);

    bool showQuestionDialog(unsigned int paramNum, const QString& title,const QString& info);

    void showWarningDialog(const QString& title, const QString& mesInfo);

    void showInformationDialog(const QString &title, const QString &mesInfo);

    void showCriticalDialog(const QString &title, const QString &mesInfo);

    void setViewTitle(const QString &title);


signals:
    //Segnale emesso al Controller per avvisarlo della chiusura della View
    void viewClosed() const;

public slots:

};

#endif // VIEW_H

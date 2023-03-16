#ifndef VIEW_H
#define VIEW_H

#include <QWidget>
#include <QSize>
#include <QMessageBox>
#include <QCloseEvent>


class Controller;


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


    virtual void setController(Controller* c);

    void setWindowSize(const QSize&);

    bool showQuestionDialog(unsigned int paramNum, const QString& title,const QString& info);

    void showWarningDialog(const QString& title, const QString& mesInfo);

    void showInformationDialog(const QString &title, const QString &mesInfo);

    void showCriticalDialog(const QString &title, const QString &mesInfo);

    void setViewTitle(const QString &title);


signals:
    void viewClosed() const;

public slots:

};

#endif // VIEW_H

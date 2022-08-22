#ifndef USERCONTROLLER_H
#define USERCONTROLLER_H

#include <controller/controller.h>
#include <view/userview.h>
#include <usermodel.h>

class userController: public Controller
{
    Q_OBJECT
public:
    userController();
private:
    /**
     * @brief connectViewCtrlSignalsSlots Metodo overloading
     * Questo Metodo serve a connettere i SIGNAL della AdminView ai Slot del AdminCtrl
     */
    void connectSlots() const;

public:
    /**
     * @brief AdminCtrl
     * @param v View collegata al Controller
     * @param m Model collegato al Controller
     */
    userController(userView* v, usermodel* m = new usermodel(), Controller* parent = nullptr);

    /**
     * @brief getView Ritorna La View castata almeno al tipo corrente AdminView
     * @return
     */
    userView* getView() const;

    /**
     * @brief getModel Ritorna il Model castato almeno al tipo corrente ModelView
     * @return
     */
    usermodel* getModel() const;

signals:

public slots:

    void onShowChart(int i) const;
     /**
      * @brief onViewClosed SLOT eseguito alla ricezione di SEGNALI di chiusura della View
      * In questo caso distrugger il suddetto controller, che di seguito distrugge la view e il model
      */
     void onViewClosed() const override;

};

#endif // USERCONTROLLER_H

#include "introcontroller.h"
#include "iostream"


introController::introController(introView* v, Controller* parent): Controller(v, nullptr, parent)
{
    connectSlots();
}

introView* introController::getView() const {
    return static_cast<introView*>(vista);
}

usermodel* introController::getModel() const{return nullptr;}

void introController::connectSlots() const{
    /*
    connect(vista, SIGNAL(createNewModel()), this, SLOT(onNewModel()));
    connect(vista, SIGNAL(openUserView()), this, SLOT(onOpenView()));*/
}

void introController::onNewModel() const{
    userView* uView = new userView(vista->size(),vista);
    uView->setViewTitle(tr("Nuovo"));
    userController* uController = new userController(uView,new usermodel(),const_cast<Controller*>(static_cast<const Controller*>(this)));
    uView->setController(uController);
    uController->showView();
    vista->hide();
}

void introController::onOpenView() const{

    QString filepath = JSonReader::selectJSONFileDialog();
    if(filepath.isNull()){
        vista->showWarningDialog("Errore Apertura File", "Selezionare un file");
        return;
    }

    QJsonDocument* jsonData = JSonReader::getJSONFileData(filepath);
    if(jsonData->isNull()){
        vista->showWarningDialog("Errore Apertura File", "Riprova con un file valido");
        return;
    }
    std::cout<<"file valido";

    //Apertura Nuova schermata Admin da progetto Salvato
    userView* uView = new userView(vista->size(),vista);
    usermodel* uModel = new usermodel(jsonData,new QString(filepath));
    //usermodel* test=new usermodel();

    //Imposto il titolo alla schermata
    QStringList pieces = uModel->getFilePath().split( "/" );
    QString last = pieces.value( pieces.length() - 1 );
    uView->setViewTitle(last);

    userController* userCtrl = new userController(uView, uModel, const_cast<introController*>(this));//sitemare segnali e slot nella funzione set controller
    uView->setController(userCtrl);//sitemare segnali e slot nella funzione set controller
    userCtrl->showView();

    vista->hide();
}

void introController::onViewClosed() const{
    delete this;
}



#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),tests(new QList<Test*>()),currentTest(0),currentItem(NULL)
{
    ui->setupUi(this);

    tests->append(new Test1());
    tests->append(new Test2());

    QTimer::singleShot(0,this,SLOT(showStartDialog()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showStartDialog(){

    QMessageBox msgBox(this);
    msgBox.setWindowTitle( "Avvia Test" );
    msgBox.setText("Questo Test serve per valutare alcune proprietà delle Interfaccie Utente ( UI )\n"
                   "Ogni schermata contiene un diverso test, segui bene le istruzioni!\n"
                   "Quando sei pronto premi \"Avvia il Test\" per iniziare." );
    QAbstractButton* avvia = msgBox.addButton("Avvia il Test",QMessageBox::AcceptRole);
    msgBox.addButton("Esci",QMessageBox::RejectRole);

    msgBox.exec();

    if(msgBox.clickedButton() == avvia){
        currentItem = tests->at(currentTest)->getNext();
        ui->contentLayout->addWidget(currentItem);
        tests->at(currentTest)->widgetShowed();
    }else{
        this->close();
    }

}

void MainWindow::on_bAvanti_clicked()
{
    if(!tests->at(currentTest)->haveNext())
        currentTest = currentTest+1;

    if(currentTest < tests->size())
        currentItem = tests->at(currentTest)->getNext();
        ui->contentLayout->addWidget(currentItem);
    else
        //showRiepilogo();
}

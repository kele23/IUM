#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),tests(new QList<Test*>()),currentTest(0),currentItem(NULL)
{
    ui->setupUi(this);

    ui->riepilogoWidget->hide();

    tests->append(new Test());
    tests->append(new Test());

    QTimer::singleShot(0,this,SLOT(showStartDialog()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showStartDialog(){

    StartDialog *startDialog = new StartDialog(this);
    connect(startDialog,SIGNAL(accepted()),this,SLOT(on_bAvanti_clicked()));
    connect(startDialog,SIGNAL(rejected()),this,SLOT(close()));
    startDialog->show();

}

void MainWindow::on_bAvanti_clicked()
{
    if(currentItem != NULL)
        ui->contentLayout->removeWidget(currentItem);

    while(currentTest < tests->size() && !tests->at(currentTest)->haveNext())
        currentTest = currentTest+1;

    if(currentTest < tests->size()){
        currentItem = tests->at(currentTest)->getNext();
        ui->contentLayout->addWidget(currentItem);
    }
    else
        ui->riepilogoWidget->show();
}

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),tests(new QList<Test*>()),currentTest(0),currentItem(NULL)
{
    ui->setupUi(this);

    tests->append(new Form());
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

    while(currentTest < tests->size() && !tests->at(currentTest)->hasNext())
        currentTest = currentTest+1;

    QWidget* next;
    if(currentTest < tests->size()){
        next = tests->at(currentTest)->getNext();
    }
    else{
        next = new Riepilogo();
    }

    if(currentItem == NULL){
        currentItem = next;
        ui->contentLayout->addWidget(currentItem);
    }else{
        ui->contentLayout->replaceWidget(currentItem,next);
        currentItem = next;
        if(currentTest < tests->size())
            tests->at(currentTest)->widgetShowed();
    }
}

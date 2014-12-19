#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "test1/test1.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),tests(new QList<Test*>()),currentTest(0),currentItem(NULL)
{
    ui->setupUi(this);

    qsrand(time(NULL));

    tests->append(new Test1());
    tests->append(new Test2());

    for(int i = 0; i < tests->size(); i++){

        Test *test = tests->at(i);
        int ind = qrand() % tests->size();
        Test *testRa = tests->at(ind);

        tests->replace(ind,test);
        tests->replace(i,testRa);
    }

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
    if(currentItem != NULL){
        int elt = currentTime.elapsed();
        tests->at(currentTest)->elapsedTime(elt);
        currentTime.restart();
    }else{
        currentTime.start();
    }

    while(currentTest < tests->size() && !tests->at(currentTest)->hasNext())
        currentTest = currentTest+1;

    QWidget* next;
    if(currentTest < tests->size()){
        next = tests->at(currentTest)->getNext();
    }
    else{
        next = new Riepilogo();
        ui->bAvanti->setText("Esci");
        disconnect(ui->bAvanti,SIGNAL(clicked()),this,SLOT(on_bAvanti_clicked()));
        connect(ui->bAvanti,SIGNAL(clicked()),this,SLOT(close()));
    }

    if(currentItem == NULL){
        currentItem = next;
        ui->contentLayout->addWidget(currentItem);
    }else{
        currentItem->hide();
        ui->contentLayout->replaceWidget(currentItem,next);
        currentItem = next;
    }
}

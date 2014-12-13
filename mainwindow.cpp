#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),tests(new QList<Test*>()),currentTest(0)
{
    ui->setupUi(this);

    tests->append(new Test1());
    tests->append(new Test2());

    connect(this,SIGNAL(window_loaded()),this,SLOT(showStartDialog()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showStartDialog(){

    QMessageBox msgBox(this);
    msgBox.setWindowTitle( "Avvia Test" );
    msgBox.setText("Questo Test serve per valutare alcune proprietà delle Interfaccie Utente");
    msgBox.addButton("Avvia il Test",QMessageBox::AcceptRole);
    msgBox.addButton("Esci",QMessageBox::RejectRole);

    msgBox.exec();

}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QMessageBox>
#include <QTimer>
#include <QLayoutItem>
#include "test.h"
#include "startdialog.h"
#include "riepilogo.h"
#include "test2/test2.h"
#include "result.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    //Interfaccia
    Ui::MainWindow *ui;

    //Proprietà Private
    QList<Test*> *tests;
    int currentTest;

    QWidget *currentItem;
    QTime currentTime;
    //Metodi Privati

//SLOT PRIVATI
private slots:
    void showStartDialog();
    void on_bAvanti_clicked();
};

#endif // MAINWINDOW_H

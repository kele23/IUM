#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QMessageBox>
#include "test.h"
#include "test1.h"
#include "test2.h"

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

    //Metodi Privati
    void showStartDialog();

private slots:
    void startDialogClosed(QAbstractButton* );
};

#endif // MAINWINDOW_H

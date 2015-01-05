#include "panel1test2.h"
#include "ui_panel1test2.h"

Panel1Test2::Panel1Test2(QWidget *parent,Prova prova) :
    QWidget(parent),
    ui(new Ui::Panel1Test2)
{
    ui->setupUi(this);
    ui->textBrowser->setText(prova.testo);
}

Panel1Test2::~Panel1Test2()
{
    delete ui;
}

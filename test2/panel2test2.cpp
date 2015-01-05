#include "panel2test2.h"
#include "ui_panel2test2.h"

Panel2Test2::Panel2Test2(QWidget *parent,Prova prova) :
    QWidget(parent),
    ui(new Ui::Panel2Test2)
{
    ui->setupUi(this);
    ui->textBrowser->setText(prova.testo);
}

Panel2Test2::~Panel2Test2()
{
    delete ui;
}

#include "panel2test2.h"
#include "ui_panel2test2.h"

Panel2Test2::Panel2Test2(QWidget *parent,Prova prova) :
    QWidget(parent),
    ui(new Ui::Panel2Test2)
{
    ui->setupUi(this);
    ui->textBrowser->setText("<BODY bgcolor=\"#FFFFFF\"><P style=\"color:#CCCC00;\">"+prova.testo+"</P></BODY>");
    ui->label->setText(prova.parola);
}

Panel2Test2::~Panel2Test2()
{
    delete ui;
}

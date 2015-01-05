#include "panel1test2.h"
#include "ui_panel1test2.h"

Panel1Test2::Panel1Test2(QWidget *parent,Prova prova) :
    QWidget(parent),
    ui(new Ui::Panel1Test2)
{
    ui->setupUi(this);
    ui->textBrowser->setText("<BODY bgcolor=\"#000042\"><P style=\"color:#ffffff;\">"+prova.testo+"</P></BODY>");
    ui->label->setText(prova.parola);
}

Panel1Test2::~Panel1Test2()
{
    delete ui;
}

#include "riepilogo.h"
#include "ui_riepilogo.h"

Riepilogo::Riepilogo(QWidget *parent,QString res) :
    QWidget(parent),
    ui(new Ui::Riepilogo)
{
    ui->setupUi(this);
    ui->riepilogoText->setText(res);
}

Riepilogo::~Riepilogo()
{
    delete ui;
}

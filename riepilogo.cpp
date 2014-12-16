#include "riepilogo.h"
#include "ui_riepilogo.h"

Riepilogo::Riepilogo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Riepilogo)
{
    ui->setupUi(this);
}

Riepilogo::~Riepilogo()
{
    delete ui;
}

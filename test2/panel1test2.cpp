#include "panel1test2.h"
#include "ui_panel1test2.h"

Panel1Test2::Panel1Test2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Panel1Test2)
{
    ui->setupUi(this);
}

Panel1Test2::~Panel1Test2()
{
    delete ui;
}

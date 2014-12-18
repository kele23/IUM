#include "panel2test1.h"
#include "ui_panel2test1.h"

Panel2test1::Panel2test1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Panel2test1)
{
    ui->setupUi(this);
}

Panel2test1::~Panel2test1()
{
    delete ui;
}

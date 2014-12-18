#include "panel2test2.h"
#include "ui_panel2test2.h"

Panel2Test2::Panel2Test2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Panel2Test2)
{
    ui->setupUi(this);
}

Panel2Test2::~Panel2Test2()
{
    delete ui;
}

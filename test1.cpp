#include "test1.h"
#include "ui_test1.h"

Test1::Test1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Test1)
{
    ui->setupUi(this);
}

Test1::~Test1()
{
    delete ui;
}

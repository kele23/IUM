#include "panel1test1.h"
#include "ui_panel1test1.h"

Panel1Test1::Panel1Test1(QWidget *parent, QString targetWord) :
    targetWord(""),
    QWidget(parent),
    ui(new Ui::Panel1Test1)
{
    this->targetWord = targetWord;
    ui->setupUi(this);
}

Panel1Test1::~Panel1Test1()
{
    delete ui;
}

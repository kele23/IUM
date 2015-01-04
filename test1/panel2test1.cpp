#include "panel2test1.h"
#include "ui_panel2test1.h"

Panel2Test1::Panel2Test1(QWidget *parent, QString targetWord) :
    targetWord(""),
    QWidget(parent),
    ui(new Ui::Panel2Test1)
{
    this->targetWord = targetWord;
    ui->setupUi(this);
}

Panel2Test1::~Panel2Test1()
{
    delete ui;
}

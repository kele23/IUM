#include "panel1test1.h"
#include "ui_panel1test1.h"

Panel1Test1::Panel1Test1(QWidget *parent, QString targetWord) :
    targetWord(""),
    QWidget(parent),
    ui(new Ui::Panel1Test1)
{
    this->targetWord = targetWord;
    ui->setupUi(this);

    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(wordClicked()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(wordClicked()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(wordClicked()));
}

Panel1Test1::~Panel1Test1()
{
    delete ui;
}

void Panel1Test1::wordClicked()
{
    QPushButton* b = (QPushButton*) this->sender();
    if(b->text().compare("ciao") == 0){
        emit goToNextPanel();
    }
}

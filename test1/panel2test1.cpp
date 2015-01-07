#include "panel2test1.h"
#include "ui_panel2test1.h"

Panel2Test1::Panel2Test1(QWidget *parent, QString targetWord) :
    targetWord(""),
    QWidget(parent),
    ui(new Ui::Panel2Test1)
{
    this->targetWord = targetWord;
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(wordClicked()));
}

Panel2Test1::~Panel2Test1()
{
    delete ui;
}

void Panel2Test1::wordClicked()
{
    QPushButton* b = (QPushButton*) this->sender();
    if(b->text().compare("ciao") == 0){
        emit goToNextPanel();
    }
}

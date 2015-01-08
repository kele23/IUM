#include "panel1test1.h"
#include "ui_panel1test1.h"

Panel1Test1::Panel1Test1(QWidget *parent, QString targetWord, QList<QString> *words) :
    targetWord(""),
    QWidget(parent),
    ui(new Ui::Panel1Test1)
{
    this->targetWord = targetWord;
    ui->setupUi(this);

    QList<QAbstractButton *> buttons = ui->buttonGroup->buttons();

    int limit;
    if(buttons.size() < words->size())
        limit = buttons.size();
    else
        limit = words->size();

    for(int i = 0; i < limit; i++ )
        buttons.at(i)->setText(words->at(i));

    foreach(QAbstractButton b, buttons) {
        QPushButton button = (QPushButton) b;
        connect(button,SIGNAL(clicked()),this,SLOT(wordClicked()));
    }
    /*
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(wordClicked()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(wordClicked()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(wordClicked()));
    */
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

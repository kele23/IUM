#include "panel2test1.h"
#include "ui_panel2test1.h"

Panel2Test1::Panel2Test1(QWidget *parent, QString targetWord, QList<QString> *words) :
    targetWord(""),
    QWidget(parent),
    ui(new Ui::Panel2Test1)
{
    this->targetWord = targetWord;
    ui->setupUi(this);

    /*QList<QAbstractButton *> buttons = ui->buttonGroup->buttons();

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
    }*/

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

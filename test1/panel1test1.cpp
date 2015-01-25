#include "panel1test1.h"
#include "ui_panel1test1.h"

Panel1Test1::Panel1Test1(QWidget *parent, QString targetWord, QList<QString> *words,bool readable) :
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

    ui->label_2->setText("<html><head/><body><p><span style=\"font-size:9pt; font-weight:600;\">" + targetWord + "</span></p></body></html>");

    QPushButton* button;
    foreach(QAbstractButton *b, buttons) {
        button = (QPushButton*) b;
        b->setProperty("readable",readable);
        connect(button,SIGNAL(clicked()),this,SLOT(wordClicked()));
    }
}

Panel1Test1::~Panel1Test1()
{
    delete ui;
}

void Panel1Test1::wordClicked()
{
    QPushButton* b = (QPushButton*) this->sender();
    if(b->text().compare(targetWord) == 0){
        emit goToNextPanel();
    }
}

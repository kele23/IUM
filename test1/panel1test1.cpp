#include "panel1test1.h"
#include "ui_panel1test1.h"

Panel1Test1::Panel1Test1(QWidget *parent, QString targetWord, QList<QString> *words) :
    targetWord(""),
    QWidget(parent),
    ui(new Ui::Panel1Test1)
{
    this->targetWord = targetWord;
    //const QString stylesh = "QPushButton { font: 87 10pt \"Arial Black\"\; color:rgb(190, 40, 40)} QPushButton[switchColor=\"true\"] {color:rgb(0, 64, 255)}";

    //check current stylesheet
    //qDebug("%s", ui->widget->styleSheet().toUtf8().constData());
    ui->setupUi(this);
    QList<QAbstractButton *> buttons = ui->buttonGroup->buttons();

    int limit;
    if(buttons.size() < words->size())
        limit = buttons.size();
    else
        limit = words->size();

    for(int i = 0; i < limit; i++ )
        buttons.at(i)->setText(words->at(i));
    ui->label_2->setText(targetWord);
    foreach(QAbstractButton *b, buttons) {
        QPushButton* button = (QPushButton*) b;
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

void Panel1Test1::changeColors(QString stylesh)
{
    ui->widget->setStyleSheet(stylesh);
}

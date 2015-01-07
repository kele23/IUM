#include "paneltest2.h"
#include "ui_paneltest2.h"

PanelTest2::PanelTest2(QWidget *parent,Exam exam) :
    QWidget(parent),
    ui(new Ui::PanelTest2)
{
    ui->setupUi(this);
    ui->textBrowser->setText("<BODY bgcolor=\""+exam.backgroundColor+"\"><P style=\"color:"+exam.textColor+";\">"+exam.text+"</P></BODY>");
    ui->lWordSearch->setText(exam.word);
}

PanelTest2::~PanelTest2()
{
    delete ui;
}

int PanelTest2::getInsOccurrences(){
    return ui->spinBox->value();
}

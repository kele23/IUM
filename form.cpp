#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form),show(false)
{
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}

bool Form::hasNext(){
    if(!show)
        return true;
    else
        return false;
}

QWidget* Form::getNext(){
    show = true;
    return this;
}

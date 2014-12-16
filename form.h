#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include "test.h"

namespace Ui {
class Form;
}

class Form : public QWidget, public Test
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();

    bool hasNext();
    QWidget* getNext();

private:
    Ui::Form *ui;

    bool show;
};

#endif // FORM_H

#ifndef PANEL1TEST2_H
#define PANEL1TEST2_H

#include <QWidget>
#include "test2/prova.h"

namespace Ui {
class Panel1Test2;
}

class Panel1Test2 : public QWidget
{
    Q_OBJECT

public:
    explicit Panel1Test2(QWidget *parent = 0,Prova prova = Prova());
    ~Panel1Test2();

private:
    Ui::Panel1Test2 *ui;
};

#endif // PANEL1TEST2_H

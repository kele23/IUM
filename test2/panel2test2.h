#ifndef PANEL2TEST2_H
#define PANEL2TEST2_H

#include <QWidget>
#include "test2/prova.h"

namespace Ui {
class Panel2Test2;
}

class Panel2Test2 : public QWidget
{
    Q_OBJECT

public:
    explicit Panel2Test2(QWidget *parent = 0,Prova prova = Prova());
    ~Panel2Test2();

private:
    Ui::Panel2Test2 *ui;
};

#endif // PANEL2TEST2_H

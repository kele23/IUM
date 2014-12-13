#ifndef TEST1_H
#define TEST1_H

#include <QWidget>
#include "test.h"

namespace Ui {
class Test1;
}

class Test1 : public QWidget, public Test
{
    Q_OBJECT

public:
    explicit Test1(QWidget *parent = 0);
    ~Test1();


private:
    Ui::Test1 *ui;
};

#endif // TEST1_H

#ifndef TEST1_H
#define TEST1_H

#include <QWidget>
#include "test.h"


class Test1 : public Test
{

public:
    Test1();
    ~Test1();

    QString getResult();
    bool hasNext();
    QWidget* getNext();
};

#endif // TEST1_H

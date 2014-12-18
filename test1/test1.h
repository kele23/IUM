#ifndef TEST1_H
#define TEST1_H

#include <QWidget>
#include "test.h"


class Test1 : public Test
{

public:
    Test1(QWidget *parent);
    ~Test1();

    QString getResult();
    bool hasNext();
    QWidget* getNext();

private:
    QList<QWidget*> *panels;
    int currentPanel;
};

#endif // TEST1_H

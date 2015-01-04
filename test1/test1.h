#ifndef TEST1_H
#define TEST1_H

#include <QWidget>
#include "test.h"


class Test1 : public Test
{

public:
    Test1();
    ~Test1();

    bool hasNext();
    QWidget* getNext();
    QString getRandomWord();

private:
    void createList(QList<QString>*words);
};

#endif // TEST1_H

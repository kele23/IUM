#ifndef TEST1_H
#define TEST1_H

#include <QObject>
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

    bool needNextButton();

private:
    void createList(QList<QString>*words);
};

#endif // TEST1_H

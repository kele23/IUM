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

    QString getTestName();

private:
    QList<QString> *words;
    void createList(QList<QString> *words);
    void randomizeWords(QList<QString> *words);
};

#endif // TEST1_H

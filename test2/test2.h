#ifndef TEST2_H
#define TEST2_H

#include "test.h"
#include <QWidget>
#include "test2/panel1test2.h"
#include "test2/panel2test2.h"

class Test2 : public Test
{
public:
    Test2();

    bool hasNext();
    QWidget* getNext();
    void elapsedTime(int elapsed);

};

#endif // TEST2_H

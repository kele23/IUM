#include "test2.h"

Test2::Test2() : panels(new QList<QWidget*>()),currentPanel(0)
{
    panels->append(new Panel1Test2());
    panels->append(new Panel2Test2());
}

bool Test2::hasNext(){
    if(currentPanel < panels->size())
        return true;
    return false;
}

QWidget* Test2::getNext(){
    return panels->at(currentPanel++);
}

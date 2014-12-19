#include "test1.h"
#include "panel1test1.h"
#include "panel2test1.h"

Test1::Test1(QWidget *parent) : panels(new QList<QWidget*>()), currentPanel(0)
{
    //panels->append(new Panel1test1(parent));
    panels->append(new Panel2test1(parent));
}

Test1::~Test1()
{
}

QString Test1::getResult(){
    return QString();
}

bool Test1::hasNext(){
    if(currentPanel < panels->size())
        return true;
    return false;
}

QWidget* Test1::getNext(){
    int index = currentPanel++;
    return panels->at(index);
}

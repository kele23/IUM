#include "test2.h"

Test2::Test2() : currentPanel(0)
{
}

bool Test2::hasNext(){
    if(currentPanel < 2)
        return true;
    return false;
}

QWidget* Test2::getNext(){
    QWidget *ret;
    switch(currentPanel){
        case 0:
            ret = new Panel1Test2();
            break;
        case 1:
            ret = new Panel2Test2();
            break;
    }
    currentPanel++;
    return ret;
}

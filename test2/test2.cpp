#include "test2.h"

Test2::Test2()
{
    panels = new QList<QWidget*>();
    currentPanel = 0;
    results = new QVector<int>();

    caricaProve();

    panels->append(new Panel1Test2(0,prove.at(0)));
    panels->append(new Panel2Test2(0,prove.at(1)));
}

bool Test2::hasNext(){
    if(currentPanel < panels->size())
        return true;
    return false;
}

QWidget* Test2::getNext(){
    return panels->at(currentPanel++);
}

void Test2::elapsedTime(int elapsed){

}

void Test2::caricaProve(){

    QFile file(":/test2/testi.txt");
    if (!file.exists())
        qFatal("File does not exist");
    if (!file.open(QIODevice::ReadOnly))
        qFatal("Could not open file");

    QXmlSimpleReader xmlReader;
    QXmlInputSource *source = new QXmlInputSource(&file);

    Handler *handler = new Handler;
    xmlReader.setContentHandler(handler);
    xmlReader.setErrorHandler(handler);

    bool ok = xmlReader.parse(source);

    if (!ok)
        qFatal("Parsing failed.");

    prove = handler->getProve();

}

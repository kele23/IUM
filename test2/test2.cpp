#include "test2.h"

Test2::Test2()
{
    panels = new QList<QWidget*>();
    currentPanel = 0;
    results = new QVector<int>();

    loadExams();

    panels->append(new PanelTest2(0,exams.at(0)));
    panels->append(new PanelTest2(0,exams.at(1)));
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
    int err = abs(exams.at(currentPanel-1).occurrences - ((PanelTest2*)panels->at(currentPanel-1))->getInsOccurrences());
    results->append(elapsed + err*500);
}

void Test2::loadExams(){

    QFile file(":/test2/exams.txt");
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

    exams = handler->getExams();

}

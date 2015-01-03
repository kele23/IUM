#include <QFile>
#include <QTextStream>
#include "test1.h"
#include "test1/panel1test1.h"
#include "test1/panel2test1.h"


Test1::Test1()
{
    panels = new QList<QWidget*>();
    currentPanel = 0;
    results = new QVector<int>();
    words = new QList<QString>();

    panels->append(new Panel1Test1());
    panels->append(new Panel2Test1());
    createList(words);

}

Test1::~Test1()
{
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

void Test1::createList(QList<QString> *words) {
    QFile file("/test1/wordslist.txt");
    if (!file.exists())
        qDebug("IL FILE NON ESISTE!");
    if (!file.open(QIODevice::ReadOnly))
        qFatal("Could not open file");
    QTextStream in(&file);
    while(!file.atEnd()) {
        qDebug("letta parola");
        words->append(in.readLine());
    }
}

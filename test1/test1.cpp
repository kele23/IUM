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

    createList(words);
    QString randomWord = getRandomWord();
    panels->append(new Panel1Test1(0, randomWord));
    panels->append(new Panel2Test1(0, randomWord));

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
    QFile file(":/test1/wordslist.txt");
    if (!file.exists())
        qFatal("File does not exist");
    if (!file.open(QIODevice::ReadOnly))
        qFatal("Could not open file");
    QTextStream in(&file);
    while(!in.atEnd())
        words->append(in.readLine());
    file.close();
    qDebug("Dimensione lista: %d", words->size());
    for(int i = 0; i < words->size(); i++) {
        qDebug("Parola: %s", words->at(i).toUtf8().constData());
    }
}

QString Test1::getRandomWord() {
    int index = qrand() % words->size();
    return words->at(index);
}

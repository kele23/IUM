#include <QFile>
#include <QTextStream>
#include "test1.h"
#include "test1/panel1test1.h"


Test1::Test1()
{
    panels = new QList<QWidget*>();
    currentPanel = 0;
    results = new QVector<int>();
    words = new QList<QString>();

    createList(words);
    QString randomWord = getRandomWord();
    Panel1Test1 *p1 = new Panel1Test1(0, randomWord, words);
    connect(p1,SIGNAL(goToNextPanel()),this,SLOT(goNextPanel()));
    panels->append(p1);
    randomizeWords(words);
    Panel1Test1 *p2 = new Panel1Test1(0, getRandomWord(), words);
    p2->changeColors("QPushButton { font: 87 10pt \"Arial Black\"; color:rgb(190, 40, 40)} QPushButton[switchColor=\"true\"] {color:rgb(0, 64, 255)}");
    p2->repaint();
    connect(p2,SIGNAL(goToNextPanel()),this,SLOT(goNextPanel()));
    panels->append(p2);

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

    randomizeWords(words);

    qDebug("Dimensione lista: %d", words->size());
    for(int i = 0; i < words->size(); i++) {
        qDebug("Parola: %s", words->at(i).toUtf8().constData());
    }
}

QString Test1::getRandomWord() {
    int index = qrand() % words->size();
    return words->at(index);
}

void Test1::randomizeWords(QList<QString> *words){
    for(int i = 0; i < words->size(); i++){

        QString wd = words->at(i);
        int ind = qrand() % words->size();
        QString randomWd = words->at(ind);

        words->replace(ind,wd);
        words->replace(i,randomWd);
    }
}

bool Test1::needNextButton(){
    return false;
}

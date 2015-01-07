#ifndef TEST2_H
#define TEST2_H

#include "test.h"
#include <QWidget>
#include <QtXml>
#include <QXmlStreamReader>
#include <QXmlSimpleReader>
#include <QXmlInputSource>
#include "test2/paneltest2.h"
#include "test2/paneltest2.h"
#include "test2/exam.h"

class Test2 : public Test
{
public:
    Test2();

    bool hasNext();
    QWidget* getNext();
    void elapsedTime(int elapsed);

    void loadExams();

private:

    QList<Exam> exams;

    class Handler : public QXmlDefaultHandler{

    public:

        bool fatalError (const QXmlParseException & exception)
        {
            qWarning() << "Fatal error on line" << exception.lineNumber()
                       << ", column" << exception.columnNumber() << ":"
                       << exception.message();

            return false;
        }

        bool endElement(const QString & namespaceURI, const QString & localName, const QString & qName){
            if(localName.compare("WORD") == 0){
                tempExam.word = tempRead;
            }
            else if(localName.compare("OCCURRENCES") == 0){
                tempExam.occurrences = tempRead.toInt();
            }
            else if(localName.compare("TEXT") == 0){
                tempExam.text = tempRead.simplified();
            }
            else if(localName.compare("BACKGROUNDCOLOR") == 0){
                tempExam.backgroundColor = tempRead.simplified();
            }
            else if(localName.compare("TEXTCOLOR") == 0){
                tempExam.textColor = tempRead.simplified();
            }
            else if(localName.compare("EXAM") == 0){
                exams.append(tempExam);
                //qWarning() << "Occorrenze: " << tempExam.occorrenze << " Parola: " << tempExam.parola << " Testo: " << tempExam.testo ;
            }
            return true;
        }

        bool characters(const QString &ch){
            tempRead = ch;
            return true;
        }

        QList<Exam> getExams(){
            return exams;
        }

    private:
        QList<Exam> exams;
        QString tempRead;
        Exam tempExam;
    };
};

#endif // TEST2_H

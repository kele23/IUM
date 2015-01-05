#ifndef TEST2_H
#define TEST2_H

#include "test.h"
#include <QWidget>
#include <QtXml>
#include <QXmlStreamReader>
#include <QXmlSimpleReader>
#include <QXmlInputSource>
#include "test2/panel1test2.h"
#include "test2/panel2test2.h"
#include "test2/prova.h"

class Test2 : public Test
{
public:
    Test2();

    bool hasNext();
    QWidget* getNext();
    void elapsedTime(int elapsed);

    void caricaProve();

private:

    QList<Prova> prove;

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
            if(localName.compare("PAROLA") == 0){
                tempProva.parola = tempRead;
            }
            else if(localName.compare("OCCORRENZE") == 0){
                tempProva.occorrenze = tempRead.toInt();
            }
            else if(localName.compare("TESTO") == 0){
                tempProva.testo = tempRead.simplified();
            }
            else if(localName.compare("PROVA") == 0){
                prove.append(tempProva);
                //qWarning() << "Occorrenze: " << tempProva.occorrenze << " Parola: " << tempProva.parola << " Testo: " << tempProva.testo ;
            }
            return true;
        }

        bool characters(const QString &ch){
            tempRead = ch;
            return true;
        }

        QList<Prova> getProve(){
            return prove;
        }

    private:
        QList<Prova> prove;
        QString tempRead;
        Prova tempProva;
    };
};

#endif // TEST2_H

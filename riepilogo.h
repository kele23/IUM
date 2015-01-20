#ifndef RIEPILOGO_H
#define RIEPILOGO_H

#include <QWidget>
#include <QMap>
#include <QXmlStreamWriter>
#include <QFile>
#include <QXmlSimpleReader>
#include <QXmlInputSource>
#include "result.h"

namespace Ui {
class Riepilogo;
}

class Riepilogo : public QWidget
{
    Q_OBJECT

public:
    explicit Riepilogo(QWidget *parent = 0,QList<Result> *res = 0);
    ~Riepilogo();

private:
    Ui::Riepilogo *ui;
    QList<Result> *res;

    void loadResults();
    void saveResults();

    class Handler : public QXmlDefaultHandler{

    public:

        Handler() : QXmlDefaultHandler(){
            res = new QList<Result>();
        }

        bool fatalError (const QXmlParseException & exception)
        {
            /*qWarning() << "Fatal error on line" << exception.lineNumber()
                       << ", column" << exception.columnNumber() << ":"
                       << exception.message();*/

            return false;
        }

        bool endElement(const QString & namespaceURI, const QString & localName, const QString & qName){
            if(localName.compare("NAME") == 0){
                tempName = tempRead;
            }
            else if(localName.compare("VALUE") == 0){
                Result r;
                r.name = tempName;
                r.value = tempRead.toInt();
                res->append(r);
            }
            return true;
        }

        bool characters(const QString &ch){
            tempRead = ch;
            return true;
        }

        QList<Result>* getResults(){
            return res;
        }

    private:
        QList<Result>* res;
        QString tempRead;
        QString tempName;
    };
};

#endif // RIEPILOGO_H

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

    /**
     * @brief Carica i testi salvati nel file delle risorse test2/exams.txt
     */
    void loadExams();

private:

    QList<Exam> exams;

    /**
     * @brief La classe Handler gestisce la lettura del file XML, rispondendo a eventi quali la fine di un elemento XML o
     * la lettura del testo.
     */
    class Handler : public QXmlDefaultHandler{

    public:

        /**
         * @brief Metodo avviato automaticamente se l'xml reader trova un errore fatale durante il parsing del file xml
         * @param exception, parametro passato automaticamente dal xml reader per descrivere l'errore trovato
         * @return false sempre
         */
        bool fatalError (const QXmlParseException & exception)
        {
            qWarning() << "Fatal error on line" << exception.lineNumber()
                       << ", column" << exception.columnNumber() << ":"
                       << exception.message();

            return false;
        }

        /**
         * @brief Metodo avviato automaticamente, durante il parsing del file xml, ogni volta che viene trovata la fine di un tag.
         * Se il tag è uno di quelli validi, allora il sistema agisce di conseguenza aggiungendo un esame o modificando il contenuto di un esame.
         * @param namespaceURI
         * @param localName
         * @param qName
         * @return
         */
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
            }
            return true;
        }

        /**
         * @brief Metodo avviato automaticamente, durante il parsing del file xml, ogni volta che viene letta una stringa all'interno di campi o CDATA
         * @param La stringa letta
         * @return
         */
        bool characters(const QString &ch){
            tempRead = ch;
            return true;
        }

        /**
         * @brief Ritorna la lista di esami che è stata letta dall'xml
         * @return Lista di Esami
         */
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

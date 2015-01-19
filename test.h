#ifndef TEST_H
#define TEST_H

#include <QString>
#include <QWidget>
#include <QObject>
#include <QLabel>
#include <QTime>
#include <QVector>

/**
 * @brief Interfaccia Test, definisce i metodi generici che ogni classe Test deve implementare
 */
class Test : public QObject{

    Q_OBJECT

public:

    Test(QObject* parent = 0) : QObject(parent){

    }

    /**
     * @brief getResult Ritorna alla MainWindow il vettore di risultati ottenuti nel test.
     * @return il vettore dei risultati.
     */
    virtual QVector<int>* getResults(){
        return results;
    }

    /**
     * @brief haveNext Controlla se il Test contiene altri Widget da mostrare.
     * @return true se il Test contiene altri Widget, false altrimenti.
     */
    virtual bool hasNext(){
        return false;
    }

    /**
     * @brief getNext Ritorna il prossimo Widget che deve essere mostrato dal Test.
     * @return
     */
    virtual QWidget* getNext(){
        return new QLabel("Sono un Widget Inutile");
    }

    /**
     * @brief elapsedTime Salva il punteggio ottenuto nel pannello corrente.
     * @param elapsed tempo trascorso, in millisecondi, corrisponde al punteggio.
     */
    virtual void elapsedTime(int elapsed){
        results->append(elapsed);
    }

    /**
     * @brief needNextButton
     * @return
     */
    virtual bool needNextButton(){
        return true;
    }

signals:
    void goToNextPanel();

protected:

    /**
     * @brief panels Lista dei Widget appartenenti al test.
     */
    QList<QWidget*> *panels;

    /**
     * @brief currentPanel Il pannello correntemente mostrato nel test.
     */
    int currentPanel;

    /**
     * @brief results Contiene il punteggio risultato conseguito in ogni pannello del test.
     */
    QVector<int> *results;


protected slots:
    void goNextPanel(){
        emit goToNextPanel();
    }

};

#endif // TEST_H

#ifndef TEST_H
#define TEST_H

#include <QString>
#include <QWidget>
#include <QObject>
#include <QLabel>

/**
 * @brief Interfaccia Test, definisce i metodi generici che ogni classe Test deve implementare
 */
class Test{

public:

    /**
     * @brief getResult Ritorna il risultato di questo Test in formato Stringa.
     * @return Stringa Vuota se non ci sono risultati altrimenti il risultato del Test.
     */
    virtual QString getResult(){
        return QString();
    }
    /**
     * @brief haveNext Controlla se il Test contiene altri Widget da mostrare.
     * @return true se il Test contiene altri Widget, false altrimenti.
     */
    virtual bool haveNext(){
        return false;
    }

    /**
     * @brief getNext Ritorna il prossimo Widget che deve essere mostrato dal Test.
     * @return
     */
    virtual QWidget* getNext(){
        return new QLabel("Hi!");
    }

    /**
     * @brief widgetShowed Metodo avviato ogni volta che un Widget di questo Test viene mostrato.
     */
    virtual void widgetShowed(){

    }

};

#endif // TEST_H

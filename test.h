#ifndef TEST_H
#define TEST_H

#include <QString>
#include <QWidget>
#include <QObject>
#include <QLabel>
#include <QTime>

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

protected:

    /**
     * @brief panels Lista dei Widget appartenenti al test.
     */
    QList<QWidget*> *panels;

    /**
     * @brief currentPanel Il pannello correntemente mostrato nel test.
     */
    int currentPanel;

};

#endif // TEST_H

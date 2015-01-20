#ifndef PANEL1TEST1_H
#define PANEL1TEST1_H

#include <QWidget>
#include <QPushButton>
#include <QButtonGroup>

namespace Ui {
class Panel1Test1;
}

class Panel1Test1 : public QWidget
{
    Q_OBJECT

public:
    explicit Panel1Test1(QWidget *parent = 0, QString targetWord = 0, QList<QString> *words = 0, bool readable = false);
    ~Panel1Test1();
    void changeColors(QString stylesh);

signals:
    void goToNextPanel();

private slots:
    void wordClicked();

private:
    Ui::Panel1Test1 *ui;
    QString targetWord;
};

#endif // PANEL1TEST1_H

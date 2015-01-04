#ifndef PANEL2TEST1_H
#define PANEL2TEST1_H

#include <QWidget>

namespace Ui {
class Panel2Test1;
}

class Panel2Test1 : public QWidget
{
    Q_OBJECT

public:
    explicit Panel2Test1(QWidget *parent = 0, QString targetWord = 0);
    ~Panel2Test1();

private:
    Ui::Panel2Test1 *ui;
    QString targetWord;
};

#endif // PANEL2TEST1_H

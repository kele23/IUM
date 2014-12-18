#ifndef PANEL1TEST1_H
#define PANEL1TEST1_H

#include <QWidget>

namespace Ui {
class Panel1Test1;
}

class Panel1Test1 : public QWidget
{
    Q_OBJECT

public:
    explicit Panel1Test1(QWidget *parent = 0);
    ~Panel1Test1();

private:
    Ui::Panel1Test1 *ui;
};

#endif // PANEL1TEST1_H

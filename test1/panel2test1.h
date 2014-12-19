#ifndef PANEL2TEST1_H
#define PANEL2TEST1_H

#include <QWidget>

namespace Ui {
class Panel2test1;
}

class Panel2test1 : public QWidget
{
    Q_OBJECT

public:
    explicit Panel2test1(QWidget *parent = 0);
    ~Panel2test1();

private:
    Ui::Panel2test1 *ui;
};

#endif // PANEL2TEST1_H

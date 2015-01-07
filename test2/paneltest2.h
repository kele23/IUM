#ifndef PANELTEST2_H
#define PANELTEST2_H

#include <QWidget>
#include "test2/exam.h"

namespace Ui {
class PanelTest2;
}

class PanelTest2 : public QWidget
{
    Q_OBJECT

public:
    explicit PanelTest2(QWidget *parent = 0,Exam exam = Exam());
    ~PanelTest2();

    int getInsOccurrences();

private:
    Ui::PanelTest2 *ui;
};

#endif // PANELTEST2_H

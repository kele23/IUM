#ifndef RIEPILOGO_H
#define RIEPILOGO_H

#include <QWidget>

namespace Ui {
class Riepilogo;
}

class Riepilogo : public QWidget
{
    Q_OBJECT

public:
    explicit Riepilogo(QWidget *parent = 0,QString res = "");
    ~Riepilogo();

private:
    Ui::Riepilogo *ui;
};

#endif // RIEPILOGO_H

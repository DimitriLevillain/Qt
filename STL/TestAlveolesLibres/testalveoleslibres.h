#ifndef TESTALVEOLESLIBRES_H
#define TESTALVEOLESLIBRES_H

#include <QWidget>
#include "alveoleslibres.h"

namespace Ui {
class TestAlveolesLibres;
}

class TestAlveolesLibres : public QWidget
{
    Q_OBJECT

public:
    explicit TestAlveolesLibres(QWidget *parent = nullptr);
    ~TestAlveolesLibres();

private slots:
    void on_pushButtonQuitter_clicked();

    void on_pushButtonReserver_clicked();

private:
    Ui::TestAlveolesLibres *ui;
    AlveolesLibres *alveoles;
};

#endif // TESTALVEOLESLIBRES_H

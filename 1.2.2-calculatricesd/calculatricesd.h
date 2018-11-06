#ifndef CALCULATRICESD_H
#define CALCULATRICESD_H

#include <QWidget>

namespace Ui {
class CalculatriceSD;
}

class CalculatriceSD : public QWidget
{
    Q_OBJECT

public:
    explicit CalculatriceSD(QWidget *parent = nullptr);
    ~CalculatriceSD();

private slots:
    void on_pushButtonClear_clicked();

    void on_pushButtonEgal_clicked();

    void onQPushButtonClicked();

private:
    Ui::CalculatriceSD *ui;
};

#endif // CALCULATRICESD_H

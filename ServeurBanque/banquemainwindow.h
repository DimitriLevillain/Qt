#ifndef BANQUEMAINWINDOW_H
#define BANQUEMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class BanqueMainWindow;
}

class BanqueMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit BanqueMainWindow(QWidget *parent = nullptr);
    ~BanqueMainWindow();

private:
    Ui::BanqueMainWindow *ui;
};

#endif // BANQUEMAINWINDOW_H

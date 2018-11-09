#ifndef SERVEURWIDGET_H
#define SERVEURWIDGET_H

#include <QWidget>

namespace Ui {
class ServeurWidget;
}

class ServeurWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ServeurWidget(QWidget *parent = nullptr);
    ~ServeurWidget();

private:
    Ui::ServeurWidget *ui;
};

#endif // SERVEURWIDGET_H

#ifndef SERVEURWIDGET_H
#define SERVEURWIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QHostInfo>
#include <QProcess>

namespace Ui {
class ServeurWidget;
}

class ServeurWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ServeurWidget(QWidget *parent = nullptr);
    ~ServeurWidget();

private slots:

    void on_pushButtonQuitter_clicked();

    void on_pushButtonLancementServeur_clicked();

    void onQTcpServer_newConnection();

    void onQTcpSocketReadyRead();

    void onQProcess_readyReadStandartOutput();

private:
    Ui::ServeurWidget *ui;
    QTcpServer *socketEcouteServeur;
    QTcpSocket *socketDialogueClient;
    QProcess *process;
};

#endif // SERVEURWIDGET_H

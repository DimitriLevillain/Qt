#ifndef SERVEURWIDGET_H
#define SERVEURWIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QProcess>
#include <QTcpSocket>
#include <QHostInfo>

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

    void on_pushButtonLancement_clicked();

    void onQTcpServer_newConnection();

    void onQTcpSocket_readyRead();

    void onQProcess_readyReadStandartOutput();

    void onQTcpSocket_disconnected();

private:
    Ui::ServeurWidget *ui;
    QTcpServer *socketEcouteServeur;
    QList<QTcpSocket*> socketDialogueClient;
    QList<QProcess*> process;
};

#endif // SERVEURWIDGET_H

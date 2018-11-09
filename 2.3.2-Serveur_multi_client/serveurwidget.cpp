#include "serveurwidget.h"
#include "ui_serveurwidget.h"

ServeurWidget::ServeurWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ServeurWidget)
{
    ui->setupUi(this);

    socketEcouteServeur = new QTcpServer(this);
    //socketDialogueClient = new QTcpSocket(this);
    //process = new QProcess(this);

    connect(socketEcouteServeur, &QTcpServer::newConnection,this,&ServeurWidget::onQTcpServer_newConnection);
}

ServeurWidget::~ServeurWidget()
{
    delete ui;
}

void ServeurWidget::on_pushButtonQuitter_clicked()
{
    close();
}

void ServeurWidget::on_pushButtonLancement_clicked()
{

}

void ServeurWidget::onQTcpServer_newConnection()
{
    QTcpSocket *client;
    client = socketEcouteServeur->nextPendingConnection();
    connect(client,&QTcpSocket::readyRead,this,&ServeurWidget::onQTcpSocket_readyRead);
    socketDialogueClient.append(client);
    //connect(process, &QProcess::readyReadStandardOutput,this,&ServeurWidget::onQProcess_readyReadStandartOutput);
}

void ServeurWidget::onQTcpSocket_readyRead()
{

}

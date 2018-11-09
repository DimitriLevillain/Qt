#include "serveurwidget.h"
#include "ui_serveurwidget.h"

ServeurWidget::ServeurWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ServeurWidget)
{
    ui->setupUi(this);

    socketEcouteServeur = new QTcpServer(this);
    socketDialogueClient = new QTcpSocket(this);
    process = new QProcess(this);

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

void ServeurWidget::on_pushButtonLancementServeur_clicked()
{
    if(!socketEcouteServeur->listen(QHostAddress::Any, ui->spinBoxPort->value()))
    {
        qDebug() << "Le serveur ne peut pas se lancer";
    }
    else
    {
        qDebug() << "Le serveur est lancé";
    }
}

void ServeurWidget::onQTcpServer_newConnection()
{
    socketDialogueClient = socketEcouteServeur->nextPendingConnection();
    connect(socketDialogueClient, &QTcpSocket::readyRead,this,&ServeurWidget::onQTcpSocketReadyRead);
    connect(process, &QProcess::readyReadStandardOutput,this,&ServeurWidget::onQProcess_readyReadStandartOutput);
}

void ServeurWidget::onQTcpSocketReadyRead()
{
    QString reponse;
    QTextStream texte(socketDialogueClient);

    reponse = socketDialogueClient->readAll();
    if(reponse == 'c')
    {
        reponse = getenv("USERNAME");
        ui->textEditClients->append(reponse);
        texte << reponse;
    }
    if(reponse == 'u')
    {
        reponse = QHostInfo::localHostName();
        ui->textEditClients->append(reponse);
        texte << reponse;
    }
    if(reponse == 'o')
    {
        process->start("uname",QStringList("-p"));
    }
    if(reponse == 'a')
    {
        process->start("uname");
    }
    //texte << "message recu" << endl;
}

void ServeurWidget::onQProcess_readyReadStandartOutput()
{
    QString reponse = process->readAllStandardOutput();
    if(!reponse.isEmpty())
    {
        QString message = "Réponse envoyée à " + socketDialogueClient->peerAddress().toString()+" : " + reponse;
        ui->textEditClients->append(message);
        socketDialogueClient->write(reponse.toLatin1());
    }
}

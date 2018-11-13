#include "serveurwidget.h"
#include "ui_serveurwidget.h"

ServeurWidget::ServeurWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ServeurWidget)
{
    ui->setupUi(this);

    socketEcouteServeur = new QTcpServer(this);


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
    QTcpSocket *client;
    client = socketEcouteServeur->nextPendingConnection();
    connect(client,&QTcpSocket::readyRead,this,&ServeurWidget::onQTcpSocket_readyRead);
    connect(client,&QTcpSocket::disconnected,this,&ServeurWidget::onQTcpSocket_disconnected);
    socketDialogueClient.append(client);

    QProcess *processus = new QProcess;
    connect(processus, &QProcess::readyReadStandardOutput,this,&ServeurWidget::onQProcess_readyReadStandartOutput);
    process.append(processus);
}

void ServeurWidget::onQTcpSocket_disconnected()
{
    QTcpSocket *client=qobject_cast<QTcpSocket*>(sender());
    int indexProcess=socketDialogueClient.indexOf(client);
    process.removeAt(indexProcess);
    socketDialogueClient.removeOne(socketDialogueClient.at(indexProcess));
}

void ServeurWidget::onQTcpSocket_readyRead()
{
    //QByteArray donnees;
    QString donnees;
    //QString texte;
    QTcpSocket *client=qobject_cast<QTcpSocket*>(sender());
    int indexProcess=socketDialogueClient.indexOf(client);
    donnees = socketDialogueClient.at(indexProcess)->readAll();
    qDebug() << indexProcess;
    ui->textEditClients->append(QString::number(indexProcess));
    ui->textEditClients->append(donnees);
    //process.at(indexProcess)->start("uname");

    if(donnees == 'u')
    {
        donnees = getenv("USERNAME");
        ui->textEditClients->append(donnees);
        socketDialogueClient.at(indexProcess)->write(donnees.toLatin1());
    }
    if(donnees == 'c')
    {
        donnees = QHostInfo::localHostName();
        ui->textEditClients->append(donnees);
        socketDialogueClient.at(indexProcess)->write(donnees.toLatin1());
    }
    if(donnees == 'a')
    {
        process.at(indexProcess)->start("uname",QStringList("-p"));
    }
    if(donnees == 'o')
    {
        process.at(indexProcess)->start("uname");
    }
}

void ServeurWidget::onQProcess_readyReadStandartOutput()
{
    QProcess *processus=qobject_cast<QProcess*>(sender());
    int indexProcess=process.indexOf(processus);
    QString reponse = process.at(indexProcess)->readAllStandardOutput();
    if(!reponse.isEmpty())
    {
        QString message = "Réponse envoyée à " + socketDialogueClient.at(indexProcess)->peerAddress().toString()+" : " + reponse;
        ui->textEditClients->append(message);
        socketDialogueClient.at(indexProcess)->write(reponse.toLatin1());
    }
}


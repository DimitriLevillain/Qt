#include "clientwidget.h"
#include "ui_clientwidget.h"

ClientWidget::ClientWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientWidget)
{
    ui->setupUi(this);
    socketDeDialogueAvecServeur=new QTcpSocket (this);

    connect(socketDeDialogueAvecServeur,
    QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),
    this,
    &ClientWidget::onQTcpSocket_error);
    connect(socketDeDialogueAvecServeur, &QTcpSocket::connected,
            this,&ClientWidget::onQTcpSocket_connected);
    connect(socketDeDialogueAvecServeur, &QTcpSocket::disconnected,
            this,&ClientWidget::onQTcpSocket_disconnected);
    connect(socketDeDialogueAvecServeur, &QTcpSocket::hostFound,
            this,&ClientWidget::onQTcpSocket_hostFound);
    connect(socketDeDialogueAvecServeur, &QTcpSocket::stateChanged,
            this,&ClientWidget::onQTcpSocket_stateChanged);
    connect(socketDeDialogueAvecServeur, &QTcpSocket::aboutToClose,
            this,&ClientWidget::onQTcpSocket_aboutToClose);
    connect(socketDeDialogueAvecServeur, &QTcpSocket::bytesWritten,
            this,&ClientWidget::onQTcpSocket_bytesWritten);
    connect(socketDeDialogueAvecServeur, &QTcpSocket::readChannelFinished,
            this,&ClientWidget::onQTcpSocket_readChannelFinished);
    connect(socketDeDialogueAvecServeur, &QTcpSocket::readyRead,
            this,&ClientWidget::onQTcpSocket_readyRead);
}

ClientWidget::~ClientWidget()
{
    delete ui;
}


void ClientWidget::on_pushButtonQuitter_clicked()
{
    close();
}

void ClientWidget::on_pushButtonOrdinateuDistant_clicked()
{
    typeDeDemande="c";
    socketDeDialogueAvecServeur->write(typeDeDemande.toLatin1());
}

void ClientWidget::on_pushButtonNomUtilisateur_clicked()
{
    typeDeDemande="u";
    socketDeDialogueAvecServeur->write(typeDeDemande.toLatin1());
}

void ClientWidget::on_pushButtonArchitecture_clicked()
{
    typeDeDemande="a";
    socketDeDialogueAvecServeur->write(typeDeDemande.toLatin1());
}

void ClientWidget::on_pushButtonOS_clicked()
{
    typeDeDemande="o";
    socketDeDialogueAvecServeur->write(typeDeDemande.toLatin1());
}

void ClientWidget::on_pushButtonConnexion_clicked()
{
    if (ui->pushButtonConnexion->text()!="Déconnexion"){
            // pour chaque nouvelle connexion on réinitialise la zone evenement
            ui->textEditAffichageEtat->clear();
            // connexion au serveur
            socketDeDialogueAvecServeur->connectToHost ( ui->lineEditAdresseIPServeur->text(),ui->lineEditNumeroPort->text().toInt() );

        }
        else
        {
            socketDeDialogueAvecServeur->disconnectFromHost();

    }
}


void ClientWidget::onQTcpSocket_connected()
{
    ui->textEditAffichageEtat->append("Connecté");
    ui->pushButtonConnexion->setText("Déconnexion");
    ui->lineEditAdresseIPServeur->setDisabled(1);
    ui->lineEditNumeroPort->setDisabled(1);
    ui->groupBoxInformations->setEnabled(1);
}

void ClientWidget::onQTcpSocket_disconnected()
{
    ui->textEditAffichageEtat->append("Déconnecté");
    ui->pushButtonConnexion->setText("Connexion");
    ui->lineEditAdresseIPServeur->setEnabled(1);
    ui->lineEditNumeroPort->setEnabled(1);
    ui->groupBoxInformations->setDisabled(1);
}

void ClientWidget::onQTcpSocket_error(QAbstractSocket::SocketError socketError)
{
    ui->textEditAffichageEtat->append(socketDeDialogueAvecServeur->errorString());
}

void ClientWidget::onQTcpSocket_hostFound()
{
    ui->textEditAffichageEtat->append("hostfound");
}

void ClientWidget::onQTcpSocket_stateChanged(QAbstractSocket::SocketState socketState)
{
    QString message;
        switch (socketState)
        {

        case QAbstractSocket::HostLookupState:
            message="Le client effectue une recherche de nom d'hôte.";
            break;
        case QAbstractSocket::ConnectingState:
            message="E1 - Le client demande l'établissement d'une connexion.";
            break;
        case QAbstractSocket::ConnectedState:
            message="E3 - Une connexion est établie avec le serveur.";
            break;

        // Fermeture 1 : quand le client n'a plus de données à envoyer dans le flux,
        // il envoie un segment dont l'indicateur FIN est défini.
        // toutefois des données peuvent toujours être en attente d'être reçues.
        case QAbstractSocket::ClosingState	:
            message="F1 - le client n'a plus de données à envoyer.";
            break;

        // Fermeture 2 : le serveur envoie un segment ACK
        // pour indiquer la bonne réception du segment FIN
        // afin de fermer la session du client au serveur.
        case QAbstractSocket::UnconnectedState :
            message="F2 - Le client n'est plus connecté.";
            break;

        case QAbstractSocket::ListeningState :
            message="For internal use only. ";
            break;
        }
    ui->textEditAffichageEtat->append(message);
}

void ClientWidget::onQTcpSocket_aboutToClose()
{

}

void ClientWidget::onQTcpSocket_bytesWritten(qint64 bytes)
{

}

void ClientWidget::onQTcpSocket_readChannelFinished()
{
    ui->textEditAffichageEtat->append("F3 - le serveur met fin au dialogue.");
}

void ClientWidget::onQTcpSocket_readyRead()
{
    QByteArray donnees = socketDeDialogueAvecServeur->readAll();
    if(typeDeDemande == 'a')
    {
        ui->lineEditArchitecture->insert(donnees.data());
    }
    if(typeDeDemande == 'u')
    {
        ui->lineEditNomUtilisateur->insert(donnees.data());
    }
    if(typeDeDemande == 'c')
    {
        ui->lineEditDistant->insert(donnees.data());
    }
    if(typeDeDemande == 'o')
    {
        ui->lineEditOS->insert(donnees.data());
    }
}

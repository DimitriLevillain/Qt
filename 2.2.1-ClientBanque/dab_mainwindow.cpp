#include "dab_mainwindow.h"
#include "ui_dab_mainwindow.h"

DAB_MainWindow::DAB_MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DAB_MainWindow)
{
    ui->setupUi(this);
    socketDeDialogueAvecServeur=new QTcpSocket (this);

    connect(socketDeDialogueAvecServeur,
    QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),this,&DAB_MainWindow::onQTcpSocket_error);
    connect(socketDeDialogueAvecServeur, &QTcpSocket::connected,this,&DAB_MainWindow::onQTcpSocket_connected);
    connect(socketDeDialogueAvecServeur, &QTcpSocket::disconnected,this,&DAB_MainWindow::onQTcpSocket_disconnected);
    connect(socketDeDialogueAvecServeur, &QTcpSocket::readyRead,this,&DAB_MainWindow::onQTcpSocket_readyRead);
}

DAB_MainWindow::~DAB_MainWindow()
{
    delete ui;
}

void DAB_MainWindow::on_pushButtonConnexion_clicked()
{
    if (ui->pushButtonConnexion->text()!="Déconnexion"){
        // pour chaque nouvelle connexion on réinitialise la zone evenement
        ui->textEditEtat->clear();
        // connexion au serveur
        socketDeDialogueAvecServeur->connectToHost ( ui->lineEditAdresse->text(),ui->lineEditPort->text().toInt() );

        }
        else
        {
            socketDeDialogueAvecServeur->disconnectFromHost();

    }
}

void DAB_MainWindow::on_pushButtonEnvoi_clicked()
{
    quint16 taille=0;
    QBuffer tampon;
    QChar commande;
    tampon.open(QIODevice::WriteOnly);
    QDataStream out(&tampon);

    QString tmp_montant = ui->lineEditMontant->text();
    float montant = tmp_montant.toFloat();

    if(ui->radioButtonSolde->isChecked())
    {
        commande='S';
        out << taille << commande;
        taille=tampon.size()-sizeof(taille);
        tampon.seek(0);
        out<<taille;
        socketDeDialogueAvecServeur->write(tampon.buffer());
    }

    if(ui->radioButtonRetrait->isChecked() || ui->radioButtonDepot->isChecked())
    {
        if(ui->radioButtonRetrait->isChecked())
        {
            commande='R';
        }
        if(ui->radioButtonDepot->isChecked())
        {
            commande='D';
        }

    // constructrion de la trame
    out << taille << commande << montant;
    // calcul de la taille de la trame
    taille=tampon.size()-sizeof(taille);
    //placement sur la première position du flux pour pouvoir modifier la taille
    tampon.seek(0);
    // modification de la trame avec la taille reel de la trame
    out<<taille;
    // envoi du QByteArray du tampon via la socket
    socketDeDialogueAvecServeur->write(tampon.buffer());
    }
}

void DAB_MainWindow::on_pushButtonNumero_clicked()
{
    quint16 taille=0;
    QChar commande='N';
    int compte = 1234;
    QBuffer tampon;
    QString tmp_numero = ui->lineEditNumero->text();
    bool ok = false;
    int resultat = tmp_numero.toInt(&ok, 10);
    if(resultat == compte)
    {
    tampon.open(QIODevice::WriteOnly);
    // association du tampon au flux de sortie
    QDataStream out(&tampon);
    // constructrion de la trame
    out << taille << commande << compte;
    // calcul de la taille de la trame
    taille=tampon.size()-sizeof(taille);
    //placement sur la première position du flux pour pouvoir modifier la taille
    tampon.seek(0);
    // modification de la trame avec la taille reel de la trame
    out<<taille;
    // envoi du QByteArray du tampon via la socket
    socketDeDialogueAvecServeur->write(tampon.buffer());
    }
    else
    {
        ui->lineEditMessage->clear();
        ui->lineEditMessage->insert("Numéro de compte incorrect");
    }
}

void DAB_MainWindow::onQTcpSocket_connected()
{
    ui->textEditEtat->append("Connecté");
    ui->pushButtonConnexion->setText("Déconnexion");
    ui->lineEditAdresse->setDisabled(1);
    ui->groupBoxOperation->setEnabled(1);
    ui->lineEditNumero->setEnabled(1);
    ui->lineEditMontant->setEnabled(1);
}

void DAB_MainWindow::onQTcpSocket_disconnected()
{
    ui->textEditEtat->append("Déconnecté");
    ui->pushButtonConnexion->setText("Connexion");
    ui->lineEditAdresse->setEnabled(1);
    ui->groupBoxOperation->setDisabled(1);
}

void DAB_MainWindow::onQTcpSocket_error(QAbstractSocket::SocketError socketError)
{
    ui->textEditEtat->append(socketDeDialogueAvecServeur->errorString());
}

void DAB_MainWindow::onQTcpSocket_readyRead()
{
    quint16 taille=0;
    QString message;
    // si le nombre d'octets recu est au moins egal a celui de la taille de ce que l'on doit recevoir
    if (socketDeDialogueAvecServeur->bytesAvailable() >= (qint64)sizeof(taille))
    {
        //association de la socket au flux d'entree
        QDataStream in(socketDeDialogueAvecServeur);
        // extraire la taille de ce que l'on doit recevoir
        in >> taille;
        //si le nombre d'octet recu est au moins egal a celui de ce que l'on doit recevoir
        if (socketDeDialogueAvecServeur->bytesAvailable() >= (qint64)taille)
        {
            //extraire le message de la banque et le mettre dans message
            in>>message;
            ui->lineEditMessage->clear();
            ui->lineEditMessage->insert(message);
        }
    }
}

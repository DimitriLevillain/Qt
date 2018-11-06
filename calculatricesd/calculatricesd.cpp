#include "calculatricesd.h"
#include "ui_calculatricesd.h"
#include <QScriptEngine>

CalculatriceSD::CalculatriceSD(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CalculatriceSD)
{
    ui->setupUi(this);
    //Touches valeurs
    connect (ui->pushButton0, &QPushButton::clicked, this, &CalculatriceSD::onQPushButtonClicked);
    connect (ui->pushButton1, &QPushButton::clicked, this, &CalculatriceSD::onQPushButtonClicked);
    connect (ui->pushButton2, &QPushButton::clicked, this, &CalculatriceSD::onQPushButtonClicked);
    connect (ui->pushButton3, &QPushButton::clicked, this, &CalculatriceSD::onQPushButtonClicked);
    connect (ui->pushButton4, &QPushButton::clicked, this, &CalculatriceSD::onQPushButtonClicked);
    connect (ui->pushButton5, &QPushButton::clicked, this, &CalculatriceSD::onQPushButtonClicked);
    connect (ui->pushButton6, &QPushButton::clicked, this, &CalculatriceSD::onQPushButtonClicked);
    connect (ui->pushButton7, &QPushButton::clicked, this, &CalculatriceSD::onQPushButtonClicked);
    connect (ui->pushButton8, &QPushButton::clicked, this, &CalculatriceSD::onQPushButtonClicked);
    connect (ui->pushButton9, &QPushButton::clicked, this, &CalculatriceSD::onQPushButtonClicked);
    //Touches operateurs
    connect (ui->pushButtonPlus, &QPushButton::clicked, this, &CalculatriceSD::onQPushButtonClicked);
    connect (ui->pushButtonMoins, &QPushButton::clicked, this, &CalculatriceSD::onQPushButtonClicked);
    connect (ui->pushButtonDiviser, &QPushButton::clicked, this, &CalculatriceSD::onQPushButtonClicked);
    connect (ui->pushButtonMultiplier, &QPushButton::clicked, this, &CalculatriceSD::onQPushButtonClicked);
}

CalculatriceSD::~CalculatriceSD()
{
    delete ui;
}



void CalculatriceSD::on_pushButtonClear_clicked()
{
    ui->lineEditAffichage->clear();
}

void CalculatriceSD::on_pushButtonEgal_clicked()
{
    QString expression = ui->lineEditAffichage->text();
    QScriptEngine engine;
    QScriptValue valeur = engine.evaluate(expression);
    QString resultat = valeur.toString();
    ui->lineEditAffichage->setText(resultat);
}

void CalculatriceSD::onQPushButtonClicked()
{
    QPushButton *touche;
    touche = qobject_cast<QPushButton*>(sender());
    QString text = touche->text();
    ui->lineEditAffichage->insert(text);
}

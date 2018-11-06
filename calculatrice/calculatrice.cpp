#include "calculatrice.h"
#include "ui_calculatrice.h"
#include <QScriptEngine>

Calculatrice::Calculatrice(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Calculatrice)
{
    ui->setupUi(this);
}

Calculatrice::~Calculatrice()
{
    delete ui;
}

void Calculatrice::on_pushButton7_clicked()
{
    Affichage(7);
}


void Calculatrice::on_pushButton8_clicked()
{
    Affichage(8);
}

void Calculatrice::on_pushButton9_clicked()
{
    Affichage(9);
}

void Calculatrice::on_pushButtonPlus_clicked()
{
    ui->lineEditAffichage->insert("+");
}

void Calculatrice::on_pushButton4_clicked()
{
    Affichage(4);
}

void Calculatrice::on_pushButton5_clicked()
{
    Affichage(5);
}

void Calculatrice::on_pushButton6_clicked()
{
    Affichage(6);
}

void Calculatrice::on_pushButtonMoins_clicked()
{
    ui->lineEditAffichage->insert("-");
}

void Calculatrice::on_pushButton1_clicked()
{
    Affichage(1);
}

void Calculatrice::on_pushButton2_clicked()
{
    Affichage(2);
}

void Calculatrice::on_pushButton3_clicked()
{
    Affichage(3);
}

void Calculatrice::on_pushButtonMultiplier_clicked()
{
    ui->lineEditAffichage->insert("*");
}

void Calculatrice::on_pushButtonClear_clicked()
{
    ui->lineEditAffichage->clear();
}

void Calculatrice::on_pushButton0_clicked()
{
    Affichage(0);
}

void Calculatrice::on_pushButtonEgal_clicked()
{
    QString expression = ui->lineEditAffichage->text();
    QScriptEngine engine;
    QScriptValue valeur = engine.evaluate(expression);
    QString resultat = valeur.toString();
    ui->lineEditAffichage->setText(resultat);
}

void Calculatrice::on_pushButtonDiviser_clicked()
{
    ui->lineEditAffichage->insert("/");
}

void Calculatrice::Affichage(int chiffre)
{
    ui->lineEditAffichage->insert(QString::number(chiffre, 'd', 0));
}


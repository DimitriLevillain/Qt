#include "widget.h"
#include "ui_widget.h"

using namespace std;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButtonQuitter_clicked()
{
    close();
}

void Widget::on_pushButtonSuite_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
    ui->tabWidget->widget(1)->setVisible(true);
    afficherInfos();
}

void Widget::afficherInfos()
{
    //Initialisation du poids, taille, age, nom et prenom
    nom = ui->lineEditNom->text();
    prenom = ui->lineEditPrenom->text();
    age = ui->spinBoxAge->value();
    poids = ui->doubleSpinBoxPoids->value();
    taille = ui->doubleSpinBoxTaille->value();

    double imc = poids/(taille * taille);

    //Affichage message de bienvenue
    ui->textEditCalculDuPoids->setText("Bienvenue : "+prenom+" "+nom);
    ui->textEditCalculDuPoids->append("Votre indice de masse corporelle est : " + QString::number(imc, 'f', 1));
    ui->textEditCalculDuPoids->append("\nVotre Corpulence est qualifié de : " + DeterminerClassification(imc));

}

QString Widget::DeterminerClassification(double imc)
{
    for (int i = 0; i < NBIMC - 1; i++) {
        if (imc > imcs[i] && imc <= imcs[i + 1]) {
            indiceCorpulence = i + 1;
        }
    }
    // cas extreme
    if (imc < 16.5) {
        indiceCorpulence = 0;
    }
    if (imc > 40) {
       indiceCorpulence = NBCORPULENCE - 1;
    }
    // affichage de la corpulence: corpulences[indiceCorpulence]
    return corpulences[indiceCorpulence];
}


void Widget::on_pushButtonDevine_clicked()
{
    Devine();
}

void Widget::Devine()
{
    double poidsIdeal = 0;

        if (ui->radioButtonFemme->isChecked()) {
            poidsIdeal = 45.5 + 2.3 * (taille / 0.0254 - 60.0);
        }
        if (ui->radioButtonHomme->isChecked()) {
            poidsIdeal = 50.0 + 2.3 * (taille / 0.0254 - 60.0);
        }
        if (poidsIdeal > 0) {
            ui->textEditCalculDuPoids->append("\nVotre poids idéal avec la formule de Devine est : <b>" + QString::number(poidsIdeal, 'f', 1) + " kg </b>");
            double ecart = poids-poidsIdeal;
            if (ecart >= 0) {
              ui->textEditCalculDuPoids->append("Vous devez perdre : <b>"+QString::number(ecart, 'f', 1)+" kg</b>\n");
            }
            else {
              ui->textEditCalculDuPoids->append("Vous devez prendre : <b>"+QString::number(-ecart, 'f', 1)+" kg</b>\n");
            }
    }
}


void Widget::on_pushButtonLorentz_clicked()
{
    Lorentz();
}


void Widget::Lorentz()
{
    double poidsIdeal = 0;

        if (ui->radioButtonFemme->isChecked()) {
            poidsIdeal = (taille*100)-100-((taille*100-150)/(2.5));
        }
        if (ui->radioButtonHomme->isChecked()) {
            poidsIdeal = (taille*100)-100-((taille*100-150)/(4));
        }
        if (poidsIdeal > 0) {
            ui->textEditCalculDuPoids->append("\nVotre poids idéal avec la formule de Lorentz est : <b>" + QString::number(poidsIdeal, 'f', 1) + " kg </b>");
            double ecart = poids-poidsIdeal;
            if (ecart >= 0) {
              ui->textEditCalculDuPoids->append("Vous devez perdre : <b>"+QString::number(ecart, 'f', 1)+" kg</b>\n");
            }
            else {
              ui->textEditCalculDuPoids->append("Vous devez prendre : <b>"+QString::number(-ecart, 'f', 1)+" kg</b>\n");
            }
    }
}


void Widget::on_pushButtonLorentzAge_clicked()
{
    LorentzAge();
}

void Widget::LorentzAge()
{
    double poidsIdeal = 0;
    poidsIdeal = 50+((taille*100-150)/(4))+((age-20)/(4));

    if (poidsIdeal > 0) {
        ui->textEditCalculDuPoids->append("\nVotre poids idéal avec la formule de Lorentz en fonction de l'âge est : <b>" + QString::number(poidsIdeal, 'f', 1) + " kg </b>");
        double ecart = poids-poidsIdeal;
        if (ecart >= 0) {
            ui->textEditCalculDuPoids->append("Vous devez perdre : <b>"+QString::number(ecart, 'f', 1)+" kg</b>\n");
        }
        else {
            ui->textEditCalculDuPoids->append("Vous devez prendre : <b>"+QString::number(-ecart, 'f', 1)+" kg</b>\n");
        }
    }
}

void Widget::on_tabWidget_currentChanged(int index)
{
    if(index == 1){
        afficherInfos();

    }
}

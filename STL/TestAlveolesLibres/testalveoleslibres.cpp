#include "testalveoleslibres.h"
#include "ui_testalveoleslibres.h"
#include "alveoleslibres.h"

TestAlveolesLibres::TestAlveolesLibres(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestAlveolesLibres)
{
    ui->setupUi(this);
    ui->pushButtonLiberer->setDisabled(true);
    alveoles = new AlveolesLibres(4,5);

    for(const int & entier : *alveoles)
    {
        ui->listWidgetNumero->addItem(QString::number(entier));
    }
}

TestAlveolesLibres::~TestAlveolesLibres()
{
    delete ui;
}

void TestAlveolesLibres::on_pushButtonQuitter_clicked()
{
    close();
}

void TestAlveolesLibres::on_pushButtonReserver_clicked()
{
    short numeroAlveole = 21 -alveoles->back();

    short numeroRangee=numeroAlveole/5+1;
    short numeroColonne=numeroAlveole-5*(numeroRangee-1);

    if(numeroAlveole <= 20)
    {
        bool retVal = alveoles->Reserver(numeroRangee, numeroColonne);
        ui->listWidgetRangees->addItem(QString::number(numeroAlveole));
        ui->listWidgetNumero->removeItemWidget();
    }
}

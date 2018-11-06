#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>


using namespace std;
namespace Ui {
class Widget;
}


class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButtonQuitter_clicked();

    void on_pushButtonSuite_clicked();

    void on_pushButtonDevine_clicked();

    void on_pushButtonLorentz_clicked();

    void on_pushButtonLorentzAge_clicked();

    void on_tabWidget_currentChanged(int index);

private:
    Ui::Widget *ui;
    void afficherInfos();
    double poids;
    double taille;
    QString nom;
    QString prenom;
    int age;
    static const int NBIMC=6;
    static const int NBCORPULENCE=7;

    QString DeterminerClassification(double imc);
    void Devine();
    void Lorentz();
    void LorentzAge();

    double imcs[NBIMC] = {16.5, 18.5, 25, 30, 35, 40};
    QString corpulences[NBCORPULENCE] = {"Famine", "Maigreur", "Normale", "Surpoids", "Obésité modérée", "Obésité sévère", "Obésité morbide"};
    double imc=0;
    int indiceCorpulence = 0;
};



#endif // WIDGET_H

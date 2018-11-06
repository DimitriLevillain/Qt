#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Linux_clicked()
{
    ui->textEditEvenement->append("Linux");

}

void MainWindow::on_pushButton_Windows_clicked()
{
    ui->textEditEvenement->append("Windows");
}

void MainWindow::on_pushButton_OS_X_Lion_clicked()
{
    ui->textEditEvenement->append("OS X Lion");
}

void MainWindow::on_radioButton_Linux_clicked()
{
    ui->textEditEvenement->append("Linux");
}


void MainWindow::on_radioButton_OS_X_Lion_clicked()
{
    ui->textEditEvenement->append("OS X Lion");
}

void MainWindow::on_radioButton_Windows_clicked()
{
    ui->textEditEvenement->append("Windows");
}


void MainWindow::on_lineEditCode_textChanged(const QString &arg1)
{
    ui->textEditEvenement->append(ui->lineEditCode->text());
}

void MainWindow::on_actionJava_triggered()
{
    ui->textEditEvenement->append("Java");
}

void MainWindow::on_actionC_triggered()
{
    ui->textEditEvenement->append("C");
}

void MainWindow::on_actionC_2_triggered()
{
    ui->textEditEvenement->append("C++");
}


void MainWindow::on_actionJava_script_triggered()
{
    ui->textEditEvenement->append("Javascript");
}

void MainWindow::on_comboBoxOs_currentTextChanged(const QString &arg1)
{
    ui->textEditEvenement->append(arg1);
}

void MainWindow::on_checkBox_OS_X_Lion_clicked()
{
    ui->textEditEvenement->append("OS X Lion");
}


void MainWindow::on_checkBox_Windows_clicked()
{
    ui->textEditEvenement->append("Windows");
}


void MainWindow::on_chekBox_Linux_clicked()
{
    ui->textEditEvenement->append("Linux");
}

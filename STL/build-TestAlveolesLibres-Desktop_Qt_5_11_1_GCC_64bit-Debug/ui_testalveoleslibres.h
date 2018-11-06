/********************************************************************************
** Form generated from reading UI file 'testalveoleslibres.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTALVEOLESLIBRES_H
#define UI_TESTALVEOLESLIBRES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestAlveolesLibres
{
public:
    QLabel *labelNumero;
    QListWidget *listWidgetNumero;
    QLabel *labelRangees;
    QListWidget *listWidgetRangees;
    QPushButton *pushButtonQuitter;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButtonReserver;
    QPushButton *pushButtonLiberer;

    void setupUi(QWidget *TestAlveolesLibres)
    {
        if (TestAlveolesLibres->objectName().isEmpty())
            TestAlveolesLibres->setObjectName(QStringLiteral("TestAlveolesLibres"));
        TestAlveolesLibres->resize(509, 368);
        labelNumero = new QLabel(TestAlveolesLibres);
        labelNumero->setObjectName(QStringLiteral("labelNumero"));
        labelNumero->setGeometry(QRect(40, 30, 141, 17));
        listWidgetNumero = new QListWidget(TestAlveolesLibres);
        listWidgetNumero->setObjectName(QStringLiteral("listWidgetNumero"));
        listWidgetNumero->setGeometry(QRect(40, 50, 141, 221));
        labelRangees = new QLabel(TestAlveolesLibres);
        labelRangees->setObjectName(QStringLiteral("labelRangees"));
        labelRangees->setGeometry(QRect(310, 30, 171, 17));
        listWidgetRangees = new QListWidget(TestAlveolesLibres);
        listWidgetRangees->setObjectName(QStringLiteral("listWidgetRangees"));
        listWidgetRangees->setGeometry(QRect(330, 50, 141, 221));
        pushButtonQuitter = new QPushButton(TestAlveolesLibres);
        pushButtonQuitter->setObjectName(QStringLiteral("pushButtonQuitter"));
        pushButtonQuitter->setGeometry(QRect(150, 280, 221, 61));
        widget = new QWidget(TestAlveolesLibres);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(210, 130, 82, 81));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonReserver = new QPushButton(widget);
        pushButtonReserver->setObjectName(QStringLiteral("pushButtonReserver"));

        verticalLayout->addWidget(pushButtonReserver);

        pushButtonLiberer = new QPushButton(widget);
        pushButtonLiberer->setObjectName(QStringLiteral("pushButtonLiberer"));

        verticalLayout->addWidget(pushButtonLiberer);


        retranslateUi(TestAlveolesLibres);

        QMetaObject::connectSlotsByName(TestAlveolesLibres);
    } // setupUi

    void retranslateUi(QWidget *TestAlveolesLibres)
    {
        TestAlveolesLibres->setWindowTitle(QApplication::translate("TestAlveolesLibres", "TestAlveolesLibres", nullptr));
        labelNumero->setText(QApplication::translate("TestAlveolesLibres", "Num\303\251ro d'alv\303\251oles libres", nullptr));
        labelRangees->setText(QApplication::translate("TestAlveolesLibres", "Rang\303\251es & colonnes occup\303\251es", nullptr));
        pushButtonQuitter->setText(QApplication::translate("TestAlveolesLibres", "Quitter", nullptr));
        pushButtonReserver->setText(QApplication::translate("TestAlveolesLibres", "R\303\251server >>", nullptr));
        pushButtonLiberer->setText(QApplication::translate("TestAlveolesLibres", "<< Lib\303\251rer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TestAlveolesLibres: public Ui_TestAlveolesLibres {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTALVEOLESLIBRES_H

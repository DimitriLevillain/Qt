/********************************************************************************
** Form generated from reading UI file 'alveoleslibres.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALVEOLESLIBRES_H
#define UI_ALVEOLESLIBRES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AlveolesLIbres
{
public:
    QLabel *labelNumero;
    QListWidget *listWidgetNumero;
    QLabel *labelRangee;
    QListWidget *listWidgetRangee;
    QPushButton *pushButtonQuitter;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButtonReserver;
    QPushButton *pushButtonLiberer;

    void setupUi(QWidget *AlveolesLIbres)
    {
        if (AlveolesLIbres->objectName().isEmpty())
            AlveolesLIbres->setObjectName(QStringLiteral("AlveolesLIbres"));
        AlveolesLIbres->resize(489, 388);
        labelNumero = new QLabel(AlveolesLIbres);
        labelNumero->setObjectName(QStringLiteral("labelNumero"));
        labelNumero->setGeometry(QRect(30, 30, 141, 17));
        listWidgetNumero = new QListWidget(AlveolesLIbres);
        listWidgetNumero->setObjectName(QStringLiteral("listWidgetNumero"));
        listWidgetNumero->setGeometry(QRect(30, 50, 141, 251));
        labelRangee = new QLabel(AlveolesLIbres);
        labelRangee->setObjectName(QStringLiteral("labelRangee"));
        labelRangee->setGeometry(QRect(280, 30, 171, 17));
        listWidgetRangee = new QListWidget(AlveolesLIbres);
        listWidgetRangee->setObjectName(QStringLiteral("listWidgetRangee"));
        listWidgetRangee->setGeometry(QRect(300, 50, 141, 251));
        pushButtonQuitter = new QPushButton(AlveolesLIbres);
        pushButtonQuitter->setObjectName(QStringLiteral("pushButtonQuitter"));
        pushButtonQuitter->setGeometry(QRect(129, 314, 221, 51));
        widget = new QWidget(AlveolesLIbres);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(200, 150, 82, 81));
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


        retranslateUi(AlveolesLIbres);

        QMetaObject::connectSlotsByName(AlveolesLIbres);
    } // setupUi

    void retranslateUi(QWidget *AlveolesLIbres)
    {
        AlveolesLIbres->setWindowTitle(QApplication::translate("AlveolesLIbres", "AlveolesLIbres", nullptr));
        labelNumero->setText(QApplication::translate("AlveolesLIbres", "Num\303\251ro d'alv\303\251oles libres", nullptr));
        labelRangee->setText(QApplication::translate("AlveolesLIbres", "Rang\303\251es & colonnes occup\303\251es", nullptr));
        pushButtonQuitter->setText(QApplication::translate("AlveolesLIbres", "Quitter", nullptr));
        pushButtonReserver->setText(QApplication::translate("AlveolesLIbres", "R\303\251server >>", nullptr));
        pushButtonLiberer->setText(QApplication::translate("AlveolesLIbres", "<< Lib\303\251rer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AlveolesLIbres: public Ui_AlveolesLIbres {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALVEOLESLIBRES_H

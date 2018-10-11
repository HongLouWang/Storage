/********************************************************************************
** Form generated from reading UI file 'controlpannel.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLPANNEL_H
#define UI_CONTROLPANNEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ControlPannel
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;

    void setupUi(QDialog *ControlPannel)
    {
        if (ControlPannel->objectName().isEmpty())
            ControlPannel->setObjectName(QStringLiteral("ControlPannel"));
        ControlPannel->resize(223, 128);
        widget = new QWidget(ControlPannel);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 201, 111));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 0, 1, 1, 1);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 1, 0, 1, 1);

        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 1, 1, 1, 1);

        pushButton_5 = new QPushButton(widget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        gridLayout->addWidget(pushButton_5, 2, 0, 1, 1);

        pushButton_6 = new QPushButton(widget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        gridLayout->addWidget(pushButton_6, 2, 1, 1, 1);

        pushButton_7 = new QPushButton(widget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        gridLayout->addWidget(pushButton_7, 3, 0, 1, 1);

        pushButton_8 = new QPushButton(widget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));

        gridLayout->addWidget(pushButton_8, 3, 1, 1, 1);


        retranslateUi(ControlPannel);

        QMetaObject::connectSlotsByName(ControlPannel);
    } // setupUi

    void retranslateUi(QDialog *ControlPannel)
    {
        ControlPannel->setWindowTitle(QApplication::translate("ControlPannel", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("ControlPannel", "Freight Info", nullptr));
        pushButton_2->setText(QApplication::translate("ControlPannel", "New Customer", nullptr));
        pushButton_3->setText(QApplication::translate("ControlPannel", "Schedual New PickUp", nullptr));
        pushButton_4->setText(QApplication::translate("ControlPannel", "New Logistics", nullptr));
        pushButton_5->setText(QApplication::translate("ControlPannel", "Logistics Manage", nullptr));
        pushButton_6->setText(QApplication::translate("ControlPannel", "Freight Arrive", nullptr));
        pushButton_7->setText(QApplication::translate("ControlPannel", "Storage Manage", nullptr));
        pushButton_8->setText(QApplication::translate("ControlPannel", "Pick Up", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ControlPannel: public Ui_ControlPannel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLPANNEL_H

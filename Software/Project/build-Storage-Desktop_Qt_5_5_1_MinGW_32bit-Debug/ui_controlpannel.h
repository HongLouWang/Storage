/********************************************************************************
** Form generated from reading UI file 'controlpannel.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLPANNEL_H
#define UI_CONTROLPANNEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ControlPannel
{
public:
    QWidget *layoutWidget;
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
        ControlPannel->resize(219, 176);
        layoutWidget = new QWidget(ControlPannel);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 201, 112));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 0, 1, 1, 1);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 1, 0, 1, 1);

        pushButton_4 = new QPushButton(layoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 1, 1, 1, 1);

        pushButton_5 = new QPushButton(layoutWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        gridLayout->addWidget(pushButton_5, 2, 0, 1, 1);

        pushButton_6 = new QPushButton(layoutWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        gridLayout->addWidget(pushButton_6, 2, 1, 1, 1);

        pushButton_7 = new QPushButton(layoutWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        gridLayout->addWidget(pushButton_7, 3, 0, 1, 1);

        pushButton_8 = new QPushButton(layoutWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));

        gridLayout->addWidget(pushButton_8, 3, 1, 1, 1);


        retranslateUi(ControlPannel);

        QMetaObject::connectSlotsByName(ControlPannel);
    } // setupUi

    void retranslateUi(QDialog *ControlPannel)
    {
        ControlPannel->setWindowTitle(QApplication::translate("ControlPannel", "Dialog", 0));
        pushButton->setText(QApplication::translate("ControlPannel", "Freight Info", 0));
        pushButton_2->setText(QApplication::translate("ControlPannel", "New Customer", 0));
        pushButton_3->setText(QApplication::translate("ControlPannel", "Schedual New PickUp", 0));
        pushButton_4->setText(QApplication::translate("ControlPannel", "New Logistics", 0));
        pushButton_5->setText(QApplication::translate("ControlPannel", "Logistics Manage", 0));
        pushButton_6->setText(QApplication::translate("ControlPannel", "Freight Arrive", 0));
        pushButton_7->setText(QApplication::translate("ControlPannel", "Storage Manage", 0));
        pushButton_8->setText(QApplication::translate("ControlPannel", "Pick Up", 0));
    } // retranslateUi

};

namespace Ui {
    class ControlPannel: public Ui_ControlPannel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLPANNEL_H

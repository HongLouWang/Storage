/********************************************************************************
** Form generated from reading UI file 'pullman_new_pickup.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PULLMAN_NEW_PICKUP_H
#define UI_PULLMAN_NEW_PICKUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pullman_new_pickup
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QSplitter *splitter;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QDateTimeEdit *dateTimeEdit;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;

    void setupUi(QDialog *pullman_new_pickup)
    {
        if (pullman_new_pickup->objectName().isEmpty())
            pullman_new_pickup->setObjectName(QStringLiteral("pullman_new_pickup"));
        pullman_new_pickup->resize(281, 356);
        layoutWidget = new QWidget(pullman_new_pickup);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 258, 331));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        splitter = new QSplitter(layoutWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        label_3 = new QLabel(splitter);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_3->setFont(font);
        splitter->addWidget(label_3);
        lineEdit_3 = new QLineEdit(splitter);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        splitter->addWidget(lineEdit_3);

        gridLayout->addWidget(splitter, 2, 0, 1, 3);

        tableWidget = new QTableWidget(layoutWidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        gridLayout->addWidget(tableWidget, 3, 0, 1, 3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 3);

        dateTimeEdit = new QDateTimeEdit(layoutWidget);
        dateTimeEdit->setObjectName(QStringLiteral("dateTimeEdit"));

        gridLayout->addWidget(dateTimeEdit, 4, 0, 1, 3);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setFont(font);

        gridLayout->addWidget(pushButton_2, 5, 1, 1, 1);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setFont(font);

        gridLayout->addWidget(pushButton_3, 5, 2, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_2);


        gridLayout->addLayout(formLayout, 1, 0, 1, 3);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setFont(font);

        gridLayout->addWidget(pushButton, 5, 0, 1, 1);


        retranslateUi(pullman_new_pickup);
        QObject::connect(pushButton_2, SIGNAL(clicked()), pullman_new_pickup, SLOT(close()));

        QMetaObject::connectSlotsByName(pullman_new_pickup);
    } // setupUi

    void retranslateUi(QDialog *pullman_new_pickup)
    {
        pullman_new_pickup->setWindowTitle(QApplication::translate("pullman_new_pickup", "Dialog", 0));
        label_3->setText(QApplication::translate("pullman_new_pickup", "Phone:", 0));
        label->setText(QApplication::translate("pullman_new_pickup", "Firstname:", 0));
        pushButton_2->setText(QApplication::translate("pullman_new_pickup", "Discard", 0));
        pushButton_3->setText(QApplication::translate("pullman_new_pickup", "Submit", 0));
        label_2->setText(QApplication::translate("pullman_new_pickup", "Lastname:", 0));
        pushButton->setText(QApplication::translate("pullman_new_pickup", "New Customer", 0));
    } // retranslateUi

};

namespace Ui {
    class pullman_new_pickup: public Ui_pullman_new_pickup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PULLMAN_NEW_PICKUP_H

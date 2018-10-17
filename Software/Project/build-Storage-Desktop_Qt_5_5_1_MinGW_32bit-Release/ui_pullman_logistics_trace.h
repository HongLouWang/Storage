/********************************************************************************
** Form generated from reading UI file 'pullman_logistics_trace.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PULLMAN_LOGISTICS_TRACE_H
#define UI_PULLMAN_LOGISTICS_TRACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pullman_logistics_trace
{
public:
    QTableView *tableView;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QFormLayout *formLayout_2;
    QLabel *label;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer;
    QFormLayout *formLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *pullman_logistics_trace)
    {
        if (pullman_logistics_trace->objectName().isEmpty())
            pullman_logistics_trace->setObjectName(QStringLiteral("pullman_logistics_trace"));
        pullman_logistics_trace->resize(931, 443);
        tableView = new QTableView(pullman_logistics_trace);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(10, 10, 911, 381));
        layoutWidget = new QWidget(pullman_logistics_trace);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 400, 901, 27));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label);

        comboBox = new QComboBox(layoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, comboBox);


        gridLayout->addLayout(formLayout_2, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(548, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setFont(font);

        formLayout->setWidget(0, QFormLayout::FieldRole, pushButton);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, pushButton_2);


        gridLayout->addLayout(formLayout, 0, 2, 1, 1);


        retranslateUi(pullman_logistics_trace);
        QObject::connect(pushButton_2, SIGNAL(clicked()), pullman_logistics_trace, SLOT(close()));

        QMetaObject::connectSlotsByName(pullman_logistics_trace);
    } // setupUi

    void retranslateUi(QDialog *pullman_logistics_trace)
    {
        pullman_logistics_trace->setWindowTitle(QApplication::translate("pullman_logistics_trace", "Dialog", 0));
        label->setText(QApplication::translate("pullman_logistics_trace", "Sort By:", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("pullman_logistics_trace", "ID", 0)
         << QApplication::translate("pullman_logistics_trace", "Carrier", 0)
         << QApplication::translate("pullman_logistics_trace", "Establish City", 0)
         << QApplication::translate("pullman_logistics_trace", "Establish Country", 0)
         << QApplication::translate("pullman_logistics_trace", "Arrive City", 0)
         << QApplication::translate("pullman_logistics_trace", "Arrive Country", 0)
         << QApplication::translate("pullman_logistics_trace", "Establish Date", 0)
         << QApplication::translate("pullman_logistics_trace", "Arrive Date", 0)
         << QApplication::translate("pullman_logistics_trace", "Delay", 0)
         << QApplication::translate("pullman_logistics_trace", "Need Custom", 0)
         << QApplication::translate("pullman_logistics_trace", "Custom Pass/Fail", 0)
        );
        pushButton->setText(QApplication::translate("pullman_logistics_trace", "Cancel", 0));
        pushButton_2->setText(QApplication::translate("pullman_logistics_trace", "Refresh", 0));
    } // retranslateUi

};

namespace Ui {
    class pullman_logistics_trace: public Ui_pullman_logistics_trace {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PULLMAN_LOGISTICS_TRACE_H

/********************************************************************************
** Form generated from reading UI file 'pullman_main.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PULLMAN_MAIN_H
#define UI_PULLMAN_MAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Pullman_Main
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_9;
    QLabel *label_6;
    QLabel *label_2;
    QLabel *label_7;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_8;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_3;
    QTableView *tableView;
    QScrollArea *scrollArea_3;
    QWidget *scrollAreaWidgetContents_4;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTableView *tableView_2;
    QWidget *tab_3;
    QTableView *tableView_3;
    QWidget *tab_2;
    QTableView *tableView_4;
    QScrollArea *scrollArea_4;
    QWidget *scrollAreaWidgetContents_5;
    QTableView *tableView_5;
    QScrollArea *scrollArea_5;
    QWidget *scrollAreaWidgetContents_6;
    QTableView *tableView_6;
    QScrollArea *scrollArea_6;
    QWidget *scrollAreaWidgetContents_7;
    QTableView *tableView_7;
    QScrollArea *scrollArea_7;
    QWidget *scrollAreaWidgetContents_8;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;

    void setupUi(QDialog *Pullman_Main)
    {
        if (Pullman_Main->objectName().isEmpty())
            Pullman_Main->setObjectName(QStringLiteral("Pullman_Main"));
        Pullman_Main->resize(1153, 714);
        scrollArea = new QScrollArea(Pullman_Main);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(11, 11, 241, 151));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 239, 149));
        scrollAreaWidgetContents->setMinimumSize(QSize(215, 107));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_4 = new QLabel(scrollAreaWidgetContents);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 1, 1, 1, 1);

        label_9 = new QLabel(scrollAreaWidgetContents);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font);

        gridLayout->addWidget(label_9, 4, 1, 1, 1);

        label_6 = new QLabel(scrollAreaWidgetContents);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        gridLayout->addWidget(label_6, 2, 1, 1, 1);

        label_2 = new QLabel(scrollAreaWidgetContents);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        label_7 = new QLabel(scrollAreaWidgetContents);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);

        gridLayout->addWidget(label_7, 3, 1, 1, 1);

        label_3 = new QLabel(scrollAreaWidgetContents);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        label_5 = new QLabel(scrollAreaWidgetContents);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        label_8 = new QLabel(scrollAreaWidgetContents);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);

        gridLayout->addWidget(label_8, 4, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);
        scrollArea_2 = new QScrollArea(Pullman_Main);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setGeometry(QRect(11, 160, 241, 281));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QStringLiteral("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 239, 279));
        tableView = new QTableView(scrollAreaWidgetContents_3);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(10, 20, 211, 241));
        scrollArea_2->setWidget(scrollAreaWidgetContents_3);
        scrollArea_3 = new QScrollArea(Pullman_Main);
        scrollArea_3->setObjectName(QStringLiteral("scrollArea_3"));
        scrollArea_3->setGeometry(QRect(10, 440, 241, 251));
        scrollArea_3->setWidgetResizable(true);
        scrollAreaWidgetContents_4 = new QWidget();
        scrollAreaWidgetContents_4->setObjectName(QStringLiteral("scrollAreaWidgetContents_4"));
        scrollAreaWidgetContents_4->setGeometry(QRect(0, 0, 239, 249));
        tabWidget = new QTabWidget(scrollAreaWidgetContents_4);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 20, 221, 211));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tableView_2 = new QTableView(tab);
        tableView_2->setObjectName(QStringLiteral("tableView_2"));
        tableView_2->setGeometry(QRect(10, 10, 201, 171));
        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tableView_3 = new QTableView(tab_3);
        tableView_3->setObjectName(QStringLiteral("tableView_3"));
        tableView_3->setGeometry(QRect(0, 0, 201, 171));
        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tableView_4 = new QTableView(tab_2);
        tableView_4->setObjectName(QStringLiteral("tableView_4"));
        tableView_4->setGeometry(QRect(10, 10, 201, 171));
        tabWidget->addTab(tab_2, QString());
        scrollArea_3->setWidget(scrollAreaWidgetContents_4);
        scrollArea_4 = new QScrollArea(Pullman_Main);
        scrollArea_4->setObjectName(QStringLiteral("scrollArea_4"));
        scrollArea_4->setGeometry(QRect(250, 10, 881, 160));
        scrollArea_4->setWidgetResizable(true);
        scrollAreaWidgetContents_5 = new QWidget();
        scrollAreaWidgetContents_5->setObjectName(QStringLiteral("scrollAreaWidgetContents_5"));
        scrollAreaWidgetContents_5->setGeometry(QRect(0, 0, 879, 158));
        tableView_5 = new QTableView(scrollAreaWidgetContents_5);
        tableView_5->setObjectName(QStringLiteral("tableView_5"));
        tableView_5->setGeometry(QRect(10, 10, 861, 131));
        scrollArea_4->setWidget(scrollAreaWidgetContents_5);
        scrollArea_5 = new QScrollArea(Pullman_Main);
        scrollArea_5->setObjectName(QStringLiteral("scrollArea_5"));
        scrollArea_5->setGeometry(QRect(250, 160, 881, 281));
        scrollArea_5->setWidgetResizable(true);
        scrollAreaWidgetContents_6 = new QWidget();
        scrollAreaWidgetContents_6->setObjectName(QStringLiteral("scrollAreaWidgetContents_6"));
        scrollAreaWidgetContents_6->setGeometry(QRect(0, 0, 879, 279));
        tableView_6 = new QTableView(scrollAreaWidgetContents_6);
        tableView_6->setObjectName(QStringLiteral("tableView_6"));
        tableView_6->setGeometry(QRect(10, 20, 861, 241));
        scrollArea_5->setWidget(scrollAreaWidgetContents_6);
        scrollArea_6 = new QScrollArea(Pullman_Main);
        scrollArea_6->setObjectName(QStringLiteral("scrollArea_6"));
        scrollArea_6->setGeometry(QRect(250, 440, 881, 201));
        scrollArea_6->setWidgetResizable(true);
        scrollAreaWidgetContents_7 = new QWidget();
        scrollAreaWidgetContents_7->setObjectName(QStringLiteral("scrollAreaWidgetContents_7"));
        scrollAreaWidgetContents_7->setGeometry(QRect(0, 0, 879, 199));
        tableView_7 = new QTableView(scrollAreaWidgetContents_7);
        tableView_7->setObjectName(QStringLiteral("tableView_7"));
        tableView_7->setGeometry(QRect(10, 10, 861, 171));
        scrollArea_6->setWidget(scrollAreaWidgetContents_7);
        scrollArea_7 = new QScrollArea(Pullman_Main);
        scrollArea_7->setObjectName(QStringLiteral("scrollArea_7"));
        scrollArea_7->setGeometry(QRect(250, 640, 881, 51));
        scrollArea_7->setWidgetResizable(true);
        scrollAreaWidgetContents_8 = new QWidget();
        scrollAreaWidgetContents_8->setObjectName(QStringLiteral("scrollAreaWidgetContents_8"));
        scrollAreaWidgetContents_8->setGeometry(QRect(0, 0, 879, 49));
        layoutWidget = new QWidget(scrollAreaWidgetContents_8);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(540, 10, 335, 25));
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setFont(font);

        gridLayout_2->addWidget(pushButton_2, 0, 2, 1, 1);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setFont(font);

        gridLayout_2->addWidget(pushButton, 0, 3, 1, 1);

        pushButton_4 = new QPushButton(layoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setEnabled(true);
        pushButton_4->setFont(font);

        gridLayout_2->addWidget(pushButton_4, 0, 0, 1, 1);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setFont(font);

        gridLayout_2->addWidget(pushButton_3, 0, 1, 1, 1);

        scrollArea_7->setWidget(scrollAreaWidgetContents_8);

        retranslateUi(Pullman_Main);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(Pullman_Main);
    } // setupUi

    void retranslateUi(QDialog *Pullman_Main)
    {
        Pullman_Main->setWindowTitle(QApplication::translate("Pullman_Main", "Dialog", 0));
        label->setText(QApplication::translate("Pullman_Main", "Storage Name:", 0));
        label_4->setText(QApplication::translate("Pullman_Main", "TextLabel", 0));
        label_9->setText(QApplication::translate("Pullman_Main", "USA", 0));
        label_6->setText(QApplication::translate("Pullman_Main", "652 Armstrong Rd", 0));
        label_2->setText(QApplication::translate("Pullman_Main", "Pullman Storage", 0));
        label_7->setText(QApplication::translate("Pullman_Main", "Pullman, WA 99163", 0));
        label_3->setText(QApplication::translate("Pullman_Main", "Officier Name:", 0));
        label_5->setText(QApplication::translate("Pullman_Main", "Address:", 0));
        label_8->setText(QApplication::translate("Pullman_Main", "Country:", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Pullman_Main", "Tab 1", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Pullman_Main", "Page", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Pullman_Main", "Tab 2", 0));
        pushButton_2->setText(QApplication::translate("Pullman_Main", "Lock", 0));
        pushButton->setText(QApplication::translate("Pullman_Main", "Logout", 0));
        pushButton_4->setText(QApplication::translate("Pullman_Main", "Refresh", 0));
        pushButton_3->setText(QApplication::translate("Pullman_Main", "Control Pannel", 0));
    } // retranslateUi

};

namespace Ui {
    class Pullman_Main: public Ui_Pullman_Main {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PULLMAN_MAIN_H

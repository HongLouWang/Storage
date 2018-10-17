#include "pullman_main.h"
#include "ui_pullman_main.h"
#include "database.h"
#include "include.h"
#include <QSqlTableModel>
#include "p_fetchdata.h"
#include "f_login.h"
#include "qmail.h"
#include "shief.h"

shief p_main_shief;
MySQL N;
int FLAG_LOCK;
Pullman_Main p_main;
qmail q_mail;




Pullman_Main::Pullman_Main(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pullman_Main)
{
    this->setWindowFlags(p_main.windowFlags() &~ Qt::WindowMaximizeButtonHint);
    ui->setupUi(this);
    ui->tabWidget->setTabText(0,"Shief #1");
    ui->tabWidget->setTabText(1,"Shief #2");
    ui->tabWidget->setTabText(2,"Shief #3");
    fetchdata();
    q_mail.Init_Mail(this);
    p_main_shief.getshiefpostable();
    //qmail::Init_Mail(this);
}

Pullman_Main::~Pullman_Main()
{
    delete ui;
}

void Pullman_Main::on_pushButton_clicked()
{
   N.SQLCA.close();
   //qApp->exit();
}

void Pullman_Main::on_pushButton_3_clicked()
{
    p_controlpannel->open();
}

void Pullman_Main::on_pushButton_2_clicked()
{
    if(FLAG_LOCK == 0)
    {
        p_lock();
        FLAG_LOCK = 1;
    }
    else if(FLAG_LOCK == 1)
    {
        p_unlock();
        FLAG_LOCK = 0;
    }
}

/*
Function:   fetchdata
Desc:       fetch data from Database to model
Para:       NONE
Return      NONE
*/
void Pullman_Main::fetchdata()
{
    model = new QSqlTableModel(this);
    model->setTable("pickup_pullman");
    ui->tableView->setModel(model);
    model->select();

    model->setTable("logistics");
    ui->tableView_5->setModel(model);
    model->select();

    model->setTable("logistics");
    ui->tableView_6->setModel(model);
    model->select();

    model->setTable("logistics");
    ui->tableView_7->setModel(model);
    model->select();

}

/*
Function:   p_lock
Desc:       Lock down Main window Object
Para:       NONE
Return      NONE
*/
void Pullman_Main::p_lock()
{
    ui->tableView->setEnabled(false);
    ui->tableView_2->setEnabled(false);
    ui->tableView_3->setEnabled(false);
    ui->tableView_4->setEnabled(false);
    ui->tableView_5->setEnabled(false);
    ui->tableView_6->setEnabled(false);
    ui->tableView_7->setEnabled(false);

    ui->tabWidget->setTabEnabled(0,false);
    ui->tabWidget->setTabEnabled(1,false);
    ui->tabWidget->setTabEnabled(2,false);

    ui->pushButton_3->setEnabled(false);
    ui->pushButton_4->setEnabled(false);

    ui->pushButton_2->setText("Unlock");
}

/*
Function:   p_unlock
Desc:       Unlock Main window Object
Para:       NONE
Return      NONE
*/
void Pullman_Main::p_unlock()
{
    ui->tableView->setEnabled(true);
    ui->tableView_2->setEnabled(true);
    ui->tableView_3->setEnabled(true);
    ui->tableView_4->setEnabled(true);
    ui->tableView_5->setEnabled(true);
    ui->tableView_6->setEnabled(true);
    ui->tableView_7->setEnabled(true);

    ui->tabWidget->setTabEnabled(0,true);
    ui->tabWidget->setTabEnabled(1,true);
    ui->tabWidget->setTabEnabled(2,true);

    ui->pushButton_3->setEnabled(true);
    ui->pushButton_4->setEnabled(true);

    ui->pushButton_2->setText("lock");
}



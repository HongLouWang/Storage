#include "login.h"
#include "ui_login.h"
#include "database.h"
#include "f_login.h"
#include <QMessageBox>

MySQL::MySQL()
{
}

MySQL M;

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    M.init_database();
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
    QString T_Username, T_Password;
    T_Username = ui->lineEdit->text();
    T_Password = ui->lineEdit_2->text();

    if(!M.login(T_Username, T_Password))
    {
        QMessageBox::warning(this,"Error: ","Invalied Username or Password!");
    }
    else
    {
        p_main.open();
        this->close();
    }
}



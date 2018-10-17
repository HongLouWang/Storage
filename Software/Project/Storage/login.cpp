#include "login.h"
#include "ui_login.h"
#include "database.h"
#include "f_login.h"
#include <QMessageBox>
#include <QFile>
#include <QTextCodec>
#include "log.h"
#include <QString>

//extern int log();

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

    QString S_Username;

    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    //QTextCodec::setCodecForCStrings(codec);
    QFile file("/pullman/Config.txt");
    while(!file.atEnd())
    {
        QByteArray line = file.readLine();
        QString str(line);
        S_Username = str.mid(str.indexOf("S_Username = "), (str.replace(0, 13, "")).indexOf(" "));
        ui->lineEdit->setText(S_Username);
    }

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
        p_main->open();
        M.getuserinfo();
        log("LOGIN");
        this->close();
    }
}



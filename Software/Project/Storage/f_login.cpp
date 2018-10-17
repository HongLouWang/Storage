#include "database.h"
#include "f_login.h"
#include <QMessageBox>
#include "userinfo.h"
#include <QVariant>



bool MySQL::login(QString name, QString pass)
{
    QString str = QString("SELECT * FROM STUFF WHERE USERNAME = '%1' AND PASSWORD = '%2'").arg(name).arg(pass);
    query = new QSqlQuery;
    query->exec(str);
    query->last();
    int record = query->at()+1;
    if(record == 0)
    {
        return false;
    }
    ID = query->value(0).toInt();
    return true;

}

void MySQL::init_database()
{

    SQLCA.setHostName("47.254.76.209");
    SQLCA.setUserName("root");
    SQLCA.setPassword("w20080811");
    SQLCA.setDatabaseName("storage");

    if(!SQLCA.open())
    {
        //QMessageBox::warning(this, "ERROE: ", SQLCA.lastError().text());
        return;
    }

}

void MySQL::getuserinfo()
{
    QString str = QString("Select Username, Password, Firstname, Lastname, Phone, Sex from stuff where ID = '%1'").arg(ID);
    query = new QSqlQuery;
    query->exec(str);
    Username = query->value("Username").toString();
    Password = query->value("Password").toString();
    Firstname = query->value("Firstname").toString();
    Lastname = query->value("Lastname").toString();
    Phone = query->value("Phone").toString();
    Sex = query->value("Sex").toString();
    //Username =
}

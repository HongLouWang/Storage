#include "database.h"
#include "f_login.h"
#include <QMessageBox>

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


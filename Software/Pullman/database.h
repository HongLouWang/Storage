#ifndef DATABASE_H
#define DATABASE_H


#include <QSql>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>



class MySQL
{
public:
    MySQL();
    bool login(QString name, QString pass);
    void MySQL::init_database();
    QSqlDatabase SQLCA = QSqlDatabase::addDatabase("QMYSQL");
private:

    QSqlQuery *query;
};


#endif // DATABASE_H

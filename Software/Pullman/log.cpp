//#include "log.h"
#include <database.h>
#include <QString>
#include <QSqlquery>
#include <QSqlError>
#include <QDateTime>
//#include "userinfo.h"

extern int ID;

QSqlQuery *query_log;

int log(QString Info)
{
    QString Stime;
    QString Qquery_log = "SELECT current_timestamp()";
    QDate CTDate;
    QTime CTTime;
    query_log = new QSqlQuery;
    query_log->exec(Qquery_log);
    while(query_log->next())
    {
        Stime = query_log->first();
    }
    CTDate = QDate::currentDate();
    CTTime = QTime::currentTime();

    QString str = QString(" INSERT INTO log(Content, Uid, ServerTime, LocalDate, LocalTime) values ('%1','%2','%3','%4','%5')").arg(Info).arg(ID).arg(Stime).arg(CTDate.toString()).arg(CTTime.toString());
    query_log->exec(str);

    if(query_log->numRowsAffected() != 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}



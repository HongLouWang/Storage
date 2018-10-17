#include "getshiefpostable.h"
#include "shief.h"
#include <QString>
#include <QVariant>
#include <QSqlQuery>

void  shief::getshiefpostable()
{
    int i,ii,iii;
    for(i = 1; i < shief_number; i++)
    {
        for(ii = 1; i < shief_row_pos; i++)
        {
            for(iii = 1; iii < shief_column_pos; iii++)
            {
                QString str = QString("select value from sheif_position_pullman where x='%1' and y='%2' and z='%3'").arg(i).arg(ii).arg(iii);

                query_shief = new QSqlQuery;
                query_shief->exec(str);
                position[i][ii][iii] = query_shief->value(1).toString();
            }
        }
    }
}

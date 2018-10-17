#ifndef SHIEF_H
#define SHIEF_H
#include <QString>
#include <QSqlQuery>
class shief
{
public:
    QString position[3][10][10];
    QString postavai;
    int available_position[3][10][10];
    int shief_number, shief_row_pos, shief_column_pos;
     QSqlQuery *query_shief;
    void getshiefpostable();
};

#endif // SHIEF_H

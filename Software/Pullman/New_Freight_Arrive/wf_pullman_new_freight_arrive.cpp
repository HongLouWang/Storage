#include "wf_pullman_new_freight_arrive.h"
#include "pullman_new_freight_arrive.h"
#include "ui_pullman_new_freight_arrive.h"
#include <QSqlQuery>
#include <QVariant>
#include <QString>

void pullman_new_freight_arrive::getinfo()
{

    QString str  = QString("select logistics_trackingnumber from v_logistics_fright where freight_trackingnumber = '%1'").arg(tracking_id);
    QString str1 = QString("select id from freight where freight_trackingnumber = '%1'").arg(tracking_number);
    QString str2 = QString("select *from v_logistics where TrackingNumber = '%1'").arg(tracking_number);
    QString str3 = QString("select id from logistics where trackingnumber = '%1'").arg(logistics_number);

    query_new_freight_arrive = new QSqlQuery;
    query_new_freight_arrive->exec(str1);
    tracking_id = query_new_freight_arrive->value('id').toInt();

    query_new_freight_arrive = new QSqlQuery;
    query_new_freight_arrive->exec(str);
    logistics_number = query_new_freight_arrive->value('Logistics_trackingNumber').toString();

    query_new_freight_arrive = new QSqlQuery;
    query_new_freight_arrive->exec(str3);
    logistics_id = query_new_freight_arrive->value('id').toInt();

    query_new_freight_arrive = new QSqlQuery;
    query_new_freight_arrive->exec(str1);
    customer_id = query_new_freight_arrive->value('Customer_id').toInt();
    customer_firstname = query_new_freight_arrive->value('customer_firstname').toString();
    customer_lastname = query_new_freight_arrive->value('customer_lastname').toString();
    customer_email = query_new_freight_arrive->value('customer_email').toString();

    if(customer_id == last_customer_id)
    {
        customer_same = 1;
        last_customer_id = customer_id;
    }
    else
    {
        customer_same = 0;
        last_customer_id = customer_id;
    }

}

void pullman_new_freight_arrive::showinfo()
{
    ui->lineEdit->setText(tracking_number);
    ui->lineEdit_2->setText(QString(tracking_id));
    ui->lineEdit_3->setText(logistics_number);
    ui->lineEdit_4->setText(QString(logistics_id));
    ui->lineEdit_7->setText(QString(customer_id));
    ui->lineEdit_8->setText(customer_firstname);
    ui->lineEdit_9->setText(customer_lastname);

    if(ui->lineEdit_6->text().isNull())
    {
        on_pushButton_2_clicked();
    }
}







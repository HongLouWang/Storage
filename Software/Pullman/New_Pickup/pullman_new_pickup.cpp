#include "pullman_new_pickup.h"
#include "ui_pullman_new_pickup.h"
#include "database.h"
#include <QMessageBox>
#include "log.h"
#include "pullman_new_customer.h"

pullman_new_pickup p_new_pickup;

QString SQL = "SELECT * FROM CUSTOMER WHERE ",SQL1,SQL2,con;
QString pickup_firstname, pickup_lastname, pickup_phone, pickup_email,pickup_date;
QSqlQuery *query;
int C_ID, C_Dly = 0;

pullman_new_customer p_new_customer;

pullman_new_pickup::pullman_new_pickup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pullman_new_pickup)
{
    this->setWindowFlags(p_new_pickup.windowFlags() &~ Qt::WindowMaximizeButtonHint);
    ui->setupUi(this);

}

pullman_new_pickup::~pullman_new_pickup()
{
    delete ui;
}

void pullman_new_pickup::on_lineEdit_editingFinished()
{
    if(SQL.indexOf("firstname") != 0)
    {
        SQL1 = SQL.mid(0,SQL.indexOf("firstname"));
        SQL = SQL.mid(0,SQL1.length());
        SQL2 = SQL;
        con = "firstname = " + ui->lineEdit->text();
        SQL = SQL1 + con + SQL2;
    }
    else
    {
        con = "fistname = " + ui->lineEdit->text();
        SQL = SQL + con;
    }
}

void pullman_new_pickup::on_pushButton_3_clicked()
{
    pickup_firstname = ui->lineEdit->text();
    pickup_lastname = ui->lineEdit_2->text();
    pickup_phone = ui->lineEdit_3->text();
    pickup_date = ui->dateTimeEdit->text();

    QString str = QString("SELECT id from customer where firstname = '%1' and lastname = '%2' and phone = '%3'").arg(pickup_firstname).arg(pickup_lastname).arg(pickup_phone);
    query = new QSqlQuery;
    query->exec(str);
    C_ID = query->value("id").toInt();
    int record = query->at()+1;
    if(record == 0)
    {
        QMessageBox::warning(this,"Error: ","Undefined Customer, Please Set Up New Customer First!");
        return;
    }
    else
    {
        QString str = QString("Insert into pickup_pullman(customer_firstname, customer_lastname, customer_phone, customer_id,customer_id,pickup_date,delay)values('%1','%2','%3','%4','%5','%6','%7')").arg(pickup_firstname).arg(pickup_lastname).arg(pickup_phone).arg(pickup_email).arg(C_ID).arg(pickup_date).arg(C_Dly);
        query->exec(str);
        if(query->numRowsAffected() <= 0)
        {
            QMessageBox::warning(this,"Error: ","Network Error, Please check internet connection or connect your IT cooridenator!");
            return;
        }
        else
        {
            QMessageBox::warning(this,"Error: ","New pick up set up successful!");
            log("NEWCUSTOMER");
        }
    }

}

void pullman_new_pickup::on_pushButton_clicked()
{
    p_new_customer.open();
    this->close();
}

#include "pullman_new_customer.h"
#include "ui_pullman_new_customer.h"
#include <QRadioButton>
#include <QSqlQuery>
#include <QVariant>
#include <QAbstractButton>
#include "wf_pullman_new_customer.h"
#include <QMessageBox>
#include "log.h"
#include <QPageSetupDialog>
#include <QFileDialog>
#include <QPrintPreviewDialog>
#include <QPrinter>
//#include "qmail.h"

QSqlQuery *query_new_customer;
qmail q_mail;
QButtonGroup *DocGroup;
int DocGroup_Checked;
//QString customer_firstname, customer_lastname, customer_sex, customer_phone, customer_address, customer_address1, customer_address2, customer_address3, customer_doc_country, customer_email, customer_doc, customer_doc_type;

int customer_class = 100;

extern QString MailUserName;
extern QString MailPassword;
extern int log(QString info);

pullman_new_customer::pullman_new_customer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pullman_new_customer)
{
    ui->setupUi(this);
    ui->textEdit->setVisible(false);
    DocGroup = new QButtonGroup(this);
    DocGroup->addButton(ui->radioButton_3);
    DocGroup->addButton(ui->radioButton_4);
    DocGroup->addButton(ui->radioButton_5);
    DocGroup->addButton(ui->radioButton_6);
    DocGroup->setId(ui->radioButton_3,0);
    DocGroup->setId(ui->radioButton_4,1);
    DocGroup->setId(ui->radioButton_5,2);
    DocGroup->setId(ui->radioButton_6,3);
}

pullman_new_customer::~pullman_new_customer()
{
    delete ui;
}

void pullman_new_customer::on_lineEdit_8_editingFinished()
{
    //if(ui->radioButton_3->clicked())
    customer_doc = ui->lineEdit_8->text();

    DocGroup_Checked = DocGroup->checkedId();
    if(DocGroup_Checked == 0)
    {
        QString str = QString("Select id from customer where SSN = '%1'").arg(customer_doc);
        query_new_customer = new QSqlQuery;
        query_new_customer->exec(str);
        customer_id = query_new_customer->value("id").toInt();
    }
    else if(DocGroup_Checked == 1)
    {
        QString str = QString("Select id from customer where ITIN = '%1'").arg(customer_doc);
        query_new_customer = new QSqlQuery;
        query_new_customer->exec(str);
        customer_id = query_new_customer->value("id").toInt();
    }
    else if(DocGroup_Checked == 2)
    {
        QString str = QString("Select id from customer where Passport = '%1'").arg(customer_doc);
        query_new_customer = new QSqlQuery;
        query_new_customer->exec(str);
        customer_id = query_new_customer->value("id").toInt();
    }
    else if(DocGroup_Checked == 3)
    {
        QString str = QString("Select id from customer where StateIssue = '%1'").arg(customer_doc);
        query_new_customer = new QSqlQuery;
        query_new_customer->exec(str);
        customer_id = query_new_customer->value("id").toInt();
    }

    int record = query_new_customer->at()+1;
    if(record == 0)
    {

    }
    else
    {
       getinfoserver(customer_id);
       showinfo();
    }
}

void pullman_new_customer::on_radioButton_clicked()
{
    customer_sex = "Male";
}

void pullman_new_customer::on_radioButton_2_clicked()
{
    customer_sex = "Female";
}

void pullman_new_customer::on_pushButton_8_clicked()
{
    customer_firstname = ui->lineEdit->text();
    customer_lastname = ui->lineEdit_2->text();
    customer_phone = ui->lineEdit_3->text();
    customer_email = ui->lineEdit_4->text();
    customer_address1 = ui->lineEdit_5->text();
    customer_address2 = ui->lineEdit_6->text();
    customer_address3 = ui->lineEdit_7->text();
    customer_address = customer_address1 + customer_address2 + customer_address3;
    customer_doc = ui->lineEdit_8->text();
    customer_doc_country = ui->lineEdit_9->text();

    if(checkinfo() != 0)
    {
        QMessageBox::warning(this,"Error!","Illegal Information, Please check!");
        log("ATTEMPT INSERT ILLEGAL CUSTOMER INFORMATION");
    }
    else
    {
        DocGroup_Checked = DocGroup->checkedId();
        if(DocGroup_Checked == 0)
        {
           QString str = QString("Insert into customer(firstname, lastname, email, phone, sex, SSN, IssueCountryState, class) value ('%1','%2','%3','%4','%5','%6','%7','%8')").arg(customer_firstname).arg(customer_lastname).arg(customer_email).arg(customer_phone).arg(customer_sex).arg(customer_doc).arg(customer_doc_country).arg(customer_class);
           query_new_customer = new QSqlQuery;
           query_new_customer->exec(str);
        }
        else if(DocGroup_Checked == 1)
        {
            QString str = QString("Insert into customer(firstname, lastname, email, phone, sex, ITIN, IssueCountryState, class) value ('%1','%2','%3','%4','%5','%6','%7','%8')").arg(customer_firstname).arg(customer_lastname).arg(customer_email).arg(customer_phone).arg(customer_sex).arg(customer_doc).arg(customer_doc_country).arg(customer_class);
            query_new_customer = new QSqlQuery;
            query_new_customer->exec(str);
        }
        else if(DocGroup_Checked == 2)
        {
            QString str = QString("Insert into customer(firstname, lastname, email, phone, sex, passport, IssueCountryState, class) value ('%1','%2','%3','%4','%5','%6','%7','%8')").arg(customer_firstname).arg(customer_lastname).arg(customer_email).arg(customer_phone).arg(customer_sex).arg(customer_doc).arg(customer_doc_country).arg(customer_class);
            query_new_customer = new QSqlQuery;
            query_new_customer->exec(str);
        }
        else if(DocGroup_Checked == 3)
        {
            QString str = QString("Insert into customer(firstname, lastname, email, phone, sex, StateIssue, IssueCountryState, class) value ('%1','%2','%3','%4','%5','%6','%7','%8')").arg(customer_firstname).arg(customer_lastname).arg(customer_email).arg(customer_phone).arg(customer_sex).arg(customer_doc).arg(customer_doc_country).arg(customer_class);
            query_new_customer = new QSqlQuery;
            query_new_customer->exec(str);
        }
        log("NEWCUSTOMERISSUED");
        setUpPage();
        createPdf();
        ui->textEdit->print(&printer);
        doPrintPreview();
        q_mail.Construct_Mail(customer_email,"Congratulation! Welcome to Use Emerald Down Storage Service","Congratulation! Welcome to Use Emerald Down Storage Service");
        q_mail.Send_mail(this);
        QMessageBox::warning(this,"Error!","Success! New Customer!");
    }
}

void pullman_new_customer::showinfo()
{
    ui->lineEdit->setText(customer_firstname);
    ui->lineEdit_2->setText(customer_lastname);
    ui->lineEdit_3->setText(customer_phone);
    ui->lineEdit_4->setText(customer_email);
    ui->lineEdit_5->setText(customer_address);
    ui->lineEdit_9->setText(customer_doc_country);
    if(customer_sex == "Male")
    {
        ui->radioButton->setChecked(true);
    }
    else
    {
        ui->radioButton_2->setChecked(true);
    }
}




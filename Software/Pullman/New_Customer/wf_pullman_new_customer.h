#ifndef WF_PULLMAN_NEW_CUSTOMER_H
#define WF_PULLMAN_NEW_CUSTOMER_H

#include <QString>
#include <QSqlQuery>
#include <QButtonGroup>

extern QSqlQuery *query_new_customer;

extern QButtonGroup *DocGroup;
extern int DocGroup_Checked;
//extern QString customer_firstname, customer_lastname, customer_sex, customer_phone, customer_address, customer_address1, customer_address2, customer_address3, customer_doc_country, customer_email, customer_doc, customer_doc_type;
extern int customer_id;

//void getinfoserver(int id);
//int checkinfo();

#endif // WF_PULLMAN_NEW_CUSTOMER_H

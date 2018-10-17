#include "wf_pullman_new_customer.h"
#include "pullman_new_customer.h"
#include <QVariant>

pullman_new_customer *p;
//Ui::pullman_new_customer *ui;

void pullman_new_customer::getinfoserver(int id)
{
    QString str = QString("Select * from customer where id = '%1'").arg(id);
    query_new_customer = new QSqlQuery;
    query_new_customer->exec(str);

    customer_firstname = query_new_customer->value("firstname").toString();
    customer_lastname  = query_new_customer->value("lastname").toString();
    customer_sex       = query_new_customer->value("sex").toString();
    customer_phone     = query_new_customer->value("phone").toString();
    customer_email     = query_new_customer->value("emailss").toString();
    customer_address   = query_new_customer->value("address").toString();
    customer_doc_country = query_new_customer->value("IssueCountryState").toString();

}

int pullman_new_customer::checkinfo()
{
    if(customer_firstname == "")
    {
        return 1;
    }

    if(customer_lastname == "")
    {
        return 1;
    }

    if(customer_sex == "")
    {
        return 1;
    }

    if(customer_phone == "")
    {
        return 1;
    }

    if(customer_email == "")
    {
        return 1;
    }

    if(customer_address == "")
    {
        return 1;
    }

    if(customer_doc == "")
    {
        return 1;
    }

    if(customer_doc_country == "")
    {
        return 1;
    }

    return 0;
}



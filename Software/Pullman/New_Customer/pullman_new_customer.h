#ifndef PULLMAN_NEW_CUSTOMER_H
#define PULLMAN_NEW_CUSTOMER_H

#include <QDialog>
#include "qmail.h"
#include <QPrinter>

namespace Ui {
class pullman_new_customer;
}

class pullman_new_customer : public QDialog
{
    Q_OBJECT

public:
    qmail q_mail;
    explicit pullman_new_customer(QWidget *parent = nullptr);
    ~pullman_new_customer();
    void showinfo();
    void getinfoserver(int id);
    int  checkinfo();
    void setUpPage();
    void createPdf();
    void doPrintPreview();

    QString customer_firstname, customer_lastname, customer_sex, customer_phone, customer_address, customer_address1, customer_address2, customer_address3, customer_doc_country, customer_email, customer_doc, customer_doc_type;
    int customer_id;
    QPrinter printer;;

private slots:
    void on_lineEdit_8_editingFinished();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::pullman_new_customer *ui;
};

#endif // PULLMAN_NEW_CUSTOMER_H

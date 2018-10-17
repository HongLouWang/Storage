#ifndef PULLMAN_NEW_FREIGHT_ARRIVE_H
#define PULLMAN_NEW_FREIGHT_ARRIVE_H
#include <QSqlQuery>
#include <QDialog>

namespace Ui {
class pullman_new_freight_arrive;
}

class pullman_new_freight_arrive : public QDialog
{
    Q_OBJECT

public:
    explicit pullman_new_freight_arrive(QWidget *parent = nullptr);
    ~pullman_new_freight_arrive();
    void Init_Mail(QWidget *m_parent);
    void Construct_Mail(QString address_send, QString Subject, QString text);
    void Send_mail(QWidget *m_parent);
    void getinfo();
    void showinfo();

    QString customer_firstname, customer_lastname, customer_email, tracking_number, logistics_number;
    int tracking_id, logistics_id, customer_id, last_customer_id;
    int docking_id, pos = 1, customer_same;
    QString email_tracking_number, email_logistics_number[512];
    int i = 0, arr_customer_id[1024][512];
    QSqlQuery *query_new_freight_arrive;

private slots:
    void on_lineEdit_editingFinished();

    void on_pushButton_2_clicked();

private:
    Ui::pullman_new_freight_arrive *ui;
};

#endif // PULLMAN_NEW_FREIGHT_ARRIVE_H

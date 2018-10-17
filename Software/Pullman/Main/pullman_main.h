#ifndef PULLMAN_MAIN_H
#define PULLMAN_MAIN_H

#include <QDialog>
#include <QSqlTableModel>
#include "controlpannel.h"
//#include "qmail.h"

namespace Ui {
class Pullman_Main;
}

class Pullman_Main : public QDialog
{
    Q_OBJECT

public:
    explicit Pullman_Main(QWidget *parent = nullptr);
    ~Pullman_Main();
    void fetchdata();
    void p_lock();
    void p_unlock();
    //void qmail::Init_Mail(QWidget *m_parent);


private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Pullman_Main *ui;
    QSqlTableModel *model;
    ControlPannel *p_controlpannel;

};





#endif // PULLMAN_MAIN_H

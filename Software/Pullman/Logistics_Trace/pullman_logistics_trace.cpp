#include "pullman_logistics_trace.h"
#include "ui_pullman_logistics_trace.h"
#include <QString>

pullman_logistics_trace p_logiistics_trace;

pullman_logistics_trace::pullman_logistics_trace(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pullman_logistics_trace)
{
    this->setWindowFlags(p_logiistics_trace.windowFlags() &~ Qt::WindowMaximizeButtonHint);
    ui->setupUi(this);

    model = new QSqlTableModel(this);
    model->setTable("logistics");
    ui->tableView->setModel(model);
    model->select();
}

pullman_logistics_trace::~pullman_logistics_trace()
{
    delete ui;
}

void pullman_logistics_trace::on_pushButton_2_clicked()
{
    model = new QSqlTableModel(this);
    model->setTable("logistics");
    ui->tableView->setModel(model);
    model->select();
}

void pullman_logistics_trace::on_pushButton_clicked()
{

}





void pullman_logistics_trace::on_comboBox_currentIndexChanged(const QString &arg1)
{
    QString ctt;
    ctt = ui->comboBox->currentText();

    if(ctt == "ID")
    {
        ui->tableView->sortByColumn(1);
    }
    else if(ctt == "Carrier")
    {
        ui->tableView->sortByColumn(2);
    }
    else if(ctt == "Establish City")
    {
        ui->tableView->sortByColumn(3);
    }
    else if(ctt == "Establish Country")
    {
        ui->tableView->sortByColumn(4);
    }
    else if(ctt == "Arrive City")
    {
        ui->tableView->sortByColumn(5);
    }
    else if(ctt == "Arrive Country")
    {
        ui->tableView->sortByColumn(6);
    }
    else if(ctt == "Establish Date")
    {
        ui->tableView->sortByColumn(7);
    }
    else if(ctt == "Arrive Date")
    {
        ui->tableView->sortByColumn(8);
    }
    else if(ctt == "Delay")
    {
        ui->tableView->sortByColumn(9);
    }
    else if(ctt == "Need Custom")
    {
        ui->tableView->sortByColumn(10);
    }

}



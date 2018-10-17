#include "pullman_new_freight_arrive.h"
#include "ui_pullman_new_freight_arrive.h"
#include "wf_pullman_new_freight_arrive.h"
#include <QSqlQuery>
#include <QString>
#include "shief.h"

shief p_new_freight_arrive_shief;

pullman_new_freight_arrive::pullman_new_freight_arrive(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pullman_new_freight_arrive)
{
    ui->setupUi(this);
}

pullman_new_freight_arrive::~pullman_new_freight_arrive()
{
    delete ui;

}

void pullman_new_freight_arrive::on_lineEdit_editingFinished()
{
    tracking_id = ui->lineEdit->text().toInt();
}



void pullman_new_freight_arrive::on_pushButton_2_clicked()
{
    p_new_freight_arrive_shief.getshiefpostable();
    p_new_freight_arrive_shief.postavai = p_new_freight_arrive_shief.available_position[1][2][3];
    ui->lineEdit_6->setText(p_new_freight_arrive_shief.postavai);
}

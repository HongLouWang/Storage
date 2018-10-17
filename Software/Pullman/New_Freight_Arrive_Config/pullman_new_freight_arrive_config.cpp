#include "pullman_new_freight_arrive_config.h"
#include "ui_pullman_new_freight_arrive_config.h"

pullman_new_freight_arrive_config::pullman_new_freight_arrive_config(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pullman_new_freight_arrive_config)
{
    ui->setupUi(this);
}

pullman_new_freight_arrive_config::~pullman_new_freight_arrive_config()
{
    delete ui;
}

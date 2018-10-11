#include "pullman_logistics_trace.h"
#include "ui_pullman_logistics_trace.h"

pullman_logistics_trace::pullman_logistics_trace(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pullman_logistics_trace)
{
    ui->setupUi(this);
}

pullman_logistics_trace::~pullman_logistics_trace()
{
    delete ui;
}

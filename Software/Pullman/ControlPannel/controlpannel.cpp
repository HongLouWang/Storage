#include "controlpannel.h"
#include "ui_controlpannel.h"

ControlPannel p_controlpannel;

ControlPannel::ControlPannel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ControlPannel)
{
    this->setWindowFlags(p_controlpannel.windowFlags() &~ Qt::WindowMaximizeButtonHint);
    ui->setupUi(this);
}

ControlPannel::~ControlPannel()
{
    delete ui;
}

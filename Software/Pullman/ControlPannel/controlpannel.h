#ifndef CONTROLPANNEL_H
#define CONTROLPANNEL_H

#include <QDialog>

namespace Ui {
class ControlPannel;
}

class ControlPannel : public QDialog
{
    Q_OBJECT

public:
    explicit ControlPannel(QWidget *parent = nullptr);
    ~ControlPannel();

private:
    Ui::ControlPannel *ui;
};

#endif // CONTROLPANNEL_H

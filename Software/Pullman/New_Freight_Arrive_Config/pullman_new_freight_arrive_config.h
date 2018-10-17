#ifndef PULLMAN_NEW_FREIGHT_ARRIVE_CONFIG_H
#define PULLMAN_NEW_FREIGHT_ARRIVE_CONFIG_H

#include <QDialog>

namespace Ui {
class pullman_new_freight_arrive_config;
}

class pullman_new_freight_arrive_config : public QDialog
{
    Q_OBJECT

public:
    explicit pullman_new_freight_arrive_config(QWidget *parent = nullptr);
    ~pullman_new_freight_arrive_config();

private:
    Ui::pullman_new_freight_arrive_config *ui;
};

#endif // PULLMAN_NEW_FREIGHT_ARRIVE_CONFIG_H

#ifndef PULLMAN_NEW_PICKUP_H
#define PULLMAN_NEW_PICKUP_H

#include <QDialog>

namespace Ui {
class pullman_new_pickup;
}

class pullman_new_pickup : public QDialog
{
    Q_OBJECT

public:
    explicit pullman_new_pickup(QWidget *parent = nullptr);
    ~pullman_new_pickup();

private slots:
    void on_lineEdit_editingFinished();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::pullman_new_pickup *ui;

};

#endif // PULLMAN_NEW_PICKUP_H

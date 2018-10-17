#ifndef PULLMAN_LOGISTICS_TRACE_H
#define PULLMAN_LOGISTICS_TRACE_H

#include <QDialog>
#include <QSqlTableModel>

namespace Ui {
class pullman_logistics_trace;
}

class pullman_logistics_trace : public QDialog
{
    Q_OBJECT

public:
    explicit pullman_logistics_trace(QWidget *parent = nullptr);
    ~pullman_logistics_trace();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

private:
    Ui::pullman_logistics_trace *ui;
    QSqlTableModel *model;

};

#endif // PULLMAN_LOGISTICS_TRACE_H

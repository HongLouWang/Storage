#ifndef PULLMAN_LOGISTICS_TRACE_H
#define PULLMAN_LOGISTICS_TRACE_H

#include <QDialog>

namespace Ui {
class pullman_logistics_trace;
}

class pullman_logistics_trace : public QDialog
{
    Q_OBJECT

public:
    explicit pullman_logistics_trace(QWidget *parent = nullptr);
    ~pullman_logistics_trace();

private:
    Ui::pullman_logistics_trace *ui;
};

#endif // PULLMAN_LOGISTICS_TRACE_H

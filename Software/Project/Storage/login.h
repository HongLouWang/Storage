#include <QMainWindow>
#include "log.h"


#ifndef LOGIN_H
#define LOGIN_H
#include "pullman_main.h"
//#include "controlpannel.h"

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
    //void getuserinfo();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Login *ui;
    Pullman_Main *p_main;
};

#endif // LOGIN_H

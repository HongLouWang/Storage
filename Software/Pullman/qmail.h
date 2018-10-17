#ifndef QMAIL_H
#define QMAIL_H
#include "smtpmime.h"




class qmail
{
public:
    MimeMessage message;

    QString MailUserName = "Shutian@edmining.cn";
    QString MailPassword = "Ww20080811";
    void Init_Mail(QWidget *m_parent);
    void Construct_Mail(QString address_send, QString Subject, MimePart text);
    void Send_mail(QWidget *m_parent);
};

#endif // QMAIL_H

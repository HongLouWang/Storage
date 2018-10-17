#include "qmail.h"
#include "smtpmime.h"
#include <QMessageBox>
#include "log.h"

extern QString MailUserName;
extern QString MailPassword;

SmtpClient smtp("smtp.mxhichina.com", 25, SmtpClient::TcpConnection);

void qmail::Init_Mail(QWidget *m_parent)
{
    smtp.setUser(MailUserName);
    smtp.setPassword(MailPassword);
    if(!smtp.connectToHost())
    {
        QMessageBox::warning(m_parent,"Error!","Can not connect to the mail server!");
        log("FAILMAILSERVER");
        return;
    }

    if(!smtp.login())
    {
        QMessageBox::warning(m_parent,"Error!","Username or Password incorrect!");
        log("UNAUTHORIZEDLOGIN");
        return;
    }
}

void qmail::Construct_Mail(QString address_send, QString Subject, MimePart text)
{
    message.setSender(new EmailAddress("shutian@edmining.cn"));
    message.addRecipient(new EmailAddress(address_send));
    message.setSubject(Subject);
    message.addPart(&text);
}

void qmail::Send_mail(QWidget *m_parent)
{
    if(!smtp.sendMail(message))
    {
        QMessageBox::warning(m_parent,"Error!","Unable to send email!");
        log("FAILSENDEMAIL");
        return;
    }
    else
    {
        QMessageBox::warning(m_parent,"Error!","Send Email Successfully!");
    }
}


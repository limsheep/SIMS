#ifndef LOGINDAOIMPL_H
#define LOGINDAOIMPL_H

#include "gloable.h"


class LoginDaoImpl : public LoginDao
{
public:
    LoginDaoImpl();

    bool checkMemberAcct(QString acct);
    QString getMemberPswd(QString acct);
};

#endif // LOGINDAOIMPL_H

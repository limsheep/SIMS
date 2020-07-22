#ifndef LOGINSERVICEIMPL_H
#define LOGINSERVICEIMPL_H

#include "gloable.h"



class LoginServiceImpl : public LoginService
{
public:
    LoginServiceImpl();

    STACODE checkMemberAcct(QString acct);
    STACODE getMemberPswd(QString acct,QString pswd);
};

#endif // LOGINSERVICEIMPL_H

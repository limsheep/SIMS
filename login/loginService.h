#ifndef LOGINSERVICE_H
#define LOGINSERVICE_H

#include <QString>
#include "STACODE.h"

class LoginService
{ 
public:
    virtual ~LoginService(){};

public:
    virtual STACODE checkMemberAcct(QString acct) = 0;
    virtual STACODE getMemberPswd(QString acct,QString pswd) = 0;
};

#endif // LOGINSERVICE_H

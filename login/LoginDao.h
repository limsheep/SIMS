#ifndef LOGINDAO_H
#define LOGINDAO_H

#include<QString>

class LoginDao{
public:
    virtual ~LoginDao(){};
public:
    virtual bool checkMemberAcct(QString acct) = 0;
    virtual QString getMemberPswd(QString acct) = 0;
};

#endif // LOGINDAO_H

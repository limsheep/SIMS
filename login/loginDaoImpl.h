#ifndef LOGINDAOIMPL_H
#define LOGINDAOIMPL_H

#include "gloable.h"

/**
 * @brief The LoginDaoImpl class 数据库访问业务接口实现
 */
class LoginDaoImpl : public LoginDao
{
public:
    LoginDaoImpl();

    bool checkMemberAcct(QString acct);
    QString getMemberPswd(QString acct);
};

#endif // LOGINDAOIMPL_H

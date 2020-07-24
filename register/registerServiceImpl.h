#ifndef REGISTERSERVICEIMPL_H
#define REGISTERSERVICEIMPL_H

#include "gloable.h"

/**
 * @brief The RegisterServiceImpl class 注册服务接口实现
 */
class RegisterServiceImpl : public RegisterService
{
public:
    RegisterServiceImpl();

    STACODE rescheckMemberAcct(QString acct, QString name);
    bool setMemberInfo(QString name,QString acct, QString pswd, QString phone);
};
#endif // REGISTERSERVICEIMPL_H

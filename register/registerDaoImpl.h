#ifndef REGISTERDAOIMPL_H
#define REGISTERDAOIMPL_H

#include "gloable.h"

/**
 * @brief The LoginDaoImpl class 注册数据库访问业务接口实现
 */
class registerDaoImpl : public registerDao
{
public:
    registerDaoImpl();

    STACODE rescheckMemberAcct(QString acct, QString name);
    bool setMemberInfo(QString name,QString acct, QString pswd, QString phone);
};

#endif // REGISTERDAOIMPL_H

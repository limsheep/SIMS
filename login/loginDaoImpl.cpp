#include "loginDaoImpl.h"

LoginDaoImpl::LoginDaoImpl()
{

}

bool LoginDaoImpl::checkMemberAcct(QString acct)
{
    //TODO
    //此处编写访问数据库函数
    bool res = true;
    return res;
}

QString LoginDaoImpl::getMemberPswd(QString acct)
{
    //TODO
    //此处编写访问数据库的函数
    QString in = acct;
    QString pswd = "123456"; //仅用于测试
    return pswd;
}

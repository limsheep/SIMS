#include "loginDaoImpl.h"

LoginDaoImpl::LoginDaoImpl()
{

}

/**
 * @brief LoginDaoImpl::checkMemberAcct 查询账号是否存在于数据库中
 * @param acct 账号
 * @return 返回账号的存在情况
 */
bool LoginDaoImpl::checkMemberAcct(QString acct)
{
    //TODO
    //此处编写访问数据库函数
    bool res = true;
    return res;
}

/**
 * @brief LoginDaoImpl::getMemberPswd 访问数据库获取密码
 * @param acct 账号
 * @return 返回密码
 */
QString LoginDaoImpl::getMemberPswd(QString acct)
{
    //TODO
    //此处编写访问数据库的函数
    QString in = acct;
    QString pswd = "123456"; //仅用于测试
    return pswd;
}

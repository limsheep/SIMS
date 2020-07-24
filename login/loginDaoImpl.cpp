#include "loginDaoImpl.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>

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
    bool res = false;
    QSqlQuery query;
    query.exec("select * from manager");
    while(query.next()){
        if(query.value("jobnumber") == acct){
            res = true;
        }
    }

    return res;
}

/**
 * @brief LoginDaoImpl::getMemberPswd 访问数据库获取密码
 * @param acct 账号
 * @return 返回密码
 */
QString LoginDaoImpl::getMemberPswd(QString acct)
{
    QSqlQuery query;
    QString pswd;
    query.exec("select * from manager");
    while(query.next()){
        if(query.value("jobnumber") == acct){
            pswd = query.value("password").toString();
        }
    }
    return pswd;
}

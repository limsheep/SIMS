#include "registerDaoImpl.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>

registerDaoImpl::registerDaoImpl()
{

}

/**
 * @brief checkMemberAcct 查询账号是否存在,查询姓名是否注册
 * @param acct，name
 * @return 返回账号和姓名的存在情况 ACCT_ALEXISTS-账号存在; ACCT_UNEXIST-账号不存在; NAME_ALEXISTS-姓名存在
 */
STACODE registerDaoImpl::rescheckMemberAcct(QString acct, QString name)
{
    STACODE stacode;
    QSqlQuery query;
    query.exec("select * from manager");
    while(query.next()){
        if(query.value("jobnumber") == acct){
            stacode = ACCT_ALEXISTS;
            break;
        }

        else if(query.value("name") == name){
            stacode = NAME_ALEXISTS;
            break;
        }
    }
    stacode = ACCT_UNEXIST;

    return stacode;
}

/**
 * @brief LoginDaoImpl::resetMemberInfo 访问数据库插入数据
     * @param acct
     * @param pswd
     * @param phone
     * @param name
     * @return 返回注册是否成功 true-成功 false-失败
     *
 */
bool registerDaoImpl::setMemberInfo(QString name,QString acct, QString pswd, QString phone)
{
    QSqlQuery query;
    QString sql = QString("insert into manager(name,jobnumber,password,phone) values('%1','%2','%3','%4')")
            .arg(name)
            .arg(acct)
            .arg(pswd)
            .arg(phone);

    bool res = query.exec(sql);
    return res;
}

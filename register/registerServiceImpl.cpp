#include "registerserviceimpl.h"
#include "registerDao.h"
#include "registerDaoImpl.h"


RegisterServiceImpl::RegisterServiceImpl()
{

}

/**
 * @brief RegisterServiceImpl::rescheckMemberAcct
 * @param acct 账号， name 名字
 * @return 返回账号和姓名的存在情况 ACCT_ALEXISTS-账号存在; ACCT_UNEXIST-账号不存在; NAME_ALEXISTS-姓名存在
 */

STACODE RegisterServiceImpl::rescheckMemberAcct(QString acct, QString name)
{
    STACODE stacod;
    if(acct == NULL || name == NULL)
    {
        stacod = PARAM_NULL;
        return stacod;
    }
    registerDao * registerdao = new registerDaoImpl();
    stacod = registerdao->rescheckMemberAcct(acct, name);//检查账号和姓名是否在数据库中

    delete registerdao;
    return stacod;

}

/**
 * @brief RegisterServiceImpl::setMemberInfo
 * @param acct
 * @param pswd
 * @param phone
 * @param name
 * @param position
 * @return 返回bool  true-注册成功; false-注册失败
 */

bool RegisterServiceImpl::setMemberInfo(QString name,QString acct, QString pswd, QString phone)
{
    bool res;
    registerDao * registerdao = new registerDaoImpl();
    res = registerdao->setMemberInfo(name, acct, pswd, phone);
    delete registerdao;

    return res;
}


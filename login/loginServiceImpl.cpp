#include "loginServiceImpl.h"
#include "LoginDao.h"
#include "loginDaoImpl.h"

LoginServiceImpl::LoginServiceImpl()
{

}

/**
 * @brief LoginServiceImpl::checkMemberAcct
 * @param acct 账号
 * @return 返回状态码
 */
STACODE LoginServiceImpl::checkMemberAcct(QString acct)
{
    STACODE staCode;
    if(acct == NULL){  //对参数判空
        staCode = PARAM_NULL;
        return staCode;
    }
    LoginDao *loginDao = new LoginDaoImpl();
    bool haveAcct = loginDao->checkMemberAcct(acct); //查询账号是否存在
    if(haveAcct){
        staCode =  SUCCESS;
    }else{
        staCode = ACCT_UNEXIST;
    }
    delete loginDao;
    return staCode;
}

/**
 * @brief LoginServiceImpl::getMemberPswd
 * @param acct 账号
 * @param pswd 密码
 * @return 返回状态码
 */
STACODE LoginServiceImpl::getMemberPswd(QString acct,QString pswd)
{
    STACODE staCode;
    if(acct == NULL || pswd == NULL){
        staCode = PARAM_NULL;
        return staCode;
    }
    LoginDao *loginDao = new LoginDaoImpl();
    QString realPswd = loginDao->getMemberPswd(acct);
    if(pswd == realPswd){  //加密后的密码比对一致则成功
        staCode = SUCCESS;
    }else{
        staCode = PSWD_ERR;
    }
    delete loginDao;
    return staCode;
}

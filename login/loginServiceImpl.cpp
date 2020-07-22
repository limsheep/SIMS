#include "loginServiceImpl.h"
#include "LoginDao.h"
#include "loginDaoImpl.h"

LoginServiceImpl::LoginServiceImpl()
{

}

STACODE LoginServiceImpl::checkMemberAcct(QString acct)
{
    STACODE staCode;
    if(acct == NULL){
        staCode = PARAM_NULL;
        return staCode;
    }
    LoginDao *loginDao = new LoginDaoImpl();
    bool haveAcct = loginDao->checkMemberAcct(acct);
    if(!haveAcct){
        staCode =  ACCT_UNEXIST;
    }else{
        staCode = SUCCESS;
    }
    delete loginDao;
    return staCode;
}

STACODE LoginServiceImpl::getMemberPswd(QString acct,QString pswd)
{
    STACODE staCode;
    if(acct == NULL || pswd == NULL){
        staCode = PARAM_NULL;
        return staCode;
    }
    LoginDao *loginDao = new LoginDaoImpl();
    QString realPswd = loginDao->getMemberPswd(acct);
    if(pswd == realPswd){
        staCode = SUCCESS;
    }else{
        staCode = PSWD_ERR;
    }
    delete loginDao;
    return staCode;
}

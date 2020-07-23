#ifndef LOGINSERVICE_H
#define LOGINSERVICE_H

#include <QString>
#include "STACODE.h"

/**
 * @brief The LoginService class 登录服务接口
 */
class LoginService
{ 
public:
    virtual ~LoginService(){}; //有虚函数的类需要添加虚析构函数

public:
    /**
     * @brief checkMemberAcct 查询账号是否存在
     * @param acct
     * @return 返回账号的存在情况 SUCCESS-存在; ACCT_UNEXIST-账号不存在; PARAM_NULL-输入参数为空
     */
    virtual STACODE checkMemberAcct(QString acct) = 0;

    /**
     * @brief getMemberPswd  判断密码是否正确
     * @param acct
     * @param pswd
     * @return 返回状态码  SUCCESS-正确; PSWD_ERR-密码错误; PARAM_NULL-输入参数为空
     */
    virtual STACODE getMemberPswd(QString acct,QString pswd) = 0;
};

#endif // LOGINSERVICE_H

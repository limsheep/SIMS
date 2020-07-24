#ifndef REGISTERSERVICE_H
#define REGISTERSERVICE_H


#include <QString>
#include "STACODE.h"

/**
 * @brief The RegisterService class 注册服务接口
 */
class RegisterService
{
public:
    virtual ~RegisterService(){}    //有虚函数的类需要添加虚析构函数

public:
    /**
     * @brief rescheckMemberAcct 查询账号,姓名是否存在
     * @param acct
     * @return 返回账号的存在情况 ACCT_ALEXISTS-账号存在; ACCT_UNEXIST-账号不存在; PARAM_NULL-输入参数为空
     */
    virtual STACODE rescheckMemberAcct(QString acct, QString name) = 0;

    /**
     * @brief setMemberInfo  插入用户信息
     * @param acct
     * @param pswd
     * @param phone
     * @param name
     * @param position
     * @return 返回状态码  SUCCESS-注册成功;PARAM_NULL-参数为空
     */
    virtual bool setMemberInfo(QString name,QString acct, QString pswd, QString phone) = 0;
};

#endif // REGISTERSERVICE_H

#ifndef REGISTERDAO_H
#define REGISTERDAO_H

#include<QString>
#include"STACODE.h"

/**
 * @brief The LoginDao class 注册数据库访问业务接口
 */

class registerDao{
public:
    virtual ~registerDao(){}

public:
    /**
     * @brief rescheckMemberAcct 查询账号,姓名是否存在
     * @param acct
     * @return 返回账号的存在情况 ACCT_ALEXISTS-账号存在; ACCT_UNEXIST-账号不存在; PARAM_NULL-输入参数为空
     */
    virtual STACODE rescheckMemberAcct(QString acct, QString name) = 0;

    /**
     * @brief setMemberInfo 插入信息
     * @param acct
     * @param pswd
     * @param phone
     * @param name
     * @return 返回bool  true-注册成功; false-注册失败
     */

    virtual bool setMemberInfo(QString name,QString acct, QString pswd, QString phone) = 0;
};


#endif // REGISTERDAO_H

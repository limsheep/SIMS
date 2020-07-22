#ifndef LOGINDAO_H
#define LOGINDAO_H

#include<QString>

/**
 * @brief The LoginDao class 数据库访问业务接口
 */
class LoginDao{
public:
    virtual ~LoginDao(){};  //有虚函数的类需要添加虚析构函数
public:
    /**
     * @brief checkMemberAcct 查询账号是否存在
     * @param acct
     * @return 返回账号的存在情况 true-存在; false-账号不存在
     */
    virtual bool checkMemberAcct(QString acct) = 0;

    /**
     * @brief getMemberPswd 获取密码
     * @param acct
     * @return 返回查询到的密码
     */
    virtual QString getMemberPswd(QString acct) = 0;
};

#endif // LOGINDAO_H

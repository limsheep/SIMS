#ifndef STACODE_H
#define STACODE_H

/**
 * @brief The STACODE enum  状态码
 */
enum STACODE{
    SUCCESS,  //成功
    ACCT_UNEXIST,  //账号不存在
    PSWD_ERR,  //密码错误
    PARAM_NULL,  //参数为空

    ACCT_ALEXISTS,//账号已经存在
    NAME_ALEXISTS//姓名已经存在
};

#endif // STACODE_H

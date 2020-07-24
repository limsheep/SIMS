#include "Login.h"
#include "ui_Login.h"
#include <QRegExp>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include "gloable.h"



Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    //开工了
    ui->stackedW->setCurrentWidget(ui->welcome);

    QRegExp regExp("^[0-9]{11}$");
    QRegExpValidator *pattern = new QRegExpValidator(regExp,this);
    ui->lineEdit_bossresPhone->setValidator(pattern);//设置只能输入11位
    ui->lineEdit_bossresPhone->setValidator(pattern);

    QRegExp regExpName("[\u4e00-\u9fa5]{3,4}");
    QRegExpValidator *patternName = new QRegExpValidator(regExpName,this);
    ui->lineEdit_bossresName->setValidator(patternName);//设置只能输入中文
    ui->lineEdit_manaresName->setValidator(patternName);

    QRegExp regExpInter("^[0-9]{10}$");//设置只能输入10位
    QRegExpValidator *patternJnb = new QRegExpValidator(regExpInter,this);
    ui->lineEdit_bossJnb->setValidator(patternJnb);
    ui->lineEdit_bossresJbn->setValidator(patternJnb);
    ui->lineEdit_manaJbn->setValidator(patternJnb);
    ui->lineEdit_manaresJnb->setValidator(patternJnb);

    ui->lineEdit_bossPwd->setEchoMode(QLineEdit::Password);
    ui->lineEdit_bossresPwd->setEchoMode(QLineEdit::Password);
    ui->lineEdit_bossreSure->setEchoMode(QLineEdit::Password);
    ui->lineEdit_manaPwd->setEchoMode(QLineEdit::Password);
    ui->lineEdit_manaresPwd->setEchoMode(QLineEdit::Password);
    ui->lineEdit_manaresSure->setEchoMode(QLineEdit::Password);

    //打开数据库
    connectDB();
   // QSqlQuery query;
    //添加数据库表
    //query.exec("create table boss(id int primary key auto_increment, name varchar(255),  jobnumber varchar(10), password varchar(255), phone varchar(11))");
    //query.exec("create table manager(id int primary key auto_increment, name varchar(255),  jobnumber varchar(10), password varchar(255), phone varchar(11))");
}

void Login::connectDB()
{
    //添加数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("123456");
    db.setDatabaseName("supermarket");

    //打开数据库
    if(!db.open())
    {
        QMessageBox::warning(this, "数据库打开失败", db.lastError().text());
        return;
    }
}

Login::~Login()
{
    delete ui;


}

/*boss整体操作界面*/

//boss登录界面
//按下boss按钮
void Login::on_Boss_clicked()
{
    ui->stackedW->setCurrentWidget(ui->bslogin);
    on_Button_bossClear_clicked();
}
//boss去往注册页面
void Login::on_Button_bossTores_clicked()
{
    ui->stackedW->setCurrentWidget(ui->bsregist);
    on_Button_bossresClear_clicked();
}

//boss清空登录界面
void Login::on_Button_bossClear_clicked()
{
    ui->lineEdit_bossJnb->clear();
    ui->lineEdit_bossPwd->clear();
}
//返回welcome界面
void Login::on_Button_bossReturn_clicked()
{
    ui->stackedW->setCurrentWidget(ui->welcome);
}

//boss登录操作
void Login::on_Button_bossLogin_clicked()
{
    QString bossJnb = ui->lineEdit_bossJnb->text();
    QString bossPwd = ui->lineEdit_bossPwd->text();
    if(bossJnb.length() == 0 || bossPwd.length() == 0){
        QMessageBox::warning(this, "账号密码不完整", "请填写完整的信息", QMessageBox::Ok);
        return;
    }
}


//boss注册界面

//清空注册页面
void Login::on_Button_bossresClear_clicked()
{
    ui->lineEdit_bossresJbn->clear();
    ui->lineEdit_bossresName->clear();
    ui->lineEdit_bossresPhone->clear();
    ui->lineEdit_bossresPwd->clear();
    ui->lineEdit_bossreSure->clear();
}
//返回boss登录页面
void Login::on_Button_bossresReturn_clicked()
{
    ui->stackedW->setCurrentWidget(ui->bslogin);
    Login::on_Button_bossClear_clicked();
}


/*管理员整体界面*/

//管理员登录界面

//按下管理员按钮
void Login::on_Manager_clicked()
{
    ui->stackedW->setCurrentWidget(ui->malogin);
    Login::on_Button_manaClear_clicked();
}
//管理员登录动作
void Login::on_Button_manaLogin_clicked()
{
    QString acct = ui->lineEdit_manaJbn->text();
    QString pswd = ui->lineEdit_manaPwd->text();
    //此处应该对密码进行加密处理，作为后续升级需求
    if(acct == NULL || pswd == NULL){
        QMessageBox::warning(this, "信息不完整", "请输入账号与密码", QMessageBox::Ok);
        return;
    }
    LoginService *loginService = new LoginServiceImpl();
    STACODE status = loginService->checkMemberAcct(acct);
    if(status == PARAM_NULL){
        QMessageBox::warning(this, "信息不完整", "请输入账号", QMessageBox::Ok);
        return;
    }else if(status == ACCT_UNEXIST){
        QMessageBox::warning(this, "账号不存在", "请输入正确的账号", QMessageBox::Ok);
        return;
    }else if(status != SUCCESS){
        return;
    }
    status = loginService->getMemberPswd(acct,pswd);  //获取密码
    if(status == PARAM_NULL){
        QMessageBox::warning(this, "信息不完整", "请输入密码", QMessageBox::Ok);
        return;
    }else if(status == PSWD_ERR){
        QMessageBox::warning(this, "密码错误", "请输入正确密码", QMessageBox::Ok);
        return;
    }else if(status == SUCCESS){
        QMessageBox::information(this,"登录","登录成功",QMessageBox::Ok);
        return;
    }
}
//管理员前往注册界面
void Login::on_Button_manaToregist_clicked()
{
    ui->stackedW->setCurrentWidget(ui->maregist);
    on_Button_manaresClear_clicked();
}
//清空管理员登录界面
void Login::on_Button_manaClear_clicked()
{
    ui->lineEdit_manaJbn->clear();
    ui->lineEdit_manaPwd->clear();
}

//返回主界面
void Login::on_Button_manaReturn_clicked()
{
    ui->stackedW->setCurrentWidget(ui->welcome);
}

//管理员注册页面

//清空管理员注册页面
void Login::on_Button_manaresClear_clicked()
{
    ui->lineEdit_manaresJnb->clear();
    ui->lineEdit_manaresName->clear();
    ui->lineEdit_manaresPhone->clear();
    ui->lineEdit_manaresPwd->clear();
    ui->lineEdit_manaresSure->clear();
}

//返回管理员登录界面
void Login::on_Button_manaresReturn_clicked()
{
    ui->stackedW->setCurrentWidget(ui->malogin);
    on_Button_manaClear_clicked();
}
//管理员注册动作
void Login::on_Button_manaRegist_clicked()
{
    QString acct = ui->lineEdit_manaresJnb->text();
    QString pswd = ui->lineEdit_manaresPwd->text();
    QString phone = ui->lineEdit_manaresPhone->text();
    QString surepswd = ui->lineEdit_manaresSure->text();
    QString name = ui->lineEdit_manaresName->text();
    //此处应该对密码进行加密处理，作为后续升级需求
    if(acct == NULL || pswd == NULL || phone == NULL || surepswd == NULL || name == NULL){
        QMessageBox::warning(this, "信息不完整", "请填写全部信息", QMessageBox::Ok);
        return;
    }
    if(phone.length() != 11){ //判断号码的位数
        QMessageBox::warning(this,"号码错误","请输入正确的电话号码！",QMessageBox::Yes);
        ui->lineEdit_manaresPhone->clear();
        return;
    }
    if(name == NULL){  //判断姓名为空
        QMessageBox::warning(this,"姓名为空","请输入你的姓名！",QMessageBox::Yes);
        ui->lineEdit_manaresName->clear();
        return;
    }
    if(pswd.length() < 6){//密码严密性检测
        QMessageBox::warning(this,"密码简单","请保证密码不少于6个字符",QMessageBox::Yes);
        ui->lineEdit_manaresPwd ->clear();
        ui->lineEdit_manaresSure->clear();
        return;
    }
    if(pswd != surepswd){  //检验密码一致性
        QMessageBox::warning(this,"warning","两次密码输入不一致");
        ui->lineEdit_manaresSure->clear();
        ui->lineEdit_manaresPwd->clear();
        return;
    }

    RegisterService * registerservice = new RegisterServiceImpl();
    STACODE status = registerservice->rescheckMemberAcct(acct, name);
    if(status == ACCT_ALEXISTS){
        QMessageBox::warning(this, "账号已存在", "账号已存在，可直接登录", QMessageBox::Ok);
        return;
    }
    else if(status == PARAM_NULL){
        QMessageBox::warning(this, "信息不完整", "信息不完整，请补全信息", QMessageBox::Ok);
        return;
    }
    else if(status == NAME_ALEXISTS){
        QMessageBox::warning(this,"error","您的姓名已经注册，请直接登陆", QMessageBox::Ok);
        on_Button_manaresReturn_clicked();
    }

    else if(status == ACCT_UNEXIST){
        bool res = registerservice->setMemberInfo(name, acct, pswd, phone);

        if(!res){
            QMessageBox::warning(this, "注册", "注册失败", QMessageBox::Ok);
            on_Button_manaresClear_clicked();
            return;
        }else{
            QMessageBox::information(this,"注册","注册成功",QMessageBox::Ok);
            on_Button_manaresReturn_clicked();
            return;
        }
    }
}

#include "Login.h"
#include "ui_Login.h"
#include <QRegExp>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>



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


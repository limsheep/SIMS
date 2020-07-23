#ifndef login_H
#define Login_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QMainWindow
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_Boss_clicked();

    void on_Button_bossTores_clicked();

    void on_Button_bossClear_clicked();

    void on_Button_bossReturn_clicked();


    void on_Button_bossresClear_clicked();

    void on_Button_bossresReturn_clicked();

    void on_Manager_clicked();

    void on_Button_manaToregist_clicked();

    void on_Button_manaClear_clicked();

    void on_Button_manaReturn_clicked();

    void on_Button_manaresClear_clicked();

    void on_Button_manaresReturn_clicked();

    void on_Button_bossLogin_clicked();

    void on_Button_manaLogin_clicked();

private:
    Ui::Login *ui;
};
#endif // Login_H

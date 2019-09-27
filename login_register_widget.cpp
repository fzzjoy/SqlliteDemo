#include "login_register_widget.h"
#include "ui_login_register_widget.h"
#include "utils.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlResult>
#include <QDebug>

LoginRegisterWidget::LoginRegisterWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginRegisterWidget)
{
    ui->setupUi(this);
}

LoginRegisterWidget::~LoginRegisterWidget()
{
    delete ui;
}

void LoginRegisterWidget::on_loginRegisterPushButton_clicked()
{
    switch (work_mode)
    {
    case WorkMode::LOGIN_MODE:
        onLogin(ui->nameLineEdit->text(), ui->passwdLineEdit->text());
        break;
    case WorkMode::REGISTER_MODE:
        onRegister(ui->nameLineEdit->text(), ui->passwdLineEdit->text());
        break;
    default:
        break;
    }
}

void LoginRegisterWidget::onLogin(const QString &user_name, const QString &user_passwd)
{
    if((user_name.isEmpty()) || (user_passwd.isEmpty()))
    {
        QString err_info = tr("登录失败[用户名密码不能为空]");
        QMessageBox::critical(this, tr("错误提示"), err_info, QMessageBox::Ok | QMessageBox::Default, 0);
        return;
    }

    QSqlQuery query;
    QString sql = QString("select * from %1 where name='%2'").arg(kTableName).arg(user_name);
    if(!query.exec(sql))
    {
        QString err_info = tr("登录失败[%1]").arg(query.lastError().text());
        QMessageBox::critical(this, tr("错误提示"), err_info, QMessageBox::Ok | QMessageBox::Default, 0);
        return;
    }

    if(!query.next())
    {
        // not exist
        QString err_info = tr("登录失败[用户名不存在,请重新输入]");
        QMessageBox::critical(this, tr("错误提示"), err_info, QMessageBox::Ok | QMessageBox::Default, 0);
        return;
    }

    if(user_passwd != query.value("password").toString())
    {
        QString err_info = tr("登录失败[密码错误,请检查]");
        QMessageBox::critical(this, tr("错误提示"), err_info, QMessageBox::Ok | QMessageBox::Default, 0);
        return;
    }

    QMessageBox::information(this, tr("提示"), tr("登录成功"), QMessageBox::Ok | QMessageBox::Default, 0);
}

void LoginRegisterWidget::onRegister(const QString &user_name, const QString &user_passwd)
{
    if((user_name.isEmpty()) || (user_passwd.isEmpty()))
    {
        QString err_info = tr("注册失败[用户名密码不能为空]");
        QMessageBox::critical(this, tr("错误提示"), err_info, QMessageBox::Ok | QMessageBox::Default, 0);
        return;
    }

    QSqlQuery query;
    QString sql = QString("select * from %1 where name='%2'").arg(kTableName).arg(user_name);
    if(!query.exec(sql))
    {
        QString err_info = tr("注册失败[%1]").arg(query.lastError().text());
        QMessageBox::critical(this, tr("错误提示"), err_info, QMessageBox::Ok | QMessageBox::Default, 0);
        return;
    }

    if(query.next())
    {
        // exist
        QString err_info = tr("注册失败[用户已经存在,请重新输入]");
        QMessageBox::critical(this, tr("错误提示"), err_info, QMessageBox::Ok | QMessageBox::Default, 0);
        return;
    }

    sql = QString("INSERT INTO %1 VALUES(%2, %3)").arg(kTableName).arg(user_name).arg(user_passwd);
    if(!query.exec(sql))
    {
        QString err_info = tr("注册失败[%1]").arg(query.lastError().text());
        QMessageBox::critical(this, tr("错误提示"), err_info, QMessageBox::Ok | QMessageBox::Default, 0);
        return;
    }

    QMessageBox::information(this, tr("提示"), tr("注册成功"), QMessageBox::Ok | QMessageBox::Default, 0);
}

void LoginRegisterWidget::setWork_mode(const WorkMode &value)
{
    work_mode = value;
    switch (value) {
    case WorkMode::LOGIN_MODE:
        ui->loginRegisterPushButton->setText(tr("登录"));
        break;
    case WorkMode::REGISTER_MODE:
        ui->loginRegisterPushButton->setText(tr("注册"));
        break;
    default:
        break;
    }
}

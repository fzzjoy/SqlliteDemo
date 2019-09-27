#pragma once

#include <QWidget>

namespace Ui {
class LoginRegisterWidget;
}

class LoginRegisterWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LoginRegisterWidget(QWidget *parent = 0);
    ~LoginRegisterWidget();

    enum class WorkMode {
        LOGIN_MODE = 0,
        REGISTER_MODE,
    };

    void setWork_mode(const WorkMode &value);

private slots:
    void on_loginRegisterPushButton_clicked();

private:
    void onLogin(const QString &user_name, const QString &user_passwd);
    void onRegister(const QString &user_name, const QString &user_passwd);

    Ui::LoginRegisterWidget *ui;
    WorkMode                work_mode = WorkMode::LOGIN_MODE;

};


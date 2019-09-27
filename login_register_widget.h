#ifndef LOGIN_REGISTER_WIDGET_H
#define LOGIN_REGISTER_WIDGET_H

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

private slots:
    void on_loginRegisterPushButton_clicked();

private:
    Ui::LoginRegisterWidget *ui;
};

#endif // LOGIN_REGISTER_WIDGET_H

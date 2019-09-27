#include "login_register_widget.h"
#include "ui_login_register_widget.h"

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

}

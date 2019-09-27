#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "utils.h"
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    login_register_widget_ = make_unique<LoginRegisterWidget>();
    login_register_widget_->setWork_mode(LoginRegisterWidget::WorkMode::REGISTER_MODE);

    search_dialog_ = make_unique<SearchDialog>();
}

MainWindow::~MainWindow()
{
    if(database_.isOpen())
    {
        database_.close();
    }
    delete ui;
}

void MainWindow::showEvent(QShowEvent *event)
{
    Q_UNUSED(event);
    database_ = QSqlDatabase::addDatabase(kDbDriver);
    database_.setDatabaseName(kDbName);
    if(!database_.open())
    {
        QString err_info = tr("打开数据库失败[%1]").arg(database_.lastError().text());
        QMessageBox::critical(this, tr("错误提示"), err_info, QMessageBox::Ok | QMessageBox::Default, 0);
        return;
    }

    if(!createTable(kTableName))
    {
        return;
    }
    else
    {
        qDebug() << "create table success" << endl;
    }
}

bool MainWindow::createTable(const QString &name)
{
    QSqlQuery query;
    QString sql = QString("select * from sqlite_master where name='%1'").arg(name);
    query.exec(sql);
    if(query.next())
    {
        // exist
        qDebug() << "exist table" << endl;
        return true;
    }

    // create
    sql = QString("create table %1(name text primary key, password text)").arg(name);
    if(!query.exec(sql))
    {
        QString err_info = tr("打开数据库失败[%1]").arg(query.lastError().text());
        QMessageBox::critical(this, tr("错误提示"), err_info, QMessageBox::Ok | QMessageBox::Default, 0);
        return false;
    }
    return true;
}


void MainWindow::on_registerCmdLinkButton_clicked()
{
    login_register_widget_->show();
}

void MainWindow::on_searchCmdLinkButton_clicked()
{
    search_dialog_->show();
}

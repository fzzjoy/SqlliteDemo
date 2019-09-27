#pragma once

#include "search_widget.h"
#include "login_register_widget.h"
#include <QMainWindow>
#include <QSqlDatabase>
#include <memory>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_registerCmdLinkButton_clicked();

    void on_searchCmdLinkButton_clicked();

private:
    void showEvent(QShowEvent *event);
    bool createTable(const QString &name);

private:
    Ui::MainWindow *ui;

    QSqlDatabase                            database_;
    std::unique_ptr<LoginRegisterWidget>    login_register_widget_ = nullptr;
    std::unique_ptr<SearchWidget>           search_widget_ = nullptr;
};


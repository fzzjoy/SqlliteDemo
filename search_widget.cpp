#include "search_widget.h"
#include "ui_search_widget.h"
#include "utils.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>

using namespace std;

SearchWidget::SearchWidget(const QSqlDatabase &base, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchWidget)
{
    ui->setupUi(this);
    model_ = make_unique<QSqlTableModel>(this, base);
}

SearchWidget::~SearchWidget()
{
    delete ui;
}

void SearchWidget::showEvent(QShowEvent *event)
{
    Q_UNUSED(event)

    model_->setTable(kTableName);
    model_->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model_->select();

    model_->setHeaderData(0, Qt::Horizontal, QObject::tr("name"));
    model_->setHeaderData(1, Qt::Horizontal, QObject::tr("password"));

    ui->userTableView->setModel(model_.get());
    ui->userTableView->show();
}

void SearchWidget::execAction(const QString &action)
{
    if(!model_->submitAll())
    {
        QString err_info = tr("%1失败[%2]").arg(action).arg(model_->lastError().text());
        QMessageBox::critical(this, tr("错误提示"), err_info, QMessageBox::Ok | QMessageBox::Default, 0);
        return;
    }
    else
    {
        QMessageBox::information(this, tr("提示"), tr("%1成功").arg(action), QMessageBox::Ok | QMessageBox::Default, 0);
    }
}

void SearchWidget::on_searchPushButton_clicked()
{
    QString sql;
    if(ui->searchLineEdit->text().isEmpty())
    {
        sql = "";
    }
    else
    {
        sql = QString("name='%1'").arg(ui->searchLineEdit->text());
    }

    model_->setFilter(sql);
    model_->select();
}

void SearchWidget::on_savePushButton_clicked()
{
    execAction(std::move(tr("保存")));
}

void SearchWidget::on_deletePushButton_clicked()
{
    QItemSelectionModel *selections = ui->userTableView->selectionModel();
    QModelIndexList selected = selections->selectedIndexes();
    if(selected.size() == 0)
    {
        QMessageBox::warning(this, tr("错误提示"), tr("请先选中要删除的记录"), QMessageBox::Ok | QMessageBox::Default, 0);
        return;
    }

    QMessageBox::StandardButton reply = QMessageBox::question(this, tr("提示"), tr("确定删除选中记录?"), QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::No)
    {
        return;
    }

    foreach (QModelIndex index, selected)
    {
        model_->removeRow(index.row());
    }
    execAction(std::move(tr("删除")));
}

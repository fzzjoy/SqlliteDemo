#include "search_widget.h"
#include "ui_search_widget.h"
#include "utils.h"

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
    Q_UNUSED(event);

    model_->setTable(kTableName);
    model_->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model_->select();

    model_->setHeaderData(0, Qt::Horizontal, QObject::tr("name"));
    model_->setHeaderData(1, Qt::Horizontal, QObject::tr("password"));

    ui->userTableView->setModel(model_.get());
    ui->userTableView->show();
}

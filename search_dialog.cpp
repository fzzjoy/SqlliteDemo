#include "search_dialog.h"
#include "ui_search_dialog.h"

SearchDialog::SearchDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchDialog)
{
    ui->setupUi(this);
}

SearchDialog::~SearchDialog()
{
    delete ui;
}

void SearchDialog::showEvent(QShowEvent *event)
{
    Q_UNUSED(event);
}

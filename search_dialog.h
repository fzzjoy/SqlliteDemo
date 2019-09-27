#pragma once

#include <QDialog>

namespace Ui {
class SearchDialog;
}

class SearchDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SearchDialog(QWidget *parent = 0);
    ~SearchDialog();

private:
    void showEvent(QShowEvent *event);

    Ui::SearchDialog *ui;
};


#ifndef SEARCH_DIALOG_H
#define SEARCH_DIALOG_H

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
    Ui::SearchDialog *ui;
};

#endif // SEARCH_DIALOG_H

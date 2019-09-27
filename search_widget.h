#ifndef SEARCH_WIDGET_H
#define SEARCH_WIDGET_H

#include <QWidget>
#include <QSqlTableModel>
#include <QSqlDatabase>
#include <memory>

namespace Ui {
class SearchWidget;
}

class SearchWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SearchWidget(const QSqlDatabase &base, QWidget *parent = nullptr);
    ~SearchWidget();

private:
    void showEvent(QShowEvent *event);

    Ui::SearchWidget                    *ui;
    std::unique_ptr<QSqlTableModel>     model_;

};

#endif // SEARCH_WIDGET_H

#ifndef RANDBOOK_H
#define RANDBOOK_H

#include <QDialog>
#include <QStandardItemModel>

namespace Ui {
class RandBook;
}

class RandBook : public QDialog
{
    Q_OBJECT

public:
    explicit RandBook(QWidget *parent = nullptr);
    ~RandBook();

private:
    Ui::RandBook *ui;
    QStandardItemModel *csvModel;
};

#endif // RANDBOOK_H

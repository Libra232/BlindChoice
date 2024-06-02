#ifndef LOOKBOOKS_H
#define LOOKBOOKS_H

#include <QDialog>
#include <QStandardItemModel>

namespace Ui {
class LookBooks;
}

class LookBooks : public QDialog
{
    Q_OBJECT

private slots:
    void deleteSelectedRows();
    void saveChanges();

public:
    explicit LookBooks(QWidget *parent = nullptr);
    ~LookBooks();

private:
    Ui::LookBooks *ui;
    QStandardItemModel *csvModel;
};

#endif // LOOKBOOKS_H

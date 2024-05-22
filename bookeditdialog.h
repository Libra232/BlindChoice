#ifndef BOOKEDITDIALOG_H
#define BOOKEDITDIALOG_H

#include <QDialog>

namespace Ui {
class BookEditDialog;
}

class BookEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BookEditDialog(QWidget *parent = nullptr);
    ~BookEditDialog();

private:
    Ui::BookEditDialog *ui;
};

#endif // BOOKEDITDIALOG_H

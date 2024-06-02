#ifndef ADDBOOK_H
#define ADDBOOK_H

#include <QDialog>

namespace Ui {
class AddBook;
}

class AddBook : public QDialog
{
    Q_OBJECT

public:
    explicit AddBook(QWidget *parent = nullptr);
    ~AddBook();


private slots:
    void on_buttonBox_accepted();

private:
    void buildGenreComboBox();
    Ui::AddBook *ui;
};

#endif // ADDBOOK_H

#ifndef BOOKCHOICE_H
#define BOOKCHOICE_H

#include <QDialog>

namespace Ui {
class BookChoice;
}

class BookChoice : public QDialog
{
    Q_OBJECT

public:
    explicit BookChoice(QWidget *parent = nullptr);
    ~BookChoice();

private slots:
    void on_pushButtonAdd_clicked();

    void on_pushButtonAll_clicked();

    void on_pushButtonRand_clicked();

    void on_pushButtonGenre_clicked();

private:
    Ui::BookChoice *ui;
};

#endif // BOOKCHOICE_H

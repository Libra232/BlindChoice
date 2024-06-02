#ifndef MOVIECHOICE_H
#define MOVIECHOICE_H

#include <QDialog>

namespace Ui {
class MovieChoice;
}

class MovieChoice : public QDialog
{
    Q_OBJECT

public:
    explicit MovieChoice(QWidget *parent = nullptr);
    ~MovieChoice();

private slots:
    void on_pushButtonAdd_clicked();

    void on_pushButtonAll_clicked();

    void on_pushButtonRand_clicked();

private:
    Ui::MovieChoice *ui;
};

#endif // MOVIECHOICE_H

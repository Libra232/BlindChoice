#ifndef GENRECHOICE_H
#define GENRECHOICE_H

#include <QDialog>

namespace Ui {
class GenreChoice;
}

class GenreChoice : public QDialog
{
    Q_OBJECT

public:
    explicit GenreChoice(QWidget *parent = nullptr);
    ~GenreChoice();

private:
    Ui::GenreChoice *ui;
};

#endif // GENRECHOICE_H

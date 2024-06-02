#ifndef ADDMOVIES_H
#define ADDMOVIES_H

#include <QDialog>

namespace Ui {
class AddMovies;
}

class AddMovies : public QDialog
{
    Q_OBJECT

public:
    explicit AddMovies(QWidget *parent = nullptr);
    ~AddMovies();

private slots:
    void on_buttonBox_accepted();

private:
    void buildGenreComboBox();
    Ui::AddMovies *ui;
};

#endif // ADDMOVIES_H

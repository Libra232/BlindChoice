#ifndef ADDMOVIE_H
#define ADDMOVIE_H

#include <QDialog>

namespace Ui {
class AddMovie;
}

class AddMovie : public QDialog
{
    Q_OBJECT

public:
    explicit AddMovie(QWidget *parent = nullptr);
    ~AddMovie();

private slots:
    void on_buttonBox_2_accepted();

private:
    void buildGenreComboBox();
    Ui::AddMovie *ui;
};

#endif // ADDMOVIE_H

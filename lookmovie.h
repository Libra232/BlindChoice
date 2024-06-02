#ifndef LOOKMOVIE_H
#define LOOKMOVIE_H

#include <QDialog>
#include <QStandardItemModel>

namespace Ui {
class LookMovie;
}

class LookMovie : public QDialog
{
    Q_OBJECT

public:
    explicit LookMovie(QWidget *parent = nullptr);
    ~LookMovie();

private slots:
    void deleteSelectedRows();
    void saveChanges();

private:
    Ui::LookMovie *ui;
    QStandardItemModel *csvModel;
};

#endif // LOOKMOVIE_H

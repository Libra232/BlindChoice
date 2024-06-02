#ifndef NEWRANDB_H
#define NEWRANDB_H

#include <QDialog>

namespace Ui {
class NewRandB;
}

class NewRandB : public QDialog
{
    Q_OBJECT

public:
    explicit NewRandB(QWidget *parent = nullptr);
    ~NewRandB();

private:
    Ui::NewRandB *ui;
};

#endif // NEWRANDB_H

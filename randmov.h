#ifndef RANDMOV_H
#define RANDMOV_H

#include <QDialog>
#include <QStandardItemModel>

namespace Ui {
class RandMov;
}

class RandMov : public QDialog
{
    Q_OBJECT

public:
    explicit RandMov(QWidget *parent = nullptr);
    ~RandMov();

private:
    Ui::RandMov *ui;
    QStandardItemModel *csvModel;
};

#endif // RANDMOV_H

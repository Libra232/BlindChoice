#ifndef RANDMOVI_H
#define RANDMOVI_H

#include <QDialog>
#include <QStandardItemModel>

namespace Ui {
class RandMovi;
}

class RandMovi : public QDialog
{
    Q_OBJECT

public:
    explicit RandMovi(QWidget *parent = nullptr);
    ~RandMovi();

private:
    Ui::RandMovi *ui;
    QStandardItemModel *csvModel;
};

#endif // RANDMOVI_H

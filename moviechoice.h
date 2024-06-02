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

private:
    Ui::MovieChoice *ui;
};

#endif // MOVIECHOICE_H

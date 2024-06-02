#include "moviechoice.h"
#include "ui_moviechoice.h"

MovieChoice::MovieChoice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MovieChoice)
{
    ui->setupUi(this);
}

MovieChoice::~MovieChoice()
{
    delete ui;
}

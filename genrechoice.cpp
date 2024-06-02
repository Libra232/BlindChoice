#include "genrechoice.h"
#include "ui_genrechoice.h"

GenreChoice::GenreChoice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GenreChoice)
{
    ui->setupUi(this);
}

GenreChoice::~GenreChoice()
{
    delete ui;
}

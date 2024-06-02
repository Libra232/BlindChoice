#include "moviechoice.h"
#include "ui_moviechoice.h"
#include "addmovies.h"
#include "lookmovie.h"
#include "randmovi.h"

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

void MovieChoice::on_pushButtonAdd_clicked()
{
    AddMovies nbook;
    nbook.setModal(true);
    nbook.exec();
}


void MovieChoice::on_pushButtonAll_clicked()
{
    LookMovie nbook;
    nbook.setModal(true);
    nbook.exec();
}


void MovieChoice::on_pushButtonRand_clicked()
{
    RandMovi nbook;
    nbook.setModal(true);
    nbook.exec();
}


#include "bookchoice.h"
#include "ui_bookchoice.h"
#include "addbook.h"
#include "lookbooks.h"
#include "randbook.h"

BookChoice::BookChoice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BookChoice)
{
    ui->setupUi(this);
}

BookChoice::~BookChoice()
{
    delete ui;
}

void BookChoice::on_pushButtonAdd_clicked()
{
    AddBook nbook;
    nbook.setModal(true);
    nbook.exec();
}


void BookChoice::on_pushButtonAll_clicked()
{
    LookBooks nbook;
    nbook.setModal(true);
    nbook.exec();
}


void BookChoice::on_pushButtonRand_clicked()
{
    RandBook nbook;
    nbook.setModal(true);
    nbook.exec();
}



#include "newrandb.h"
#include "ui_newrandb.h"

NewRandB::NewRandB(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewRandB)
{
    ui->setupUi(this);
}

NewRandB::~NewRandB()
{
    delete ui;
}

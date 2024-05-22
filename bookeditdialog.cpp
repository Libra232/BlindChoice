#include "bookeditdialog.h"
#include "ui_bookeditdialog.h"

BookEditDialog::BookEditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BookEditDialog)
{
    ui->setupUi(this);
}

BookEditDialog::~BookEditDialog()
{
    delete ui;
}

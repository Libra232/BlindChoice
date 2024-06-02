#include "addbook.h"
#include "ui_addbook.h"
#include "storage.h"

AddBook::AddBook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddBook)
{
    ui->setupUi(this);
    buildGenreComboBox();
}

AddBook::~AddBook()
{
    delete ui;
}

void AddBook::buildGenreComboBox()
{
    for (const QString& item: {"comedy", "horror", "documentary", "science fiction", "musical", "cartoon", "western", "thriller", "historical", "romantic comedy", "adventure", "biographical", "detective"}){
        ui->genreComboBox->addItem(item);
    }
}

void AddBook::on_buttonBox_accepted()
{
    Book data;
    Storage store("Books.csv");
    data.Author = ui->authorLineEdit->text();
    data.Name = ui->nameLineEdit->text();
    data.Description = ui->descLineEdit->text();
    data.Link = ui->linkLineEdit->text();
    data.Genre = ui->genreComboBox->currentText();
    data.year = ui->yearSpinBox->value();
    store.writeCsv(data);
}


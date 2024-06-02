#include "addmovies.h"
#include "ui_addmovies.h"
#include "storage.h"

AddMovies::AddMovies(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddMovies)
{
    ui->setupUi(this);
    buildGenreComboBox();

}

AddMovies::~AddMovies()
{
    delete ui;
}

void AddMovies::buildGenreComboBox()
{
    for (const QString& item: {"comedy", "horror", "documentary", "science fiction", "musical", "cartoon", "western", "thriller", "action film", "historical film", "romantic comedy", "adventure", "biographical", "family-oriented film", "detective film"}){
        ui->genreComboBox_2->addItem(item);
    }
}

void AddMovies::on_buttonBox_accepted()
{
    Movie data;
    Storage store("Movies.csv");
    data.Director = ui->authorLineEdit_2->text();
    data.Name = ui->nameLineEdit_2->text();
    data.Description = ui->descLineEdit_2->text();
    data.Link = ui->linkLineEdit_2->text();
    data.Genre = ui->genreComboBox_2->currentText();
    data.year = ui->yearSpinBox_2->value();
    store.writeCsvM(data);
}

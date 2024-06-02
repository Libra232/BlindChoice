#include "addmovie.h"
#include "ui_addmovie.h"
#include "storage.h"

AddMovie::AddMovie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddMovie)
{
    ui->setupUi(this);
    buildGenreComboBox();

}

AddMovie::~AddMovie()
{
    delete ui;
}

void AddMovie::buildGenreComboBox()
{
    for (const QString& item: {"comedy", "horror", "documentary", "science fiction", "musical", "cartoon", "western", "thriller", "action film", "historical film", "romantic comedy", "adventure", "biographical", "family-oriented film", "detective film"}){
        ui->genreComboBox_2->addItem(item);
    }
}

void AddMovie::on_buttonBox_2_accepted()
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

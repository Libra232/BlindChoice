#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "storage.h"
#include "bookeditdialog.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    buildGenreComboBox();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::buildGenreComboBox()
{
    for (const QString& item: {"comedy", "horror", "documentary", "science fiction", "musical", "cartoon", "western", "thriller", "action film", "historical film", "romantic comedy", "adventure", "biographical", "family-oriented film", "detective film"}){
        ui->genreComboBox->addItem(item);
    }
}

void MainWindow::on_pushButton_clicked()
{
    Book data;
    Storage store("dox.csv");
    data.Author = ui->authorLineEdit->text();
    data.Name = ui->nameLineEdit->text();
    data.Description = ui->descLineEdit->text();
    data.Link = ui->linkLineEdit->text();
    data.year = ui->yearSpinBox->value();
    data.Genre = ui->genreComboBox->currentText();
    store.writeCsv(data);
    // ui->lineEdit->setText("Hello");
    BookEditDialog bed;
    if (bed.exec())
    {

    }

}


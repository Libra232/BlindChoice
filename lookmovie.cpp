#include "lookmovie.h"
#include "ui_lookmovie.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>


LookMovie::LookMovie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LookMovie)
{
    ui->setupUi(this);
    csvModel = new QStandardItemModel(this);
    csvModel->setColumnCount(6);
    csvModel->setHorizontalHeaderLabels(QStringList() << "Director" << "Name" << "Link" << "Description" << "Genre" << "Year");
    ui->tableView->setModel(csvModel);
    QFile file("Movies.csv");
    if ( !file.open(QFile::ReadWrite | QFile::Text) ) {
        qDebug() << "File not exists";
    } else {
        QTextStream in(&file);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QList<QStandardItem *> standardItemsList;
            for (QString item : line.split(",")) {
                standardItemsList.append(new QStandardItem(item));
            }
            csvModel->insertRow(csvModel->rowCount(), standardItemsList);
        }
        connect(ui->pushButtonDelete, &QPushButton::clicked, this, &LookMovie::deleteSelectedRows);
        connect(ui->pushButtonSave, &QPushButton::clicked, this, &LookMovie::saveChanges);
        file.close();
    }
}

LookMovie::~LookMovie()
{
    delete ui;
    delete csvModel;
}

void LookMovie::deleteSelectedRows()
{
    QModelIndexList selectedRows = ui->tableView->selectionModel()->selectedRows();
    std::sort(selectedRows.begin(), selectedRows.end(), [](const QModelIndex &a, const QModelIndex &b) {
        return a.row() > b.row(); // Sort in descending order
    });

    for (const QModelIndex &index : selectedRows) {
        csvModel->removeRow(index.row());
    }
}

void LookMovie::saveChanges()
{
    QFile file("Movies.csv");
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        qDebug() << "Unable to open file for writing";
        return;
    }

    QTextStream out(&file);
    for (int row = 0; row < csvModel->rowCount(); ++row) {
        QStringList rowContents;
        for (int column = 0; column < csvModel->columnCount(); ++column) {
            rowContents << csvModel->item(row, column)->text();
        }
        out << rowContents.join(',') << "\n";
    }
    file.close();
}

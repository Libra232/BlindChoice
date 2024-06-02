#include "randmovi.h"
#include "ui_randmovi.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QRandomGenerator>

RandMovi::RandMovi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RandMovi)
{
    ui->setupUi(this);
    csvModel = new QStandardItemModel(this);
    csvModel->setColumnCount(6);
    csvModel->setHorizontalHeaderLabels(QStringList() << "Director" << "Name" << "Link" << "Description" << "Genre" << "Year");
    ui->tableView->setModel(csvModel);

    QFile file("Movies.csv");
    if ( !file.open(QFile::ReadOnly | QFile::Text) ) {
        qDebug() << "File not exists";
    } else {
        QTextStream in(&file);
        QList<QStringList> rows;

        while (!in.atEnd()) {
            QString line = in.readLine();
            rows.append(line.split(","));
        }

        if (!rows.isEmpty()) {
            int randomRow = QRandomGenerator::global()->bounded(rows.size());
            QStringList rowItems = rows[randomRow];

            QList<QStandardItem *> standardItemsList;
            for (const QString &item : rowItems) {
                standardItemsList.append(new QStandardItem(item));
            }
            csvModel->appendRow(standardItemsList);
        }
        file.close();
    }
}

RandMovi::~RandMovi()
{
    delete ui;
    delete csvModel;
}

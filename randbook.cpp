#include "randbook.h"
#include "ui_randbook.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QRandomGenerator>

RandBook::RandBook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RandBook)
{
    ui->setupUi(this);
    csvModel = new QStandardItemModel(this);
    csvModel->setColumnCount(6);
    csvModel->setHorizontalHeaderLabels(QStringList() << "Author" << "Name" << "Link" << "Description" << "Genre" << "Year");
    ui->tableView->setModel(csvModel);

    QFile file("Books.csv");
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

RandBook::~RandBook()
{
    delete ui;
    delete csvModel;
}

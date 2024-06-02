#include "lookbooks.h"
#include "ui_lookbooks.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>


LookBooks::LookBooks(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LookBooks)
{
    ui->setupUi(this);
    csvModel = new QStandardItemModel(this);
    csvModel->setColumnCount(6);
    csvModel->setHorizontalHeaderLabels(QStringList() << "Author" << "Name" << "Link" << "Description" << "Genre" << "Year");
    ui->tableView->setModel(csvModel);
    QFile file("Books.csv");
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
        file.close();
    }
}

LookBooks::~LookBooks()
{
    delete ui;
    delete csvModel;
}


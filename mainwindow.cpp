#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "bookchoice.h"
#include "moviechoice.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonMovie_clicked()
{
    MovieChoice movie;
    movie.setModal(true);
    movie.exec();
}


void MainWindow::on_pushButtonBook_clicked()
{
    BookChoice book;
    book.setModal(true);
    book.exec();
}


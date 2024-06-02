#include "storage.h"
#include <fstream>
#include <sstream>
#include <QFile>
#include <QTextStream>


Storage::Storage(const QString &path):_path(path){};

void Storage::readCsv()
{
    QFile file(_path);
    file.open(QFile::ReadOnly);
    QString line = file.readLine();
    while (!file.atEnd()){
        line = file.readLine();
        Book book;
        auto row = line.split(',');
        for (int i = 0; i < row.size(); i++)
        {
            if (row[i].isEmpty())
            {
                row[i] = "0";
            }
            if (i == static_cast<int>(CSV_FIELDS::Author)) book.Author = row[i];
            if (i == static_cast<int>(CSV_FIELDS::Description)) book.Description = row[i];
            if (i == static_cast<int>(CSV_FIELDS::Genre)) book.Genre = row[i];
            if (i == static_cast<int>(CSV_FIELDS::Link)) book.Link = row[i];
            if (i == static_cast<int>(CSV_FIELDS::Name)) book.Name = row[i];
            if (i == static_cast<int>(CSV_FIELDS::Year)) book.year = row[i].toInt();
        }
        _libriary.append(book);
    }
    file.close();
};

void Storage::writeCsv(Book &book)
{
    QFile file(_path);
    file.open(QFile::Append);
    QTextStream ts(&file);
    ts <<  book.Author << "," << book.Name << "," << book.Link << ","<< book.Description << "," << book.Genre << "," << book.year << "\n";
    file.close();
}

void Storage::writeCsvM(Movie &movie)
{
    QFile file(_path);
    file.open(QFile::Append);
    QTextStream ts(&file);
    ts <<  movie.Director << "," << movie.Name << "," << movie.Link << ","<< movie.Description << "," << movie.Genre << "," << movie.year << "\n";
    file.close();
}

Book Storage::getRandomRow() {
    int randomIndex = rand();
    return _libriary[randomIndex];
}

#ifndef STORAGE
#define STORAGE
#include <QString>
#include <iostream>
#include <string>
#include <QList>

//typedef QList<QList<QString>> strvec;
using strvec = QList<QList<QString>>;

enum class CSV_FIELDS
{
    Name, Author, Description, Link, Genre, Year
};

struct Book
{
    QString Name;
    QString Author;
    QString Description;
    QString Link;
    QString Genre;
};

struct Movie
{
    QString Name;
    QString Director;
    QString Description;
    QString Link;
    QString Genre;
    int year;
};

class Storage
{
    public:
    void writeCsv(Book &book);
    void readCsv();
    Storage(const QString &path);
    friend std::ostream& operator <<(std::ostream& ostream, const Storage& t);

    private:
    QList<Book> _libriary;
    QList<Movie> _archive;
    QString _path;
};

std::ostream& operator <<(std::ostream& ostream, const Book& h);
std::ostream& operator <<(std::ostream& ostream, const Movie& h);



#endif

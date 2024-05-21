#ifndef STORAGE
#define STORAGE
#include <iostream>
#include <string>
#include <vector>

//typedef std::vector<std::vector<std::string>> strvec;
using strvec = std::vector<std::vector<std::string>>;

enum class CSV_FIELDS
{
    Name, Author, Description, Genre, Link, Year
};

struct Book
{
    std::string Name;
    std::string Author;
    std::string Description;
    std::string Link;
};

struct Movie
{
    std::string Name;
    std::string Director;
    std::string Description;
    std::string Link;
    int year;
};

class Storage
{
    public:
    static void readCsv(const std::string &path, strvec &table);
    Storage(const strvec &table);
    friend std::ostream& operator <<(std::ostream& ostream, const Storage& t);

    private:
    std::vector<Book> _libriary;
    std::vector<Movie> _archive;
};

std::ostream& operator <<(std::ostream& ostream, const Book& h);
std::ostream& operator <<(std::ostream& ostream, const Movie& h);



#endif
